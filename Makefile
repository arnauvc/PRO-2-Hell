# MAKEFILE: utilidad para preparar ejecutables en los que intervienen
# varias clases, de forma que con una unica instruccion se compilan o linkan
# los ficheros estrictamente necesarios.
#

all: Agenda.o Rellotge.o Tasca.o comanda.o token.o program.o program.exe
	
Agenda.o: Agenda.cc Agenda.hh
	g++ -c Agenda.cc -D_GLIBCXX_DEBUG
 
Rellotge.o: Rellotge.cc Rellotge.hh
	g++ -c Rellotge.cc -D_GLIBCXX_DEBUG
 
Tasca.o: Tasca.cc Tasca.hh
	g++ -c Tasca.cc -D_GLIBCXX_DEBUG
 
comanda.o: comanda.cc comanda.hh
	g++ -c comanda.cc -D_GLIBCXX_DEBUG
 
token.o: token.cc token.hh
	g++ -c token.cc -D_GLIBCXX_DEBUG
 
program.o: program.cc
	g++ -c program.cc -D_GLIBCXX_DEBUG
 
program.exe: program.o Agenda.o Tasca.o Rellotge.o comanda.o token.o
	g++ -o program.exe program.o Agenda.o Tasca.o Rellotge.o comanda.o token.o
	
practica.tar: 	Agenda.cc Agenda.hh Makefile program.cc Rellotge.cc Rellotge.hh Tasca.cc Tasca.hh
	tar -cvf practica.tar Agenda.cc Agenda.hh Makefile program.cc Rellotge.cc Rellotge.hh Tasca.cc Tasca.hh
clean:
	rm *.o
	rm *.exe