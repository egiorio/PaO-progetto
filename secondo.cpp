#include "secondo.h"

secondo *secondo::create(QXmlStreamReader & r) const
{
    std::string nome = "Senza nome";
    double prezzo = 0.0;
    bool cottura = true;
    std::string tipo = "Vegetariano";
    if(r.readNextStartElement() && r.name()=="nome")
        nome = r.readElementText().toStdString();
    if(r.readNextStartElement() && r.name()=="prezzo")
        prezzo = r.readElementText().toDouble();
    if(r.readNextStartElement() && r.name()=="cottura")
        cottura = r.readElementText() == "true"? true:false;
    if(r.readNextStartElement() && r.name()=="tipo")
        tipo = r.readElementText().toStdString();

    r.skipCurrentElement();
    return new secondo(nome, prezzo, cottura, tipo);
}

secondo::secondo(string  a, double b, bool c, string s): ricette(a, b, c), classeAlimentare(s){}

string secondo::getClasse() const{
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

     //ricette::serialize(output);

     output.writeStartElement("Classe Alimentare");
     output.writeCharacters(QString::fromStdString(getClasse()));
      output.writeEndElement();

      output.writeEndElement();
}

void secondo::XML(QXmlStreamWriter &out) const
{
    out.writeStartElement("Secondo");
    ricette::XML(out);

    out.writeStartElement("Classe Alimentare: ");
    out.writeCharacters(QString::fromStdString(classeAlimentare));
    out.writeEndElement();

    out.writeEndElement();
}
