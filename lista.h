#ifndef _lista_h_
#define _lista_h_

#include <iostream>

class G_NemaTek {};
inline std::ostream& operator<<(std::ostream& os, const G_NemaTek&)
{
	return os << "\n*** GRESKA: Ne postoji tekuci element! ***\n";
}

template<typename T>
class Lista {
	struct Elem {
		T pod;
		Elem* next;
		Elem(const T& t, Elem* s = nullptr)
		{
			pod = t;
			next = s;
		}
	};

	Elem* prvi, *posl;
	mutable Elem *tek, *pret;
	int duz;
	/*void kopiraj(const Lista& l)
	{
		prvi = posl = tek = pret = nullptr;
		for (Elem* pok = l.prvi; pok; pok = pok->next)
		{
			Elem* novi = new Elem(pok->pod);
			posl = (!prvi ? prvi : posl->next) = novi;
			if (pok == l.tek) tek = novi;
			if (pok == l.pret) tek = novi;
		}
	}*/
	void premesti(Lista& l)
	{
		prvi = l.prvi;
		posl = l.posl;
		l.prvi = l.posl = nullptr;
	}
	void brisi()
	{
		while (prvi)
		{
			Elem* stari = prvi;
			prvi = prvi->next;
			delete stari;
		}
		pret = tek = posl = nullptr;

	}
public:
	Lista() { prvi = posl = pret = tek = nullptr; duz = 0; }
	Lista(const Lista& l) /*{ kopiraj(l); }*/ = delete;
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }
	
	Lista& operator=(const Lista& l) = delete;
	/*{
		if (this != &l)
		{
			isprazni();
			kopiraj(l);
		}
		return *this;
	}*/
	Lista& operator=(Lista&& l)
	{
		if (this != &l)
		{
			isprazni();
			premesti(l);
		}
		return *this;
	}
	Lista& dodaj(const T& t)
	{
		posl = (!prvi ? prvi : posl->next) = new Elem(t);
		duz += 1;
		return *this;
	}
	int getDuz() const
	{
		return duz;
	}
	Lista& naPrvi()
	{
		tek = prvi;
		pret = nullptr;
		return *this;
	}
	const Lista& naPrvi() const
	{
		tek = prvi;
		pret = nullptr;
		return *this;
	}

	Lista& naSledeci()
	{
		pret = tek;
		if (tek) tek = tek->next;
		return *this;
	}
	const Lista& naSledeci() const
	{
		pret = tek;
		if (tek) tek = tek->next;
		return *this;
	}
	bool imaTek() const { return tek != nullptr; }

	T& getTek() { if (!tek) throw G_NemaTek(); return tek->pod; }
	const T& getTek() const { if (!tek) throw G_NemaTek(); return tek->pod; }

	Lista& izbaciTek()
	{
		if (!tek) throw G_NemaTek();
		Elem* stari = tek;
		tek = tek->next;
		(!pret ? prvi : pret->next) = tek;
		if (!tek) posl = pret;
		delete stari;
		duz -= 1;
		return *this;

	}

	

};




#endif // !_lista_h_
