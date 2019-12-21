#ifndef _datum_h_
#define _datum_h_

#include <iostream>

class G_DatumPre{};
inline std::ostream& operator<<(std::ostream& os, const G_DatumPre&)
{
	return os << "\n*** GRASKA: Prvi datume je pre drugog! ***\n";
}

class G_DatumInd{};
inline std::ostream& operator<<(std::ostream& os, const G_DatumInd&)
{
	return os << "\n*** GRESKA: Nije validan identifikator! ***\n";
}
class Datum {
	short dan, mes, god;
public:
	Datum(short d = 28, short m = 12, short g = 2019) { dan = d; mes = m;god = g; }

	friend bool operator<(const Datum& d1, const Datum& d2);
	friend long operator-(const Datum& d1, const Datum& d2);

	short& operator[](std::string id);
	const short& operator[](std::string id) const;

	friend std::ostream& operator<<(std::ostream& os, const Datum& d);
};


#endif // !_datum_h_