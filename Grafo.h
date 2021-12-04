#ifndef _GRAFO_H_
#define _GRAFO_H_
#include <bits/stdc++.h>
#include<fstream>
using namespace std;
template<class T>
class Grafo{
    private:
        int nvertices=0;
        vector<list<T>> vertices;
        vector<list<T>> verticesad;
    public:
        void crearGrafo();
        void insertarNodo(T dato);
        void insertarArista(T valor, T n1, T n2);
        void insertarAristaAd(T valor, T n1, T n2);
        void borrarNodo(T dato);
        void borrarArista(T n1, T n2);
        bool esVacio();
        bool existeNodo(T);
        bool sonAdyacentes(T,T);
        void verAdyacencias();
        void graficar(string file);
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
void Grafo<T>::insertarNodo(T dato){
    list<T> aux;
    aux.push_back(dato);
    if(existeNodo(dato)==false){
        vertices.push_back(aux);
        verticesad.push_back(aux);
        nvertices++;    
    }
    return;
}


template<class T>
void Grafo<T>::insertarArista(T valor, T n1, T n2){
    insertarAristaAd(valor,n1,n2);
    if(valor == 0) return;
    for(list<T> &a : vertices){
        if((*a.begin()) == n1){
            a.push_back(n2);
            return;      /*Se inserta a la lista*/
        }
    }
}

template<class T>
void Grafo<T>::insertarAristaAd(T valor, T n1, T n2){
    if(valor == 0) return;
    for(list<T> &a : verticesad){
        if((*a.begin()) == n1){
            a.push_back(n2);
            break;      /*Se inserta a la lista*/
        }
    }

    for(list<T> &a : verticesad){
        if((*a.begin()) == n2){
            a.push_back(n1);      /*Se inserta a la lista*/
            return;
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
    for(list<T> &a: verticesad){
        if((*a.begin())==dato) continue;
        a.remove(dato);
    }
    for (typename vector<list<T>>::iterator i = verticesad.begin(); i != verticesad.end(); i++){
        if( ( *((*i).begin())) == dato ){
            verticesad.erase((i));
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
            break;
        }
    }
    for(list<T> &a : verticesad){
        if((*a.begin()) == n1){
            a.remove(n2);
            break;
        }
    }
    for(list<T> a : verticesad){
        if((*a.begin()) == n2){
            a.remove(n1);
            break;
        }
    }
}

template<class T>
bool Grafo<T>::esVacio(){
    if(nvertices == 0)return true;
    return false;
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
bool Grafo<T>::sonAdyacentes(T n1, T n2){
    for(list<T> a : vertices){
        if((*a.begin()) == n1){
            for(T nod : a){
                if(nod == n2) 
                    return true;
            }
        }
    }
    return false;
}

template<class T>
void Grafo<T>::verAdyacencias(){
    sort(verticesad.begin(), verticesad.end());
    for(list<T> a : verticesad){
        for(T nod : a ){
            cout << "[" << nod <<"]->";
        }
        cout << "\n";
    }
}

template<class T>
void Grafo<T>::graficar(string file){
    ofstream archivo;
    archivo.open(file.c_str(),ios::out);
    archivo << "graph {\n";
    sort(vertices.begin(), vertices.end());
    for(list<T> a : vertices){
        for(T nod : a ){
            if(*a.begin() != nod){
                archivo << *a.begin() <<"--"<< nod <<";\n"; 
            }
        }
    }
    archivo << "}\n";
    archivo.close();
}

#endif
