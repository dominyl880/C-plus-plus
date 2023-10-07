#include<iostream>
using namespace std;
int main(){
    char id[5][5],name[5][20];
    float score[5];
    for(int i=0; i<5; i++){ 
        cout<<"enter id : "; cin>>id[i]; 
        cout<<"enter name : "; cin>>name[i]; 
        cout<<"enter score : "; cin>>score[i]; 


    }

    for(int p=0; p<5; p++){
        cout<<id[p]<<"   "<<name[p]<<score[p]<<endl;

    }

}