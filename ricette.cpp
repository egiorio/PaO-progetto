
#include "ricette.h"



//std::map<std::string, ricette*>  ricette::mapp =  std::map<std::string, ricette*>();
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

ricette *ricette::unserialize(QXmlStreamReader & r)
{/*
    if(r.name() != "ricette")
        throw std::string("Nome non corretto");
    std::string temp = r.attributes().value("Tipo").toString().toStdString();
    if(mapp.count(temp) == 0)
        throw  std::string("non trovato");
    return mapp[temp]->create(r);

*/
}

void ricette::serialize(QXmlStreamWriter & w) const{
    w.writeStartElement("Nome ricetta:");
    w.writeCharacters(QString::fromStdString(nome));
    w.writeEndElement();

    w.writeStartElement(("Prezzo"));
    w.writeCharacters(QString::number(getPrezzo()));
    w.writeEndElement();
    w.writeStartElement("Cottura");
    w.writeCharacters(getCottura() ? "true" : "false");
    w.writeEndElement();


}
