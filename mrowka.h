#ifndef MROWKA_H
#define MROWKA_H

class mrowka
{
public:
	mrowka();
	virtual ~mrowka();

	enum EWNS { prawo = 0, lewo = 1, gora = 2, dol = 3 };

	friend class plansza;


	EWNS kierunek;
};

#endif // MROWKA_H
