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
	Tableau();
	virtual ~Tableau();

private:
	int taille, nb_element;
	Entree *entree;
};

} /* namespace std */
#endif /* TABLEAU_H_ */
