#include "Particula.h"


Particula::Particula(int id)
{
	this->id = id;
}

Particula::~Particula()
{
}

void Particula::setPosicion(vector<float> posicion)
{
	this->posicion = posicion;
}

void Particula::setVelocidad(vector<float> velocidad)
{
	this->velocidad = velocidad;
}

void Particula::setCosto(vector<float> costo)
{
	this->costo = costo;
}

vector<float> Particula::getPosicion()
{
	return this->posicion;
}

vector<float> Particula::getVelocidad()
{
	return this->velocidad;
}

vector<float> Particula::getCosto()
{
	return this->costo;
}

int Particula::getId()
{
	return this->id;
}
