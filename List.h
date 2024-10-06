#ifndef LIST_H
#define LIST_H

#include <stdexcept> // Para usar std::out_of_range

template <typename T>
class List { // Clase abstracta pura (solo hay métodos virtuales)
	public:
		virtual void insert(int pos, T e) = 0;
		virtual void append(T e) { 		// append y prepend son dos instancias 
			insert(size(), e); 	// particulares de insert()
		}
		virtual void prepend(T e){
			insert(0, e);
		}
		virtual T remove(int pos) = 0;
		virtual T get (int pos) = 0;
		virtual int search (T e) = 0;
		virtual bool empty() = 0;
		virtual int size() = 0;
		// Destructor virtual para que las clases derivadas puedan limpiar 
		virtual ~List(){}

};





/*
template <typename T>
class ListArray { // Falta poner que es una clase derivada
	private:
		T* arr; // Puntero al arra
		int max; // Tamaño actual del array
		int n; //Número de elementos que contiene la lista
		static const int MINSIZE; // Deberá inicializarse a 2;
		void resize(int new_size);
	public:
		// Aquí los método virtuales puros
		ListArray();
		~ListArray();
		T operator[] (int pos);

		friend std::ostream& operator << (std::ostream &out, const ListArray<T> &list);

};
*/
#endif
