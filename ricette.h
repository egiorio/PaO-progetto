#ifndef RICETTE_H
#define RICETTE_H


#include <QXmlStreamWriter>
#include<string>
#include<map>
using std::string;


class ricette
{
private:
    string nome;
    double prezzo;
    bool cottura;
    virtual ricette* create(QXmlStreamReader&) const = 0;
protected:
    static std::map<std::string, ricette*>mapp;



public:
    ricette();
    ricette(string nome,  double prezzo,  bool cottura);
     virtual ~ricette();
     string getNome() const;
     double getPrezzo() const;
     bool getCottura() const;
     void setNome(string&) ;
     void setPrezzo(double);
     void setCottura(bool);
     virtual std::string TipoR() const = 0;
     virtual ricette* clone() const=0;
     virtual bool operator==(const ricette&) const =0;

     //SERIALIZZAZIONE DEI DATI
     virtual void serialize(QXmlStreamWriter&) const = 0;
     static ricette* unserialize(QXmlStreamReader&);





};

#endif // RICETTE_H
