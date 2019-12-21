#include "vozilo.h"

void Vozilo::pisi(std::ostream & os) const
{
	os << model << '-' << getBrPut() << '-' << proz;
}

std::ostream & operator<<(std::ostream & os, const Vozilo & v)
{
	v.pisi(os);
	return os;
}
