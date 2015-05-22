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
	cout << " " << R.consulta_data();
	cout << " " << R.consulta_hora();
	ordena_etiquetes();
	
	list<string>::iterator it = etiquetes.begin();
	while (it!=etiquetes.end()) {
		cout << " " << *it;
		++it;
	}
	
	cout << endl;
}

string Tasca::titol_tasca() {
	return titol;
}

string Tasca::hora_tasca() {
	return R.consulta_hora();
}

string Tasca::data_tasca() {
	return R.consulta_data();
}

Rellotge Tasca::rellotge_tasca() {
	return R;
}


bool Tasca::conte_etiqueta_simple(string e) {
	ordena_etiquetes();
	list<string>::iterator it = etiquetes.begin();
	while (it!=etiquetes.end()) {
		if (*it==e) return true;
		else if (e<*it) return false;
		++it;
	}
	return false;
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
	x=etiquetes.end();
	return false;
}


void Tasca::llegeix_tasca(string t, string h, string d) {
	titol = t;
	R.modifica_hora(h);
	R.modifica_data(d);

}

void Tasca::afegeix_etiqueta(string e) {
	list<string>::iterator x = etiquetes.begin();
	
	if (not conte_etiqueta(e,x)) etiquetes.insert(x,e);
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


bool Tasca::compleix_expressio(const string &exp, int &i) {
	if (exp[i]=='#') {		
		string e;
		while (exp[i]!='.' and exp[i]!=',' and exp[i]!=')' and i<exp.size()) {
			e.push_back(exp[i]);
			++i;
		}
		return (conte_etiqueta_simple(e));
	} else {
		++i; 
		bool r1 = compleix_expressio(exp,i);
		char c = exp[i]; 
		++i; 
		bool r2 = compleix_expressio(exp,i);
		++i;
		if (c=='.') {
			return (r1 and r2);
		} else {
			return (r1 or r2);
		}
	}
}


	

void Tasca::esborra_etiqueta(string e) {
	
	list<string>::iterator x = etiquetes.begin();	
	if (not conte_etiqueta(e,x)) cout << "No s'ha realitzat" << endl;
	else etiquetes.erase(x);
}


void Tasca::esborra_etiquetes() {
	if (etiquetes.size()==0) cout << "No s'ha realitzat" << endl;
	else etiquetes.clear();
}