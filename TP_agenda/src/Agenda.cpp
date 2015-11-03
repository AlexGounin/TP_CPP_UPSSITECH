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

void Agenda::afficher(ostream& out) {
#ifdef POINTEUR
	this->mon_tab->afficher(out);
#else
	this->mon_tab.afficher(out);
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

void Agenda::concat(Agenda const& agd) {
#ifdef POINTEUR
	int taille = this->mon_tab->getTaille() + agd.mon_tab->getTaille();
	Tableau *nouveau = new Tableau(taille);
	Entree tmp;
	for(int i = 0; i < this->mon_tab->getNbElement(); ++i) {
		tmp = this->mon_tab->obtenirEntree(i);
		nouveau->ajouter(tmp.getNom(), tmp.getNum());
	}
	for(int i = 0; i < agd.mon_tab->getNbElement(); ++i) {
		tmp = agd.mon_tab->obtenirEntree(i);
		nouveau->ajouter(tmp.getNom(), tmp.getNum());
	}

	this->mon_tab = new Tableau(*(nouveau));;
#else
	int taille = this->mon_tab.getTaille() + agd.mon_tab.getTaille();
	Tableau nouveau = Tableau(taille);
	Entree tmp;
	for(int i = 0; i < this->mon_tab.getNbElement(); ++i) {
		tmp = this->mon_tab.obtenirEntree(i);
		nouveau.ajouter(tmp.getNom(), tmp.getNum());
	}
	for(int i = 0; i < agd.mon_tab.getNbElement(); ++i) {
		tmp = agd.mon_tab.obtenirEntree(i);
		nouveau->ajouter(tmp.getNom(), tmp.getNum());
	}
	this.mon_tab = nouveau;
#endif
}

Agenda::~Agenda() {
#ifdef POINTEUR
	delete this->mon_tab;
#endif
}

ostream& operator<<(ostream& out, Agenda& agd) {
	agd.afficher(out);
	return out;
}


void Agenda::operator+=(Entree const& ent) {
	this->ajouter(ent.getNom(), ent.getNum());
}

Agenda& Agenda::operator=(Agenda& agd) {
	if(this != &agd) {

#ifdef POINTEUR
	delete(this->mon_tab);
	this->mon_tab = new Tableau(*(agd.mon_tab));
#else
	this->mon_tab = Tableau(agd.mon_tab);
#endif

	}
	return *this;
}

Agenda& operator+(Agenda const& agd1, Agenda const& agd2) {
	Agenda *ag = new Agenda(agd1);
	ag->concat(agd2);

	return *ag;
}

void Agenda::operator+=(Agenda& agd) {
	this->concat(agd);
}

Entree Agenda::operator[](string nom) {
	Entree tmp;
	for(int i = 1; i < this->mon_tab->getNbElement(); ++i) {
		tmp = this->mon_tab->obtenirEntree(i);
		if(tmp.getNom() == nom) {
			return tmp;
		}
	}
	return tmp;
}

void Agenda::operator-=(string nom) {
	this->supprimer(nom);
}

bool operator==(Agenda const& agd1, Agenda const&agd2) {
#ifdef POINTEUR
	if(agd1.mon_tab->getTaille() != agd2.mon_tab->getTaille()) {
		return false;
	}
	if(agd1.mon_tab->getNbElement() != agd2.mon_tab->getNbElement()) {
		return false;
	}

	Entree e, e1;
	for(int i = 0; i < agd1.mon_tab->getNbElement(); ++i) {
		e = agd1.mon_tab->obtenirEntree(i);
		e1 = agd2.mon_tab->obtenirEntree(i);
		if(e.getNom() != e1.getNom() || e.getNum() != e1.getNum()) {
			return false;
		}
	}
	return true;
#else
	if(agd1.mon_tab.getTaille() != agd2.mon_tab.getTaille()) {
			return false;
		}
		if(agd1.mon_tab.getNbElement() != agd2.mon_tab.getNbElement()) {
			return false;
		}

		Entree e, e1;
		for(int i = 0; i < agd1.mon_tab.getNbElement(); ++i) {
			e = agd1.mon_tab.obtenirEntree(i);
			e1 = agd2.mon_tab.obtenirEntree(i);
			if(e.getNom() != e1.getNom() || e.getNum() != e1.getNum()) {
				return false;
			}
		}
		return true;
#endif
}

bool operator/(string nom, Agenda const& agd) {
#ifdef POINTEUR
	return *(agd.mon_tab) / nom;
#else
	return agd.mon_tab / nom;
#endif
}

void Agenda::operator ()(string c) {
#ifdef POINTEUR
	Entree tmp;
	for(int i = 0; i < this->mon_tab->getNbElement(); ++i) {
		tmp = this->mon_tab->obtenirEntree(i);
		if(c.at(0) == tmp.getNom().at(0)) {
			cout << tmp.getNom() << "  " << tmp.getNum() << endl;
		}
	}
#else
	Entree tmp;
	for(int i = 0; i < this->mon_tab.getNbElement(); ++i) {
		tmp = this->mon_tab.obtenirEntree(i);
		if(c == tmp.getNom()[0]) {
			cout << tmp.getNom() << "  " << tmp.getNum() << endl;
		}
	}
#endif
}

} /* namespace std */
