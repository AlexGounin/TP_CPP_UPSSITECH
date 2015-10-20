/*
 * Entree.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#include "Entree.h"

namespace std {

Entree::Entree(string name, string num) {
	this->nom = name;
	this->num_tel = num;
}

Entree::~Entree() {
}

void Entree::affiche(){
	cout << "nom: " << this->nom << endl;
	cout << "numero de tel: " << this->num_tel << endl;
}

} /* namespace std */
