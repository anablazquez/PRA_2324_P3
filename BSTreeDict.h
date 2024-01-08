#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
      BSTree<TableEntry<V>>* tree;  // modificar la clase table entry para la sobrecarga de operadores

    public:
     BSTreeDict(){
   tree = new BSTree<TableEntry<V>>;  }//vacio
   ~BSTreeDict(){
	    delete tree;}

   friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
		out<<*bs.tree;
		return out;

	}
   V operator[](std::string key){

		return search(key);}

   V remove(std::string key) override{
               V aux = search(key);
               tree->remove(key);
               return aux;
        }
	void insert(std::string key, V value) override{
		TableEntry<V> *aux = new TableEntry<V>(key, value);
		tree->insert(*aux);
		delete aux;

	}

	V search(std::string key) override{

		V aux = (tree->search(key)).value;
		return aux;
	}

	int entries() override{
		return tree->size();
	}
     
     
     
      // ...
        
};

#endif
