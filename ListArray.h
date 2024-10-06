#ifndef LISTARRAY_H
#define LISTARRAY_H
#include <ostream> // Para imprimir por pantalla
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> { // Clase derivada concreta 
	private:
		// Tenemos que definir e implementar los métodos heredados
		T* arr; // Puntero al array
		int max; // Tamaño actual del array
		int n; //Número de elementos que contiene la lista
		static const int MINSIZE = 2;
		void resize(int new_size){
			T* new_arr = new T[new_size];
			// Copiamos los elementos del viejos array al nuevo
			for (int i = 0; i < n; i++){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			// Actualizamos el tamaño del vector
			arr = new_arr;
			max = new_size;
		}
	public:
		// Constructor
		ListArray() : max[MINSIZE], n(0){
			arr = new T[MINSIZE];
		}
		// Destructor
		~ListArray(){
			delete[] arr;
		}

		// Añadir los método virtuales puros
		void insert(int pos, T e) override {
			if (pos < 0 || pos > n){
				throw std::out_of_range("Posición fuera del rango! ");
			}
			// Si el array está lleno se debe redimensionar
			if (n == max){
				resize(max * 2);
			}
			// Desplazar los elementos hacia la derecha
			for (int i = n; i > pos; i--){
				arr[i] = arr[i-1];
			}
			// Insertar el elmento
			arr[pos] = e;
			n++;
		}
		T remove(int pos) override {
			if (pos < 0 || pos >= n){
				throw std::out_of_range("Posición fuera del rango! ");
			}
			
			T remove_elem = arr[pos]; // Nombramos el elmento que queremos eliminar
			
			// Desplaza los elementos hacia la izquierda
			for (int i = pos; i < n; i++){
				arr[i] = arr[i+1];
			}
			n--;
			// Redimensionamos el array por si hay memoria sin usar
			if(n > 0 && n < (max / 4)){ // Si hay un cuarto de capacidad restante
				resize(max/2);
			}
			return remove_elem;
		}

		T get(int pos) override {
			if (pos < 0 || pos >= n){
				throw std::out_of_range("Posición fuera del rango! ");
			}
			return arr[pos];
		}

		int search (T e) override {
			for (int i = 0; i < n; i++){
				if (arr[i] == e){ return i;}
			}
			return -1; // No se ha encontrado
		}

		bool empty() override {
			return n == 0; // Comparador
		}

		int size() override {
			return n;
		}

		// Sobrecarga del operador []
		T operator[] (int pos){ // Es igual que la función get
			if (pos < 0 || pos >= n){
				throw std::out_of_range("Posición fuera del rango! ");
			}
			return arr[pos];
		}
		
		//Sobrecarga GLOBAL del operador <<
		friend std::ostream& operator << (std::ostream &out, const ListArray<T> &list){
			out << "[";
			for(int i = 0; i < list.n; i++){
				out << list.arr[i];
				if (i < list.n - 1){
					out << ",";
				}
			}
			out << "]";
			return out;
		}

};
#endif
