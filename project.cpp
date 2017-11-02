#include<iostream>
#include"Auths.h"
using namespace std;

int main(){
    int ch;
    Auths enter;
    while(1){
    cout<<"1.Log In\n2.Register\n3.Logout\n";
    cin>>ch;
    switch(ch){
        case 1:
            if(enter.LogIn()){
            cout<<"You are logged in successfully\n"; 
            auth = 1;  
            }else cout<<"somthing went wrong!\n";

            break;
        case 2:
            if(enter.Register()){
             cout<<"registered successfully\n";
             system("cls");
            enter.LogIn();
            }else  cout<<"can't register\n";

            break;
        case 3:
            enter.Logout();
            break; 
    }
}
    return 0;
}