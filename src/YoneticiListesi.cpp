#include "YoneticiListesi.hpp"
#include <iostream>
#include <iomanip>
#include<string.h>
#include <fstream>

YoneticiListesi::YoneticiListesi()
{
    size = 0;
    first = nullptr;
    last = nullptr;
    SatirListesi* satirListesi;
    std::string data ="";

    std::ifstream reader("./veriler.txt");
    while(!reader.eof())
    {
        std::getline(reader,data);
        satirListesi= new SatirListesi();
        while(data!="")
        {
            satirListesi->add(stoi(data.substr(0,data.find_first_of(" "))));
            data=data.substr(data.find_first_of(" ")+1,data.length()-data.find_first_of(" "));
        }
        add(satirListesi);
    }
    reader.close();

    int index = 0;
    int lineIndex = 0;
    char choice;
    bool kDelete= false;
    int kDeleteNumber=-1;
    while(true)
    {
        system("cls");
        if(first==nullptr)
            break;
        print(index, lineIndex,kDeleteNumber);
        std::cin>>choice;

        switch (choice)
        {
            case 'a':
                if(index!=0)
                {
                    index--;
                }
                break;
            case 'd':
                if(index!=size/8 && size%8 !=0)
                {
                    index++;
                }
                if(index==size/8&&lineIndex>=size%8)
                {
                    lineIndex= size%8-1;
                }
                break;
            case 'c':
                if(lineIndex!=8)
                {
                    if(index!=size/8||lineIndex!=size%8-1)
                    {
                        lineIndex++;
                    }
                }
                if(index+1==size/8 && size%8 ==0&&lineIndex==8)
                {
                    lineIndex=7;
                }
                if(lineIndex==8 && index!=size/8)
                {
                    index++;
                    lineIndex=0;
                }
            break;
            case 'z':
                if(index!=0||lineIndex!=0)
                {
                    lineIndex--;
                }
                if(lineIndex==-1 && index!=0)
                {
                    index--;
                    lineIndex=7;
                }
            break;
            case 'p':
                deleteNode(index*8+lineIndex+1);
            break;
            case 'k':
                AdminNode*temp =first;
                for(int i=0;i<index*8+lineIndex;i++)
                {
                    temp=temp->next;
                }
                if(kDelete==false)
                {                 
                    kDeleteNumber= rand()%temp->data->size;
                    kDelete=true;
                }
                else 
                {
                    temp->data->deleteNode(kDeleteNumber+1);
                    if(temp->data->first==nullptr)
                    {
                        deleteNode(index*8+lineIndex+1);
                    }
                    kDelete=false;
                    kDeleteNumber=-1;
                }
            break;
        }

    }
}
YoneticiListesi::~YoneticiListesi()
{
    clean();
}
void YoneticiListesi::add(SatirListesi* data)
{
    AdminNode* temp= new AdminNode(data);
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
void YoneticiListesi::deleteNode(int position)
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

    AdminNode* temp = first;
    
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
void YoneticiListesi::clean()
{
    for(int i = size; i > 0; i--)
    {
        deleteNode(i);
    }
}

void YoneticiListesi::print(int index,int lineIndex,int kDelete)
{
    int lineNumber = 11;
    int space = 5 ;
    if(index==0)
    {
        std::cout<<"ilk ";
    }else{
        std::cout<<"<---";
    }
    if(size/8 <= index)
    {
        int line=((size)%8)*lineNumber+(((size)%8)-1)*space-4;
        std::cout<<std::setw(line)<<"son";
        std::cout<<" "<<line;
    }
    else if(size/8==index+1 && size%8==0)
    {
        std::cout<<std::setw(8*lineNumber+7*space-4)<<" son";
    }
    else{
        std::cout<<std::setw(8*lineNumber+7*space-4)<<"--->";
    }
    sort();
    std::cout<<std::endl;
    AdminNode* temp3=first;
    for(int i=0;i<index*8;i++)
    {
        temp3=temp3->next;
    }
    printHelper(temp3,2,' ',lineNumber,space,index);
    printHelper(temp3,5,'-',lineNumber,space,index);
    printHelper(temp3,1,'|',lineNumber,space,index);
    printHelper(temp3,5,'-',lineNumber,space,index);
    printHelper(temp3,4,'|',lineNumber,space,index);
    printHelper(temp3,5,'-',lineNumber,space,index);
    printHelper(temp3,3,'|',lineNumber,space,index);
    printHelper(temp3,5,'-',lineNumber,space,index);
    AdminNode* temp2=first;
    for(int i=0;i<index*8+lineIndex;i++)
    {
        temp2=temp2->next;
    }
    temp2->data->print(lineIndex,kDelete);

}
void YoneticiListesi::printHelper(AdminNode* temp,int choice,const char character,int lineNumber,int space,int index)
{
    int number=8;
    if(size/8<=index)
    {
        number= size%8;
    }
    for(int i=0;i<number;i++)
    {
        std::cout<<character<<std::setw(lineNumber-2);
        switch (choice)
        {
        case 1:
            std::cout<<temp->prev;
            break;
        case 2:
            std::cout<<temp;
            break;
        case 3:
            std::cout<<temp->next;
            break;
        case 4:
            std::cout<<calculateAvarege(temp->data->first,temp->data->size);
            break;
        default:
            std::string line="";
            for(int i=0;i<lineNumber-2;i++)
            {
                line+=character;
            }
            std::cout<<line;
            break;
        break;
        }
        std::cout<<character<<std::setw(space)<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}
void YoneticiListesi::sort()//Ortalama sıralama 
{
    int i, j;
    int n=size;
    AdminNode* temp=first;
    AdminNode* temp2=first;
    AdminNode* smallest=first;   
    SatirListesi* swap;
    while(temp!=nullptr)
    {
        temp2= temp;
        smallest= temp;
        while(temp2!=nullptr)
        {
            if(calculateAvarege(smallest->data->first,smallest->data->size)>calculateAvarege(temp2->data->first,temp2->data->size))
            {
                smallest = temp2;
            }
            temp2 = temp2->next;
        }
        swap = temp->data;
        temp->data = smallest->data;
        smallest->data = swap;
        temp = temp->next;
    }
}
double YoneticiListesi::calculateAvarege(Node* temp,int size)//Ortalama hesabı
{
    double total = 0;
    while(temp != nullptr)
    {
        total += temp->data;
        temp = temp->next;     
    }
    return total/(double)size;
}