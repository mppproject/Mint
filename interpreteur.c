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
#include "Headers/memoire.h"
#include "Headers/interpreteur.h"

#define NUMBER_FUNC    100
#define NUMBER_GLOBAL_VARS 150
#define NUMBER_LOCAL_VARS  200
#define ID_LEN          31 
#define FUNC_CALLS      31
#define PROG_SIZE   10000
#define FOR_tEST    31
#define MAX_TAB_IDENT 50

extern int pos;
extern char *bug;
//register int is_doing;
char *filename;
int ident_pos = 0 ;
int nb_errors;
int nb_warning;
char *pname;

int searching_important_stuff(char * file){
	int find;
	find = searh_for(file,"#bda");
	if (find == 0){
		printf("[Error] : #bda makaynach f labdya dyal %s \n",file);
		nb_errors++;
		return -1;
	}
	find = searh_for(file,"bda(");
	if (find == 0){
		printf("[Error] : bda fonction makaynach \n");
		nb_errors++;
	}
	if (find > 1){
		printf("[Error] : 'bda' kayna  \n");
		nb_errors++;
	}
}
int using_kmpp_for_fun(){
	// a simple options . if we have 0 errors we will use kmpp to compile the file
	char cmd[200];
	int nb_rand;
	srand(time(NULL));
	nb_rand  = rand()%(100-0);
	pname = "test";
	if (!nb_errors && !nb_warning){
		sprintf(cmd,"kmpp %s -o %s%d",filename,pname,nb_rand);
		printf("[MINT] : %s%d generated \n",pname,nb_rand);
		system(cmd);
	}
	return ;
}
int searh_for(char * file, char *str){
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	FILE * fp;
	fp = fopen(file,"r");
	if (!fp){

	}
	else {
		while(fgets(temp, 512, fp) != NULL) {
			if((strstr(temp, str)) != NULL) {
				find_result++;
			}
			line_num++;
		}
			return find_result;
	}
	fclose(fp);
	

}
int nb_line(){
	int all_line = 0;
	char temp[512];
	FILE * f;
	f = fopen(filename,"r");
	if (!f){

	}
	else {

		while(!feof(f)){
        	fgets(temp, 512, f);
			all_line++;
		}
		return all_line;
	}
	fclose(f);
}
int remove_char(char* str, char c){
	char *_pr = str, *_pw = str;
    while (*_pr) {
        *_pw = *_pr++;
        _pw += (*_pw != c);
    }
    *_pw = '\0';

}
int remove_string(char *src,char *key)
{
 	// removing the #include and <> or "" for having the name of the header file
 	 while( *src )
  	 {
   		char *k=key,*s=src;
    	while( *k && *k==*s ) ++k,++s;
    	if( !*k )
    	{
      		while( *s ) *src++=*s++;
      			*src=0;
      			return 1;
    	}
    	++src;
  	}
  return 0;
}
char *get_funct_token(){
	char *token;
	//every function should have a token ex : dc5Sd4FFef
	return token;
}
int functions(char * string, int line,FILE* f){
	tab t;
	int i;
	int nb_ident_i = 0 ;
	int s = 0;
	int z = 0;
	int nb_ident = 0;
	int all_line = 0;
	int nb_var = 0;
	int var_pos = 0;
	int nb_funct = 0, funct_pos = 0;
	char * hf = string;
	char * hf_funct = string;
	char * multiple_variables;
	memoire m;
	m.tabvar = calloc(all_line*3, sizeof(variable));
	m.tabfunct = calloc(all_line*2, sizeof(function));
	//having number of the file
	all_line = nb_line();
	t.tab_ident = NULL;
	t.tab_ident = calloc(all_line*2, sizeof(char*));
	t.tab_functions = calloc(all_line*2, sizeof(int*));
	if (strstr(string,"ra9m") || strstr(string,"_7arf") || strstr(string,"khawi") || strstr(string,"_7a9i9i")){
		//will use the strtok to support multiple declaration in one line ex : int f,g;
		if (strstr(string ,",")){
			if (string[strlen(string)-1] != ';' && !strstr(string,"{")){
				printf("star %d : nssiti ';' f lakher d star \n",line);
				nb_errors++;
			}
			while( multiple_variables != NULL ) 
  		 	{
      			multiple_variables = strtok(NULL, ",");
      			nb_var = nb_var + 1;
				var_pos = nb_var;
				m.tabvar[var_pos].nom = multiple_variables;
				m.tabvar[var_pos].type = 1; // 1 for int 
				m.tabvar[var_pos].adresse = 0x00000;
   			}
		}
		if (strstr(string,"{")){
			// if we found a { we will wait for another }
			nb_ident = nb_ident + 1;
			ident_pos = nb_ident;
			t.tab_ident[ident_pos] = '{';
			t.tab_functions[ident_pos] = 2;
			s = 1;
		}
		if (strstr(string,"(")){
			// if we found a ( we will wait for another }
			// it's a function so we will add it to the tab funct
			/*
			======================
				Save function
			======================
			*/
			/*
				if(strstr(string,"int") && strstr(string,"(")){
					while(remove_string(hf_funct,"int"));
					remove_char(hf_funct,' ');
					nb_funct++;
					funct_pos = nb_funct;
					m.tabfunct[funct_pos].name = hf;
					m.tabfunct[funct_pos].token = get_funct_token();
				}
				else if(strstr(string,"char") && strstr(string,"(")){
					while(remove_string(hf_funct,"char"));
					remove_char(hf_funct,' ');
				}
				else if(strstr(string,"void") && strstr(string,"(")){
					while(remove_string(hf_funct,"void"));
					remove_char(hf_funct,' ');
				}
				else if(strstr(string,"float") && strstr(string,"(")){
					while(remove_string(hf_funct,"float"));
					remove_char(hf_funct,' ');
				}
				*/
			/*
			======================
				End Save function
			======================
			*/

			nb_ident = nb_ident + 1;
			ident_pos = nb_ident;
			t.tab_ident[ident_pos] = '(';
			t.tab_functions[ident_pos] = 4;
			//s = 1;
		}
		if (strstr(string,")")){
			nb_ident = nb_ident + 1;
			ident_pos = nb_ident;
			t.tab_ident[ident_pos] = ')';
			t.tab_functions[ident_pos] = 5;
			//s = 1;
		}
		if (strstr(string,";")){
			// it's a varibale , so we will add it to the tab var
			if(strstr(string,"ra9m") && !strstr(string,"(")){
				while(remove_string(hf,"int"));
				remove_char(hf,' ');
				remove_char(hf,';');
				nb_var = nb_var + 1;
				var_pos = nb_var;
				m.tabvar[var_pos].nom = hf;
				m.tabvar[var_pos].type = 1; // 1 for int 
				m.tabvar[var_pos].adresse = 0x00000;

			}
			else if (strstr(string,"char") && !strstr(string,"(")){
				while(remove_string(hf,"char"));
				remove_char(hf,' ');
			}
			else if (strstr(string,"void") && !strstr(string,"(")){
				while(remove_string(hf,"char"));
				remove_char(hf,' ');
			}
			else if (strstr(hf,"float") && !strstr(string,"(")){
				while(remove_string(hf,"char"));
				remove_char(hf,' ');
			}
			s = 1;
		}
		if(s == 0){
			printf("star %d : nssiti ';' oula '{'  \n",line);
			nb_errors++;
		}
	}
	if (strstr(string,";") && !strstr(string,"(")){
		remove_char(hf,';');
		for(i = 0 ; i<all_line*3 ;i++){
			if (m.tabvar[i].nom != 0){
				if (strstr(hf,m.tabvar[i].nom)){
				
				}
				else{
					printf("star %d : '%s' makaynach  \n",line,hf);
					nb_errors++;
				}
			}
			else {
				printf("star %d : '%s' makaynach \n",line,hf);
				nb_errors++;
			}
		}
	}
	if (strstr(string,"}")){
		nb_ident = nb_ident + 1;
		ident_pos = nb_ident;
		t.tab_ident[ident_pos] = '}';
		t.tab_functions[ident_pos] = 3;
		s = 1;
	} 
	// variables

	if ((feof(f) == 0)){
		if (t.tab_ident[ident_pos] == '{'){
			printf("star %d : nssiti '}'  \n",(line +1));
			nb_errors++;
		}
		if (t.tab_ident[ident_pos] == '('){
			printf("star %d : nssiti ')' \n",(line));
			nb_errors++;
		}
	}

	return 0;
}


int printf_function(char  *content, int line,FILE* f){
	memoire m;
	int i;
	int pos_p = 0, nb_p = 0;
	char * ct ;
	char ** tprint;
	tprint = NULL;
	tprint = calloc(strlen(content),sizeof(char**));
	if (strstr(content,",")){
		//we will analyse all the content if we have a %d or %s and variables if they are declared
		// will use strtok to have all variables and a temp tab
		 ct = strtok(content, ",");
    
   		while( ct != NULL ) 
  		 {
     		//printf("%s \n",content);
      		ct = strtok(NULL, ",");
      		nb_p++;
      		pos_p = nb_p;
      		tprint[pos_p] = ct;
      		//printf("%s \n",tprint[pos_p]);
   		}
	}
	if (!strstr(content,",") && strstr(content,"%")){
		printf("star %d : '%%' bla des variables \n",line);
		nb_errors++;
	}
	if (!nb_errors){
		if (strstr(content,"\\n")){
			remove_char(content,'n');
			remove_char(content,'\\');
			printf("%s\n",content);
		}
		else {
			printf("%s",content);
		}
	}
				
}
int show_result(int fonct_id, char * content, int type,int line,FILE* f){
	register int a;
	if (!nb_errors){
		//showing result
		switch(fonct_id){
			case 1:
				printf_function(content,line,f);
				break;
		}


	}
	return 0;
}
int header_functions(char * string, int line,FILE* f){
	int s=0;
	char *h_file = string;
	if(strstr(string,"ktab(")){
		if (strstr(string,"	 ")){
			///while(remove_string(string,"   "));
		}
		if(strstr(string,";")){
			s = 1;
			while(remove_string(h_file,"printf("));
			remove_char(h_file,')');
			remove_char(h_file,';');
			remove_char(h_file,'"');
			show_result(1,h_file,0,line,f);
		}
		if(s == 0){
			printf("star %d : nssiti ';' oula '{' \n",line);
			nb_errors++;
		}
	}
	return 0;
}
int directive_proc(char * string, int line,FILE* f){
	char *h_file =string;
	char t[1025] ;
	/*
	mint don't need any header file for interpreting m++ files
	if (strstr(string,"#include")){
		// name of header
		while(remove_string(h_file,"#include"));
		remove_char(h_file,'<');
		remove_char(h_file,'>');
		remove_char(h_file,' ');
		FILE * header;
		char path[1025];
		sprintf(path,"/usr/include/%s",h_file);
		header = fopen(path,"r");
		if (!header){
			printf("line %d : %s no such file or directory\n",line,h_file);
			nb_errors++;
		}
	}
	*/

}
int parsing(char * string, int line,FILE* f){
	tab t;
	directive_proc(string,line,f);
	functions(string,line,f);
	header_functions(string,line,f);
}
int check_extension(char *file){
	if (!strstr(file,".m++")){
		printf("[Error] : fichier .m++ machi valid \n");
		return -1;
	}
}	

int read_file(char * file){
	FILE * program;
	filename = file;
	program = NULL;
	program = fopen(file,"r");
	char line[1025];
	int sz = 0;
	int nb_line = 0;
	if (!program){
		printf("[Error]: can't find %s \n",file);
	}
	else{
		check_extension(file);
		searching_important_stuff(file);
		while(!feof(program)){
			fgets(line, 1025, program);line[strlen(line) - 1] = '\0';
			nb_line = nb_line + 1;
			parsing(line,nb_line,program);
		}

	}
	//using_kmpp_for_fun();
	printf("[MINT] : Finished with %d error(s) and %d warning \n",nb_errors,nb_warning);
	fclose(program);
	return 0;
}
char bintohex(int n){
/*
    char hex[100];
    int i=0,decimal=0, rem;
    while (n!=0)
    {
        decimal += (n%10)*pow(2,i);
        n/=10;
        ++i;
    }

    i=0;
    while (decimal!=0)
    {
        rem=decimal%16;
        switch(rem)
        {
            case 10:
              hex[i]='A';
              break;
            case 11:
              hex[i]='B';
              break;
            case 12:
              hex[i]='C';
              break;
            case 13:
              hex[i]='D';
              break;
            case 14:
              hex[i]='E';
              break;
            case 15:
              hex[i]='F';
              break;
            default:
              hex[i]=rem+'0';
              break;
        }
        ++i;
        decimal/=16;
    }
    hex[i]='\0';
    strrev(hex);
    return hex;  
*/
}
/*
Fonction :LireNombre
Description :
retourne :
*/
int LireNombre (unsigned char *mem, int taille, int *valeur){
	char hex[100];
	//hex = bintohex(valeur);

}
/*
fonction : EcrireNombre
Description : qui permet d'ecrire dans la mémoire mem le nombre valeur codée sur taille octets
retourne :
*/
int EcrireNombre (unsigned char *mem, int taille, int valeur){



}
/*
Fonction :InitMemoire
Description :
retourne :
*/
