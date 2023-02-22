/** 
* @file SatirListesi.hpp
* @description SatirListesi sınıfının gövdesi
* @course Birinci öğretim C grubu
* @assignment 1. Ödev
* @date 14.11.2022
* @author burak ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#if !defined(SATIRLISTESI_HPP)
#define SATIRLISTESI_HPP

#include "Node.hpp"

class SatirListesi
{
public:
    int size;
    Node* first;
    Node* last;
    SatirListesi();
    ~SatirListesi();
    void add(int data);
    void deleteNode(int position);
    void clean();
    void print(int index,int kDelete);
    Node* yerBul(int sira);
};
#endif // SATIRLISTESI_HPP