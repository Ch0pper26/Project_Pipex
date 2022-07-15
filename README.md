# Project_Pipex

Ce project reproduit le fonctionnment des pipes

Pour compiler le project utiliser la régle make du Makefile et ensuite lancer le ./pipex

Le programme gère les multiples pipes

 ./pipex infile "ls -l" "wc -l" outfile
 
 se comporte comme < infile ls -l | wc -l > 
