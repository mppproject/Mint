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
#include "Headers/memoire.h"
#include "Headers/erreur.h"

memoire *InitMemoire (int taille, int nb_vars){

	memoire * m;
	variable v;

	m->tabmem = NULL;
	m->tabvar = NULL;

	m->tabmem = malloc((taille)*sizeof(unsigned char*));
	m->tabvar = malloc((nb_vars)*sizeof(variable*));

	if ((!m->tabvar) && (!m->tabmem))
		AfficheErreur("Initmemoire", v.nom, ERR_ALLOC);



	return m;
}
/*
Fonction :AfficheMemoire
Description :
retourne :
*/
int AfficheMemoire (unsigned char *octets, int start, int N){

	int i;
	for (i = start; i<N; i++){
		printf("octets[%i] ==> %d\n",i,octets[i]);
	}

	return 0;

}
/*
Fonction :FreeMemoire
Description :
retourne :
*/
void FreeMemoire (memoire *mem){
	free(mem->tabmem);
	free(mem->tabvar);
	//free(mem);
        //AfficheErreur("Initmemoire", v.nom, ERR_FREE);
	return ;
}



