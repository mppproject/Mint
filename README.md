Mint
====

(Mpp Interpreter) is a small interpreter for MPP that handles syntax errors.

Mint dependencies
====

Mint requires the libmpp package to be installed on your machine. you can get it from here : www.mpp-project.eu/p/download.html

How to use ?
====

You can download the debian package from www.mpp-project.eu , otherwise you can compile it yourself by running the following command :

    $ make
    $ ./mint -h
    
    
Mint doesn't need any header file , so you don't have to add an #include .


Example file
====  

    #bda
    ra9m bda(){
    ktab("test \n");
    }
  
  
