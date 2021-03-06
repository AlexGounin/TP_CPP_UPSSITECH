/*
 * Tableau.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#include "Tableau.h"

#include <stdlib.h>
#include <iostream>

namespace std {

//constructeur par default
Tableau::Tableau(int taille) {
	this->taille = taille;
	this->nb_element = 0;
	this->entree = new Entree[taille];
}

//constructeur par copy
Tableau::Tableau(Tableau const& tab) {
	this->nb_element = tab.nb_element;
	this->taille = tab.taille;
	this->entree = new Entree[this->taille];
	for(int i = 0; i < this->nb_element; ++i) {
		this->entree[i] = tab.obtenirEntree(i);
	}
}

//Affiche mon tableau en entier
void Tableau::afficher() {
	cout << "taille: " << this->taille << " Nombre element: " << this->nb_element << endl;
	for(int i = 0; i < this->nb_element; ++i) {
		this->entree[i].affiche();
	}
}

void Tableau::afficher(ostream & out) {
	out << "taille: " << this->taille << " Nombre element: " << this->nb_element << endl;
	for(int i = 0; i < this->nb_element; ++i) {
		this->entree[i].affiche(out);
	}
}

//Ajout d'une entree dans notre tableau
void Tableau::ajouter(string nom, string num) {
	if(this->nb_element >= this->taille) {
		throw "Nombre d'élement max atteint";
	}

	this->entree[this->nb_element++] = Entree(nom, num);
}

//Suppression a partir d'un nom et d'un numero de telephone
void Tableau::supprimer(string nom, string num) {
	bool find = false;
	for(int i = 1; i < this->nb_element; ++i) {
		//quand ils sont egaux
		if(this->entree[i-1].getNom().compare(nom) == 0 && this->entree[i-1].getNum().compare(num) == 0) {
			find = true;
		}
		if(find) {
			this->entree[i-1] = this->entree[i];
		}
	}
	this->nb_element--;
}

//Suppression a partir d'un nom
void Tableau::supprimer(string nom) {
	bool find = false, continuer = true;
	while(continuer) {
		find = false;
		for(int i = 1; i <= this->nb_element; ++i) {
			//quand ils sont egaux
			if(this->entree[i-1].getNom().compare(nom) == 0) {
				find = true;
			}
			if(find) {
				this->entree[i-1] = this->entree[i];
			}
		}
		if(find) {
			this->nb_element--;
		}
		continuer = find;
	}
}

//accesseur sur le nombre d'élement
int Tableau::getNbElement() {
	return this->nb_element;
}

//accesseur sur la taille de ce tableau
int Tableau::getTaille() {
	return this->taille;
}

Entree Tableau::obtenirEntree(int indice) const {
	if(indice > this->nb_element || indice < 0) {
		return this->entree[0];
	}
	return this->entree[indice];
}

//destructeur
Tableau::~Tableau() {
	delete this->entree;
}

bool Tableau::operator/(string nom) {
	for(int i = 0; i < this->nb_element; ++i) {
		if(this->entree[i].getNom() == nom) {
			return true;
		}
	}

	return false;
}

} /* namespace std */
