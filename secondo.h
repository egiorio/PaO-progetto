#ifndef SECONDO_H
#define SECONDO_H
#include"ricette.h"
#include<string>
using std::string;


class secondo: public ricette
{
private:
    string classeAlimentare; // se carne o pesce

public:
    secondo();
    secondo(string nome, double prezzo,  bool cottura,  string classeAlimentare );
    string getClasse() const;
    virtual ~secondo() override;
    secondo* clone() const override;
    virtual std::string TipoR() const override;
   bool operator==(const ricette&) const override;

   virtual void serialize(QXmlStreamWriter&) const override;


};

#endif // SECONDO_H
