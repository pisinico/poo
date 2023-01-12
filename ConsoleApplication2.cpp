#include <iostream>
#include<string>
#pragma warning(disable:4996)

using namespace std;

char* copy(const char* s)
{
	char* a = new char[20];
	if (a == NULL)
		return NULL;

	char* c = a;
	while (*s != '\0')
	{
		*c = *s;
		s++;
		c++;
	}

	*c = '\0';
	return a;
}

class Sistem
{
protected: char regulator[100], traductor[100], element_executie[100];

public: Sistem(char const*, char const*, char const*);
	  ~Sistem();

	  void afisare_sistem();
};

Sistem::Sistem(char const* R, char const* T, char const* EE)
{
	strcpy(regulator, R);
	strcpy(traductor, T);
	strcpy(element_executie, EE);
}

Sistem::~Sistem()
{
	cout << "\n obiect distrus";
}



void Sistem::afisare_sistem()
{
	cout << "\t Sistem";
	cout << "\n Regulator:" << regulator;
	cout << "\n Traductor:" << traductor;
	cout << "\n Element executie:" << element_executie;
}

class Sistem_Reglare : public Sistem
{

protected: char traductor_pH[100], electrod1[100], electrod2[100];

public: Sistem_Reglare(char const*, char const*, char const*, char const*, char const*, char const*);
	  ~Sistem_Reglare();

	  void afisare_Sistem_Reglare();
};

Sistem_Reglare::Sistem_Reglare(char const* R, char const* T, char const* EE, char const* TP, char const* ES, char const* ER) :Sistem(R, T, EE)
{
	strcpy(traductor_pH, TP);
	strcpy(electrod1, ES);
	strcpy(electrod2, ER);
}

Sistem_Reglare::~Sistem_Reglare()
{
	cout << "\n obiect distrus";
}

void Sistem_Reglare::afisare_Sistem_Reglare()
{
	Sistem::afisare_sistem();
	cout << "\n \n \t Sistem Reglare";
	cout << "\n Traductor pH:" << traductor_pH;
	cout << "\n Electrod:" << electrod1;
	cout << "\n Electrod:" << electrod2;
}

class SRA : public Sistem_Reglare
{

protected: char amplificator[100], rezistente[100];

public: SRA(char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*);
	  ~SRA();

	  void afisare_SRA();
};

SRA::SRA(char const* R, char const* T, char const* EE, char const* TP, char const* ES, char const* ER, char const* A, char const* RE) : Sistem_Reglare(R, T, EE, TP, ES, ER)
{
	strcpy(amplificator, A);
	strcpy(rezistente, RE);
}

SRA::~SRA()
{
	cout << "\n obiect distrus";
}

void SRA::afisare_SRA()
{
	Sistem_Reglare::afisare_Sistem_Reglare();
	cout << "\n \n \n \t Sistem Reglare Automata";
	cout << "\n Amplificator:" << amplificator;
	cout << "\n Rezistente:" << rezistente;
}

class SRA_pH : public SRA
{

protected: char convertor[100];

public: SRA_pH(char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*);
	  ~SRA_pH();

	  void afisare_SRA_pH();
};

SRA_pH::SRA_pH(char const* R, char const* T, char const* EE, char const* TP, char const* ES, char const* ER, char const* A, char const* RE, char const* C) : SRA(R, T, EE, TP, ES, ER, A, RE)
{
	strcpy(convertor, C);
}

SRA_pH::~SRA_pH()
{
	cout << "\n obiect distrus";
}

void SRA_pH::afisare_SRA_pH()
{
	SRA::afisare_SRA();
	cout << "\n \n \n \n \t Sistem Reglare Automata al pH-ului";
	cout << "\n Convertor:" << convertor;
}

class SRA_pH_apa_potabila : public SRA_pH
{

protected: char micro_procesor[100];

public: SRA_pH_apa_potabila(char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*);
	  ~SRA_pH_apa_potabila();

	  void afisare_SRA_pH_apa_potabila();
};

SRA_pH_apa_potabila::SRA_pH_apa_potabila(char const* R, char const* T, char const* EE, char const* TP, char const* ES, char const* ER, char const* A, char const* RE, char const* C, char const* MP) : SRA_pH(R, T, EE, TP, ES, ER, A, RE, C)
{
	strcpy(micro_procesor, MP);
}

SRA_pH_apa_potabila::~SRA_pH_apa_potabila()
{
	cout << "\n obiect distrus";
}

void SRA_pH_apa_potabila::afisare_SRA_pH_apa_potabila()
{
	SRA_pH::afisare_SRA_pH();
	cout << "\n \n \n \n \n \t SISTEM DE REGLARE AUTOMATA A PH-ULUI APEI POTABILE";
	cout << "\n Micro-Procesor:" << micro_procesor;
}

class SRA_pH_apa_potabila_PID : public SRA_pH_apa_potabila
{

protected: int kr, ti, td, ph;

public: SRA_pH_apa_potabila_PID(char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, int, int, int, int);
	  ~SRA_pH_apa_potabila_PID();

	  void afisare_SRA_pH_apa_potabila_PID();

	  inline void set_ph(int q)
	  {
		  this->ph = q;
	  }
	  friend int get_ph(SRA_pH_apa_potabila_PID&);

};

SRA_pH_apa_potabila_PID::SRA_pH_apa_potabila_PID(char const* R, char const* T, char const* EE, char const* TP, char const* ES, char const* ER, char const* A, char const* RE, char const* C, char const* MP, int x, int y, int z, int w) : SRA_pH_apa_potabila(R, T, EE, TP, ES, ER, A, RE, C, MP)
{
	kr = x;
	ti = y;
	td = z;
	ph = w;

}

SRA_pH_apa_potabila_PID::~SRA_pH_apa_potabila_PID()
{
	cout << "\n obiect distrus";
}

void SRA_pH_apa_potabila_PID::afisare_SRA_pH_apa_potabila_PID()
{
	SRA_pH_apa_potabila::afisare_SRA_pH_apa_potabila();
	cout << "\n \n \n \n \n \t SISTEM DE REGLARE AUTOMATA A PH-ULUI APEI POTABILE PID";
	cout << "\nKr: " << kr;
	cout << "\nTi: " << ti;
	cout << "\nTd: " << td;
	cout << "\nPH: " << ph;
	cout << "\n____________________________________";
}

int get_ph(SRA_pH_apa_potabila_PID& v)
{
	return v.ph;
}



class SRA_pH_apa_potabila_PID_caracter_bazic : public SRA_pH_apa_potabila_PID
{



public: SRA_pH_apa_potabila_PID_caracter_bazic(char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, int, int, int, int);
	  ~SRA_pH_apa_potabila_PID_caracter_bazic();

	  void afisare_SRA_pH_apa_potabila_PID_caracter_bazic();


};

SRA_pH_apa_potabila_PID_caracter_bazic::SRA_pH_apa_potabila_PID_caracter_bazic(char const* R, char const* T, char const* EE, char const* TP, char const* ES, char const* ER, char const* A, char const* RE, char const* C, char const* MP, int x, int y, int z, int w) : SRA_pH_apa_potabila_PID(R, T, EE, TP, ES, ER, A, RE, C, MP, x, y, z, w)
{

}

SRA_pH_apa_potabila_PID_caracter_bazic::~SRA_pH_apa_potabila_PID_caracter_bazic()
{
	cout << "\n obiect distrus";
}

void SRA_pH_apa_potabila_PID_caracter_bazic::afisare_SRA_pH_apa_potabila_PID_caracter_bazic()
{
	SRA_pH_apa_potabila_PID::afisare_SRA_pH_apa_potabila_PID();
	cout << "\n \n \n \n \n \t SISTEM DE REGLARE AUTOMATA AL PH-ULUI PID CARACTER BAZIC";
	cout << "\nPH: " << ph;
	cout << "\n _________________________________";
}




class SRA_pH_apa_potabila_PID_caracter_acid : public SRA_pH_apa_potabila_PID
{



public: SRA_pH_apa_potabila_PID_caracter_acid(char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, char const*, int, int, int, int);
	  ~SRA_pH_apa_potabila_PID_caracter_acid();

	  void afisare_SRA_pH_apa_potabila_PID_caracter_acid();


};

SRA_pH_apa_potabila_PID_caracter_acid::SRA_pH_apa_potabila_PID_caracter_acid(char const* R, char const* T, char const* EE, char const* TP, char const* ES, char const* ER, char const* A, char const* RE, char const* C, char const* MP, int x, int y, int z, int w) : SRA_pH_apa_potabila_PID(R, T, EE, TP, ES, ER, A, RE, C, MP, x, y, z, w)
{

}

SRA_pH_apa_potabila_PID_caracter_acid::~SRA_pH_apa_potabila_PID_caracter_acid()
{
	cout << "\n obiect distrus";
}

void SRA_pH_apa_potabila_PID_caracter_acid::afisare_SRA_pH_apa_potabila_PID_caracter_acid()
{
	SRA_pH_apa_potabila_PID::afisare_SRA_pH_apa_potabila_PID();
	cout << "\n \n \n \n \n \t SISTEM DE REGLARE AUTOMATA AL PH-ULUI PID CARACTER ACID";
	cout << "\nPH: " << ph;
	cout << "\n ___________________________";
}



int main()
{
	char const* abc = new char[100];
	abc = copy("Pentru reglarea pH-ului");

	char const* abc1 = new char[100];
	abc1 = copy("De sticla");

	char const* abc2 = new char[100];
	abc2 = copy("De referinta");

	char const* abc0 = new char[100];
	abc0 = copy("Automat");

	char const* abcd = new char[100];
	abcd = copy("Greisinger");

	char const* abc6 = new char[100];
	abc6 = copy("De calcul");

	char const* abc5 = new char[100];
	abc5 = copy("A/D");

	char const* abc4 = new char[100];
	abc4 = copy("De intrare");

	char const* abc3 = new char[100];
	abc3 = copy("De mV");

	SRA_pH_apa_potabila_PID_caracter_acid s1(abc, abc, abc0, abcd, abc1, abc2, abc3, abc4, abc5, abc6, 1, 2, 3, 5);
	SRA_pH_apa_potabila_PID_caracter_bazic s2(abc, abc, abc0, abcd, abc1, abc2, abc3, abc4, abc5, abc6, 1, 2, 3, 8);

	int ph1 = get_ph(s1);
	int ph2 = get_ph(s2);




	if (ph1 < 7)
	{
		s1.afisare_SRA_pH_apa_potabila_PID_caracter_acid();
		cout << endl << endl;
	}

	else if (ph1 >= 7)

	{
		cout << "Sistem 1 nu are caracter acid" << endl << endl;


	}
	if (ph2 > 7)
	{
		s2.afisare_SRA_pH_apa_potabila_PID_caracter_bazic();
		cout << endl << endl;
	}

	else if (ph2 <= 7)

	{
		cout << "Sistem 2 nu are caracter bazic" << endl << endl;


	}



}