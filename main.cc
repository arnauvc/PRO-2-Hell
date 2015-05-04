#include "Agenda.hh"
#include "Tasca.hh"
#include "comanda.hh"
#include “Rellotge.hh”

int main(){

    Agenda A;
    Comanda c;
    bool be;
    bool no_sortir;

    cout << “Escriu una comanda:” << endl;
    no_sortir=c.llegir(be); 	// c.llegir retorna true si la comanda no és “sortir”

    while (no_sortir) {
	 if (be) { 	// si la comanda és errònia, c.llegir ja escriu el missatge d’error
   		 if (c.es_insercio()) {
			A.inserta_tasca(c);
   		 }
   		 else if (c.es_consulta()){
			if (c.es_rellotge()) A.consulta_rellotge();
			else A.consulta(c);
   		 }
   		 else if (c.es_modificacio()){
			if (c.es_rellotge()) A.modifica_rellotge(c);
			else A.modifica_tasca(c);
   		 }
  		 else if (c.es_esborrat()){
			A.esborra(c);
   		 }
}

	no_sortir=c.llegir(be);
    }
}
