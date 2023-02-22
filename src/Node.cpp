/** 
* @file Node.cpp
* @description Dugum sınıfının gövdesi
* @course Birinci öğretim C grubu
* @assignment 1. Ödev
* @date 14.11.2022
* @author burak ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "Node.hpp"

Node::Node(int data)//Kurucu sınıf
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}