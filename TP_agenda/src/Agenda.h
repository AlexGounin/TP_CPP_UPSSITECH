/*
 * Agenda.h
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#define POINTEUR

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
#ifdef POINTEUR
	Tableau *mon_tab;
#else
	Tableau mon_tab;
#endif
};

} /* namespace std */
#endif /* AGENDA_H_ */
