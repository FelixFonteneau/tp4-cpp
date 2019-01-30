ECHO= @echo
RM= rm
COMP= g++
EDL= g++
CPPFLAGS= -ansi -pedantic -g -Wall -std=c++11 -D MAP
EDLFLAGS=
RMFLAGS= -f
INT= Top.h TestTop.h
REAL= $(INT:.h=.cpp)
OBJ= $(REAL:.cpp=.o)
LIBS=
INCPATH=
LIBPATH=
EFFACE= clean
EXE= analog
DATE= 25.01
AUTHOR= Houda & Felix
YEAR= 2019
EMAIL= houda.ouhssain@insa-lyon.fr felix.fonteneau@insa-lyon.fr

.PHONY: $(EFFACE)

$(EXE) : $(OBJ)
	$(ECHO) "Edition de liens de <$(EXE)>"
	$(EDL) -o $(EXE) $(OBJ) $(LIBS)

%.o : %.cpp %.h
	$(ECHO) "Compilation de <$(<)>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

Top.o : Top.h

TestTop.o : TestTop.h


$(EFFACE) :
	$(ECHO) "Suppression des fichiers"
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core
