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

#ifdef POINTEUR
Agenda::Agenda(int taille) {
	this->mon_tab = new Tableau(taille);
}
#else
Agenda::Agenda(int taille): mon_tab(taille) {

}
#endif

Agenda::Agenda(Agenda const& agd) {
#ifdef POINTEUR
	this->mon_tab = new Tableau(*(agd.mon_tab));
#else
	this->mon_tab = agd.mon_tab;
#endif
}

void Agenda::afficher() {
#ifdef POINTEUR
	this->mon_tab->afficher();
#else
	this->mon_tab.afficher();
#endif
}

void Agenda::ajouter(string nom, string num) {
#ifdef POINTEUR
	this->mon_tab->ajouter(nom, num);
#else
	this->mon_tab.ajouter(nom, num);
#endif
}

void Agenda::supprimer(string nom, string num) {
#ifdef POINTEUR
	this->mon_tab->supprimer(nom, num);
#else
	this->mon_tab.supprimer(nom, num);
#endif
}

void Agenda::supprimer(string nom) {
#ifdef POINTEUR
	this->mon_tab->supprimer(nom);
#else
	this->mon_tab.supprimer(nom);
#endif
}

void Agenda::concat(Agenda agd) {
#ifdef POINTEUR
	int taille = this->mon_tab->getTaille() + agd.mon_tab->getTaille();
	Tableau nouveau = Tableau(taille);
	Entree tmp;
	for(int i = 0; i < this->mon_tab->getNbElement(); ++i) {
		tmp = this->mon_tab->obtenirEntree(i);
		nouveau.ajouter(tmp.getNom(), tmp.getNum());
	}
#else
	int taille = this->mon_tab.getTaille() + agd.mon_tab.getTaille();
	Tableau nouveau = Tableau(taille);
	Entree tmp;
	for(int i = 0; i < this->mon_tab.getNbElement(); ++i) {
		tmp = this->mon_tab.obtenirEntree(i);
		nouveau.ajouter(tmp.getNom(), tmp.getNum());
	}
#endif
}
Agenda::~Agenda() {
#ifdef POINTEUR
	delete this->mon_tab;
#endif
}

} /* namespace std */
