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

typedef struct s_variable
{
	char *nom;    // Nom de variable
	int type;       // Type de variable
	int adresse;   // Adresse de la variable

}variable;
typedef struct s_function
{
	char *name;
	int lib;
	char *content;
	int adresse;
	char *token;

}function;
typedef struct s_s_printf{
	char *cont;
}f_printf;
typedef struct memoire
{
	unsigned char *tabmem;
	variable *tabvar;
	function *tabfunct;
	f_printf *tab_printf;

}memoire;


memoire *InitMemoire (int taille, int nb_vars);
int AfficheMemoire (unsigned char *octets, int start, int N);
void FreeMemoire (memoire *mem);
int EcrireNombre (unsigned char *mem, int taille, int valeur);
int LireNombre (unsigned char *mem, int taille, int *valeur);
