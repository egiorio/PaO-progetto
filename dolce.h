#ifndef DOLCE_H
#define DOLCE_H
#include "ricette.h"
#include<string>
using std::string;

class dolce: public ricette
{
private:
    string categoria; //se vegano o non vegano


public:
    dolce ( string ID,  double prezzo,   bool cottura,  string categoria);
    virtual ~dolce();
    string getCategoria() const;
    dolce* clone() const override;
    virtual std::string TipoR() const override;
    bool operator==(const ricette&) const override;


    virtual void serialize(QXmlStreamWriter&) const override;

};

#endif // DOLCE_H
