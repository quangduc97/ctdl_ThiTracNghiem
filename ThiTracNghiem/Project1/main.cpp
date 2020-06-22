#include "function.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	DSLOP dslop;
	DSMH dsmh;
	DSCH dsch;
	int a[2000];

	Khoitao(dslop, dsmh, dsch, a);
	while (true) {
		RunMenu(dslop, dsmh, dsch, a);
	}

	return 0;
}
