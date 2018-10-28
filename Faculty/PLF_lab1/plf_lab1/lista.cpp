#include "lista.h"
#include <iostream>

using namespace std;


PNod creare_rec() {
	TElem x;
	cout << "x = ";
	cin >> x;
	if (x == 0)
		return NULL;
	else {
		PNod p = new Nod();
		p->e = x;
		p->urm = creare_rec();
		return p;
	}
}

Lista creare() {
	Lista l;
	l._prim = creare_rec();
	return l;
}

void tipar_rec(PNod p) {
	if (p != NULL) {
		cout << p->e << " ";
		tipar_rec(p->urm);
	}
}

void tipar(Lista l) {
	tipar_rec(l._prim);
}

void distrug_rec(PNod p) {
	if (p != NULL) {
		distrug_rec(p->urm);
		delete p;
	}
}

void distrug(Lista l) {
	//se elibereaza memoria alocata nodurilor listei
	distrug_rec(l._prim);
}

int len(Lista l)
{
	PNod n = l._prim;
	while (n != NULL) {
	}
}

bool eListaVida(Lista l) {
	if( l._prim == NULL)
		return true;
	return false;
}

void isInList(int elem){

}

Lista sublista(Lista l)
{
	Lista list = listaVida();
	Nod nod = *l._prim;
	list._prim = nod.urm;
	nod = *nod.urm;
	while (nod.urm != NULL) {

	}
}

Lista listaVida()
{
	Lista list = Lista();
	list._prim = NULL;
	return list;
}

