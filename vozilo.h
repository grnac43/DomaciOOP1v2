#ifndef _vozilo_h_
#define _vozilo_h_
#include "datum.h"
#include <iostream>
#include <string>

class Vozilo {
	std::string model;
	Datum proz;
	double cena_dan;
public:
	Vozilo(std::string i, Datum p, double c): model(i), proz(p), cena_dan(c){}
	Vozilo(const Vozilo&) = delete;
	Vozilo& operator=(const Vozilo&) = delete;
	virtual ~Vozilo(){}
	virtual int getBrPut() const = 0;
	//virtual std::string getVozac() const = 0;
	const Datum getP() const { return proz; }
	virtual double cenaI(const Datum& d, bool vozac) const { return cena_dan; }
protected:
	virtual void pisi(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const Vozilo& v);
};

#endif // !_vozilo_h_
