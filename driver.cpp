#include <iostream> 
#include "miniGit.hpp"
#include <filesystem>
//namespace fs = std::filesystem; 
using namespace std; 

void displayMenu(){
    cout << "=== Main Menu ===" << endl; 
    cout << "1. Add a file" << endl; 
    cout << "2. Remove a file" << endl; 
    cout << "3. Commit a file " << endl; 
    cout << "4. Checkout a file " << endl; 
    cout << "5. Quit" << endl; 
}

int main(int argc, char const *argv[]){
    string userinput;  

   

    while(true){
        displayMenu();
        getline(cin,userinput);
        if(userinput == "1"){
            break; 
        }
        else if(userinput == "2")
        {
            break;
        }
        else if(userinput == "3")
        {
            break; 
        }
        else if(userinput == "4")
        {
            break; 
        }
        else if(userinput == "5")
        {
            cout << "Goodbye!" << endl; 
        }
        else{
            //cout << "Command not found"<< endl;  
            //or break; 
        }
    }
}