#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include <string>
#include "../PRA_2324_P1/ListLinked.h"  

using namespace std;

template <typename V>
class HashTable: public Dict<V> {

    private:
      int h(std::string key){
	      int sum=0;
	       for( int i =0; i<key.length(); i++){
		        sum += int(key.at(i));}
	       return sum %max;

      }// funcion que calcula la posicion en la tabla hash de key
	int n;
       int max;
        ListLinked<TableEntry<V>>*table;

    public:
        HashTable(int size){
		table= new ListLinked<TableEntry<V>>[size];//metodo constructor
							   //memoria dinamica,
							   //basicamente un
							   //constructor de
							   //nodos.
		n=0;
		max=size;}//inicializar
		       
		       //
	~HashTable(){//libera solo memoria dinamica de table
		 for( int i=0; i<max;i++)//recorre toda la tabla 
			 table[i].~ListLinked();//y en cada indice de la tabla elimina listas
		delete[] table;}//como se ha creado con new se destruye asi y como es de arrays tiene los corchetes

	int capacity(){
		return max;}

	friend ostream& operator<<(std::ostream &out, const HashTable<V> &th){
		 out<<"HashTable[Entries: "<<th.n << ",Capacity:" <<th.max << "]\n" << "\n"; 
		 for(int i=0; i < th.max;i++){//recorremos tabla
			 out << "Cubeta : " <<i<< "\n";
			  out << th.table[i]<<std::endl;
		 }



		return out;

	}
	V operator[](std::string key){
		 int pos = table[h(key)].search(key);
		if(pos < 0)// no existe posicion
			throw std::runtime_error("clave no  encontrada");
		
		V aux = table[h(key)].get(pos).value;//devuelve valor correspondiente a jkey
		return aux;

		 }



	 void insert(std::string key, V value)override{
		 
		int pos = table[h(key)].search(key);//en la tabla con la posicion h(key) buscamos la key, si no esta nos drara posicion 0 pero si í que esta nos dara un numero entero
		//una tabla con size h_(key)  se busca la key, t devuyelve la posicion si esta
                if(pos >= 0)
                        throw std::runtime_error("Ya introducido");

		TableEntry<V> aux(key, value);//clase table entry con su key y su value(cada cubito, pues creas un cubito/nodo con su key y su value)
		table[h(key)].prepend(aux);//metes el nodo dentro de la Lista de nodos al principio
		n++;//aumenta tamaño cubetas ocupadas
				 //comprobar q no exista ya la key
				 }
	 V search(std::string key)override{// lo busca y si está q devuelva pos y value
		int hash = h(key);
		int pos = table[hash].search(key);// para buscar

                if(pos < 0)
                        throw std::runtime_error("No encontrado");

                V aux = table[hash].get(pos).value;// para q te muestre que hay en esta POSICIOn
                return aux;
		   }

	 V remove(std::string key)override{
	int pos = table[h(key)].search(key);//guardamosposicion

                if(pos > max || pos < 0)//fuera del rango 
                        throw std::runtime_error("No encontrado");

		V aux = table[h(key)].remove(pos).value;//llamamos a lss funciones de list
		n--;//dismuniumos cubetas
		return aux;}




	 int entries()override{ 
		 return n ;}
        
};

#endif
