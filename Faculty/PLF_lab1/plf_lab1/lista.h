//#pragma once
//#include <iostream>
//class Node {
//public:
//	Node(int e);
//
//private:
//	Node* next;
//	int elem;
//};
//
//class List {
//	Node head = NULL;
//};

#ifndef LISTA_H
#define LISTA_H


//tip de data generic (pentru moment este intreg)
typedef int TElem;

//referire a structurii Nod;
struct Nod;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef Nod *PNod;

typedef struct Nod {
	TElem e;
	PNod urm;
};

typedef struct {
	//prim este adresa primului Nod din lista
	PNod _prim;
} Lista;

//operatii pe lista - INTERFATA

//crearea unei liste din valori citite pana la 0
Lista creare();
//tiparirea elementelor unei liste
void tipar(Lista l);
// destructorul listei
void distrug(Lista l);

int len(Lista l);

void isInList(int elem);

//returns the list without its first element
Lista sublista(Lista l);

Lista listaVida();


#endif
