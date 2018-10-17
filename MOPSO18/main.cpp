#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "MOPSO.h"
using namespace std;
enum Benchmark { ZDT1, ZDT2, ZDT3, ZDT4, ZDT6 };
enum Inercia { DAMP, CONSTRICCION, LINEAL, FUZZY };

int main(void) {
	Benchmark opcion_funcion = ZDT1;
	Inercia opcion_inercia = DAMP;
	MOPSO *mopso;
	mopso = new MOPSO(100, 0.99, 1, 1, 1, 1, 1, 1, 1, 20, 50, 3, opcion_inercia, opcion_funcion);
	return 0;
}