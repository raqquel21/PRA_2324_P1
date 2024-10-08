#include <ostream>
#include "List.h"
#include "Node.h"

template typename<T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;
	public:
		ListLinked() : first(nullptr), n(0) {} // Inicializa los dos métodos de instancia
		~ListLinked(){ // Seguir los pasos
			while(first != nullptr){
				Node<T>* aux = first->next;
				delete first;
				first = aux;
			}
		}
		// Implementar los métodos de List.h
		void insert(int pos, T e) override {
			if (pos < 0 || pos > n){
				throw std::out_of_range("Error de rango! ");
			}
			if (pos == 0){ // Si solo hay un nodo lo situamos al principio
				first = new Node<T>(e, first); // First tendrá como argumento el e y la posición first
			} else {
				Node<T> *current = first; // Creamos un puntero que nos señale donde nos encontramos actualmente
				for (int i = 0; i < pos-1; i++){ // Recorre los elementos hasta llegar a la posición anterior de 
					current = current->next;
				}
				current->next = new Node<T>(e, current->next); // Añadimos el nodo con el argumento e
			}
			n++;
		}
		T remove (int pos) override {
			if (pos < 0 || pos > n){
				throw std::out_of_range("Error de rango! ");
			}
			Node<T>* to_delete;
			T elem_eliminado;

			if(pos == 0){
				to_delete = first;
				first = first->next;
			} else {
				Node<T>* current = first;
				for(int i = 0; i < pos -1; i++){
					current = current->next;
				}
				to_delete=current->next;
				current-next= to_delete-next;
			}
			elem_eliminado = to_delete->data;
			delete to_delete;
			n--;
			return elem_eliminado;

		}
		T get (int pos) override {
			if (pos < 0 || pos > n){
				throw std::out_of_range("Error de rango! ");
			}
			Node<T>* current = first;
			for (int i = 0; i < pos-1; i++){
				current = current->next;
			}
			return current->data;
		}
		int search (T e) override {
			Node<T>* current = first;
			for(int i = 0; i < n; i++){
				if(current->data == e){
					return i;
				}
				current = current->next;
			}
			return -1;
		}
		bool empty() override {
			return (n==0);
		}
		int size() override {
			return n;
		}
		T operator[](int pos){
			if(pos < 0 || pos >= n){
				throw std::out_of_range("Fuera de rango! ");
			}
			return get(pos);
		}
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>*current = list.first;
			out << "[";
			while(current != nullptr){
				out << current->data;
				if(current->next != nullptr){
					out << ",";
				}
				current = current->next;
			}
			out << "]";
			return out;
		}
};
