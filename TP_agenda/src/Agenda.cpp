/*
 * Agenda.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#include "Agenda.h"

namespace std {

Agenda::Agenda(int taille) {
	this->mon_tab = Tableau(taille);
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

	for(int i = 0; i < this->mon_tab.getNbElement(); ++i) {

	}
}
Agenda::~Agenda() {
}

} /* namespace std */
