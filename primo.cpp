#include "primo.h"

primo::primo(string i, double p, bool c, string s): ricette(i,p,c), tipo(s){}

primo::~primo(){

}

primo* primo::clone() const{
    return  new primo(*this);

}

string primo::getTipo()const {
    return tipo;
}

std::string primo::TipoR() const
{
    return  string("Primo");
}

bool primo::operator==(const ricette& a) const{
    const primo& b=dynamic_cast<const primo&>(a);
    return (tipo==b.tipo);
}

void primo::serialize(QXmlStreamWriter & output) const
{
    output.writeStartElement("Ricette - Primo");

    output.writeStartElement("Nome");
    output.writeCharacters(QString::fromStdString(getNome()));
    output.writeEndElement();
    output.writeStartElement(("Prezzo"));
    output.writeCharacters(QString::number(getPrezzo()));
    output.writeEndElement();
    output.writeStartElement("Cottura");
    output.writeCharacters(getCottura() ? "true" : "false");
    output.writeEndElement();
    output.writeStartElement("Tipo");
    output.writeCharacters(QString::fromStdString(getTipo()));
    output.writeEndElement();

    output.writeEndElement();
    if(output.hasError())
        throw  std::exception();





}

primo *primo::create(QXmlStreamReader & r) const
{
    std::string nome = "Senza nome";
    double prezzo = 0.0;
    bool cottura = true;
    std::string tipo = "Pasta";
    if(r.readNextStartElement() && r.name()=="nome")
        nome = r.readElementText().toStdString();
    if(r.readNextStartElement() && r.name()=="prezzo")
        prezzo = r.readElementText().toDouble();
    if(r.readNextStartElement() && r.name()=="cottura")
        cottura = r.readElementText() == "true"? true:false;
    if(r.readNextStartElement() && r.name()=="tipo")
        tipo = r.readElementText().toStdString();

    r.skipCurrentElement();
    return new primo(nome, prezzo, cottura, tipo);
}
