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
	string dataR, data1, data2;
	dataR = R.consulta_data();
	map<Rellotge,Tasca,compara>::iterator itc1, itc2;
	itc1=Calendari.begin();
	itc2=itc1;
	
		
		if (c.es_passat()) { 			
			itc2 = Calendari.lower_bound(R);
			
		} else if (c.nombre_dates()==0) {	
			itc1=Calendari.lower_bound(R);
			itc2=Calendari.end();
			
		} else if (c.nombre_dates()==1) {	
			data1=c.data(1);
			if (R.compara_dates(dataR,data1)!=2) {
				Rellotge RC;
				RC.modifica_data(data1);
				RC.modifica_hora("00:00");
				itc1=Calendari.lower_bound(RC);
				RC.modifica_hora("23:59");
				itc2=Calendari.upper_bound(RC);
			}
			
		} else if (c.nombre_dates()==2) {	
			data1=c.data(1);
			data2=c.data(2);
			if (R.compara_dates(data1,data2)!=2) {
				if (R.compara_dates(dataR,data2)!=2) {
					Rellotge RC;
					RC.modifica_data(data1);
					RC.modifica_hora("00:00");
					if (R.compara_dates(dataR,data1)==2) RC=R;
					itc1=Calendari.lower_bound(RC);
					RC.modifica_data(data2);
					RC.modifica_hora("23:59");
					itc2=Calendari.upper_bound(RC);
				}
			}
		}
		
						
		int cont=1;
		for (itc1; itc1!=itc2; ++itc1) {
			Tasca T = itc1->second;			
			if (correcte(T,c)) {			
			Menu.insert(make_pair(cont, itc1->second));
			cout << cont << " ";
			T.escriu_tasca();
			++cont;
			}
		}
}		

bool Agenda::correcte(Tasca t, Comanda c) {
	string exp;
	if (c.nombre_etiquetes()==1) exp = c.etiqueta(1);
	else if (c.te_expressio()) exp = c.expressio();	
	else return true;
	int i=0;
	return (t.compleix_expressio(exp,i));
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
	
	if (conte_tasca(T)) cout << "No s'ha realitzat" << endl;
	else if (R.compara_rellotges(T.rellotge_tasca())==2) cout << "No s'ha realitzat" << endl;
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
	if (Menu.count(num)==0) cout << "No s'ha realitzat" << endl;
	else {
		bool ok=true;
		Tasca T = Menu.find(num)->second;		
		string h = T.hora_tasca();
		string d = T.data_tasca();
		Rellotge orig;
		Rellotge clau;
		orig.modifica_hora(h);
		orig.modifica_data(d);
		clau=orig;
		
		if (R.compara_rellotges(orig)==2) cout << "No s'ha realitzat" << endl;
		else {		
			for (int i=1; i<=c.nombre_etiquetes(); ++i) {
				string e = c.etiqueta(i);
				T.afegeix_etiqueta(e);
			}
			
			if (c.te_hora() or c.nombre_dates()>0) {
				if (c.te_hora()) h = c.hora();	
				if (c.nombre_dates()>0) d = c.data(1);				
				clau.modifica_hora(h);
				clau.modifica_data(d);
			
				if (Calendari.count(clau)>0) {
					cout << "No s'ha realitzat" << endl;
					ok=false;
				} else if (R.compara_rellotges(clau)==2) {
					cout << "No s'ha realitzat" << endl;
					ok=false;
				}
				
			}
			
		if (ok) {
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
		if (Menu.count(num)==0) cout << "No s'ha realitzat" << endl;
		else {
			map<int,Tasca>::iterator itm = Menu.find(num);
			Tasca T = itm->second;
			Rellotge RT;
			RT.modifica_data(T.data_tasca());
			RT.modifica_hora(T.hora_tasca());
			// R.data i R.hora son privades
			
			if (R.compara_rellotges(RT)==2) cout << "No s'ha realitzat" << endl;
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
	Rellotge RC;
	
	if (c.nombre_dates()==1) RC.modifica_data(c.data(1));
	else RC.modifica_data(R.consulta_data());
	if (c.te_hora()) RC.modifica_hora(c.hora());
	else RC.modifica_hora(R.consulta_hora());
	
	if (R.compara_rellotges(RC)==2) cout << "No s'ha realitzat" << endl;
	else R=RC;
	
}
