#ifndef _GRAFO_H_
#define _GRAFO_H_
#include <bits/stdc++.h>
using namespace std;
template<class T>
class Grafo{
    private:
        int nvertices=0;
        vector<list<T>> vertices;
    public:
        void crearGrafo();
        void insertarNodo(T dato);
        void insertarArista(T valor, T n1, T n2);
        void borrarNodo(T dato);
        void borrarArista(T n1, T n2);
        bool esVacio();
        bool existeNodo(T);
        bool sonAdyacentes();
        void verAdyacencias();
        void graficar();
        void print();
};


template<class T>
void Grafo<T>::crearGrafo(){
    nvertices = 0;
    for(list<T> &a: vertices){
        a.clear();
    }
    vertices.clear();
}

template<class T>
bool Grafo<T>::existeNodo(T dat){
    for(list<T> a : vertices){
        if((*a.begin()) == dat)
            return true;
    }
    return false;
}


template<class T>
void Grafo<T>::insertarNodo(T dato){
    list<T> aux;
    aux.push_back(dato);
    if(existeNodo(dato)==false){
        vertices.push_back(aux);
        nvertices++;    
    }
    return;
}


template<class T>
void Grafo<T>::insertarArista(T valor, T n1, T n2){
    for(list<T> &a : vertices){
        if((*a.begin()) == n1){
            a.push_back(n2);
            return;      /*Se inserta a la lista*/
        }
    }
}

template<class T>
void Grafo<T>::borrarNodo(T dato){
    for(list<T> &a: vertices){
        if((*a.begin())==dato) continue;
        a.remove(dato);
    }
    for (typename vector<list<T>>::iterator i = vertices.begin(); i != vertices.end(); i++){
        if( ( *((*i).begin())) == dato ){
            vertices.erase((i));
            nvertices--;
            break;
        }
    }
    return;
}

template<class T>
void Grafo<T>::borrarArista(T n1, T n2){
    for(list<T> &a : vertices){
        if((*a.begin()) == n1){
            a.remove(n2);
            break;
        }
    }
    for(list<T> a : vertices){
        if((*a.begin()) == n2){
            a.remove(n1);
            return;
        }
    }
}


template<class T>
void Grafo<T>::print(){
    for(list<T> a : vertices){
        for(T nod : a ){
            cout << "[" << nod <<"]->";
        }
        cout << "\n";
    }
}
#endif
