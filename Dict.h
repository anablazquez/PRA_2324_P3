#ifndef DICT_H
#define DICT_H
#include <string>

template <typename V> 
class Dict {
    public:

	    virtual void insert(std::string key, V value);//{
	   // }
	    virtual V search(std::string key);//{
	   // }
	    virtual V remove(std::string key);//{
	   // }
	    virtual int entries();//{
	   // }

        // ... aquí los métodos virtuales puros
};

#endif
