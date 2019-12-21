#include "datum.h"
#include <string>

bool operator<(const Datum & d1, const Datum & d2)
{
	if (d1.god < d2.god) return true;
	if (d1.god > d2.god) return false;
	if (d1.god == d2.god)
	{
		if (d1.mes < d2.mes) return true;
		if (d1.mes > d2.mes) return false;
		if (d1.mes == d2.mes)
			return d1.dan < d2.dan;
	}
	
}

long operator-(const Datum & d1, const Datum & d2)
{
	if (!(d1 < d2)) throw G_DatumPre();

	return d1.dan - d2.dan + (d1.mes - d2.mes) * 30 + (d1.god - d2.god) * 365;
	
}

std::ostream & operator<<(std::ostream & os, const Datum & d)
{
	return os << d.dan << '.' << d.mes << '.' << d.god << '.';
}

short & Datum::operator[](std::string id)
{
	if (id != "dan" && id != "mesec" && id != "godina") throw G_DatumInd();
	if (id == "dan") return dan;
	if (id == "mesec") return mes;
	if (id == "godina") return god;
}

const short & Datum::operator[](std::string id) const
{
	return const_cast<Datum&>(*this)[id];
}
