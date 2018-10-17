#include "MOPSO.h"



MOPSO::MOPSO()
{
}


MOPSO::MOPSO(int iter_max, float w_damp, float w, float mu, float alfa, float beta, float gamma, float c1, float c2, int nrep, int num_particulas, int num_grid, int opcion_inercia, int opcion_funcion)
{
	this->iter_max = iter_max;
	this->w_damp = w_damp;
	this->w = w;
	this->mu = mu;
	this->alfa = alfa;
	this->beta = beta;
	this->gamma = gamma;
	this->c1 = c1;
	this->c2 = c2;
	this->nrep = nrep;
	this->num_particulas = num_particulas;
	this->num_grid = num_grid;
	this->opcion_funcion = opcion_funcion;
	this->opcion_inercia = opcion_inercia;

}

MOPSO::~MOPSO()
{
}
