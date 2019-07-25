#ifndef CONTAINER1_H
#define CONTAINER1_H
#include "deepptr.h"
#include<iostream>


template <class T>
class Container{
    //contenitore
    friend class Iterator;
    friend class const_iterator;
private:
    class nodo{
    public:
        DeepPtr<T> info;

        nodo  *prev, *next;
        nodo(const DeepPtr<T> &, nodo* = nullptr, nodo* = nullptr);
        //nodo(const T&, nodo* = nullptr, nodo* = nullptr);
        nodo(DeepPtr<T> &&, nodo* =nullptr, nodo* = nullptr);
        nodo(T* , nodo * = nullptr, nodo * =nullptr);
        ~nodo();
        bool operator==(const nodo&) const;
        bool operator!=(const nodo&) const;
    };
    static nodo* copia(nodo* f, nodo*& l);
public:
    class Iterator{ //template annidato per la classe iteratore
        friend class Container;
    public:
        nodo* pos;
        Iterator(nodo * = nullptr); //costruttore

        Iterator& operator++(); // prefisso
        Iterator operator++(int); //postfisso
        Iterator& operator--() ;//prefisso
        Iterator operator--(int); //postfisso

        bool operator==(const Iterator &it) const; //ugualianza
        bool operator!=(const Iterator &it) const; //disugualianza

        T& operator*() const; //deferenziazione
        T* operator->() const; //accesso a membro
     };

    class const_iterator{ //template per la classe const
        friend class Container;
    public:
        nodo* pos;
        const_iterator(nodo * = nullptr); //costruttore

        const_iterator& operator++(); //prefisso
        const_iterator operator++(int); //postfisso
        const_iterator& operator--(); //prefisso
        const_iterator operator--(int); //postfisso

        bool operator==(const const_iterator &it) const;
        bool operator!=(const const_iterator &it) const;

        T& operator*() const;
        T* operator->() const;


    };

private:
    nodo * primo;
    nodo* ultimo;
    unsigned int size; //contatore di nodi
public:
    //container
    Container(); //default
    Container(unsigned int, const T& = T());
    Container(unsigned int);
    Container(const Container &); //costrutore copia
    Container& operator=(const Container &c);
    ~Container(); //distruttore

    unsigned int getSize() const;
    bool isEmpty() const;

    //metodi per iteratore
    T& front() const;
    T& back() const;
    Iterator begin();
    Iterator begin() const;
    const_iterator cbegin() const;
    Iterator end();
    Iterator end() const;
    const_iterator cend() const;
    //forse serve cons_iterator end() const; ???
     //iteratori per inserimento
    Iterator insert(const Iterator&, const T&);
    //Iterator insert(const Iterator&, const T*);
    void insert(Iterator, unsigned int);


    void push_back(const T&);
    //void push_back(T* t);

    void push_front(const T&);


    //iteratori per la cancellazione
    Iterator erase(Iterator);
    Iterator erase(Iterator, Iterator);
    void erase(T*);

    void clear();
    void pop_back();
    void pop_front();

    //iteratori per la ricerca
    Iterator search(const T&);
    const_iterator search(const T&) const;
    Iterator search(T*) const;


};

//_________________________________METODI!!!

//classe nodo

//costruttore di nodo
template<class T>
Container<T>::nodo::nodo(const DeepPtr<T> &t, nodo*p, nodo*n) : info(t), prev(p), next(n) {}
/*
template<class T>
Container<T>::nodo::nodo(const T &t, nodo *n, nodo*p):
    info(t),  prev(p), next(n) {}
*/
template <class T>
Container<T>::nodo::nodo(T *t, nodo *n, nodo*p):
    info(t), next(n), prev(p){}

template <class T>
Container<T>::nodo::nodo(DeepPtr<T> &&t, nodo* n, nodo*p):
    info(t), next(n), prev(p){}
//distruttore di nodo
template <class T>
Container<T>::nodo::~nodo(){
    delete next;
}

template <class T>
bool Container<T>::nodo::operator==(const nodo&n) const{
    return (info == n.info);
}

template <class T>
bool Container<T>::nodo::operator!=(const nodo&n)const{
    return !(n == *this);
}


//classe iteratore

//costruttore
template <class T>
Container<T>::Iterator::Iterator(nodo *p) : pos(p) {}


//prefisso
template <class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++(){
    if(pos != nullptr && pos->next != nullptr)
        pos = pos->next;
    return *this;
}

//postfisso
template <class T>
typename Container<T>::Iterator Container<T>::Iterator::operator++(int){
    Iterator a(*this);
    operator++();
    return a;
}
 //prefisso
template <class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator--(){
    if(pos != nullptr && pos->prev != nullptr)
        pos = pos-> prev;
    return  *this;
}

//postfisso
template <class T>
typename Container<T>::Iterator Container<T>::Iterator::operator--(int){
    Iterator a(*this);
    operator--();
    return a;
}

template <class T>
bool Container<T>::Iterator::operator==(const Iterator &it) const{
    return  pos==it.pos;
}

template <class T>
bool Container<T>::Iterator::operator!=(const Iterator&it)const{
    return !(*this == it);
}

//deferenziazione
template <class T>
T& Container<T>::Iterator::operator*() const{
    if( pos != nullptr)
        return *(pos->info);

}

template <class T>
T* Container<T>::Iterator::operator->() const{
    if(pos != nullptr)
        return pos->info;
}

//costruttore const iterator
template <class T>
Container<T>::const_iterator::const_iterator(nodo *p): pos(p){}

//prefissso
template <class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator++(){
    if( pos != nullptr && pos->next != nullptr)
        pos=pos->next;
    return *this;
}

//postfisso
template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator++(int)
{
    const_iterator a(*this);
    operator++();
    return a;
}

//prefisso
template <class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator--(){
    if(pos != nullptr && pos->prev != nullptr)
        pos=pos->prev;
    return *this;
}

//postfisso
template <class T>
typename Container<T>:: const_iterator Container<T>::const_iterator::operator--(int){
    Iterator a(*this);
    operator--();
    return a;
}

//ugualianza

template <class T>
bool Container<T>::const_iterator::operator==(const const_iterator &it) const{
    return pos == it.pos;
}

//disugualianza
template <class T>
bool Container<T>::const_iterator::operator!=(const const_iterator &it) const{
    return !(*this == it);
}

//deferenziazione
template <class T>
T& Container<T>::const_iterator::operator*()const{
    if(pos != nullptr)
        return *(pos->info);
}

//accesso a membro
template <class T>
T* Container<T>::const_iterator::operator->()const{
    if(pos != nullptr)
        return &(pos->info);
}



//CAMPI DEL CONTENITORE

template <class T>
typename Container<T>::nodo* Container<T>::copia(nodo*f, nodo*& l){
   if(!f)
       return l = nullptr;
   nodo* temp= new nodo(f->info);
   nodo* a= temp;
   while(f->next){
       a->next = new nodo(f->next->info, a);
       f = f->next;
       a = a->next;
      }
   l=a;
   return temp;
}

template <class T>
Container<T>::Container() : primo(nullptr), ultimo(nullptr), size(0){}

//modo di costruzione del container
template <class T>
Container<T>::Container(unsigned int n, const T &t){
    Container();
    while(n>0){
        push_back(t);
        n--;
    }
}

//costruttore di container con un valore di default
template <class T>
Container<T>::Container(unsigned int n){
    Container(n, T());
}

//costruttore di copia
template <class T>
Container<T>::Container(const Container &c) : primo(nullptr), ultimo(nullptr), size(c.size){
    primo=copia(c.primo, ultimo);
}

template <class T>
Container<T>& Container<T>::operator=(const Container &c){
    if(this != &c){
        if( primo!= nullptr) delete primo;
        size= c.size;
        primo = copia((c.primo), ultimo);
    }
    return  *this;
}
 //disttruttore di container
template <class T>
Container<T>::~Container(){
    delete  primo;
}

//inserimento di un elemento prima dell'elemento it
template <class T>
typename Container<T>::Iterator Container<T>::insert(const Iterator &it, const T &t){
    if(primo == nullptr){
        //se ho una lista vuota
        primo = ultimo = new nodo(DeepPtr<T>(&t));
        size=1;
        return  Iterator(primo);
    }
    else{
        nodo* a= new nodo(DeepPtr<T>(&t), it.pos, it.pos->next);
        //nodo * a= new nodo(Deeptr<T>(&t), it.pos->prev, it.pos);
        (it.pos != primo) ? it.pos->prev->next = a : primo = a;
        (it.pos != ultimo) ? it.pos->prev->next = a : ultimo = a;

        size++;
        return  it.pos->prev;
    }

}

//inserimento prima dell'elemento puntato
template <class T>
void Container<T>::insert(Iterator it, unsigned int n){
    for(unsigned int a=0; a<n; a++)
        insert(it, a);
}


//erase di un iteratore
template <class T>
typename Container<T>::Iterator Container<T>::erase(Iterator it){
    if( primo== nullptr)
        //lista vuota
        return  nullptr;

    nodo* a= it.pos->next != nullptr ? it.pos->next : nullptr;
    if(primo != ultimo){
        primo != it.pos ? it.pos->prev->next = a : primo =a;
        ultimo != it.pos ? it.pos->next->prev = it.pos->prev : ultimo= it.pos->prev;

        it.pos->next = it.pos->prev = nullptr;
    }
    delete it.pos;
    size--;
    return Iterator(a);
}

//distruzione di un itnervalllo
template <class T>
typename Container<T>::Iterator Container<T>::erase(Iterator a, Iterator b){
    while(a != b){
        erase(a);
        b++;
    }
    return b;
}

template <class T>
void Container<T>::clear(){
    erase(begin(), end());
}

//void erase
template <class T>
void Container<T>::erase(T* w){

    nodo* x;
    nodo* z=this->primo;
    while(z && primo==z){
        if(z != NULL){
            nodo* temp=z;
            z=z->next;
            this->primo=z;
            temp->next=nullptr;
            delete temp;
            }
        else{
               x=z;

               z=z->next;
        }

    }
    while (z) {
        if(z != NULL){
            nodo* temp=z;
            z=z->next;
            z->next=z;
            temp->next=nullptr;
            delete temp;
        }
        else{
            x=x->next;
            z=z->next;

        }

    }

}
//pop_back
template <class T>
void Container<T>::pop_back(){
    erase(--end());
}

//pop front
template <class T>
void Container<T>::pop_front(){
    erase(begin());
}

//dammi il primo
template <class T>
T& Container<T>::front()const{
    return *(primo->info);
}

//dammi l'ultimo
template <class T>
T& Container<T>::back()const{
    return *(ultimo->info);

}

//iteratore a primo
template <class T>
typename Container<T>::Iterator Container<T>::begin(){
    return Iterator(primo);
}

//iteratore alla fine
template <class T>
typename Container<T>::Iterator Container<T>::end(){
    return Iterator(ultimo); //quindi a null

}

template <class T>
typename Container<T>::Iterator Container<T>::begin()const{
    return Iterator(primo);
}
template <class T>
typename Container<T>::Iterator Container<T>::end() const{
    return Iterator(ultimo);
}

template <class T>
typename Container<T>::const_iterator Container<T>::cbegin() const{
    return const_iterator(primo);
}

template <class T>
typename Container<T>::const_iterator Container<T>::cend()const{
    return const_iterator(ultimo->next);
    //return const_iterator(ultimo);
}

template <class T>
unsigned int Container<T>::getSize() const{
    return size;
}

template <class T>
bool Container<T>::isEmpty() const{
    return (size == 0 && primo == nullptr);
}

//Metodi per la ricerca
template <class T>
typename Container<T>::Iterator Container<T>::search(const T& t){
    Iterator it= begin();
    for(; it != end() && *it != t; it++);
    return it;
}

//ricerca const
template <class T>
typename Container<T>::const_iterator Container<T>::search(const T& t)const{
    const_iterator cit= cbegin();
    for(; cit!= cend() && *cit != t; cit++);
    return cit;
}

//search con iteratore
template <class T>
typename Container<T>::Iterator Container<T>::search(T* t) const{
    Iterator it=begin();
    for(; it!=end() && it->info != t; ++it);
    return it;

}

//push_front
template <class T>
void Container<T>::push_front(const T& t){
    insert(begin(), t);
}

//push_back
template <class T>
void Container<T>::push_back(const T& t){
    insert(end(), t);
   /* ultimo = new nodo(t, ultimo, nullptr);
    if( primo == nullptr)
        primo = ultimo;
    else {
        (ultimo->prev)->next = ultimo;
        size++;
    */
    /*
    size++;
        if (!primo)
            primo = ultimo = new nodo(t);
        else{
            ultimo->next = new nodo(t, ultimo);
            ultimo= ultimo->next;
        }
        */
}


/*
template <class T>
void Container<T>::push_back(T* t){
    nodo* p= primo;
    while (p->next) {
        p=p->next;

    }
    p->next = new nodo(t, p, nullptr);
}


template <class T>
void Container<T>::push_back(const T& t){
    //nodo* p=primo;
    //while (p->next) {
     //   p=p->next;
      // }

    //p->next = new nodo(t, primo, nullptr);
   // ultimo->next = new nodo(t, ultimo, nullptr);
    //ultimo=ultimo->next;
}
*/

#endif // CONTAINER1_H
