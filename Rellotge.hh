/** @file Rellotge.hh
	@brief Classe Rellotge
*/

#ifndef RELLOTGE_HH
#define RELLOTGE_HH

#include <string>
#include <iostream>
using namespace std;


/** @class Rellotge
    @brief Representa un rellotge, té una <em>hora</em> i <em>data</em> en format string que poden ser consultades
    i modificades.
    */

class Rellotge{

private:	
	string hora; /* Hora en format HH:MM. */
	string data; /* Data en format DD.MM.AA. */


public:
	
 	/* Constructores */
	/** @brief Creadora per defecte.
		\pre cert
		\post El resultat és un rellotge nou, buit.
*/ 
	Rellotge();

	
	/* Destructores */
	/** @brief Destructora per defecte.
		\pre Existeix rellotge.
		\post Destrueix el rellotge.
	*/
	~Rellotge();


	/* Consultores */
	/** @brief Consulta l’hora actual d’un rellotge.
		\pre Cert
		\post Retorna l’hora del paràmetre implícit en format string (HH:MM).
	*/
	string consulta_hora();


	/** @brief Consulta la data actual d’un rellotge.
		\pre Cert
		\post Retorna la data del paràmetre implícit en format string (DD.MM.AA).
	*/
	string consulta_data();


	/** @brief Compara dues dates.
		\pre <em>data1, data2</em> són dues dates en format string.
		\post Retorna 0 si són iguals, 1 si <em>data1</em> és anterior a <em>data2</em>, 2 altrament.
	*/
	int compara_dates(string data1, string data2);


	/** @brief Compara dues hores.
		\pre <em>hora1, hora2</em> són dues hores en format string.
		\post Retorna 0 si són iguals, 1 si <em>hora1</em> és anterior a <em>hora2</em>, 2 altrament.
	*/
	int compara_hores(string hora1, string hora2);
	
	
	/** @brief Compara dos rellotges.
		\pre El paràmetre implícit i l'explícit son dos rellotges.
		\post Retorna 0 si són iguals, 1 si el paràmetre implícit és anterior a 
		<em>R2</em>, 2 altrament.
	*/
	int compara_rellotges(Rellotge R2);


	/* Modificadores */
	/** @brief Modifica l’hora del rellotge.
		\pre Cert
		\post Modifica l’hora del paràmetre implícit segons parametre explicit.
	*/
	void modifica_hora(string h);

	/** @brief Modifica la data del rellotge.
		\pre Cert
		\post Modifica la data del paràmetre implícit segons parametre explicit.
	*/
	void modifica_data(string d);
};

#endif

	



	


