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
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "Headers/memoire.h"
#include "Headers/erreur.h"
int ini_cmd(int argc, char **argv){
	int i;

   	 while (1) {
        	char c;

       	 c = getopt (argc, argv, "xhi:");
        	if (c == -1) {
            		break;
        	}
        	switch (c) {
        		case 'i':
				read_file(argv[2]);
        	   		break;
        		case 'h':
        	 	 	help();
         	 	  	break;
       	 		case '?':
        		default:
        	  		printf ("Usage: %s [-i] <filename.m++>.\n", argv[0]);
       		 }
    		
   	 }
    return -1;

}
int help(){
	printf("========================== \n");
	printf("           MINT            \n");
	printf("========================== \n");
	printf("syntaxe : mint -i <file.m++> \n");
	return -1;


}	
int main(int argc, char **argv){
	memoire * m;
	if (argc < 2 ){
		printf("[Error]: Mint need arguments , -h for help \n");
		return -1;
	}
	ini_cmd(argc, argv);
	//m = InitMemoire(2, 3);
	//AfficheMemoire(m->tabmem, 1, 4);
	EcrireNombre(m->tabmem,8,5);
	//FreeMemoire(m);
	return 0;

}
