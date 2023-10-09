#include "head.cpp"
//ไฟล์ sale
// #include "sale.cpp" 
#include"footer.cpp"
#include"header.cpp"
//#include"product.cpp"

void typeMenu(){
      string This,ID;
      char sell_t;
      int t,t2;
      int c,beforeDel,k; //หาตำแหน่ง  , จำนวนข้อมูลก่อนลบ 
      char anw; //เช็ค Y N 
      string old; //เก็บไอดีเก่า
      const int columnWidth = 12;
      string Type_list[10][2]={{"T1","Stationery"},
                                {"T2","Food"},
                                {"T3","Drink"}
                                };
      do{
          headerTable();  //แสดง =======
          cout<<setw(54)<<"---------- Type Menu ----------"<<endl;
          cout<<setw(56)<<"Press [L] to Show List Type"<<endl;
          cout<<setw(53)<<"Press [S] to Search Type"<<endl;
          cout<<setw(50)<<"Press [A] to Add Type"<<endl;  
          cout<<setw(51)<<"Press [E] to Edit Type"<<endl;
          cout<<setw(53)<<"Press [D] to Delete Type"<<endl;
          footerReturn(); //แสดง =======
          cin>>sell_t;
          system("cls");
          sell_t = toupper(sell_t);
          if(sell_t=='L'){ 
              cout<<setw(60)<<"--------------- List Type ---------------"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<setw(8)<<"ID"<<setw(14)<<"Name"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;

                 for(int i=0;i<3;i++){
                      for(int i2=0;i2<2;i2++){
                          cout<<setw(columnWidth)<<Type_list[i][i2]<<" | ";
                      }
                      //cout<<"------------------------------";
                      cout<<endl;
                  }
          }else if(sell_t=='S'){
            cout<<setw(65)<<"--------------- Search Type ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;


            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    t=m+1;
                }
                cout<<endl;
            }
            for(int i=0;i<t;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Type_list[i][i2]){
                        This=Type_list[i][i2];
                        t=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"ID : "<<Type_list[t][0]<<endl;
                    cout<<"Name : "<<Type_list[t][1]<<endl;
                    cout<<endl; 
            }
            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;

          }else if(sell_t=='A'){
            cout<<setw(60)<<"--------------- Add Type ---------------"<<endl;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    // cout<<product[m][u]<<"   ";
                    
                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    t=m+1;
                }
                // cout<<endl;
            }
                cout<<"last = "<<t<<endl;
                string Rid;
                stringstream ss;
                ss << (t+1);
                Rid="P"+ss.str();

                cout<<"ID = "<<Rid<<endl; 
                Type_list[t][0]=Rid;
                cout<<"Name : "; cin>>Type_list[t][1];
                cout<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
            // }
          }else if(sell_t=='E'){
            cout<<setw(60)<<"--------------- Edit Type ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            //cout<<ID<<endl;
            for(int m=0; m<10;m++){
                for(int u=0;u<2;u++){
                  //cout<<m<<"    "<<u<<" = ";
                  //cout<<Type_list[m][u]<<endl;

                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            //cout<<c<<endl;
            for(int i=0;i<c;i++){
                for(int i2=0;i2<2;i2++){
                    //cout<<Type_list[i][i2]<<endl;
                    if(ID==Type_list[i][i2]){
                        
                      
                        This=Type_list[i][i2];
                        c=i; 
                    }
                }  
            }  
            //cout<<c<<endl;

            //cout<<This<<endl;

            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"ID = "<<Type_list[c][0]<<endl; //ห้ามแก้ไอดี
                    do{
                        cout<<"Do you want to edit Name? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Name : "; cin>>Type_list[c][1];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');
                    cout<<endl;
            }
            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
          }else if(sell_t=='D'){
            cout<<setw(60)<<"--------------- Delete Type ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            //cout<<ID<<endl;
            for(int m=0; m<10;m++){
                for(int u=0;u<2;u++){
                  //cout<<m<<"    "<<u<<" = ";
                  //cout<<Type_list[m][u]<<endl;

                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            //cout<<c<<endl;
            for(int i=0;i<c;i++){
                for(int i2=0;i2<2;i2++){
                    //cout<<Type_list[i][i2]<<endl;
                    if(ID==Type_list[i][i2]){
                        
                      
                        This=Type_list[i][i2];
                        c=i; 
                    }
                }  
            }
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"-------------------------------------------------------------------------------"<<endl;
                    do{
                        cout<<"Do you want to delete "<<Type_list[c][0]<<"? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            Type_list[c][0]="";
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                            for(int m=0; m<10;m++){
                                for(int u=0; u<2;u++){
                                    if(Type_list[m][u]==""){
                                        break;
                                        c=m;
                                    } 
                                }
                            }
                            for(int i=0;i<c;i++){
                                for(int i2=0;i2<2;i2++){
                                    if(ID==Type_list[i][i2]){
                                        This=Type_list[i][i2];
                                        c=i; 
                                    }
                                }  
                            }  
            }
            // cout<<c<<endl;
          
            // cout<<beforeDel<<endl;
            for(int i=c;i<beforeDel;i++){
                        Type_list[i][0]="";
                        Type_list[i][1]="";
                        
                        string Rid;
                        stringstream ss;
                        ss << (i+1);
                        Rid="P"+ss.str();

                        Type_list[i][0]=Rid;
                        
                        Type_list[i][1]=Type_list[i+1][1];

                        Type_list[i+1][0]="";
                        Type_list[i+1][1]="";

                        k=i;
                        
                cout<<endl;
            }
                        Type_list[k][0]="";
                        Type_list[k][1]="";

            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
            
        }
 

    }while(sell_t!='X');
}
// void ShowProduct(string Product_list[]);