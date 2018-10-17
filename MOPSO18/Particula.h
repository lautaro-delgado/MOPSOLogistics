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
using namespace std;
class Swarm;
class Particula
{
public:
	Particula();
	Particula(int id);
	virtual ~Particula();
	void setPosicion(vector<float> posicion);
	void setVelocidad(vector<float> velocidad);
	void setCosto(vector<float> costo);
	vector<float> getPosicion();
	vector<float> getVelocidad();
	vector<float> getCosto();
	vector<float> getBestPosicion();
	vector<float> getBestCosto();
	void setBestPosicion();
	void setBestCosto();
	int getId();
private:
	vector<float> posicion;
	vector<float> velocidad;
	vector<float> costo;
	vector<float> best_posicion;
	vector<float> best_costo;
	int id;
};

