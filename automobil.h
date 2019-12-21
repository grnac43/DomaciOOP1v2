#ifndef _automobil_h_
#define _automobil_h_

#include "vozilo.h"

class G_Tip{};
inline std::ostream& operator<<(std::ostream& os, const G_Tip&)
{
	return os << "\n*** GRESKA: Nepostojeci ti! ***\n";
}
enum tip {KUPE,LIMUZINA};
class Automobil : public Vozilo {
	tip t;
	double dnevnica_v;
public:
	Automobil(std::string i, Datum p, double c, tip tt, double d) : Vozilo(i, p, c) { if (t != KUPE && t != LIMUZINA) throw G_Tip(); t = tt; dnevnica_v = d; }

	int getBrPut() const override
	{
		if (t == KUPE) return 2;
		if (t == LIMUZINA) return 5;
	}
	double cenaI(const Datum& d, bool vozac)const override;
protected:
	void pisi(std::ostream& os) const override;
};

#endif // !_automobil_h_
