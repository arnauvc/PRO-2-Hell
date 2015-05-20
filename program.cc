

#include "Agenda.hh"
#include "comanda.hh"


int main(){

    Agenda A;
    Comanda c;
    bool be;
    bool no_sortir;

    no_sortir=c.llegir(be); 	

    while (no_sortir) {
	 if (be) { 		 
   		 if (c.es_insercio()) A.inserta_tasca(c);
			
   		 else if (c.es_rellotge()) {
			 if (c.es_consulta()) A.consulta_rellotge();
			 else A.modifica_rellotge(c);
			 
		 } else if (c.es_esborrat()) A.esborra(c);
			
   		 else if (c.es_consulta()) A.consulta(c);
		 
		 else if (c.es_modificacio()) A.modifica_tasca(c);
		}
	
	no_sortir=c.llegir(be); 
    }
}

