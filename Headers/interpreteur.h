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

typedef struct tabs {
	char * tab_ident; // a tab for { } and () and []
	int  * tab_functions;

}tab;
