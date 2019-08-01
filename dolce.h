#ifndef DOLCE_H
#define DOLCE_H
#include "ricette.h"
#include<string>
using std::string;

class dolce: public ricette
{
private:
    string categoria;
    virtual dolce*create(QXmlStreamReader&) const;

public:
    dolce ( string ID,  double prezzo,   bool cottura,  string categoria);
    virtual ~dolce();
    string getCategoria() const;
    dolce* clone() const;
    virtual std::string TipoR() const override;
    bool operator==(const ricette&) const;


    virtual void serialize(QXmlStreamWriter&) const override;
    void XML(QXmlStreamWriter& out) const;
};

#endif // DOLCE_H
