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
#define PI 3.1416
using namespace std;

class MOPSO;
class Funcion
{
public:
	Funcion();
	Funcion(int tipo);
	virtual ~Funcion();
	vector<float> calcularCosto(vector<float> posicion);
	int getSizeObj();
	int getSizeVar();
	float getMaxVar(int obj);
	float getMinVar(int obj);
	float getMaxVel(int obj);
	float getMinVel(int obj);

private:
	int tipo_funcion;
	int numVar;
	int numObj;
	vector<float> Min_var;
	vector<float> Max_var;
	vector<float> Min_vel;
	vector<float> Max_vel;
};
