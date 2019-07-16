#ifndef XMLIO_H
#define XMLIO_H

#include <QString>
#include "container1.h"
#include"model.h"

class xmlIO
{
private:
    QString FileName;
public:
    xmlIO(QString);
    Container<ricette> read() const;
    void write(const Container<ricette> &) const;

};

#endif // XMLIO_H
