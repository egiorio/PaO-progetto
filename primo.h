#ifndef PRIMO_H
#define PRIMO_H
#include "ricette.h"

#include<string>
using std::string;

class primo: public ricette
{
private:

    string tipo;
public:
    primo();
    primo(string nome,double prezzo, bool cottura,  string tipo);
    virtual ~primo() override;
    primo* clone() const override;
    string getTipo()const;
    virtual std::string TipoR() const override;
    bool operator==(const ricette&) const override;

    virtual void serialize(QXmlStreamWriter&) const override;
    virtual primo* create(QXmlStreamReader&) const override;

    void XML(QXmlStreamWriter& out) const;
};

#endif // PRIMO_H
