/** 
* @file YoneticiListesi.hpp
* @description YoneticiListesi sınıfının gövdesi
* @course Birinci öğretim C grubu
* @assignment 1. Ödev
* @date 15.11.2022
* @author burak ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#if !defined(YONETICILISTESI_HPP)
#define YONETICILISTESI_HPP

#include "AdminNode.hpp"

class YoneticiListesi
{
public:
    int size;
    AdminNode* first;
    AdminNode* last;
    YoneticiListesi();
    ~YoneticiListesi();
    void add(SatirListesi* data);
    void deleteNode(int position);
    void clean();
    void print(int index,int satirIndex,int kDelete=-1);
    void printHelper(AdminNode* temp,int choice, char character,int lineNumber,int space,int index);
    void sort();
    double calculateAvarege(Node* temp,int size);
    AdminNode yerBul(int sira);
};
#endif // YONETICILISTESI_HPP