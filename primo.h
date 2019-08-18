#ifndef PRIMO_H
#define PRIMO_H
#include "ricette.h"

#include<string>
using std::string;

class primo: public ricette
{
private:

    std::string tipo; //se vegetariana o onnivora
public:
    primo();
    primo(string nome,double prezzo, bool cottura,  string tipo);
    virtual ~primo() override;
    primo* clone() const override;
    std::string getTipo()const;
    virtual std::string TipoR() const override;
    bool operator==(const ricette&) const override;

    virtual void serialize(QXmlStreamWriter&) const override;



};

#endif // PRIMO_H
