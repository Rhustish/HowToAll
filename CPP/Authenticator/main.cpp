#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include <string>
using namespace std;


void login(){
     cout<<"\n\n------------------------------Login sequence initiated----------------------------------\n";

    string username,password;
    vector<string> strvector;
    
    
    // username input
    cout<<"Enter your username: "<<endl;cin>>username;
    //password input
    cout<<"Enter your username: "<<endl;cin>>password;

    string upass = username+","+password;

    // getting old data because cant send direct query
    string temp = "";
    ifstream inputconnector;
    inputconnector.open("credentials.csv");
    while(!inputconnector.eof()){
        getline(inputconnector,temp);
        strvector.push_back(temp);
        temp = "";
    }inputconnector.close();

    //login logic
    bool logged_in = 0;
    for(auto e:strvector){
        if(e == upass){
            cout<<"Login successful, Terminating session."<<endl;
            logged_in = 1;
            return;
        }
    }
    if (!logged_in){
        cout<<"\n\nIncorrect credentials. Would you like to retry?(Y/N)\n";
        char retry;
        cin>>retry;
        if(retry == 'y'){login();}
        else{cout<<"Exiting, Thankyou for using Rhust authenticator"<<endl;}
    }


    
}
void registeration(){
    cout<<"\n\n------------------------------Registration sequence initiated----------------------------------\n";
    string username,password;
    cout<<"Choose a unique username: "<<endl;
    cin>>username;

    //password input
    cout<<"Create a password: "<<endl;
    cin>>password;

    // getting old data because cant directly append
    string temp,data = "";
    ifstream inputconnector;
    inputconnector.open("credentials.csv");
    while(!inputconnector.eof()){
        getline(inputconnector,temp);
        data.append(temp+"\n");
        temp = "";
    }inputconnector.close();

    ofstream outputconnector;
    outputconnector.open("credentials.csv");
    outputconnector<<data+username+","+password;
    outputconnector.close();

    cout<<"\n\nRegistration successful!, now initiating login sequence. Do you want to exit instead? (exit/no)\n";
    string exitornot;
    cin>>exitornot;
    if(exitornot == "exit"){
        return;
    }else{
        login();
    }
}

void run(){
    int option = 0;
    cout<<"Enter 1 to login, and 2 to register new account"<<endl;
    cin>>option;

    switch(option){
        case 0:
            break;
        case 1:
            login();
            break;
        case 2:
            registeration();
            break;
    }
    cout<<"Do you want to exit?(Y/N)"<<endl;
    char resp;
    cin>>resp;

    if (resp == 'n'){run();}
    cout<<"Thnks for using Rhust authenticator"<<endl;
}


int main()
{
    run();
    
    return 0;
}