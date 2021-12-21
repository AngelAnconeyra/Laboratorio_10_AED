#include<iostream>
#include<vector>
#include <stdlib.h>
#include "Grafo.h"
using namespace std;



int main(){
    Grafo<string,int> G;
    G.crearGrafo();
    G.insertarNodo("Arequipa");
    G.insertarNodo("Sullana");
    G.insertarNodo("Lima");
    G.insertarNodo("Huanuco");
    G.insertarNodo("Chiclayo");
    G.insertarArista(1881,"Chiclayo","Arequipa");
    G.insertarArista(310,"Sullana","Arequipa");
    G.insertarArista(8000,"Lima","Huanuco");
    G.print();
   // G.borrarNodo("Arequipa");
   // G.print();

    return 1;
}
