#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>

#include "mrowka.h"

class plansza
{
public:
	plansza();
	virtual ~plansza();

	void create_table(int);

	friend class Game;

private:

	bool ** tab;

};

#endif // PLANSZA_H
