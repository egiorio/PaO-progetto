#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class DeepPtr{
private:
    T* p;
public:
    explicit DeepPtr(const T* = nullptr); // costruttore che non crea una copia profonda
    DeepPtr(const DeepPtr&); //copia con clonazione polimorfa
    DeepPtr& operator=(const DeepPtr&);
    T* operator->() const;
    T& operator*() const;
    bool operator==(const DeepPtr& ) const;
    bool operator!=(const DeepPtr&)const;
    ~DeepPtr(); //distruttore polimorfo

};
template<class T>
bool DeepPtr<T>::operator==(const DeepPtr& x) const {
    //return (*(x.p)==*p) ;
    return p == x.p;
   }

template<class T>
bool DeepPtr<T>::operator!=(const DeepPtr& x) const{
    return !(x==*this);
}

template<class T>
DeepPtr<T>::DeepPtr(const T* q): p(q != nullptr ? q->clone() : nullptr){}
template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr& dp): p(dp.p != nullptr ? (dp.p)->clone() : nullptr){}
template<class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& dp){
    if(this != &dp){
        if(p != nullptr)
            delete p; //distruzione polimorfa implementata in T
        p = (dp.p != nullptr ? (dp.p)->clone() : nullptr);
    }
    return *this;
}
template<class T>
T* DeepPtr<T>::operator->() const{
    return p;
}
template<class T>
T& DeepPtr<T>::operator*() const{
    return *p;
}
template<class T>
DeepPtr<T>::~DeepPtr(){ if(p != nullptr) delete p; }


#endif // DEEPPTR_H
