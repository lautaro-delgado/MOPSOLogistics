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
#include "Particula.h"
using namespace std;

class MOPSO;
class Swarm
{
public:
	Swarm();
	virtual ~Swarm();
	void addParticula(vector<float> posicion);
	void setLider(int id);
	Particula getParticula(int id);
	vector<Particula> getSwarm();
	void calcularVelocidad(int opcion, float w, float c1, float c2, int numVariables);
	void setMaxVar(vector<float> maxvar);
	void setMinVar(vector<float> minvar);
	void setMaxVel(vector<float> maxvel);
	void setMinVel(vector<float> minvel);

private:
	vector<Particula> Particulas;
	Particula Lider;
	int id_max;
	vector<float> Min_var;
	vector<float> Max_var;
	vector<float> Min_vel;
	vector<float> Max_vel;
};
