
#include "ricette.h"




ricette::ricette(string name, double money, bool cook) : nome(name), prezzo(money), cottura(cook){ }

ricette::~ricette(){}

string ricette::getNome() const{
    return nome;
}
double ricette::getPrezzo() const{
    return prezzo;
}
bool ricette::getCottura() const{
    return cottura;
}

void ricette::setNome(string& name)
{
    nome=name;

}

void ricette::setPrezzo(double money)
{
    prezzo=money;
    //return prezzo;

}
void ricette::setCottura(bool c)
{
    cottura=c;
    //return cottura;

}


