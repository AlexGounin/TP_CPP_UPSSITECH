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
	void afficher(ostream& out);
	void concat(Agenda const& agd);
	void ajouter(string nom, string num);
	void supprimer(string nom, string num);
	void supprimer(string nom);


	friend ostream& operator<<(ostream& out, Agenda& agd);
	void operator+=(Entree const& ent);//a faire
	Agenda& operator=(Agenda& agd);
	friend Agenda& operator+(Agenda const& agd1, Agenda const& agd2);
	void operator+=(Agenda& agd);
	Entree operator[](string nom);
	void operator-=(string nom);
	friend bool operator==(Agenda const& agd1, Agenda const&agd2);
	friend bool operator/(string nom, Agenda const& agd);//a faire
	void operator()(string c);



private:
#ifdef POINTEUR
	Tableau *mon_tab;
#else
	Tableau mon_tab;
#endif
};

} /* namespace std */
#endif /* AGENDA_H_ */
