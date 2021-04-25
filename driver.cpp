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
        if(userinput == "1")
        {
            miniGit s;
            string filename;
            cout << "Enter a filename to be added." << endl;
            getline(cin, filename);
           
                s.addFile(filename);
            
        }
        else if(userinput == "2")
        {
            miniGit s;
            string filename;
            cout << "Enter a filename to be deleted." << endl;
            getline(cin, filename);
            if (!fs::exists(filename))
            {
                s.removeFile(filename);
            }
            else
            {
                cout << "File already exists." << endl;
            }
            
        }
        else if(userinput == "3")
        {
            miniGit s;
            int answer;
           cout << "Would you like to commit changes now?" << endl;
           cout << "Choose 1 for yes and 2 for no" << endl;
            
            if (answer == 1)
            {
               s.commitChanges();
            }
            
            
            
        }
        else if(userinput == "4")
        {
            
        }
        else if(userinput == "5")
        {
            cout << "Goodbye!" << endl; 
            
        }
        else{
            cout << "Command not found"<< endl;  
            //or break; 
        }
    }
}
