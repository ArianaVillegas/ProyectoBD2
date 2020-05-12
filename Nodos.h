#ifndef NODO_H
#define NODO_H 
#define GRADO 3 //TAMANO DE HIJOS DE UN NODO
#include <string.h>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <stdio.h>
#include "STRING.h"
using namespace std; 
/*

template <typename ID>
class BTree; 

template <typename ID>
class Node {

public: 
    vector<ID> keys; //tamano = Grado-1
    bool isLeaf;

    template<class>
    Node() = default;
    friend class BTree; 
};
 
template<typename ID> 
class Nodo_normal: public Node<ID>{
public:
    vector<string> childs;

    Nodo_normal( bool isLeaf ) :  isLeaf(isLeaf) {};
    
    template<class>
    friend class BTree; 
};
*/



template< typename ID> 
class Node {
    public:
    STRING childs[GRADO+1]; //tamaño igual a GRADO (+1 de overflow)
    ID keys[GRADO]; //tamano = Grado-1(+1 de overflow)
    bool isLeaf;
    int size;           // falta poner en el constructor 
    int position;
    Node ( bool isLeaf ) : isLeaf(isLeaf),size(0),position(-1) {};
    Node ( ) : size(0),position(-1) {};
    void print_node(){
        for(int i=0;i<size;i++){
            cout<<" "<<keys[i];
        }
        cout<<endl;
        for(int i=0;i<size;i++){
            childs[i].print();
        }
        if(!isLeaf){
            childs[2].print(); 
        }        
        cout<<endl;
    }


    template<class>
    friend class BTree;

    void insert_keys(Node<ID> &second,int start,int end){
        int helper=0;
        for (int i=start;i<end;i++){
            second.keys[helper]=this->keys[i];
            helper++;
            second.size++;
        }

    }
    void erase_keys(int start,int end){
        size-=(end-start);
    }

    void insert_childs(Node<ID> &second,int start,int end){
        int helper=0;
        for (int i=start;i<end;i++){
            second.childs[helper]=this->keys[i];
            helper++;
        }
    }

};

/**
     * @param node the node you are trying to read
     * @param position the logical position you are trying to read 
     * */
template<typename ID>
bool cargar_nodo(Node<ID> &node,int position){
    fstream pagina;
    pagina.open("nodos.txt",ios::binary|ios::in );

    pagina.seekg(0,ios::end);
    int size=pagina.tellg();

    if(size==0){
        return false;
    }

    pagina.seekg(position*sizeof(node),ios::beg);
    pagina.read((char *)&node,sizeof(node ));
    pagina.close();
    return true;
}



template<typename ID>
void escribir_nodo(Node<ID> &node){
    fstream pagina;
    if(node.position==-1){
        pagina.open("nodos.txt",ios::binary|ios::app |ios::out);
        pagina.write((char*) &node,sizeof(node) );
        pagina.close();
    }
    else{
        pagina.open("nodos.txt",ios::binary |ios::out);
        pagina.seekp(node.position*sizeof(node));
        pagina.write((char*) &node,sizeof(node) );
        pagina.close();
            
     }

}




#endif 