#include "Swarm.h"

Swarm::Swarm()
{
    this->id_max = 0;
}

Swarm::~Swarm()
{
}

void Swarm::addParticula(vector<float> posicion)
{
    Particula *part_aux;
    part_aux = new Particula((this->id_max + 1));
    part_aux->setPosicion(posicion);
    this->Particulas.push_back(*part_aux);
    part_aux->~Particula;
    this->id_max += 1;
}

vector<Particula> Swarm::getSwarm()
{
    return this->Particulas;
}

Particula Swarm::getParticula(int id)
{
    vector<int> id_aux;
    for (int i = 0; i < this->Particulas.size(); i++)
    {
        id_aux.push_back(this->Particulas[i].getId());
    }
    auto indice = find(id_aux.begin(), id_aux.end(), id);
    int idx = *indice;
    return this->Particulas[idx];
}

void Swarm::setLider(int id)
{
    this->Lider = getParticula(id);
}

void Swarm::calcularVelocidad(int opcion, float w, float c1, float c2, int numVariables)
{
    vector<float> vel_aux;
    vector<float> pos_aux;
    vel_aux.resize(numVariables);
    pos_aux.resize(numVariables);
    for (int i = 0; i < Particulas.size(); i++)
    {
        for (int j = 0; j < numVariables; j++)
        {
            switch (opcion)
            {
            case 1:
                vel_aux[j] = w * (this->Particulas[i].getVelocidad()[j]) + c1 * float(rand() / (RAND_MAX + 1.0)) * (this->Particulas[i].getBestPosicion()[j] - this->Particulas[i].getPosicion()[j]) + c2 * float(rand() / (RAND_MAX + 1.0)) * (this->Lider.getPosicion()[j] - this->Particulas[i].getPosicion()[j]);
                break;
            case 2:
                vel_aux[j] = w * ((this->Particulas[i].getVelocidad()[j]) + c1 * float(rand() / (RAND_MAX + 1.0)) * (this->Particulas[i].getBestPosicion()[j] - this->Particulas[i].getPosicion()[j]) + c2 * float(rand() / (RAND_MAX + 1.0)) * (this->Lider.getPosicion()[j] - this->Particulas[i].getPosicion()[j]));
                break;
            }
            vel_aux[j] = max(vel_aux[j], this->Min_vel[j]);
            vel_aux[j] = min(vel_aux[j], this->Max_vel[j]);
            pos_aux[j] = this->Particulas[i].getPosicion()[j] + vel_aux[j];
            vel_aux[j] = pos_aux[j] < this->Min_var[j] || pos_aux[j] > this->Max_var[j] ? vel_aux[j] * (-1) : vel_aux[j];
            pos_aux[j] = max(pos_aux[j], this->Min_var[j]);
            pos_aux[j] = min(pos_aux[j], this->Max_var[j]);
        }
        this->Particulas[i].setVelocidad(vel_aux);
        this->Particulas[i].setPosicion(pos_aux);
        vel_aux.resize(numVariables);
        pos_aux.resize(numVariables);
    }
}

void Swarm::setMaxVar(vector<float> maxvar)
{
    this->Max_var = maxvar;
}

void Swarm::setMinVar(vector<float> minvar)
{
    this->Min_var = minvar;
}

void Swarm::setMaxVel(vector<float> maxvel)
{
    this->Max_vel = maxvel;
}

void Swarm::setMinVel(vector<float> minvel)
{
    this->Min_vel = minvel;
}