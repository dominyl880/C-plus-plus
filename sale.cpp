#include"product.cpp"

  int c,beforeDel,k; //หาตำแหน่ง  , จำนวนข้อมูลก่อนลบ 
  char anw; //เช็ค Y N 
  string old; //เก็บไอดีเก่า
// ================================Sale Menu==========================
void sale(){
      string This,ID;
      char sell_s;
      int s,s2;
      const int columnWidth = 10;
      string Sale_list[100][2]={{"S1","P1"},
                                {"S2","P2"}
                               };
      int Price_list[100][3]={{5,2,10},
                              {5,2,10}
                          };
      do{
          headerTable();  //แสดง =======
          cout<<setw(55)<<"---------- Sale Menu ----------"<<endl;
          cout<<setw(54)<<"Press [L] to Show History"<<endl;
          cout<<setw(55)<<"Press [A] to Add Sale Page"<<endl;  
          cout<<setw(56)<<"Press [E] to Edit Sale page"<<endl;
          cout<<setw(58)<<"Press [D] to Delete Sale page"<<endl;
          footerReturn(); //แสดง =======
          cin>>sell_s;
          system("cls");
          sell_s = toupper(sell_s);
          if(sell_s=='L'){ 
              cout<<setw(60)<<"--------------- History ---------------"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<setw(8)<<"ID"<<setw(12)<<"Name"<<setw(14)<<"Price"<<setw(13)<<"Amount"<<setw(13)<<"Total"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;

                 for(int i=0;i<=5;i++){
                      for(int i2=0;i2<=2;i2++){
                          cout<<setw(columnWidth)<<Sale_list[i][i2]<<" | ";
                      }
                      for(int i2=0;i2<=1;i2++){
                          cout<<setw(columnWidth)<<Price_list[i][i2]<<" | ";
                      }
                      cout<<endl;
                      
                  } 
          }else if(sell_s=='A'){
            cout<<setw(60)<<"--------------- Add Sale ---------------"<<endl;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    // cout<<product[m][u]<<"   ";
                    
                    if(Sale_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    s=m+1;
                }
                // cout<<endl;
            }
                cout<<"last = "<<s<<endl;
                string Rid;
                stringstream ss;
                ss << (s+1);
                Rid="P"+ss.str();

                cout<<"ID = "<<Rid<<endl; 
                Sale_list[s][0]=Rid;
                cout<<"ID Product : "; cin>>Sale_list[s][1];
                cout<<"Price : "; cin>>Price_list[s][0];
                cout<<"Amount : "; cin>>Price_list[s][1];
                cout<<"Total : "; cin>>Price_list[s][2];
                cout<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
            // }
          }else if(sell_s=='E'){
            cout<<setw(60)<<"--------------- Edit Sale ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Sale_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Sale_list[i][i2]){
                        This=Sale_list[i][i2];
                        c=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"ID = "<<Sale_list[c][0]<<endl; //ห้ามแก้ไอดี
                    do{
                        cout<<"Do you want to edit ID Product? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New ID Product : "; cin>>Sale_list[c][1];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                    do{
                        cout<<"Do you want to edit Price? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Price : "; cin>>Price_list[c][0];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                     do{
                        cout<<"Do you want to edit Amount? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Amount : "; cin>>Price_list[c][1];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');
                    
                    do{
                        cout<<"Do you want to edit Total? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Total : "; cin>>Price_list[c][2];
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
          }else if(sell_s=='D'){
            cout<<setw(60)<<"--------------- Delete Sale ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Sale_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Sale_list[i][i2]){
                        This=Sale_list[i][i2];
                        c=i; 
                    }
                }  
            }if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"-------------------------------------------------------------------------------"<<endl;
                    do{
                        cout<<"Do you want to delete "<<Sale_list[c][0]<<"? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            Sale_list[c][0]="";
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                            for(int m=0; m<100;m++){
                                for(int u=0; u<3;u++){
                                    if(Sale_list[m][u]==""){
                                        break;
                                        c=m;
                                    } 
                                }
                            }
                            for(int i=0;i<c;i++){
                                for(int i2=0;i2<3;i2++){
                                    if(ID==Sale_list[i][i2]){
                                        This=Sale_list[i][i2];
                                        c=i; 
                                    }
                                }  
                            }  
            }
            // cout<<c<<endl;
          
            // cout<<beforeDel<<endl;
            for(int i=c;i<beforeDel;i++){
                        Sale_list[i][0]="";
                        Sale_list[i][1]="";
                        Price_list[i][0]=0;
                        Price_list[i][1]=0;
                        Price_list[i][2]=0;
                        
                        string Rid;
                        stringstream ss;
                        ss << (i+1);
                        Rid="P"+ss.str();

                        Sale_list[i][0]=Rid;
                        
                        Sale_list[i][1]=Sale_list[i+1][1];
                        Price_list[i][0]=Price_list[i+1][0];
                        Price_list[i][1]=Price_list[i+1][1];

                        Sale_list[i+1][0]="";
                        Sale_list[i+1][1]="";
                        Price_list[i+1][0]=0;
                        Price_list[i+1][1]=0;
                        Price_list[i+1][2]=0;

                        k=i;
                        
                cout<<endl;
            }
                        Sale_list[k][0]="";
                        Sale_list[k][1]="";
                        Price_list[k][0]=0;
                        Price_list[k][1]=0;
                        Price_list[k][2]=0;

            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
            
        }
      }while(sell_s!='X');
}