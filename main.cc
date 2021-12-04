#include<iostream>
#include<vector>
#include "Grafo.h"
using namespace std;



int main(){
    Grafo<int> G;
    G.crearGrafo();
    G.insertarNodo(5);
    G.insertarNodo(5);
    G.insertarNodo(6);
    G.insertarNodo(8);
    G.insertarNodo(7);
    G.insertarArista(0,5,7);
    G.insertarArista(0,7,8);
    G.insertarArista(0,5,6);
    G.insertarArista(0,8,6);
   //G.borrarArista(5,7);
    G.borrarNodo(5);
    G.print();

    return 1;
}
