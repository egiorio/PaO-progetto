#include "secondo.h"


secondo::secondo(string  a, double b, bool c, string s): ricette(a, b, c), classeAlimentare(s){}

std::string secondo::getClasse() const{
    return classeAlimentare;
}
secondo::~secondo(){}

secondo* secondo::clone() const{
    return new secondo(*this);
}

std::string secondo::TipoR() const
{
    return string("Secondo");
}

bool secondo::operator==(const ricette& a) const{
    const secondo& b=dynamic_cast<const secondo&>(a);
    return (classeAlimentare==b.classeAlimentare);
}

void secondo::serialize(QXmlStreamWriter & output) const
{
     output.writeStartElement("Ricette-Secondo");

     output.writeStartElement("Nome");
     output.writeCharacters(QString::fromStdString(getNome()));
      output.writeEndElement();
     output.writeStartElement("Prezzo");
     output.writeCharacters(QString::number(getPrezzo()));
      output.writeEndElement();
     output.writeStartElement("Cottura");
     output.writeCharacters(getCottura() ? "true" : "false");
      output.writeEndElement();



     output.writeStartElement("Classe");
     output.writeCharacters(QString::fromStdString(getClasse()));
      output.writeEndElement();

      output.writeEndElement();
}

