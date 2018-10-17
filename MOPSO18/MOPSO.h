#pragma once
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
#include "Repositorio.h"
#include "Swarm.h"
#include "Funcion.h"
using namespace std;

class MOPSO
{
public:
	MOPSO();
	MOPSO(int iter_max,float w_damp, float w, float mu, float alfa, float beta, float gamma,float c1, float c2, int nrep, int num_particulas, int num_grid, int opcion_inercia, int opcion_funcion);
	~MOPSO();

private:
	int iter_max;
	float w_damp;
	float w;
	float mu;
	float alfa;
	float beta;
	float gamma;
	float c1;
	float c2;
	int nrep;
	int num_particulas;
	int num_grid;
	int opcion_funcion;
	int opcion_inercia;
	Swarm *swarm;
	Repositorio *repositorio;
	Funcion *funcion;
};

