------------------------------------------------------------------------------
------------------------------------------------------------------------------
------------------------------THE SHEEP KEEPER--------------------------------
------------------------------------------------------------------------------
------------------------------------------------------------------------------

The Sheep Keeper est un jeu vidéo codé en C++ dans le cadre de l'évaluation de
l'unité INF-4102A Généricité et C++. Le but du jeux est de garder un maximum de 
mouton vivant à la fin des 60 secondes. Les moutons peuvent fuire les loups et 
peuvent être protegé par le berger ou le chien du berger. Les moutons peuvent se 
reproduire et courrir afin d'échapper à un loup qui serait trop proche.

Le score est calculé de la manière suivante :
naissance d'un mouton 	+100
mort d'un mouton 		-50
mort d'un loup 		+250 

Le score et le temps restant sont affiché sur l'écran grace à la bibliothèque 
SDL_ttf.


Le jeux a été coder sur windows mais reste exécutable sur linux. Il est possible 
qu'un changement de chemin d'accès au differentes images dans le code du fichier 
main.cpp soit nécessaire.
Pour lancer le jeux, il faut les bibliothèques SDL2, SDL2_image et SDL2_ttf.
Ensuite il faut utiliser le fichier CMakeLists pour compiler le jeux et pouvoir 
le lancer avec le fichier .exe dans le dossier out.

Le jeux a été coder avec de nombreuse classe afin de représenter au mieux 
les differents animaux et pouvoir ajouter des nouveau animaux. Il y a aussi un 
héritage entre la classe animal et les classes sheep et wolf. 

Les différentes classes du projet :

Sheep.hh / Sheep.cpp

Wolf.hh / Wolf.cpp

Animal.hh / Animal.cpp

Ground.hh / Ground.cpp

Player.hh / Player.cpp
