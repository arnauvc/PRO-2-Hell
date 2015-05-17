// Classe Rellotge

#include "Rellotge.hh"
#include <string>

Rellotge::Rellotge() {

}

Rellotge::~Rellotge() {}

string Rellotge::consulta_hora() {
	return hora;
}

string Rellotge::consulta_data() {
	return data;
}

int Rellotge::compara_dates(string data1, string data2) {
	if (data1==data2) return 0;
	else {
		int a1, a2;
		a1=(data1[6]*10)+data1[7];
		a2=(data2[6]*10)+data2[7];
		if (a1>a2) return 2;
		if (a2>a1) return 1;
		else {
			int m1, m2;
			m1=(data1[3]*10)+data1[4];
			m2=(data2[3]*10)+data2[4];
			if (m1>m2) return 2;
			if (m2>m1) return 1;
			else {
				int d1, d2;
				d1=(data1[0]*10)+data1[1];
				d2=(data2[0]*10)+data2[1];
				if (d1>d2) return 2;
				else return 1;
			}
		}
	}
}



int Rellotge::compara_hores(string hora1, string hora2) {
	if (hora1==hora2) return 0;
	else {
		int h1, h2;
		h1=(hora1[0]*10)+hora1[1];
		h2=(hora2[0]*10)+hora2[1];
		if (h1>h2) return 2;
		if (h2>h1) return 1;
		else {
			int m1, m2;
			m1=(hora1[3]*10)+hora1[4];
			m2=(hora2[3]*10)+hora2[4];
			if (m1>m2) return 2;
			else return 1;
			
		}
	}
}



void Rellotge::modifica_hora(string h) {
	hora=h;
}

void Rellotge::modifica_data(string d) {
	data=d;
}
