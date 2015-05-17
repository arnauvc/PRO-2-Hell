/** @file Rellotge.hh
	@brief Classe Rellotge
*/

class Rellotge{

private:	
string hora;
string data;


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
		\post Retorna la data del paràmetre implícit en format string (DD:MM:AA).
	*/
	string consulta_data();


	/** @brief Compara dues dates.
		\pre data1, data2 són dues dates en format string.
		\post Retorna 0 si són iguals, 1 si data1 és anterior a data2, 2 altrament.
	*/
	int compara_dates(string data1, string data2);


	/** @brief Compara dues hores.
		\pre hora1, hora2 són dues hores en format string.
		\post Retorna 0 si són iguals, 1 si hora1 és anterior a hora2, 2 altrament.
	*/
	int compara_hores(string hora1, string hora2);




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
