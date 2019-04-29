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
    masukan* x;
    while(test1->next!=NULL){
        test1=test1->next;
    }
    while(test1!=NULL){
        x=in;
        test2=in->next;
        while(test2!=test1->next){
            if(test2->in>x->in){
                x=test2;
            }
            test2=test2->next;
        }
        swap(test1->in,x->in);
        test1=test1->previous;
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