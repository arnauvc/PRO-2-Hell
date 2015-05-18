//Classe Agenda , fitxer .cc

#include "Agenda.hh"

Agenda::Agenda() {
	string h = "00:00";
	string d = "20.04.15";
	R.modifica_hora(h);
	R.modifica_data(d);
}

Agenda::~Agenda(){}

void Agenda::consulta_rellotge(){
	cout << R.consulta_data() << " ";
	cout << R.consulta_hora(); 
	cout << endl;

}

void Agenda::consulta(Comanda c){
	Menu.clear();
	Rellotge R;
	R.first = 
	if(c == "?"){ 

		//Impremeix per pantalla totes les tasques *futures i edita el menu
		
		int cont = 1;
		map<Rellotge,Tasca,compara>::const_iterator itC;
		for (map<Rellotge,Tasca,compara>::const_iterator itC = Calendari.lower_bound(R); itC!=Calendari.end(); ++itC){
			Menu.insert(make_pair(cont, itC->second));
			cout << cont << " ";
			Tasca T = itC->second;
			T.escriu_tasca();
			++cont;
		}
	}

	else if (c.es_passat()) {
		int cont = 1;
		for (map<Rellotge,Tasca,compara>::const_iterator itC = Calendari.begin(); itC!=Calendari.lower_bound(R); ++itC){
			//he canviat upper_bound per lower_bound, perquè una tasca amb la data i hora actuals
			//es considera tasca futura
			Menu.insert(make_pair(cont, itC->second));
			cout << cont << " ";
			Tasca T = itC->second;
			T.escriu_tasca();
			//Posar "itC->second" directament dona error a la compilació
			++cont;
		}
		
	}
		
	}
	else if (c.nombre_dates() == 1){
		int cont = 1;
		Rellotge RL,RU;
		RL.modifica_data(c.data(1));
		RL.modifica_hora("00:00");
		RU.modifica_data(c.data());
		RU.modifica_hora("23:59");

		for(map<Rellotge, Tasca>::const_iterator itC = Calendari.lower_bound(RL); itC != Calendari.upper_bound(RU); ++itC){

			Menu.insert(make_pair(cont, itC->second));
			cout << cont << " " << (itC->second).escriu_tasca() << endl;
			++cont;
	}
	else if (c.nombre_dates() == 2){
		int cont = 1;
		Rellotge RL,RU;
		RL.modifica_data(c.data(1));
		RL.modifica_hora("00:00");
		RU.modifica_data(c.data(2));
		RU.modifica_hora("23:59");

		for(map<Rellotge, Tasca>::const_iterator itC = Calendari.lower_bound(RL); itC != Calendari.upper_bound(RU); ++itC){

			Menu.insert(make_pair(cont, itC->second));
			cout << cont << " " << (itC->second).escriu_tasca() << endl;
			++cont;
	}

			
	
}

bool Agenda::conte_tasca(Tasca t) {
	Rellotge clau;
	string h, d;
	h = t.hora_tasca();
	d = t.data_tasca();
	clau.modifica_hora(h);
	clau.modifica_data(d);
	
	return (Calendari.count(clau)!=0);
	
}

void Agenda::inserta_tasca(Comanda c) {
	Tasca T;
	Rellotge clau;
	string t, h, d;
	
	t = c.titol();
	
	if (c.te_hora()) h = c.hora();
	else h = R.consulta_hora();
	
	if (c.nombre_dates()>0) d = c.data(1);
	else d = R.consulta_data();
	
	clau.modifica_hora(h);
	clau.modifica_data(d);
	
	T.llegeix_tasca(t, h, d);
	
	if (conte_tasca(T)) cout << "No s'ha realitzat." << endl;
	else if (R.compara_rellotges(T.rellotge_tasca())==2) cout << "No s'ha realitzat." << endl;
	else {	
		if (c.nombre_etiquetes()>0) {
			int n=c.nombre_etiquetes();
			for (int i=1; i<=n; ++i) {
				string e = c.etiqueta(i);
				T.afegeix_etiqueta(e);
				}
		}
		
		Calendari.insert(make_pair(clau,T));
		
	}
}


	
void Agenda::modifica_tasca(Comanda c) {
	int num = c.tasca();
	if (Menu.count(num)==0) cout << "No s'ha realitzat." << endl;
	else {
		Tasca T = Menu.find(num)->second;		
		string h = T.hora_tasca();
		string d = T.data_tasca();
		Rellotge orig;
		orig.modifica_hora(h);
		orig.modifica_data(d);
		
		if (d<R.consulta_data()) cout << "No s'ha realitzat." << endl;
		else if (d==R.consulta_data() and h<R.consulta_hora()) cout << "No s'ha realitzat." << endl;
		else {			
			if (c.te_hora()) h = c.hora();	
			if (c.nombre_dates()>0) d = c.data(1);
			Rellotge clau;
			clau.modifica_hora(h);
			clau.modifica_data(d);
			
			if (Calendari.count(clau)>0) cout << "No s'ha realitzat." << endl;
			else if (d<R.consulta_data()) cout << "No s'ha realitzat." << endl;
			else if (d==R.consulta_data() and h<R.consulta_hora()) cout << "No s'ha realitzat." << endl;
			else {
				T.modifica_tasca(c);
				
				map<int,Tasca>::iterator itmenu = Menu.find(num);
				itmenu->second = T;
				
				Calendari.erase(orig);
				Calendari.insert(make_pair(clau,T));
			}
		}
	}
}
	

void Agenda::esborra(Comanda c){ 
	if (not Calendari.empty()) {
		//Si el numero no esta al menu ha de donar error
		int num=c.tasca();
		if (Menu.count(num)==0) cout << "No s'ha realitzat." << endl;
		else {
			map<int,Tasca>::iterator itm = Menu.find(num);
			Tasca T = itm->second;
			Rellotge RT;
			RT.modifica_data(T.data_tasca());
			RT.modifica_hora(T.hora_tasca());
			// R.data i R.hora son privades
			
			if (R.compara_rellotges(RT)==2) cout << "No s'ha realitzat." << endl;
			//Si la tasca es pasada, no es pot esborrar
			else {
				map<Rellotge,Tasca,compara>::iterator it1 = Calendari.find(RT);
				//els const_iterator no permeten modificacions
				string com = c.tipus_esborrat();
				
				if (com == "tasca") {
					if (it1!=Calendari.end()) Calendari.erase(it1);
					Menu.erase(itm);
					//tambe hem de modificar el menu
				} else if (com == "etiqueta"){
					if (it1!=Calendari.end()) {
						T.esborra_etiqueta(c.etiqueta(1));
						it1->second = T;
						itm->second = T;
					}
				}
				else if (com == "etiquetes"){
					if (it1!=Calendari.end()) {
						T.esborra_etiquetes();
						it1->second = T;
						itm->second = T;
					}
				}
			}
		}
	}
}

void Agenda::modifica_rellotge(Comanda c){
	/*
	En les comparacions: 
		0 = Iguals
		1 = Primer valor < Segon valor
		2 = Primer valor > Segon valor
	
 
	El cas d = 0 i h = 0, no cal fer res. Implica que les hores son les mateixes
	*/

	int numdates = c.nombre_dates();
	if(numdates == 0){ // No te data
		if(c.te_hora()){ // Pero te hora
				h = compara_hores(consulta_hora(), c.hora())
				if(h == 1) R.modifica_hora(c.hora());
				else if (h == 2) cout << "No s'ha realitzat"
		}
	}
	else if (numdates == 1){ // Te una data
		if (c.te_hora()){ // I te una hora
			int d = compara_dates(R.consulta_data(), c.data(1));
			int h = compara_hores(consulta_hora(), c.hora());
			if( d == 1 and h == 0) {
				modifica_data();
			}
			else if(((d == 1 ) and (h == 1 or h == 2)){
				modifica_data(c.data(1));
				modifica_hora(c.hora());
			}
			else if (d == 2) {
				cout << "No s'ha realitzat" << endl;
			}
		}
		else { // Te data pero no te hora
			int d = compara_dates(R.consulta_data(), c.data(1));
			if (d == 1) modifica_data();
			else if (d == 2) cout << "No s'ha realitzat" <<endl;
		}
	}
}

/* Una implementació mes simple, amb compara_rellotges? : 
void Agenda::modifica_rellotge(Comanda c){
	Rellotge RC;
	
	if (c.nombre_dates()==1) RC.modifica_data(c.data(1));
	else RC.modifica_data(R.consulta_data());
	if (c.te_hora()) RC.modifica_hora(c.hora());
	else RC.modifica_hora(R.consulta_hora());
	
	if (R.compara_rellotges(RC)==2) cout << "No s'ha realitzat." << endl;
	else R=RC;
	
}
*/
