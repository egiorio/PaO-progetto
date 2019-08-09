#include "dolce.h"



dolce::dolce(string a, double b, bool c, string s): ricette(a, b, c), categoria(s){}

string dolce::getCategoria() const{
    return categoria;
}
dolce::~dolce(){}

dolce* dolce::clone()const{
    return new dolce(*this);
}

std::string dolce::TipoR() const
{
    return string("Dolce");
}

bool dolce::operator==(const ricette& a) const{
    const dolce& b=dynamic_cast<const dolce&>(a);
    return (categoria==b.categoria);
}

void dolce::serialize(QXmlStreamWriter & output) const
{
    output.writeStartElement("Ricette-Dolce");

   output.writeStartElement("Nome");
    output.writeCharacters(QString::fromStdString(getNome()));
     output.writeEndElement();
    output.writeStartElement("Prezzo");
    output.writeCharacters(QString::number(getPrezzo()));
     output.writeEndElement();
    output.writeStartElement("Cottura");
    output.writeCharacters(getCottura() ?"true" : "false");
     output.writeEndElement();


    output.writeStartElement("Categoria");
    output.writeCharacters(QString::fromStdString(getCategoria()));
     output.writeEndElement();

     output.writeEndElement();
}

