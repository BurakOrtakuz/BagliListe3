/** 
* @file AdminNode.hpp
* @description Yönetici düğüm sınıfının gövdesi
* @course Birinci öğretim C grubu
* @assignment 1. Ödev
* @date 15.11.2022
* @author burak ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#if !defined(ADMINNODE_HPP)
#define ADMINNODE_HPP

#include "SatirListesi.hpp"

class AdminNode
{
public:
    AdminNode(SatirListesi* data);
    SatirListesi* data;
    AdminNode* next;
    AdminNode* prev;
};
#endif // ADMINNODE_HPP