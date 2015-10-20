/*
 * Entree.h
 *
 *  Created on: 20 oct. 2015
 *      Author: agounin
 */

#ifndef ENTREE_H_
#define ENTREE_H_

#include <string>

namespace std {

class Entree {
public:
	Entree(string name = "", string num = "");
	virtual ~Entree();

	void affiche();
	string getNom();
	string getNum();
	void setNom(string nom);
	void setNum(string num);

private:
	string nom;
	string num_tel;
};

} /* namespace std */
#endif /* ENTREE_H_ */
