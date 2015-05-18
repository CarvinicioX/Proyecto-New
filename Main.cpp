#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "TDAList.h"
#include "LinkedList.h"
#include "FSArrayList.h"
#include "FSCursorList.h"
#include "Integer.h"
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
	srand(time(0));
	ofstream insertfile("insert.txt");
	ofstream removefile("remove.txt");
	ofstream firstfile("first.txt");
	ofstream lastfile("last.txt");
	ofstream indexOffile("indexOf.txt");
	ofstream getfile("get.txt");
	double TiempoEjecucion;
	time_t Inicio, Fin;
	TDAList* LinkedList1 = new LinkedList();
	TDAList* FSArrayList1 = new FSArrayList(1000);
	TDAList* FSCursorList1 = new FSCursorList(1000);
	int Posit[1000];
	bool Entro = false;
	for (int i = 0; i < 1000; i++) {
		int Ran = rand()%1000;
		for (int j = 0; j < 1000; j++) {
			if (Ran == Posit[j]) {
				Entro = true;
				break;
			}
		}
		if (!Entro) {
			Posit[i] = Ran;
		} else {
			i--;
		}
		Entro = false;
	}
	//Prueba de insert en las tres Implementaciones
	for (int i = 0; i < 1000; i++) {
		stringstream ss;
		Inicio = clock();
		FSArrayList1->insert(new Integer(i), Posit[i]);
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		LinkedList1->insert(new Integer(i), Posit[i]);
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		FSCursorList1->insert(new Integer(i), Posit[i]);
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		if (insertfile.is_open()) {
			insertfile << ss.str() << "\n";
		}
	}
	insertfile.close();
	cout << "Perfect 1" << endl;
	//Prueba de first en las tres Implementaciones
	for (int i = 0; i < 1000; i++) {
		stringstream ss;
		Inicio = clock();
		FSArrayList1->first();
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		LinkedList1->first();
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		FSCursorList1->first();
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		if (firstfile.is_open()) {
			firstfile << ss.str() << "\n";
		}
	}
	firstfile.close();
	cout << "Perfect 2" << endl;
	//Prueba de get en las tres Implementaciones
	for (int i = 0; i < 1000; i++) {
		stringstream ss;
		Inicio = clock();
		FSArrayList1->get(Posit[i]);
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		LinkedList1->get(Posit[i]);
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		FSCursorList1->get(Posit[i]);
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		if (getfile.is_open()) {
			getfile << ss.str() << "\n";
		}
	}
	getfile.close();
	cout << "Perfect 3" << endl;
	//Prueba de indexOf en las tres Implementaciones
	for (int i = 0; i < 1000; i++) {
		stringstream ss;
		Inicio = clock();
		FSArrayList1->indexOf(new Integer(i));
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		LinkedList1->indexOf(new Integer(i));
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		Inicio = clock();
		FSCursorList1->indexOf(new Integer(i));
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		if (indexOffile.is_open()) {
			indexOffile << ss.str() << "\n";
		}
	}
	indexOffile.close();
	cout << "Perfect 4" << endl;
	//Prueba de last en las tres Implementaciones
	for (int i = 0; i < 1000; i++) {
		stringstream ss;
		Inicio = clock();
		FSArrayList1->last();
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		if (LinkedList1->getSize() < Posit[i]) {
			Inicio = clock();
			LinkedList1->last();
			Fin = clock();
			TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
			ss << TiempoEjecucion << ",";
		}
		Inicio = clock();
		FSCursorList1->last();
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		ss << TiempoEjecucion << ",";
		if (lastfile.is_open()) {
			lastfile << ss.str() << "\n";
		}
	}
	lastfile.close();
	cout << "Perfect 5" << endl;
	//Prueba de remove en las tres Implementaciones
	for (int i = 0; i < 1000; i++) {
		stringstream ss;
		Inicio = clock();
		FSArrayList1->erase(Posit[i]);
		Fin = clock();
		TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		if (LinkedList1->getSize() < Posit[i]) {
			ss << TiempoEjecucion << ",";
			Inicio = clock();
			LinkedList1->erase(Posit[i]);
			Fin = clock();
			TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		}
		if (FSCursorList1->getSize() < Posit[i]) {
			ss << TiempoEjecucion << ",";
			Inicio = clock();
			FSCursorList1->erase(Posit[i]);
			Fin = clock();
			TiempoEjecucion = (double)(Fin - Inicio)/(double)CLOCKS_PER_SEC;
		}
		ss << TiempoEjecucion << ",";
		if (removefile.is_open()) {
			removefile << ss.str() << "\n";
		}
	}
	removefile.close();
	cout << "Perfect 6" << endl;
	return 0;
}