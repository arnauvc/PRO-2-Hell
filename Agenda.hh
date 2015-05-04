/** @file Agenda.hh
	@brief Classe Agenda
*/

class Agenda{

private:	
list<Tasca> Menu;
list<Tasca> Calendari;
Rellotge R;

bool conte_tasca(Tasca t, int Posicio_tasca) // Retorna true si la tasca t és a l’agenda i en cas que no retorna la posició on ha d’anar la nova tasca t

public:
	
 	/* Constructores */
	/** @brief Creadora per defecte.
		\pre cert
		\post El resultat es una agenda nova buida sense inicialitzar el rellotge
*/ 
	Agenda();
	
	/* ********************************************************************************* */
	//Aquesta funcio desapareixera si fem la classe rellotge

	/** @brief Crea agenda amb rellotge inicialitzat a 20.04.15 00:00
		\pre cert
		\post El resultat és una agenda amb rellotge inicialitzat a 20.04.15 i hora 00:00
	*/
	Agenda_ini();

	/* ********************************************************************************** */


	
	/* Destructora */
	/** @brief Destructora per defecte.
		\pre Existeixi un objecte agenda
		\post Destrueix l’agenda
*/
	~Agenda();
	

	/* Consultores */
	/** @brief Consulta data i hora actual de l’agenda.
		\pre Cert
		\post Escriu la data i hora actual de l’agenda
	*/
	void consulta_rellotge();

	
  /** @brief Consulta menu segons característiques passades per parametre explicit
	  \pre cert
	  \post Escriu una llista de totes les tasques que satisfan la consulta
  */
  void consulta(Comanda c);


  /* Modificadores */

	/** @brief Inserta una tasca futura a l’agenda.
		\pre Ha d’existir una agenda
		\post S’insereix una nova tasca al paràmetre implícit, amb les dades passades pel parametre explicit. Si la data de la tasca és anterior a la del rellotge intern, s’escriurà el missatge d’error “No s’ha realitzat.” i no s’inserirà la tasca.
	*/
	void inserta_tasca(Comanda c);

	
	/** @brief Modifica una tasca futura de l’agenda
		\pre Ha d’existir una tasca i aquesta ha de està en el futur
		\post Es modifica la tasca del parametre implicit, segons parametre explicit
	*/
	void modifica_tasca(Comanda c);
	
	/** @ brief Esborra una tasca o una etiqueta d’una tasca
	\pre Ha d’existir la tasca associada al numero de la comanda passada per parametre explicit
	\post S’esborrara la tasca o l’etiqueta de la tasca que ocupa la posició del menu
	*/
	void esborra(Comanda c);
	
	};
	
	/** @brief Modifica l’hora, la data, o ambdues,del rellotge intern.
		\pre El rellotge s’ha d’haver inicialitzat previament
	\post El resultat modifica l’hora, la data, o ambdues,del rellotge intern segons parametre explicit.
	*/
	void modifica_rellotge(Comanda c);
