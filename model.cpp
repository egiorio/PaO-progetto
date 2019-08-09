#include "model.h"
#include "ricette.h"
#include "add.h"
#include"primo.h"
#include "secondo.h"
#include "dolce.h"

#include "xmlio.h"




#include<string>
using std::string;
#include<QSaveFile>
#include <QXmlStreamWriter>



void Model::remove(ricette* x){

    contenitore.erase(x);


}

void Model::save() const{

    xmlIO xmlio("../Documenti/p2/Save.xml");

    xmlio.write(contenitore);



}

void Model::load(const QString &path)
{


 xmlIO xmlIO(path);
 contenitore = xmlIO.read();


}

Container<ricette> Model::getRicette()
{
    return contenitore;
}

ricette* Model::addO(const string type, const string name, double prezzo, bool cottura, const string altro){
       if(type=="Primo"){
            primo* p=new primo(name, prezzo, cottura, altro);
            contenitore.push_back(*(p));
            return p;
        }

        else {
            if(type=="Secondo"){
                secondo* p=new secondo(name, prezzo, cottura, altro);
                contenitore.push_back(*p);
                return p;
            }
            else{
                dolce* p=new dolce(name, prezzo, cottura, altro);
                contenitore.push_back(*p);
                return p;
            }
}


}

std::vector<ricette*> Model::cercaR(const QString name, const string type)
{


    std::vector<ricette*> to_ret;
    for(auto it=contenitore.begin(); it!= contenitore.last(); ++it){
       if(type == "Primo"){
           primo* p = dynamic_cast<primo*>(*it);
           if(p != nullptr && p->getNome() == name.toStdString())
               to_ret.push_back(p);

        }
       else{
           if(type == "Secondo"){
               secondo* s= dynamic_cast<secondo*>((*it));
               if(s != nullptr && s->getNome() == name.toStdString())
                   to_ret.push_back(s);

           }
           else{
               if(type ==  "Dolce"){
                   dolce* d=dynamic_cast<dolce*>((*it));
                   if(d != nullptr && d->getNome() == name.toStdString())
                       to_ret.push_back(d);

               }
           }
       }



        }

    return to_ret;
}

