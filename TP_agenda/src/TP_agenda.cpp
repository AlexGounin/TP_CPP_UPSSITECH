//============================================================================
// Name        : TP_agenda.cpp
// Author      : Alexandre Gounin
// Version     :
// Copyright   : Your copyright notice
// Description : TP Agenda
//============================================================================

#include <iostream>
#include <string>
#include "Entree.h"
#include "Tableau.h"
#include "Agenda.h"

using namespace std;

int main() {
	//TEST sur la classe entree
	cout << endl << "ENTREE" << endl;
	Entree e1("test", "111"), e2("coucou", "123"), e3("autre", "234");

	cout << "affichage des entrees:" << endl;
	e1.affiche(); e2.affiche(); e3.affiche();

	//TEST de la classe Tableau
	cout << endl << "TABLEAU" << endl;
	Tableau tab = Tableau(10);
	try {
		tab.ajouter(e1.getNom(), e1.getNum());
		tab.ajouter(e2.getNom(), e2.getNum());
		tab.ajouter(e3.getNom(), e3.getNum());
		tab.ajouter(e1.getNom(), e2.getNum());
	} catch (string &s) {
		cout << s << endl;
	}

	cout << "afficher le tableau:" << endl;
	tab.afficher();

	Tableau n_tab = tab;
	cout << "constructeur par copi" << endl;
	n_tab.afficher();

	tab.supprimer(e2.getNom(), e2.getNum());
	cout << "apres supression on as:" << endl;
	tab.afficher();

	tab.supprimer(e1.getNom());
	cout << "apres supression 2 on as:" << endl;
	tab.afficher();

	//TEST sur la classe Agenda
#ifdef POINTEUR
	cout << endl << "AGENDA avec pointeur" << endl;
#else
	cout << endl << "AGENDA sans pointeur" << endl;
#endif
	Agenda my_agenda;

	my_agenda.ajouter(e1.getNom(), e1.getNum());
	my_agenda.ajouter(e2.getNom(), e2.getNum());
	my_agenda.ajouter(e3.getNom(), e3.getNum());
	my_agenda.ajouter(e1.getNom(), e2.getNum());

	cout << "afficher l'agenda:" << endl;
	my_agenda.afficher();

	Agenda n_agd = my_agenda;
	cout << "constructeur par copi" << endl;
	n_agd.afficher();

	my_agenda.supprimer(e2.getNom(), e2.getNum());
	cout << "apres supression on as:" << endl;
	my_agenda.afficher();

	my_agenda.supprimer(e1.getNom());
	cout << "apres supression 2 on as:" << endl;
	my_agenda.afficher();

	Agenda agd2(10);
	agd2.ajouter("azerty", "444");
	agd2.ajouter("qsdfgh", "555");
	agd2.ajouter("wxcvbn", "666");
	my_agenda.concat(agd2);
	cout << "concatenation de 2 agenda:" << endl;
	cout << my_agenda << endl;

	cout << "test sur les operateur" << endl;
	cout << my_agenda << endl;

	cout << "test sur operator += ajout:" << endl;
	my_agenda += Entree("acoucou", "1235");
	cout << my_agenda << endl;

	cout << "test sur operateur +:" << endl;
	cout << my_agenda + agd2 << endl;

	cout << "test sur l'operateur d'affectation: " << endl;
	Agenda test = my_agenda;
	cout << test << endl;

	cout << "test sur l'egalité de 2 agenda:" << endl;
	if(test == my_agenda) {
		cout << "les agendas sont egaux" << endl << endl;
	}

	cout << "test operateur += concatanation:" << endl;
	test += my_agenda;
	cout << test << endl;

	cout << "test operateur -= supprimer les nom associer" << endl;
	test -= "azerty";
	cout << test << endl;

	cout << "test sur l'operateur []: recuperation d'une entree:" << endl;
	Entree tmp = test["qsdfgh"];
	tmp.affiche();

	cout << "test sur l'operateur / " << endl;
	if("autre" / my_agenda) {
		cout << "autre est dans mon agenda" << endl;
	}
	if(!("dgftl" / my_agenda)) {
		cout << "dgftl est pas dans mon agenda" << endl;
	}

	cout << endl << "test sur l'operateur ()" << endl;
	my_agenda("a");

	return 0;
}
