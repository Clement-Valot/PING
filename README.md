# PING
Projet Ping Campius Connecté


# GitHub

Pour que ça fonctionne faut que vous créiez un répertoire local ni sur OneDrive ni avec un chemin contenant des caractères spéciaux.
Ensuite vous installez Visual Studio Code (https://code.visualstudio.com/) + Git (https://git-scm.com/download/win)
Quand vous lancez Visual Studio Code il faut que vous choisissiez le type de terminal en faisant  : 
Press CTRL-SHIFT-P and a selection box should appear at the top of the editor. Type in default shell and click on the Terminal: Select Default Shell option.
Si jamais ça marche pas vous me demandez

Ensuite faut taper "git init" pour initialiser le répertoire avec git, puis taper
"git clone https://github.com/RemiEC/PING.git"
"git remote add upstream https://github.com/RemiEC/PING.git"
"git remote -v"

La normalement vous devriez avoir des trucs qui s'affichent
Puis vous tapez :

"git fetch upstream"
"git checkout master"
"git merge upstream/master" (celle ci peut ne pas marcher, dites moi si c'est le cas et j'update le tuto)

Là vous devriez avoir un répertoire fonctionnnel

Quand vous voudrez bosser avant de changer quoique ce soit faudra git pull upstream master
Ensuite vous écrivez vos bails
Ensuite vous irez sur l'onglet que je vous indiquerai et vous commitez les changes, puis vous faites push pour les envoyer sur le github
