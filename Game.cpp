#include "Game.h"

Game::Game() :
	size_table(0),
	licznik(0),
	x(0),
	y(0)
{
	//ctor
}

Game::~Game()
{
}

void Game::start()
{
	std::cout << "Podaj wielkosc tablicy\n";
	std::cin >> size_table;
	std::cout << "Pozycja mrowki\n";
	std::cout << "Podaj x=";
	std::cin >> *ix;
	std::cout << " Podaj y=";
	std::cin >> * iy;

	system("cls");

	plansza * p = new plansza();
	p->create_table(size_table);

	mrowka * m = new mrowka();

	m->kierunek = mrowka::gora;

	for (;;)
	{
		view(p);
		drogaMrowki(m, p, ix, iy);
		//Sleep(200);
		system("cls");
		*ilicznik += 1;
	}
}

void Game::krokKierunek(mrowka *m, std::string k, int *x, int *y)
{
	if (k == "lewo")
	{
		if (m->kierunek == mrowka::gora) { m->kierunek = mrowka::lewo; if (*x > 0) { *x -= 1; } else { *x = size_table-1; } }
		else if (m->kierunek == mrowka::lewo) { m->kierunek = mrowka::dol; if (*y > 0) { *y -= 1; } else { *y = size_table-1; } }
		else if (m->kierunek == mrowka::dol) { m->kierunek = mrowka::prawo; if (*x < size_table-1) { *x += 1; } else { *x = 0; } }
		else if (m->kierunek == mrowka::prawo) { m->kierunek = mrowka::gora; if (*y < size_table-1) { *y += 1; } else {*y = 0;} }
	}
	else if (k == "prawo")
	{
		if (m->kierunek == mrowka::gora) { m->kierunek = mrowka::prawo; if (*x < size_table-1) { *x += 1; } else { *x = 0; }}
		else if (m->kierunek == mrowka::prawo) { m->kierunek = mrowka::dol; if (*y > 0) { *y -= 1; } else { *y = size_table-1; }}
		else if (m->kierunek == mrowka::dol) { m->kierunek = mrowka::lewo; if (*x > 0) { *x -= 1; } else { *x = size_table-1; }}
		else if (m->kierunek == mrowka::lewo) { m->kierunek = mrowka::gora; if (*y < size_table-1) { *y += 1; } else { *y = 0; } }
	}
}

void Game::drogaMrowki(mrowka *m, plansza *p, int *x, int *y)
{
	if (p->tab[*x][*y] == false)
	{
		p->tab[*x][*y] = true;
		krokKierunek(m,"lewo", x, y);
	}
	else if (p->tab[*x][*y] == true)
	{
		p->tab[*x][*y] = false;
		krokKierunek(m, "prawo", x, y);
	}
}

void Game::view(plansza *p)
{
	std::cout << *ilicznik << std::endl;
	std::cout << *ix << " , " << *iy << std::endl;

	for (int i = 0; i < size_table; i++)
	{
		for (int j = 0; j < size_table; j++)
		{
			if (p->tab[j][i] == false)
			{
				SetConsoleTextAttribute(hOut, 10);
				std::cout << "   ";
			}
			else if (p->tab[j][i] == true)
			{
				SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
				std::cout << "   ";
			}
		}
		std::cout << std::endl;
	}
}
