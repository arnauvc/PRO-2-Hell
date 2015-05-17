/** @file Tasca.hh
@brief Classe Tasca
*/

#ifndef TASCA_HH
#define TASCA_HH

#include "Rellotge.hh"
#include "comanda.hh"
#include <list>
#include <string>
#include <vector>
using namespace std;

/** @class Tasca
    @brief Representa una <em>Tasca</em>, que consisteix en un títol, una data i hora (guardades a 
    un <em>Rellotge</em>), i una llista d'etiquetes (pot ser buida).
    */

class Tasca{	

private:
	
	string titol;
	Rellotge R;
	list<string> etiquetes;
	

	/** @Brief Funció per utilitzar sort i ordenar les etiquetes lexicològicament.
		\pre Dos strings.
		\post Retorna cert si a és major que b, fals altrament.
		
	*/
	static bool comp(string a, string b);
	
	
	/** @Brief Ordena les etiquetes de la Tasca lexicològicament.
		\pre Tasca amb almenys dues etiquetes al paràmetre implícit.
		\post Modifica el paràmetre implícit amb les seves etiquetes ordenades lexicològicament.
		
	*/
	void ordena_etiquetes();
	
	
	
public:
	/* Constructores */

	/** @Brief Creadora per defecte.
		\pre cert
		\post El resultat és una Tasca buida al paràmetre implícit.
	*/
	Tasca();
	
	

	/* Destructores */

	/** @Brief Destructora per defecte.
		\pre Existeix una Tasca, és el paràmetre implícit.
		\post Destrueix la Tasca.
	*/
	~Tasca();
	

	/* Consultores */
	
	/** @Brief Operació d’escriptura.
		\pre Una Tasca no buida al paràmetre implícit.
		\post Escriu la Tasca.
	*/
	void escriu_tasca();
	
	/** @Brief Consulta l'hora de la Tasca, si en té.
		\pre Una Tasca no buida al paràmetre implícit.
		\post Retorna l'hora en format string.
	*/
	string hora_tasca();
	
	/** @Brief Consulta la data de la Tasca, si en té.
		\pre Una Tasca no buida al paràmetre implícit.
		\post Retorna la data en format string.
	*/
	string data_tasca();
	
	
	/** @Brief Consulta si el paràmetre implícit conté certa etiqueta.
		\pre Una Tasca no buida al paràmetre implícit.
		\post Si conté <em>e</em> retorna cert i <em>x</em> és un iterator a la posició de
		l'etiqueta, altrament retorna fals i <em>x</em> és un iterator a l'element posterior de la posició
		on hauria de ser inserida la nova etiqueta. 
	*/
	bool conte_etiqueta(string e, list<string>::iterator &x);


	/*Modificadores*/

	/** @Brief Afegeix informació.
		\pre Tasca buida al paràmetre implícit. 
		\post El resultat és una Tasca amb titol, hora i data al paràmetre implícit.
	*/
	void llegeix_tasca(string t, string hora, string data);
	
	
	/** @Brief Afegeix una etiqueta.
		\pre Tasca al paràmetre implícit. 
		\post El resultat és una Tasca amb l'etiqueta <em>e</em> al paràmetre implícit.
	*/
	void afegeix_etiqueta(string e);

	/** @Brief Modifica l’hora, data, títol, o afegeix etiquetes a la Tasca.
		\pre Existeix la Tasca al paràmetre implícit, <em>c</em> és una Comanda amb 
			l’informació a modificar.
		\post La Tasca del paràmetre implícit ha sigut modificada segons <em>c</em>.
	*/
	void modifica_tasca(Comanda c);
	

	/** @Brief Esborra una etiqueta d’una Tasca existent.
		\pre Existeix una Tasca al paràmetre implícit. El paràmetre <em>etiqueta</em> no es buit.
		\post El paràmetre implícit no té l'etiqueta <em>etiqueta</em>. Si hi ha error escriu el missatge d'error “No 
			s’ha realitzat”.
	*/
	void esborra_etiqueta(string e);


	/** @Brief Esborra totes les etiquetes d’una Tasca existent.
		\pre Existeix una Tasca al paràmetre implícit, té almenys una etiqueta.
		\post El paràmetre implícit no té cap etiqueta.
	*/
	void esborra_etiquetes();
};

#endif
