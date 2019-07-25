#include "xmlio.h"
#include "ricette.h"
#include"primo.h"
#include"secondo.h"
#include"dolce.h"
#include "model.h"
#include "container1.h"

#include<QFile>
#include<QSaveFile>
#include <QXmlStreamReader>
#include<QXmlStreamWriter>
#include<QDebug>
#include<QMessageBox>

xmlIO::xmlIO( QString path):
    FileName(path)
{}

Container<ricette> xmlIO::read() const
{
    Container<ricette> contenitore;
    string a = FileName.toStdString();
    QFile file(QString::fromStdString(a));
    if(!file.open(QIODevice::ReadOnly)){
        //QMessageBox box(QMessageBox::warning, "Errore di appertura", "Non è stato possibile aprire il file");
        qWarning() <<"Non è stato possibile aprire il file";
        return contenitore;
    }

    //se viene aperto
    QXmlStreamReader input(&file);
    if(input.readNextStartElement() && input.name() == "root"){
        try {
            contenitore.push_back(*(ricette::unserialize(input)));
        } catch (std::string s) {
            qWarning() <<"Errore in lettura";
        }
    }



        file.close();
        return  contenitore;

}

void xmlIO::write(const Container<ricette> & contenitore) const
{


    QSaveFile file("Save.xml");

    if(!file.open(QIODevice::WriteOnly))
        throw std::exception();

    QXmlStreamWriter output(&file);

    output.setAutoFormatting(true);
    output.writeStartDocument();
    output.writeComment("File di salvataggio");

    output.writeStartElement("root");

    /*
    auto c = contenitore.begin();

 //MOLTO PROBABILMEnte NON ENTRA MAI QUI
    while(c != contenitore.end()) {
        (*c).serialize(output);
        ++c;
    }

    */
    for( auto cit = contenitore.begin(); cit != contenitore.end(); ++cit)
        (*cit).serialize(output);

    output.writeEndElement();
    output.writeEndDocument();

    file.commit();
    if(output.hasError())
       throw std::exception();




}
