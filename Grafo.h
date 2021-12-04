#ifndef GRAFO_H
#define GRAFO_H
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
template<class T>
class Grafo{
    private:
        int nvertices=0;
        vector<list<Node<T>>> vertices;
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
    for(list<Node<T>> &a: vertices){
        a.clear();
    }
    vertices.clear();
}

template<class T>
void Grafo<T>::insertarNodo(T dato){
    Node<T> nuevo(dato,NULL);
    list<Node<T>> aux;
    aux.push_back(nuevo);
    if(existeNodo(dato)==false){
        vertices.push_back(aux);
        nvertices++;    
    }
    return;
}


template<class T>
void Grafo<T>::insertarArista(T valor, T n1, T n2){
    for(list<Node<T>> &a : vertices){
        if((*a.begin()).dato == n1){
            Node<T> conex(n2,valor); //Nuevo nodo conectado con el valor y el peso de la arista/
            a.push_back(conex);
            break;      //Se inserta a la lista/
        }
    }

    for(list<Node<T>> &a : vertices){
        if((*a.begin()).dato == n2){
            Node<T> conex(n1,valor); //Nuevo nodo conectado con el valor y el peso de la arista/
            a.push_back(conex);      //Se inserta a la lista/
            return;
        }
    }
}

template<class T>
void Grafo<T>::borrarNodo(T dato){
    for (auto i = vertices.begin(); i != vertices.end(); i++){
        if( ( *((*i).begin())).dato == dato ){
            vertices.erase(i);
            nvertices--;
        }
    }
    for(list<Node<T>> a: vertices){
        for(auto i = a.begin(); i!=a.end();++i){
            if((*i).dato == dato){
                a.erase(i);
            }
        }
    }
    return;
}

template<class T>
void Grafo<T>::borrarArista(T n1, T n2){
    for(list<Node<T>> a : vertices){
        if((*a.begin()).dato == n1){
            for(auto i = a.begin(); i!=a.end();++i){
                if((*i).dato == n2){
                    a.erase(i);
                    break;
                }
            }
            break;
        }
    }
    for(list<Node<T>> a : vertices){
        if((*a.begin()).dato == n2){
            for(auto i = a.begin(); i!=a.end();++i){
                if((*i).dato == n1){
                    a.erase(i);
                    return;
                }
            }
        }
    }
}

template<class T>
bool Grafo<T>::esVacio(){

}

template<class T>
bool Grafo<T>::existeNodo(T dat){
    for(list<Node<T>> a : vertices){
        if((*a.begin()).dato == dat)
            return true;
    }
    return false;
}

template<class T>
bool Grafo<T>::sonAdyacentes(){
    
}

template<class T>
void verAdyacencias();

template<class T>
void graficar();

template<class T>
void Grafo<T>::print(){
    for(list<Node<T>>a : vertices){
        for( Node<T> nod : a ){
            cout << "[" << nod.dato << ", " << nod.ValArista << "]->";
        }
        cout << "\n";
    }
}
#endif
