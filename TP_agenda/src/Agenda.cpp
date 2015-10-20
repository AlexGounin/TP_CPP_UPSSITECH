/*
 * Agenda.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#include "Agenda.h"
#include "Entree.h"
#include <iostream>

namespace std {

Agenda::Agenda(int taille): mon_tab(taille) {

}

Agenda::Agenda(Agenda const& agd) {
	this->mon_tab = agd.mon_tab;
}

void Agenda::afficher() {
	this->mon_tab.afficher();
}

void Agenda::ajouter(string nom, string num) {
	this->mon_tab.ajouter(nom, num);
}

void Agenda::supprimer(string nom, string num) {
	this->mon_tab.supprimer(nom, num);
}

void Agenda::supprimer(string nom) {
	this->mon_tab.supprimer(nom);
}

void Agenda::concat(Agenda agd) {
	int taille = this->mon_tab.getTaille() + agd.mon_tab.getTaille();
	Tableau nouveau = Tableau(taille);
	Entree tmp;
	for(int i = 0; i < this->mon_tab.getNbElement(); ++i) {
		tmp = this->mon_tab.obtenirEntree(i);
		nouveau.ajouter(tmp.getNom(), tmp.getNum());
	}
}
Agenda::~Agenda() {
}

} /* namespace std */
