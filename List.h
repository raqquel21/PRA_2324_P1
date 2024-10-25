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

#endif
