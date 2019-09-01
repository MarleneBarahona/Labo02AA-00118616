#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
}*inicio,*fin;

class Pila{
	public:
		Nodo* crearNodo(int valor){
			Nodo *n = new Nodo;
			n->dato = valor;
			n->sig = nullptr;
			return n;
		}
		void push(int valor){
			Nodo *n = crearNodo(valor);
			n->sig = inicio;
			inicio = n;
		}
		void pop(){
			Nodo *temp = inicio;
			inicio = inicio->sig;
			free(temp);
		}
		void mostrarPila(){
			Nodo *temp = inicio;
			if(!inicio){
				printf("Pila vacia");
			}else{
			    printf("Esto es una Pila ");
				while(temp){
					printf("%d, ",temp->dato);
					temp = temp->sig;
				}
			}
		}
		Pila(){
			inicio = nullptr;
		}
};

class Cola{
	public:
		Nodo* crearNodo(int valor){
			Nodo *n = new Nodo;
			n->dato = valor;
			n->sig = nullptr;
			return n;
		}
		void push(int valor){
			Nodo *n = crearNodo(valor);
			if(!inicio){
			    inicio = n;
			    fin = n;
			}else{
			    fin->sig = n;
			    fin = n;
			}
		}
		void pop(){
			Nodo *temp = inicio;
			inicio = inicio->sig;
			free(temp);
		}
		void mostrarCola(){
			Nodo *temp = inicio;
			if(!inicio){
				printf("Cola vacia");
			}else{
			    printf("Esto es un Cola ");
				while(temp){
					printf("%d, ",temp->dato);
					temp = temp->sig;
				}
			}
		}
		
		void invertirCola(){
		    Nodo *temp = inicio;
		    //fin->sig = inicio;
		    Nodo *temp2;
		    Nodo *temp3 = fin;
		    while(temp->sig){
		        //printf("%d,",temp->dato);
		        //fin->sig = inicio;
		        temp2 = temp;
		        //fin->sig = temp2;
		        temp = temp->sig;
		    }
		    //temp2 = temp;
		    inicio->sig = temp3;
		    temp3->sig = temp2;
		    temp2->sig = inicio->sig;
		    inicio->sig = nullptr;
		    mostrarCola();
		    //fin = temp;
		    //temp2 = fin;
		    //temp->sig = nullptr;
		}
		/*void invertirCola(){
		    Nodo *temp = inicio;
		    invertir(fin);
		    fin = temp;
		    mostrarCola();
		}
		
		void invertir(Nodo *fin){
		    Nodo *temp2 = fin->sig;
		    if(temp2 != 0){
		        invertir(temp2);
		        inicio->sig = fin;
		        inicio = fin;
		        inicio->sig = 0;
		    }
		}*/
		
		/*void invertirCola(){
		    Nodo *temp = inicio;
		    int primero;
		    if(!inicio){
		        printf("Cola vacia");
		    }else {
		  		while(temp->sig){
		  		    temp->sig = temp;
					printf("%d, ",temp->dato);
					//inicio->dato = temp->dato;
					primero = temp->dato;
					temp = temp->sig;
				}
		        /*primero = inicio->dato;
		        inicio->dato = fin->dato;
		        fin->dato = primero;
		        mostrarCola();
		    }
		}*/
		
		Cola(){
			inicio = nullptr;
		}
};



int pasarColaAPila(Cola c){
    c.invertirCola();
}

int main(){
	Cola cola;
	cola.push(1);
	cola.push(2);
	cola.push(3);
	cola.push(4);
	cola.mostrarCola();
	//pasarColaAPila(cola);
	cola.invertirCola();
	//invertir(cola);
	/*Pila pila;
	pila.push(1);
	pila.push(2);
	pila.push(3);
	pila.push(4);
	pila.mostrarPila();*/
}
