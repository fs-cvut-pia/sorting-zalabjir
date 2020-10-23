#include "trideni.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void nacti(std::string nazev, seznam_slov & jmena){
	ifstream vstupniSoubor;
	vstupniSoubor.open(nazev.c_str());
	
	string radek;
	
	while(getline(vstupniSoubor, radek)){
		jmena.push_back(radek);
	}
	
	vstupniSoubor.close();
}

void serad(seznam_slov & jmena){
	string tmp;
	bool switched;
	
	do {
		switched = false;
		for (int i = 1; i < jmena.size(); i++){
			if (jmena[i].compare(jmena[i-1]) < 0){
				tmp = jmena [i];
				jmena [i] = jmena [i-1];
				jmena [i-1] = tmp;
				switched = true;
			}
		}
	} while (switched);
}

bool zeptej_se_jestli_vypsat(){
	char vypsat;
	while (true){
		cout << "Chcete vypsat serazena jmena na obrazovku? (A/N)" << endl;
		cin >> vypsat;
		if (vypsat == 'A' || vypsat == 'a') return true;
		else if (vypsat == 'N' || vypsat == 'n') return false;
		else cout << "Nerozumim. ";
	}
}

void vypis(seznam_slov const& jmena){
	for (int i = 0; i < jmena.size(); i++){
		cout << jmena[i] << '\n';
	}
}
