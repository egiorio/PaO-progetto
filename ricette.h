#ifndef RICETTE_H
#define RICETTE_H


#include <QXmlStreamWriter>
#include <QXmlStreamWriter>
#include<string>
#include<map>
using std::string;


class ricette
{
private:
    std::string nome;
    double prezzo;
    bool cottura;

public:
    ricette();
    ricette(string nome,  double prezzo,  bool cottura);
     virtual ~ricette();
     std::string getNome() const;
     double getPrezzo() const;
     bool getCottura() const;
     void setNome(string&) ;
     void setPrezzo(double);
     void setCottura(bool);
     virtual std::string TipoR() const = 0;
     virtual ricette* clone() const=0;
     virtual bool operator==(const ricette&) const =0;

     //SERIALIZZAZIONE DEI DATI
     virtual void serialize(QXmlStreamWriter&) const =0;








};

#endif // RICETTE_H
