#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <windows.h>

#include "plansza.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void start();
	void view(plansza*);
	void drogaMrowki(mrowka *, plansza *, int*, int*);
	void krokKierunek(mrowka *,  std::string, int*, int*);

protected:

private:
	int size_table, x, y, licznik;
	int * ix = &x;
	int * iy = &y;
	int * ilicznik = &licznik;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif // GAME_H
