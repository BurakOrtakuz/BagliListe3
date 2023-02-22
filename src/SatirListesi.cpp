#include "SatirListesi.hpp"
#include <iostream>
#include <iomanip>

SatirListesi::SatirListesi()
{
    size = 0;
    first = nullptr;
    last = nullptr;
}
SatirListesi::~SatirListesi()
{
    clean();
}
void SatirListesi::add(int data)
{
    Node* temp= new Node(data);
    if(first==nullptr)//İlk elemanın eklenmesi durumu
    {
        first=temp;
        last=temp;
        size++;
    }else{//İlk sırada olmayan elamanların eklenmesi durumu
        last->next=temp;
        temp->prev=last;
        last = temp;
        size++;
    }
}
void SatirListesi::deleteNode(int position)//bool çevir ve yazdırma ile haberleş
{
    if(size==0)//Elaman olmaması durumu
        return;
    if(size==1)//tek eleman olması durumu
    {
        first = nullptr;
        last = nullptr;
        size--;
        return;
    }

    Node* temp = first;
    
    if(position == 1)//İlk elemanı silme durumu
    {
        first = temp->next;
        delete temp;
        size--;
        return;
    }
    
    int i = 1;
    
    while(temp != nullptr)//Silinecek elemanı arıyoruz
    {
        if(i==position)
            break;
        i++;
        temp = temp->next;
    }
    if(temp != last)//Son eleman olmaması durumu
    {              
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

    }else{//Son eleman olması durumu
        temp->prev->next = nullptr;
        last = temp->prev;
        delete temp; 
    }
    size--;
}
void SatirListesi::clean()
{
    for(int i = size; i > 0; i--)
    {
        deleteNode(i);
    }
}

void SatirListesi::print(int index,int kDelete)
{
    int lineNumber = 11;
    int space = 5;
    int count= 0;
    int lineSpace= index *(lineNumber)+((index)*space);
    Node* temp=first;

    std::cout<< std::setw(lineSpace+1);// ^ kısmı
    for(int i=0; i < lineNumber; i++)
    {
        std::cout<< "^";
    }

    while(temp != nullptr)
    {
        //Bulunduğu düğüm adresi 
        std::cout<< std::endl;
        std::cout<< std::setw(lineSpace+lineNumber-1);
        std::cout<<temp<<std::endl;

        //Bulunduğu düğümün verisi
        std::cout<< std::setw(lineSpace+1);
        for(int i=0; i < lineNumber; i++)
        {
            std::cout<< "-";
        }
        std::cout<< std::endl;
        std::cout<< std::setw(lineSpace+1)<< "|"<<std::setw(lineNumber-2)<<temp->data<<"|";
        std::cout<< std::endl; 

        //Bulunduğu düğümün sonrakinin adresi
        std::cout<< std::setw(lineSpace+1);
        for(int i=0; i < lineNumber; i++)
        {
            std::cout<< "-";
        }
        //K delete noktası
        if(count==kDelete)
        {
            std::cout<<"<--- silinecek secili";
        }
        std::cout<< std::endl; 
        std::cout<< std::setw(lineSpace+1)<< "|"<<std::setw(lineNumber-2)<<temp->next<<"| ";
        std::cout<< std::endl; 
        std::cout<< std::setw(lineSpace+1);
        for(int i=0; i < lineNumber; i++)
        {
            std::cout<< "-";
        }
        std::cout<<std::endl;
        temp = temp->next;
        count++;
    }

}
