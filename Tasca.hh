/** @file Tasca.hh
@brief Classe Tasca
*/

class Tasca{
	string titol;
	string data;
	string hora;
	vector<string> etiquetes;
};

public:
	/* Constructores */

	/** @Brief Creadora per defecte.
		\pre cert
		\post El resultat és una tasca buida al paràmetre implícit.

	Tasca();
	*/
	

	/* Destructores */

	/** @Brief Destructora per defecte.
		\pre Existeix una tasca, és el paràmetre implícit.
		\post Destrueix la tasca

	~Tasca();
	*/

	/* Consultores * /
	
	/** @Brief Operació d’escriptura.
		\pre Una tasca no buida.
		\post Escriu la tasca.

	escriu_tasca();
	*/


	/*Modificadores*/

	/** @Brief Afegeix informació.
		\pre Tasca buida al paràmetre implícit. c és una comanda que conté el títol, data, hora i etiquetes de la tasca.
		\post El resultat és una tasca amb títol, data, hora i opcionalment etiquetes.

	llegeix_tasca(Comanda c);
*/

	/** @Brief Modifica l’hora, data, títol, o afegeix etiquetes a la tasca.
		\pre Existeix la tasca al paràmetre implícit, c és una comanda amb 
l’informació a modificar.
\post El resultat és una tasca modificada.

	modifica_tasca(Comanda c);
	*/


	/** @Brief Esborra una etiqueta d’una tasca existent.
		\pre Existeix una tasca al paràmetre implícit, té almenys una etiqueta. El 
paràmetre etiqueta no es buit.
		\post Retorna la tasca sense l’etiqueta. Si hi ha error dona el missatge “No 
s’ha realitzat”.

esborra_etiqueta(string etiqueta);
*/

/** @Brief Esborra totes les etiquetes d’una tasca existent.
	\pre Existeix una tasca al paràmetre implícit, té almenys una etiqueta.
	\post Retorna la tasca sense cap etiqueta.

esborra_etiquetes();
*/


private:

	/** @Brief Ordena les etiquetes de la tasca lexicològicament.
		\pre Tasca amb almenys dues etiquetes.
		\post Retorna la tasca amb les seves etiquetes ordenades cronològicament.

	ordena_etiquetes();
	*/

	
