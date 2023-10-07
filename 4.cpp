#include<iostream>
using namespace std;
int main(){
    int a[]={0,6,2,0,6,0,2};
    int n=6,min;
    for(int i=1; i<=n; i++){
        min=i; 
         
        for(int x:a)cout<<x<<"  | ";
        // for(int p=0;p<=n; p++){
        //     cout<<a[p]<<"   ";
        // }
        cout<<endl; 

        for(int j=i+1; j<=n; j++){
            cout<<"\n min before = "<<min<<"   ";

            cout<<"\n a[min] = "<<a[min]<<"   a[j] = "<<a[j];
            if(a[min]<a[j]){
                min=j;
            }
            cout<<"\n min after = "<<min<<"   ";
        }
        if(i<min){
            int r=a[i];
            a[i]=a[min];
            a[min]=r;
        }
        cout<<endl;
    }
}