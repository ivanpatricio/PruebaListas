#include "Lista.h"



Lista::Lista()
{
}

void Lista::insertar(int datito)
{
	Lista* nuevo;
	nuevo = new Lista();
	nuevo->setDato(datito);
	if (primero == NULL) {
		nuevo->setSig(nuevo);
		primero = nuevo;
		ultimo = nuevo;
		return;
	}
	ultimo->setSig(nuevo);
	primero->setAnt(nuevo);
	nuevo->setSig(primero);
	primero = nuevo;
}

bool Lista::eliminar(int datito, int contN)
{
	Lista* aux;
	aux = primero;
	Lista* anterior;
	anterior = NULL;
	Lista* eliminar;
	if (primero == NULL) {
		cout << "Lista se encuentra Vacia" << endl;
	
	}
	do {
		if (aux->getDato() == datito) {
			return true;
			if (aux == primero) {

				primero = primero->getSig();
				ultimo->setSig(primero);

			}
			else if (aux == ultimo) {

				ultimo = anterior;
				ultimo->setSig(primero);

			}
			else {

				anterior->siguiente = aux->siguiente;
				aux->siguiente->atras = anterior;

			}

		}
		contN--;
		anterior = aux;
		aux = aux->getSig();
	} while (aux != primero||contN>0);
	return false;
}


void Lista::setDato(int datito)
{
	Dato = datito;
}

int Lista::getDato()
{
	return Dato;
}

void Lista::setSig(Lista * sig)
{
	siguiente = sig;
}

Lista * Lista::getSig()
{
	return siguiente;
}

void Lista::imprimir()
{
	Lista* aux;
	aux = primero;
	if (primero == NULL) {
		cout << "Lista se encuentra Vacia" << endl;
	}
	else {
		do {
			printf(" %d    ", aux->getDato());
			aux = aux->getSig();
		} while (aux != primero);
	}
}



void Lista::setAnt(Lista * ant)
{
	atras = ant;
}

Lista * Lista::getAnt()
{
	return atras;
}


Lista::~Lista()
{
}

















void Lista::imprimir1(int datito)
{
	Lista* aux;
	aux = primero;
	if (primero == NULL) {
		cout << "Lista se encuentra Vacia" << endl;
	}
	else {
		do {
			if (datito != aux->getDato()) {

				printf(" %d    ", aux->getDato());
			}
			aux = aux->getSig();
		} while (aux != primero);
	}
}