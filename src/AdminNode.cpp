/** 
* @file AdminNode.cpp
* @description Admin node sınıfının gövdesi
* @course Birinci öğretim C grubu
* @assignment 1. Ödev
* @date 15.11.2022
* @author burak ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "AdminNode.hpp"

AdminNode::AdminNode(SatirListesi* data)//Kurucu sınıf
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}