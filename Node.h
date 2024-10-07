#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
	public:
		// Atributos
		T data;
		Node<T>* next;
		//Métodos
		//Constructor:
		Node (T data, Node<T>* next=nullptr);
		//Imprimir data	
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << node.data;
			return out;
};

#endif
