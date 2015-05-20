
<<<<<<< HEAD

#include "Agenda.hh"
#include "comanda.hh"


=======
/**
 * @mainpage Pràctica PRO2 - Gestor de tasques
 
/** @file program.cc
    @brief Programa principal de <em>Pràctica PRO2 - Gestor de tasques</em>.
*/

#include "Agenda.hh"
#include "comanda.hh"
#include "utils.PRO2"
#include <string>


/** @brief Programa principal.
*/
>>>>>>> origin/master
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

