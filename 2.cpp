#include<iostream>
using namespace std;
int main(){
    int a[]={0,5,2,8,9,9,1};
    int n=6,min;
    for(int i=1; i<=n; i++){
        min=i;
        // cout<<"min = "<<min<<endl;
         
        for(int x:a)cout<<x<<"   ";

        // for(int p=0;p<=n; p++){
        //     cout<<a[p]<<"   ";
        // }

        cout<<endl; 

        for(int j=i+1; j<=n; j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(i<min){
            int r=a[i];
            a[i]=a[min];
            a[min]=r;
        }
    }
}