#include "plansza.h"

plansza::plansza()
{
	//ctor
}


plansza::~plansza()
{

}

void plansza::create_table(int s)
{
	tab = new bool *[s];

	for (int i = 0; i < s; i++)
	{
		tab[i] = new bool[s];
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			tab[i][j] = false;
		}
	}
}


