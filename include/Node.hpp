/** 
* @file Node.hpp
* @description Node sınıfının kafası
* @course Birinci öğretim C grubu
* @assignment 1. Ödev
* @date 14.11.2022
* @author burak ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#if !defined(NODE_HPP)
#define NODE_HPP

class Node
{
public:
    Node(int data);
    int data;
    Node* next;
    Node* prev;
};
#endif // NODE_HPP