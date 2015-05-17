// Encara falta molta cosa, però era per tenir el fitxer guardat a algun altre lloc per si de cas


//Classe Agenda , fitxer .cc

#include "Agenda.hh"


Agenda::Agenda(){}

Agenda::~Agenda(){}

void Agenda::consulta_rellotge(){
	cout << R.consulta_data(); 
	cout << R.consulta_hora(); 
	cout << endl;

}

void Agenda::consulta(Comanda c){
	map<int, Tasca>::const_iterator itM = Menu.begin();
	map<string, Tasca>::iterator itC = Calendari.begin();
	while(itC != Calendari.end()){
		if(*itC)
		//Continue

		++itC;	
	}
}



void Agenda::inserta_tasca(Comanda c){
	//Recordar la funcio bool conte_tasca()
	list<Tasca>::iterator itC = Calendari.end();
	Tasca t;
	Calendari.instert(it, t.insereix_tasca(c));
	//Continue
}

void Agenda::modifica_tasca(Comanda c){

}

void Agenda::esborra(){
	
}

void Agenda::modificar_rellotge(Comanda c){
	/*
	En les comparacions: 
		0 = Iguals
		1 = Primer valor < Segon valor
		2 = Primer valor > Segon valor
	
 
	El cas d = 0 i h = 0, no cal fer res. Implica que les hores son les mateixes
	*/

	int numdates = c.nombre_dates();
	if(numdates = 0){ // No te data
		if(c.te_hora()){ // Pero te hora
				h = comparar_hores(consulta_hora(), c.hora())
				if(h = 1) R.modificar_hora(c.hora());
				else if (h = 2) cout << "No s'ha realitzat"
		}
	}
	else if (numdates = 1){ // Te una data
		if (c.te_hora()){ // I te una hora
			int d = comparar_dates(R.consulta_data(), c.data(1));
			int h = comparar_hores(consulta_hora(), c.hora());
			if( d = 1 and h = 0) {
				modificar_data();
			}
			else if(((d = 1 ) and (h = 1 or h = 2)){
				modificar_data(c.data(1));
				modificar_hora(c.hora());
			}
			else if (d = 2) {
				cout << "No s'ha realitzat" << endl;
			}
		}
		else { // Te data pero no te hora
			int d = comparar_dates(R.consulta_data(), c.data(1));
			if (d = 1) modificar_data();
			else if (d = 2) cout << "No s'ha realitzat" <<endl;
		}
	}
}
	

