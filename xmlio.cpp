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


    Container<ricette> load;//lista

    QFile file(FileName);

    //Aprire il file

    if(!file.open(QIODevice::ReadOnly)){
        qWarning() <<"errore!";
        return load;
    }

    //lettura fa file
    QXmlStreamReader input(&file);
    if(input.readNextStartElement()){
        if(input.name() == "root"){
            while(input.readNextStartElement()){
                if(input.name() == "Ricette-Primo"){
                    input.readNextStartElement();
                    std::string nome = (input.readElementText().toStdString());
                    input.readNextStartElement();
                    double prezzo = (input.readElementText().toDouble());
                    input.readNextStartElement();
                    bool cottura = (input.readElementText()) == "true" ? true : false;
                    input.readNextStartElement();

                    std::string tipo = (input.readElementText().toStdString());
                    primo* p= new primo(nome, prezzo, cottura, tipo);
                    input.readNextStartElement();
                    load.push_back(*p);

                }
                else{
                    if(input.name() == "Ricette-Secondo"){
                        input.readNextStartElement();
                        std::string nome = (input.readElementText().toStdString());
                        input.readNextStartElement();
                        double prezzo = (input.readElementText().toDouble());
                        input.readNextStartElement();
                        bool cottura = (input.readElementText()) == "true" ? true : false;
                        input.readNextStartElement();
                        std::string tipo = (input.readElementText().toStdString());

                        secondo * s= new secondo(nome, prezzo, cottura, tipo);
                        input.readNextStartElement();
                        load.push_back(*s);

                    }
                    else{
                        if(input.name() == "Ricette-Dolce"){
                            input.readNextStartElement();
                            std::string nome = (input.readElementText().toStdString());
                            input.readNextStartElement();
                            double prezzo = (input.readElementText().toDouble());
                            input.readNextStartElement();
                            bool cottura = (input.readElementText()) == "true" ? true : false;
                            input.readNextStartElement();
                            std::string tipo = (input.readElementText().toStdString());
                            input.readNextStartElement();
                            dolce * d= new dolce(nome, prezzo, cottura, tipo);
                            load.push_back(*d);
                        }
                        }
                    }
                }
            }
        }

    file.close();
    return load;



}

void xmlIO::write(const Container<ricette> & contenitore) const
{


    QSaveFile file("Save.xml");

    if(!file.open(QIODevice::WriteOnly))
        throw std::exception();

    QXmlStreamWriter output(&file);

    output.setAutoFormatting(true);
    output.writeStartDocument();
    output.writeComment("File di salvataggio - Non modificare!!");

    output.writeStartElement("root");

    if(contenitore.begin() == contenitore.end())
        contenitore.begin()->serialize(output);
    else{
        auto cont = contenitore.begin();
        while (cont  != contenitore.end()) {

            (cont)->serialize(output);
            ++cont;

            if (cont == contenitore.end())
                (contenitore.end()->serialize(output));

        }
       }

    output.writeEndElement();
    output.writeEndDocument();

    file.commit();
    if(output.hasError())
       throw std::exception();




}

