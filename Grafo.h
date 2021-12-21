#ifndef _GRAFO_H_
#define _GRAFO_H_
#include <bits/stdc++.h>
#include<sstream>
#include<fstream>
#include "Nodo.h"
using namespace std;
template<class T, class A>
class Grafo{
    private:
        int nvertices=0;
        vector<list<Node<T,A>>> vertices;
    public:
        void crearGrafo();
        void insertarNodo(T dato);
        void insertarArista(A valor, T n1, T n2);
        void borrarNodo(T dato);
        void borrarArista(T n1, T n2);
        bool esVacio();
        bool existeNodo(T);
        bool sonAdyacentes();
        void verAdyacencias();
        void graficar();
        void print();
        void print(ofstream &);
};


template<class T, class A>
void Grafo<T,A>::crearGrafo(){
    nvertices = 0;
    for(list<Node<T,A>> &a: vertices){
        a.clear();
    }
    vertices.clear();
}

template<class T, class A>
bool Grafo<T,A>::existeNodo(T dat){
    for(list<Node<T,A>> a : vertices){
        if((*a.begin()).dato == dat)
            return true;
    }
    return false;
}


template<class T, class A>
void Grafo<T,A>::insertarNodo(T dato){
    Node<T,A> nuevo(dato);
    list<Node<T,A>> aux;
    aux.push_back(nuevo);
    if(existeNodo(dato)==false){
        vertices.push_back(aux);
        nvertices++;    
    }
    return;
}


template<class T, class A>
void Grafo<T,A>::insertarArista(A valor, T n1, T n2){
    for(list<Node<T,A>> &a : vertices){
        if((*a.begin()).dato == n1){
            Node<T,A> conex(n2,valor); /*Nuevo nodo conectado con el valor y el peso de la arista*/
            a.push_back(conex);
            return;      /*Se inserta a la lista*/
        }
    }
}

template<class T, class A>
void Grafo<T,A>::borrarNodo(T dato){
    for(list<Node<T,A>> &a: vertices){
        for(typename list<Node<T,A>>::iterator i = ++a.begin(); i!=a.end();++i){
            if( (*i).dato == dato){
                a.erase(i);
                break;
            }
        }
    }

    for (typename vector<list<Node<T,A>>>::iterator i = vertices.begin(); i != vertices.end(); i++){
        if( ( *( (i)->begin() ) ).dato == dato ){
            vertices.erase(i);
            nvertices--;
            break;
        }
    }

    return;
}

template<class T, class A>
void Grafo<T,A>::borrarArista(T n1, T n2){
    for(list<Node<T,A>> &a : vertices){
        if((*a.begin()).dato == n1){
            for(typename list<Node<T,A>>::iterator i = a.begin(); i!=a.end();++i){
                if((*i).dato == n2){
                    a.erase(i);
                    break;
                }
            }
            break;
        }
    }
}


template<class T, class A>
void Grafo<T,A>::print(ofstream &os) {
    for(list<Node<T,A>> a : vertices)
        os << (*a.begin()).dato << ";\n";
    for(list<Node<T,A>> a : vertices){
        for(Node<T,A> nodo : a){
            if(nodo.dato != (*a.begin()).dato ) 
                os << (*a.begin()).dato << "->" << nodo.dato << " [ label = " << nodo.ValArista << "];\n";
        }
    }
}

template<class T, class A>
void Grafo<T,A>::print(){
    ofstream os("Grafo.dot");
    os << "digraph G{\n";
    os << "label = Grafo;\n";
    os << "node [shape=circle color = black];\n";
    print(os);
    os << "}\n";
    os.close();
    system("dot Grafo.dot -o Grafo.png -Tpng");
    system("Grafo.png");
}
#endif
