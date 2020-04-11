#include "g2use.h"

void aboutA()
{
	setlocale(LC_ALL, "Ukrainian");
	std::cout << "\nЄрiс Євген\nгрупа К-15\n\nВарiант 16\nВизначити, чи є чотирикутник дельтоїдом\n";
}

int main() {
	std::string pin, pout;
	std::ifstream fi;
	std::ofstream fo;
	aboutA();
	do {
		pin = getPath();
		if (pin.empty())
			pin = "in.txt";
		fi.open(pin);
	} while (fi.fail());
	do {
		pout = getPath();
		if (pout.empty())
			pout = "out.txt";
		fo.open(pout);
	} while (fo.fail());

	processData(fi, fo);

	std::cout << "\nInput data: " << pin << "\n\nOutput data: " << pout << "\n";
	fi.close();
	fo.close();
	return 0;
}