#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
       int nelem;
	BSNode<T> *root; //miembros privados
	BSNode<T>* search(BSNode<T>* n, T e) const{

		 if(n == nullptr)
                        throw std::runtime_error("No encontrado");
                else if(n->elem == e)//el arbol/clase es n y n.elem es el primer elemento que correspone a la raiz y despues  se va desplazandfo   y la e es el elemento q queremos buscar 
                        return n;
                else if (n->elem > e)
                        return search(n->left, e);// se hace recursividad
                else{
			return search(n->right, e);
		}}

	BSNode<T>* insert(BSNode<T>* n, T e){
		if(n == nullptr)
		       	return new BSNode(e);//nodo  vacio
            else if(n->elem == e)
		    throw std::runtime_error("elemento duplicado ");
            else if(n->elem < e)
		    n->right = insert(n->right, e);
            else
		   n->left = insert(n->left, e);
            return n;
        }

	void print_inorder(std::ostream &out, BSNode<T>* n) const{
		if(n != nullptr){
                        print_inorder(out, n->left);
                        out<<n->elem<<" ";
                        print_inorder(out, n->right);
                }
                else
                        out<<"";
        }
	BSNode<T>* remove(BSNode<T>* n, T e){

	  if(n == nullptr)
		  throw std:: runtime_error("Elemento no encontrado");
            else if(n->elem < e)
			    n->right = remove(n->right,e);
            else if(n->elem > e)
		    n->left = remove(n->left, e);
            else{
                if(n->left != nullptr && n->right != nullptr){
                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                } else{//1 o 0
                    n = (n->left != nullptr) ? n->left : n->right;
                } 
            } 
            return n;
          

	}
	T max(BSNode<T>* n) const{
		if(n == nullptr)
			throw std::runtime_error("");
            else if(n->right != nullptr)//si el de la derecha no es 0
		    return max(n->right);
            else return n->elem;}// si si que es cero se devuelve el valor de la raiz como el maximo
		
	BSNode<T>* remove_max(BSNode<T>* n){
		if(n->right == nullptr) 
			return n->left;//se elimina la raiz y solo se te queda la parte izquierda del nodo
            else{
                n->right = remove_max(n->right);//elimina la parte derecha y te quedas con la raiz
                return n;
            }
        }
	void delete_cascade(BSNode<T>* n) {
            if(n != nullptr){
		    
            delete_cascade(n->left);
            delete_cascade(n->right);
            delete n;}
        } 


    public:
        BSTree(){//inicializamos a cero
	nelem=0;
	root=nullptr;}	// miembros públicos
    
	int size() const {
	
	return nelem;}
	T search(T e){
		return search(root, e)->elem;}//devuelve el elemento contenido por el nodo devuelto por el metodo privado
	T operator[](T e) const{

		return search(e);}
	 void insert(T e){
		 root=insert(root,e);
		 nelem++;}
	 friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
	if(bst.root != nullptr)
		       bst.print_inorder(out,bst.root);
                return out; }

	 void remove(T e){
		 root=remove(root,e);}


	 ~BSTree(){
		 delete_cascade(root);
        }
};

#endif
