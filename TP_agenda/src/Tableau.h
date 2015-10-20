/*
 * Tableau.h
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#ifndef TABLEAU_H_
#define TABLEAU_H_

#include "Entree.h"

namespace std {

class Tableau {
public:
	Tableau(int taille = 20);
	virtual ~Tableau();
	Tableau(Tableau const& tab);

	void afficher();
	void ajouter(string nom, string num);
	void supprimer(string nom, string num);
	void supprimer(string nom);

	int getNbElement();
	int getTaille();

private:
	int taille, nb_element;
	Entree *entree;
};

} /* namespace std */
#endif /* TABLEAU_H_ */
