#include "Funcion.h"


Funcion::Funcion()
{
    this->tipo_funcion=1;
    this->numVar=2;
    for(int i=0;i<this->numVar;i++){
        this->Max_var.push_back(1);
        this->Min_var.push_back(0);
        this->Max_vel.push_back(0.1*(this->Max_var[i]-this->Min_var[i]));
        this->Min_vel.push_back(-1*this->Max_vel[i]);
    }    
}

Funcion::Funcion(int tipo){

    this->tipo_funcion=tipo;
    switch(this->tipo_funcion){
        case 1:
            this->numVar=2;
            for(int i=0;i<this->numVar;i++){
                this->Max_var.push_back(1);
                this->Min_var.push_back(0);
                this->Max_vel.push_back(0.1*(this->Max_var[i]-this->Min_var[i]));
                this->Min_vel.push_back(-1*this->Max_vel[i]);
            }
            break;
        case 2:
            this->numVar=2;
            for(int i=0;i<this->numVar;i++){
                this->Max_var.push_back(1);
                this->Min_var.push_back(0);
                this->Max_vel.push_back(0.1*(this->Max_var[i]-this->Min_var[i]));
                this->Min_vel.push_back(-1*this->Max_vel[i]);
            }
            break;
        case 3:
            this->numVar=2;
            for(int i=0;i<this->numVar;i++){
                this->Max_var.push_back(1);
                this->Min_var.push_back(0);
                this->Max_vel.push_back(0.1*(this->Max_var[i]-this->Min_var[i]));
                this->Min_vel.push_back(-1*this->Max_vel[i]);
            }
            break;
        case 4:
            this->numVar=2;
            for(int i=0;i<this->numVar;i++){
                this->Max_var.push_back(1);
                this->Min_var.push_back(0);
                this->Max_vel.push_back(0.1*(this->Max_var[i]-this->Min_var[i]));
                this->Min_vel.push_back(-1*this->Max_vel[i]);
            }
            break;                                                  
        case 5:
            this->numVar=2;
            for(int i=0;i<this->numVar;i++){
                this->Max_var.push_back(1);
                this->Min_var.push_back(0);
                this->Max_vel.push_back(0.1*(this->Max_var[i]-this->Min_var[i]));
                this->Min_vel.push_back(-1*this->Max_vel[i]);
            }
            break;                 
        default:
            this->numVar=2;
            for(int i=0;i<this->numVar;i++){
                this->Max_var.push_back(1);
                this->Min_var.push_back(0);
                this->Max_vel.push_back(0.1*(this->Max_var[i]-this->Min_var[i]));
                this->Min_vel.push_back(-1*this->Max_vel[i]);
            }
            break;         
    }
}

Funcion::~Funcion()
{
}

vector<float> Funcion::calcularCosto(vector<float> posicion){
    float suma1 = 0;
	float suma2 = 0;
	float suma3 = 0;
	float suma4 = 0;
    vector<float> Costos;
    Costos.resize(this->numVar);
    int n=posicion.size();
    switch(this->tipo_funcion){
        case 1:
            suma1=posicion[0];
            for(int i=1;i<n;i++){
                suma2 += posicion[i];
            }
            suma2=1+suma2*(9/29);
            suma3=1-sqrt((suma1/suma2));
            suma4=suma2*suma3;
            Costos.push_back(suma1);
            Costos.push_back(suma4);
            break;
        case 2:
            suma1=posicion[0];
            for(int i=1;i<n;i++){
                suma2 += posicion[i];
            }
            suma2=1+suma2*(9/29);
            suma3=1-pow((suma1/suma2),2);
            suma4=suma2*suma3;
            Costos.push_back(suma1);
            Costos.push_back(suma4);
            break;
        case 3:
            suma1=posicion[0];
            for(int i=1;i<n;i++){
                suma2+=posicion[i];
            }
            suma2=1+suma2*(9/29);
            suma3=1-sqrt((suma1/suma2))-(suma1/suma2)*sin(10*PI*suma1);
            suma4=suma2*suma3;
            Costos.push_back(suma1);
            Costos.push_back(suma4);
            break;
        case 4:
            suma1=posicion[0];
            for(int i=1;i<n;i++){
                suma2+=pow(posicion[i],2)-10*cos(4*PI*suma1);
            }
            suma2+=91;
            suma3=1-sqrt((suma1/suma2));
            suma4=suma2*suma3;
            Costos.push_back(suma1);
            Costos.push_back(suma4);
            break;
        case 5:
            suma1=1-exp(-4*posicion[0])*pow(sin(6*PI*posicion[0]),6);
            for(int i=1;i<n;i++){
                suma2+=posicion[i];
            }                
            suma2=1+9*pow((suma2/9),0.25);
            suma2=1+suma2*(9/29);
            suma3=1-pow((suma1/suma2),2);
            suma4=suma2*suma3;
            Costos.push_back(suma1);
            Costos.push_back(suma4);
            break;
        default:
            break;    
    }
    return Costos;
}

int Funcion::getSizeObj(){
    return this->numVar;
}

float Funcion::getMaxVar(int obj){
    return this->Max_var[obj];
}

float Funcion::getMinVar(int obj){
    return this->Min_var[obj];
}

float Funcion::getMaxVel(int obj){
    return this->Max_vel[obj];
}

float Funcion::getMinVel(int obj){
    return this->Min_vel[obj];
}