#include <iostream>

using namespace std;

struct masukan{
    int in;
    masukan* next;
    masukan* previous;
};

masukan* input(){
    int x;
    masukan* in=NULL;
    masukan* test=NULL;
    cout<<"Input banyak data: ";cin>>x;
    for (int i=0; i<x; i++){
        if(in==NULL){
            in = new masukan;
            cout<<"Input angka: ";cin>>in->in;
            in->next=NULL;
            in->previous=NULL;
            test=in;
            continue;
        }
        else if(test->next==NULL){
            test->next=new masukan;
            cout<<"Input angka: ";cin>>test->next->in;
            test->next->previous=test;
            test->next->next=NULL;
        }
        test=test->next;
    }
    return in;
}

void urut(masukan*& in){
    masukan* test1=in;
    masukan* test2;
    while(test1->next!=NULL){
        test2=test1->next;
        while(test2->previous!=NULL && test2->in<test2->previous->in){
            swap(test2->in,test2->previous->in);
            test2=test2->previous;
        }
        test1=test1->next;
    }
}

int main(){
    masukan* in;
    masukan* sort;
    in=input();
    urut(in);
    masukan* test=in;
    cout<<"Data yang sudah terurut: ";
    while(test!=NULL){
        cout<<test->in<<" ";
        test=test->next;
    }
    cout<<"\n";
    system("read a");
    return 0;
}