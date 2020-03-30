# PING

## GitHub

### Initialisation


Pour que ça fonctionne faut que vous créiez un répertoire local ni sur OneDrive ni avec un chemin contenant des caractères spéciaux.
Ensuite vous installez Visual Studio Code (https://code.visualstudio.com/) + Git (https://git-scm.com/download/win).
Quand vous lancez Visual Studio Code il faut que vous choisissiez le type de terminal. 
Tapez CTRL-SHIFT-P et une box devrait s'ouvrir en haut de votre éditeur. Tapez "Select Default Shell" et choisissez la shell bash
Vous pourrez comme ça avoir le terminal git bash directement intégré dans VSC plutôt que devoir gérer deux fenêtres distinctes.

////////////////////////////////
SI BASH N'APPARAIT PAS DANS LES SHELLS PROPOSEES

Ce problème survient sur plusieurs types de machine (notamment la mienne).
Il faut alors aller dans les Settings (en passant par le rouage en bas à gauche) et scroll jusqu'à ce que vous trouviez un lien 'Edit in settings.json'. Cliquez dessus, ça vous ouvrira directement le fichier settings.json sans que vous ayez à le chercher dans votre machine
Vous devriez avoir dans une des lignes du répertoire quelque chose de similaire à :
"terminal.integrated.shell.windows": "C:\\Program Files (x86)\\Git\\bin\\bash.exe",

Il s'agit du chemin qui permet au terminal de savoir quelle shell utiliser, vous devriez avoir un chemin différent qui ne mène pas à bash.
Il faut donc que vous remplaciez le chemin d'exemple que j'ai indiqué par votre chemin vers bash.exe qui aura été installé en même temps que Git. Votre chemin devrait être similaire au mien donc je vous le laisse à titre d'exemple (attention à mettre des \\ ou des / dans le chemin sinon il ne sera pas reconnu)
////////////////////////////////

Ensuite faut taper les lignes suivantes : 

```
git init
```
Pour initialiser le répertoire et permettre d'utiliser git avec

```
git remote add upstream https://github.com/RemiEC/PING.git
```
Va créer un "flux" entre votre dossier local et le git du projet
```
git remote -v
```
Devrait afficher tous les flux reliés au dossier local dans lequel vous êtes, ici ça devrait donc afficher le flux upstream
```
git fetch upstream
```
Va vous ajouter les références du git projet (notamment les infos des branches) et vous permettre de les utiliser
```
git pull upstream master
```
Va 'pull' tous les éléments que vous n'avez pas à jour dans votre dossier (ici ça va donc récupérer tout le projet de Git et le mettre sur votre machine)

Une fois tout celà fait votre répertoire est opérationnel !

Par la suite on créera sans doute plusieurs branches pour le développement de chaque feature et il faudra être vigilant à la branche sur laquelle vous êtes avant de tenter de pull ou push du code.


# Utilisation normale

EXEMPLE

En temps normal quand vous travaillerez il faudra tester les modifications sur votre ordi puis quand vous voulez les envoyer il faut utiliser les commandes suivantes : 
```
git add -A -- . 
```
Va stage tous les changements que vous avez apportés (addition, deletion, modification)
```
git commit -m <votremessage>
```
Pour commit les changements que vous avez apporté au code
```
git push upstream master (ou juste "git push" parfois ça passe)
```
Pour envoyer vos modifications au git via le "flux" upstream sur la branche master
  
  Ces commandes doivent être effectuées à chaque fois que vous voulez envoyer vos changements sur le git. L'avantage d'utiliser Studio Code et Git comme je l'ai indiqué plus haut est que plutôt que d'avoir à taper toutes ces lignes à chaques fois on peut passer par l'interface graphique de VSC pour le faire en 2-3 clics
  
  De même avant de procéder à des changements il faudra toujours pull les modifications apportées par les autres au projet, pour ça il faut utiliser la commande :
  ```
  git pull upstream master (ou juste "git pull" parfois ça passe)
  ```
 Pour recevoir via le "flux" upstream les changements apportés à la branche master (attention à être sur la bonne branche avec votre "git checkout", la branche sur laquelle vous êtes est indiquée en bas à gauche dans Studio Code pour vous aider)
  
  Encore une fois avoir le setup que j'ai conseillé facilite les choses, vous pourrez voir en bas à gauche combien de commit vous devez pull pour être à jour et combien de commit vous avez fait depuis votre dernier push. En cliquant sur le bouton d'actualisation vous pourrez pull puis push automatiquement.
  
  
  # ATTENTION
  
  - Toujours vérifier la branche sur laquelle on est
  - Pull AVANT de faire le moindre changement, sinon vous allez avoir des merges conflicts. C'est pas compliqué à résoudre mais ça peut     faire perdre du temps
  - Pas de panique si vous ratez un truc et supprimez des choses sur le Git, il est doté d'un système de version control qui permet de      restaurer des versions antérieures du repo. A moins de le faire exprès vous pourrez pas tout planter involontairement.
  - Les messages des commits doivent être clair (quoi, pourquoi, comment) pour éviter qu'on soit obligé de passer dernière pour             comprendre ce qui a changé (par exemple mes derniers commit sont très mauvais)
