#include<bits/stdc++.h>
using namespace std;
static int auth = 0;
ofstream fout;
ifstream fin;
class users
{
    public:
    char *user, *psw;
};


bool Register(){
string user, psw;
int f;
    cout<<"Enter the valide Email\n";
    cin>>user;
    cout<<"Enter password which you want\n";
    cin>>psw;
    fout.open("stuff/demo.txt");
    fout<<user;
    fout.close();
    fout.open("stuff/demo2.txt");
    fout<<psw;
    fout.close();
    cout<<"\nPlease wait we are creating your account...\n";    
    system("node register");
    //successfull registration
    fin.open("stuff/valide.txt");
    fin>>f;
    if(f == 1){
         cout<<"You have registered successfully!\n";
         return true;
         }
    else return false;
}

bool LogIn(){
    //log in part
    string user, psw;
    int f,ch;
    cout<<"Enter your Email\n";
    cin>>user;
    cout<<"Enter password\n";
    cin>>psw;
    fout.open("stuff/demo.txt");
    fout<<user;
    fout.close();
    fout.open("stuff/demo2.txt");
    fout<<psw;
    fout.close();
    cout<<"Checking for authentication\n";    
    system("node auth");
    //validation part
    fin.open("stuff/valide.txt");
    fin>>f;
    if(f == 1){
         cout<<"You have Loged in successfully!\n";
         return true;
         }
    else {
        cout<<"You don't registered there!\nPress '1' to register\n";
    cin>>ch;
    if(ch == 1) Register();
    else false;
    }
}


void retriev(){
   
}

int main(){
    int ch;
    cout<<"1.Log In\n2.Regidter\n";
    cin>>ch;
    if(ch == 1) {
        if(LogIn()){
            cout<<"You are logged in\n"; 
            auth = 1;  
        }
    }
    else if(ch == 2){
         if(Register()){
            LogIn();
         }else{
            cout<<"can't register\n";
         }
         }
    cout<<"\ncompleated!\n";
    return 0;
}