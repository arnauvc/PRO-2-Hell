// Classe Tasca

#include "Tasca.hh"


Tasca::Tasca() {
	etiquetes = list<string> ();
}



Tasca::~Tasca() {}

bool Tasca::comp(string a, string b) {
	return (a<b);
}

void Tasca::ordena_etiquetes() {
	etiquetes.sort(comp);
}




void Tasca::escriu_tasca() {	
	cout << titol;
	cout << " " << R.consulta_hora();
	cout << " " << R.consulta_data();
	ordena_etiquetes();
	
	list<string>::iterator it = etiquetes.begin();
	while (it!=etiquetes.end()) {
		cout << " " << *it;
		++it;
	}
	
	cout << endl;
}

string Tasca::hora_tasca() {
	return R.consulta_hora();
}

string Tasca::data_tasca() {
	return R.consulta_data();
}


bool Tasca::conte_etiqueta(string e, list<string>::iterator &x) {
	ordena_etiquetes();
	
	list<string>::iterator it = etiquetes.begin();
	while (it!=etiquetes.end()) {
		if (*it==e) {
			x=it;
			return true;
		}
		if (e<*it) {
			x=it;
			return false;
		}
		++it;
	}
	return false;
}


void Tasca::llegeix_tasca(string t, string h, string d) {
	titol = t;
	R.modifica_hora(h);
	R.modifica_data(d);

}

void Tasca::afegeix_etiqueta(string e) {
	list<string>::iterator x = etiquetes.begin();
	
	if (conte_etiqueta(e,x)) cout << "No s'ha realitzat." << endl;
	else {
		etiquetes.insert(x,e);
	}
		
}


void Tasca::modifica_tasca(Comanda c) {
	if (c.te_titol()) titol = c.titol();
	
	if (c.te_hora()) {
		string h = c.hora();
		R.modifica_hora(h);
	}
	
	if (c.nombre_dates()==1) {
		string d = c.data(1);
		R.modifica_data(d);
	}
	
	int n=c.nombre_etiquetes();
	
	list<string>::iterator x;	
	for (int i=1; i<=n; ++i) {
		string e=c.etiqueta(i);		
		if (not conte_etiqueta(e, x)) {
			etiquetes.insert(x, e);
		}
	}
}


void Tasca::esborra_etiqueta(string e) {
	
	list<string>::iterator x = etiquetes.begin();	
	if (not conte_etiqueta(e,x)) cout << "No s'ha realitzat." << endl;
	else etiquetes.erase(x);
}


void Tasca::esborra_etiquetes() {	
	etiquetes.clear();
}

