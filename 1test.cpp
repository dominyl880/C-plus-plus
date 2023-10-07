#include<iostream>
using namespace std;

int main(){
    string product[100][3]={{"P1","Pen","T1"},
                            {"P2","Eraser","T1"}
                           };
    int price[100][2]={{5,10},
                        {2,9}
                      };
    string select,This,ID;
    int c;
    do{
       cout<<"========================================================="<<endl;
       cout<<"S = show"<<endl;
       cout<<"A = add"<<endl;
       cout<<"E = Edit"<<endl;
       cout<<"D = Delete"<<endl;
       cout<<"--Show List--"<<endl;
       for(int i=0;i<2;i++){
           for(int i2=0;i2<3;i2++){
               cout<<product[i][i2]<<"   ";
           }
           for(int i3=0;i3<1;i3++){
               cout<<price[i][i3]<<"   ";
           }
           cout<<endl;
       } 
       cout<<"========================================================="<<endl;



       cout<<"Enter choice : "; cin>>select;
        if(select=="S"){
            cout<<"====================SEARCH================================="<<endl;
            cout<<"Enter ID : "; cin>>ID;

            for(int i=0;i<2;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==product[i][i2]){
                        This=product[i][i2];
                        c=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"ID : "<<product[c][0]<<endl;
                    cout<<"Name : "<<product[c][1]<<endl;
                    cout<<"Type : "<<product[c][2]<<endl;
                    cout<<"price : "<<product[c][0]<<endl;
                    cout<<"amount : "<<product[c][1]<<endl;
                    cout<<endl; 
            }
            This="";
            cout<<"========================================================="<<endl;


        }else if(select=="A"){

        }else if(select=="E"){
            
        }else if(select=="D"){
            
        }
 

    }while(select!="x");


}