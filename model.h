#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include<fstream>
#include<functional>
#include<vector>
using std::string;

#include"container1.h"
#include "ricette.h"


class Model
{
private:
    Container<ricette> contenitore;

public:

    using Index= Container<ricette>::Iterator;

    Model()= default;
    ~Model() = default;

    void remove(ricette*);
    //void save(const QString &) const;
    void save() const;
    void load(const QString&);
    ricette* addO(const string,  const string, double, bool, const string);

    std::vector<ricette*> cercaR(const QString);
};

#endif // MODEL_H
