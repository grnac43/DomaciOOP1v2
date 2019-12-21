#include "automobil.h"

double Automobil::cenaI(const Datum & d, bool vozac) const
{
	double s = Vozilo::cenaI(d, vozac);
	if (d - getP() < 365 * 2) s *= 1.15;
	if (vozac) s += dnevnica_v;

	return s;
}

void Automobil::pisi(std::ostream & os) const
{
	Vozilo::pisi(os);
	os << '-';
	if (t == KUPE) os << "KUPE";
	if (t == LIMUZINA) os << "LIMUZINA";
}
