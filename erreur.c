/* 

##     ## #### ##    ## ######## 
###   ###  ##  ###   ##    ##    
#### ####  ##  ####  ##    ##    
## ### ##  ##  ## ## ##    ##    
##     ##  ##  ##  ####    ##    
##     ##  ##  ##   ###    ##    
##     ## #### ##    ##    ##   

an interpreter written in C

[+]Author : Naper
[+]Web site : www.naper.eu
[+]Web site : mpp-project.org


*/
#include <stdio.h>
#include <stdlib.h>
#include "Headers/erreur.h"
/*
Fonction :AfficheErreur
Description :
retourne :
*/
int AfficheErreur (char *fct, char *var, int type){
	switch(type){
		case 1:
			printf("Erreur lors de la location de méamoire dans la fonction %s var %s",fct,var);
			break;
        	case 2:
            		printf("Erreur lors de la liberation ");
           	 	break;
        	case 3:
            		printf("");
            		break;
		case 5:
            		printf("can't find %s",var);
            		break;
	}

	return -1;
}

int error_langue(int id_lang){
    //fr or ang
    
    return 0;
}