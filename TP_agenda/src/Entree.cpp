/*
 * Entree.cpp
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#include "Entree.h"
#include <iostream>

namespace std {

Entree::Entree(string name, string num) {
	this->nom = name;
	this->num_tel = num;
}

Entree::Entree(Entree const& ent) {
	this->nom = ent.nom;
	this->num_tel = ent.num_tel;
}

Entree::~Entree() {
}

void Entree::affiche(){
	cout << this->nom << "\t" << this->num_tel << endl;
}

void Entree::affiche(ostream& out) {
	out << this->nom << "\t" << this->num_tel << endl;
}

string Entree::getNom() const{
	return this->nom;
}

string Entree::getNum() const{
	return this->num_tel;
}

void Entree::setNom(string nom) {
	this->nom = nom;
}

void Entree::setNum(string num) {
	this->num_tel = num;
}

} /* namespace std */
