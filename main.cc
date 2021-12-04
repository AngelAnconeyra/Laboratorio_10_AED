#include<iostream>
#include<vector>
#include "Grafo.h"
using namespace std;
string vacio = "vacio.dot";
string insertarA = "insertarA.dot";
string insertarN = "insertarN.dot";
string borrarA = "borrarA.dot";
string borrarN = "borrarN.dot";
string dibujo = "dibujo.dot";


int main(){
    Grafo<int> G;
    G.crearGrafo();
    G.insertarNodo(5);
    G.insertarNodo(5);
    G.insertarNodo(6);
    G.insertarNodo(8);
    G.insertarNodo(7);
    //Insertar aristas, solo 1 o 0
    G.insertarArista(1,5,7);
    G.insertarArista(0,7,8);
    G.insertarArista(1,5,6);
    G.insertarArista(0,8,6);
    G.graficar(insertarA);
    system("dot -Tjpg -O insertarA.dot");
    system("insertarA.dot.jpg");
   //G.borrarArista(5,7);
    //G.borrarNodo(5);
    //cout<<G.esVacio()<<endl;
    //cout<<G.sonAdyacentes(8,7)<<endl;
    G.verAdyacencias();

    return 1;
}
