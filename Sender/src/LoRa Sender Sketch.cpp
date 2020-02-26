#include <Arduino.h>
/*********
  Modified from the examples of the Arduino LoRa library
  More resources: https://randomnerdtutorials.com
*********/

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 18
#define rst 14
#define dio0 26

//Use ADC1 for analogRead(), ADC2 won't work when used while using Wifi
//No need for pinMode(), just write analogRead(#GPIO)

const int PinCapteur1 = 36;
const int PinCapteur2 = 37;
const int PinCapteur3 = 38;
int valueCapteur1 = 0;
int valueCapteur2 = 0;
int valueCapteur3 = 0;

//A retirer pour les définir plus tard, ici ça sert à rien
double distance1 = 0;
double distance2 = 0;
double distance3 = 0;

//define pin for the transistor control
const int Transistor = 12;

//counter for packets
int counter = 0;

void setup() {
  //Control pin for transistor, activate the sensors
  pinMode(12,OUTPUT);
  digitalWrite(12, HIGH);
  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(866E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

 
  
}

double CalculDistance (double tension)
{
  double result = -30.907*pow(tension,6.0) + 303.24*pow(tension,5.0) -1166.5*pow(tension,4.0) + 2202.3*pow(tension,3.0) - 2049.8*pow(tension,2.0) + 744.65*tension + 59.832
}
void loop() {

  //Check the values of the 3 sensors
  valueCapteur1 = analogRead(PinCapteur1);
  valueCapteur2 = analogRead(PinCapteur2);
  valueCapteur3 = analogRead(PinCapteur3);
  //To convert it from Voltage value to distance (we need to hard-test the sensor to determine the distance/voltage relation)

  // Corriger les formules avec des tests réels
  distance1 = CalculDistance(valueCapteur1);
  distance2 = CalculDistance(valueCapteur2);
  distance3 = CalculDistance(valueCapteur3);
  
  //Initialisation LoRa

  Serial.println("Sending packet: ");
  String texte = "distance 1 :";
  String texte2 =  " distance 2 : ";
  String texte3 =  " distance 3 : ";
  Serial.print(texte); Serial.println(distance1);
  Serial.print(texte2); Serial.println(distance2);
  Serial.print(texte3); Serial.println(distance3);
  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.println("Packet number " + counter);
  LoRa.print(texte); LoRa.println(distance1);
  LoRa.print(texte2); LoRa.println(distance2);
  LoRa.print(texte3); LoRa.println(distance3);
  LoRa.endPacket();
  
  counter ++;
  delay(1000);
}