#ifndef CONTAINER_H
#define CONTAINER_H
#include<iostream>

#include"deepptr.h"
/*
template <class T>
class Container{
    friend class iteratore;
    friend class const_iteratore;
private:
    class nodo{
    public:
        DeepPtr<T> info;
        nodo* prec;
        nodo* next;
        nodo(const DeepPtr<T>&, nodo* =nullptr, nodo* =nullptr);
        ~nodo();

    };
    nodo* primo;
    nodo* ultimo;
    unsigned int size_;
    static nodo* copia(nodo* a, nodo*& l);
    static void distruggi(nodo*);
public:
    class iterator{
        friend class Container<T>;
        private:
            nodo*p;
            iterator(nodo * = nullptr); //costruttore

        public:
               iterator();
               bool operator==(const iterator&) const;
               bool operator!=(const iterator&) const;
               iterator& operator++(); //prefisso
               iterator operator++(int); //postfisso
               iterator& operator--(); //--it
               iterator operator--(int); //it--
               nodo& operator*() const; //deferenziazione
               nodo* operator->() const; //accesso a memobro
               iterator operator+(unsigned int);
               iterator operator-(unsigned int);
    };
    class const_iterator{
        friend class Container<T>;
    private:
        nodo*p;
        const_iterator(nodo* = nullptr); //costruttore
     public:
        const_iterator();
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const nodo& operator*() const;
        const nodo* operator ->() const;
        const_iterator operator+(unsigned int);
        const_iterator operator-(unsigned int);

    };
    Container(); //costruttore di default
    Container(const Container&); //costruttore di copia
    ~Container();

    bool empty() const;

    void clear();
    void push_back(T*);
    void push_back(const T&);
    void erase(T*);
    iterator erase(iterator, iterator);
    iterator begin() const;
    iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    //iterator search(const DeepPtr<T>&) const;
    //void insert( T c);
    iterator search(const T&);
    const_iterator search(const T&) const;
    iterator insert(const iterator &, const T& );
};
//costruttore di iterator pubblico
template <class T>
Container<T>::iterator::iterator(): p(nullptr){}
//costruttore di iterator privato
template <class T>
Container<T>::iterator::iterator(nodo* a): p(a){}

//costruttore const_iterator
template <class T>
Container<T>::const_iterator::const_iterator(): p(nullptr){}

//costruttore a nodo
template<class T>
Container<T>::nodo::nodo(const DeepPtr<T>& i, nodo* p, nodo* n): info(i), prec(p), next(n){}
//distruttore a nodo
template<class T>
Container<T>::nodo::~nodo(){
    delete next;
}

//costruttore container default
template <class T>
Container<T>::Container():primo(nullptr), ultimo(nullptr), size_(0){}
//costruttore container con parametri
template <class T>
Container<T>::Container(const Container &c): primo(nullptr), ultimo(nullptr){
    primo=copia(c.primo, ultimo);
}

//costuttore di copia
template <class T>
Container<T>::~Container(){
    delete primo;
}

template<class T>
typename Container<T>:: nodo* Container<T>::copia(nodo* a, nodo*& l){ //forse non è giusta?!
    /*if(!n) return nullptr;
    nodo*p =new nodo;
    p->info =n->info;
    nodo*q=p;
    while(n->next){
        q->next=new nodo;
        n=n->next;
        q->next->prec=q;
        q=q->next;
        q->info=n->info;
        }
    q->next=nullptr;
    q=p;
    while(n->prec){
        q->prec=new nodo;
        n=n->prec;
        q->prec->next=q;
        q=q->prec;
        q->info=n->info;
    }
    q->prec=nullptr;
    return p;
   */
 /*   if(!a)
        return l=nullptr;
    nodo* temp= new nodo(a->info), *p =temp;
    while(a->next){
        p->next = new nodo(a->next->info, p);
        a=a->next;
        p=p->next;
    }
    l=p;
    return temp;

}

template<class T>
void Container<T>::distruggi(nodo*n){
    nodo*q;
    nodo*p=n->prec;
    while(n){
        q=n;
        n=n->next;
        delete q;
    }
    while(p){
        q=p;
        p=p->prec;
        delete q;
    }
}

//iteratore
template<class T>
bool Container<T>::iterator::operator==(const iterator& it) const{
return p==it.p;}

template<class T>
bool Container<T>::iterator::operator!=(const iterator& it) const{
    return p!=it.p;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator++(){
    p=p->next;
    return *this;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator++(int){
    iterator aux(*this);
    p=p->next;
    return aux;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator--(){
    p=p->prec;
    return *this;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator--(int){
    iterator aux(this);
    p=p->prec;
    return aux;
}


template<class T>
typename Container<T>::nodo& Container<T>::iterator::operator*()const{
    return *p;
}

template<class T>
typename Container<T>::nodo* Container<T>::iterator::operator->()const{
    return p;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator+(unsigned int x){
    iterator it;
    nodo* n=this->p;
    while(x){
        n=n->next;
        x=x-1;
    }
    it.p=n;
    return it;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator-(unsigned int x){
    iterator it;
    nodo* n=this->p;
    while(x){
        n=n->prec;
        x=x-1;
    }
    it.p=n;
    return it;
}

//const iteratore
template<class T>
bool Container<T>::const_iterator::operator==(const iterator& it) const{
    return p==it.p;
}

template<class T>
bool Container<T>::const_iterator::operator!=(const iterator& it) const{
    return p!=it.p;
}

template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator++(){
    p=p->next;
    return *this;
}

template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator++(int){
    iterator aux(this);
    p=p->next;
    return aux;
}

template<class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator--(){
    p=p->prec;
    return *this;
}

template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator--(int){
    iterator aux(this);
    p=p->prec;
    return aux;
}

template<class T>
const typename Container<T>:: nodo& Container<T>::const_iterator::operator*()const{
    return *p;
}

template<class T>
const typename Container<T>::nodo* Container<T>::const_iterator::operator->()const{
    return p;
}

template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator+(unsigned int x){
    const_iterator cit;
    nodo* n=this->p;
    while(x){
        n=n->next;
        x=x-1;
    }
    cit.p=n;
    return cit;
}
template<class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator-(unsigned int x){
    const_iterator cit;
    nodo* n=this->p;
    while(x){
        n=n->prec;
        x=x-1;
    }
    cit.p=n;
    return cit;
}

//container
template<class T>
bool Container<T>::empty() const{
    return primo;
}

template<class T>
void Container<T>::clear(){
     canc(begin(),end());
}

//cbeg e cend
template <typename T>
typename Container<T>::const_iterator Container<T>::cbegin() const{
    return const_iterator(primo);
}
template <typename T>
typename Container<T>::const_iterator Container<T>::cend() const{
    return const_iterator(ultimo);
}
//INSERT
template <class T>
typename Container<T>::iterator Container<T>::insert(const iterator &postion, const T &t){
    if(primo ==  nullptr){ //vuota
        ultimo = primo = new nodo(t, nullptr, nullptr);
        size_=1;
        return iterator(primo);
    }
        //non vuota
    nodo* a= new nodo( t, postion.p->prec, postion.p);
    (postion.p != primo) ? postion.p->prec->next = a : primo=a;
    (postion.p != ultimo) ? postion.p->prec = a : ultimo= a;

    size_++;
    return postion.p->prec;


    //nodo* a=postion.p->prec;

    //nodo* f=new nodo(t, a, /*postion.p->prec*/ //nullptr);
   /*postion.p->prec=f;
   if(postion != begin())
       f->prec->next=f;
   else {
       primo=f;
   }*/


   // nodo*p=primo;
   // while(p!=postion->prec)
     //   p=p->next;
   // nodo*q=new nodo(t, p, postion);
    //return iterator(q);


   //return iterator(f);
   /*if(primo==NULL)
       primo=f;
   else{
       nodo*x=primo;
       while(x->next)
           x=x->next;
       x->next=f;
   }
}*/
/*}
template<class T>
void Container<T>::push_back(T* t){//oppure const T& t?
    nodo* p=primo;
    while(p->next){
        p=p->next;
    }
    p->next=new nodo(t,p,nullptr);
}

template <class T>
void Container<T>::push_back(const T &t){
     insert(end(), t);

    // nodo* p=primo;
   // while(p->next)
  //      p=p->next;
    //nodo*a =new nodo(t, p, nullptr);
    //p->next=new nodo(t,p,nullptr);
    /*nodo* u=ultimo;
    while(u->next)
        u=u->next;
    u->next=new nodo(t, u, nullptr);*/
/*   }

template<class T>
typename Container<T>::iterator Container<T>::begin() const{
   return iterator(primo);

}

template<class T>
typename Container<T>::iterator Container<T>::end() const{
    /*iterator it;
    nodo* n=primo;
    while(n->next){
        n=n->next;
    }
    it.p=n->next;
    return it;
*/
  /*  return iterator(ultimo->next);
}

template<class T>
void Container<T>::erase(T* w){
    //return canc(it,it);
    nodo* x;
    nodo* z=this->primo;
    while(z && primo==z){
        if(((z->info)) !=NULL){
            nodo* temp= z;
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
        if(((z->info)) !=NULL){
            nodo* temp=z;
            z=z->next;
            x->next=z;
            temp->next=nullptr;
            delete temp;

        }
        else{
            x=x->next;
            z=z->next;
        }
    }
}

template<class T>
typename Container<T>::iterator Container<T>::erase(iterator it1, iterator it2){
    /*nodo* n=it2->next;
    if(it1.p!=primo){
        it1->prec->next=n;
        it1->prec=nullptr;
        it2->next=nullptr;
        distruggi(it1.p);
        iterator it;
        it.p=n;
        return it;
    }
    else{
        primo=n;
        it2->next=nullptr;
        distruggi(it1.p);
        iterator it;
        it.p=n;
        return it;
    }
    */
 /*   while(it1 != it2){
        erase(it1);
        it1++;
    }
    return it2;
}



template<class T>
typename Container<T>::iterator Container<T>::search( const T& t) {
    iterator it=begin();
    for(; it!=end() && it->info!=t; it++);
    return it;
}

template<class T>
typename Container<T>::const_iterator Container<T>::search(const T&t) const{
    const_iterator cit=cbegin();
    for(; cit!=cend() && *cit != t; cit++);
    return cit;
}
*/
#endif // CONTAINER_H
