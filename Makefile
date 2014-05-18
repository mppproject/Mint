# Generic GNUMakefile
﻿MAKEFILE = gnu
CC = gcc
#debug options
DOPT = -Wall -g
#release options
ROPT = -o3
#opt will get the release/debug config for the compiler
# change to $(DOPT) to produce debugable executable
OPT = $(ROPT)
#release exe name
EXE = mint
#debug exe name
DEXE = mint_d
#add all needed files here! (just C files not header)
SRC = main.c interpreteur.c erreur.c memoire.c
HDR = 
#object files for release version
OBJ = $(SRC:.c=.o)
#object files for debug version
DOBJ = $(SRC:.c=_d.o)

INCPATH = 
# List of the path to use when looking up for libraries
# modify path to match your target architecture ( x86 or x64), so it will link to the good library 
#LIBPATH = -LFreeImage/lib/linux_x86
# list of libraries to be linked
#LIBS =   -lSDL -lGL -lfreeimage -lSDL_mixer

# recipes

# ------------
# release rules

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(ROPT) $(INCPATH) $(LIBPATH)  -o $@ $(OBJ) $(LIBS)

%.o : %.c
	$(CC) $(ROPT) $(INCPATH) $(LIBPATH) $(LIBS) -c $< -o $@


# ------------
# Debug rule

debug: $(DEXE)

$(DEXE): $(DOBJ)
	$(CC) $(DOPT) $(INCPATH) $(LIBPATH)  -o $@ $(DOBJ) $(LIBS)

%_d.o : %.c
	$(CC) $(DOPT) $(INCPATH) $(LIBPATH) $(LIBS) -c $< -o $@

	
# -----------
# clean rule

clean:
	rm $(OBJ) $(DOBJ) 

	
	
	
# memo internal macro
# $@ --> The file name of the target of the rule.
# $^ --> he names of all the prerequisites, with spaces between them.
# $< The name of the first prerequisite.
