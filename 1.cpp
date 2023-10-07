#include<iostream>
using namespace std;
int main(){
    int a[6]={6,2,0,6,0,2};
 
    for(int i=0;i<=5;i++){
            for(int p=0;p<=5;p++){
                cout<<a[p]<<"   ";
            } 
            cout<<endl;
            int j=i+1;
            cout<<i<<" =  ";
            // cout<<a[i]<<"   "; 
            // cout<<a[j]<<"   "<<endl; 
            if(a[i]<a[j]){
                int temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            } 
    }
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    for(int p2=0;p2<=5;p2++){
        cout<<a[p2]<<"    ";
    }
    cout<<endl;


}