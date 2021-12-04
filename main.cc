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
    G.graficar(insertarA);
    system("dot -Tjpg -O vacio.dot");
    system("vacio.dot.jpg");
    G.insertarNodo(5);
    G.insertarNodo(5);
    G.insertarNodo(6);
    G.insertarNodo(8);
    G.insertarNodo(7);
    G.graficar(insertarN);
    system("dot -Tjpg -O insertarN.dot");
    system("insertarN.dot.jpg");
    system("pause");
    //Insertar aristas, solo 1 o 0
    G.insertarArista(1,5,7);
    G.insertarArista(0,7,8);
    G.insertarArista(1,5,6);
    G.insertarArista(0,8,6);
    G.graficar(insertarA);
    system("dot -Tjpg -O insertarA.dot");
    system("insertarA.dot.jpg");
    system("pause");
    G.borrarArista(5,7);
    G.graficar(insertarA);
    system("dot -Tjpg -O borrarA.dot");
    system("borrarA.dot.jpg");
    system("pause");
    G.borrarNodo(5);
    G.graficar(borrarN);
    system("dot -Tjpg -O borrarN.dot");
    system("borrarN.dot.jpg");
    system("pause");
    cout<<G.esVacio()<<endl;
    cout<<G.sonAdyacentes(8,7)<<endl;
    cout<<"\nLista de adyacencia:\n";
    G.verAdyacencias();
    G.graficar(dibujo);
    system("dot -Tjpg -O dibujo.dot");
    system("dibujo.dot.jpg");
    system("pause");
    return 1;
}
