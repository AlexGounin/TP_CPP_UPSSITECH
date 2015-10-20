/*
 * Agenda.h
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include "Tableau.h"

namespace std {

class Agenda {
public:
	Agenda(int taille = 20);
	virtual ~Agenda();
	Agenda(Agenda const& agd);

	void afficher();
	void concat(Agenda agd);
	void ajouter(string nom, string num);
	void supprimer(string nom, string num);
	void supprimer(string nom);

private:
	Tableau mon_tab;
};

} /* namespace std */
#endif /* AGENDA_H_ */
