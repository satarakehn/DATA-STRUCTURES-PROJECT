#include <iostream> 
#include <string>
#include "miniGit.hpp"
#include <filesystem>
using namespace std; 

namespace fs = std::filesystem; 
using namespace fs;

 

void displayMenu(){
    cout << "=== Main Menu ===" << endl; 
    cout << "1. Add a file" << endl; 
    cout << "2. Remove a file" << endl; 
    cout << "3. Commit a file " << endl; 
    cout << "4. Checkout a file " << endl; 
    cout << "5. Quit" << endl; 
}

int main(int argc, char const *argv[]){
    bool quit = false; 
    miniGit s;
    string userinput; 
    int input;  
    string filename; 

    while(!quit){

        displayMenu();
        getline(cin, userinput);

        switch(input)
        {
            case 1: {
                //miniGit s;
                string filename;
                cout << "Enter a filename to be added." << endl;
                getline(cin, filename);
           
                s.addFile(filename);
            
                break; 
            }
            case 2: {
                //miniGit s;
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
                break; 
            }
            case 3: {
                int answer;
                cout << "Would you like to commit changes now?" << endl;
                cout << "Choose 1 for yes and 2 for no" << endl;
                
                if (answer == 1)
                {
                    s.commitChanges();
                }
                break; 
            }
            case 4: {

                break; 
            }
            case 5: {
                //quit function 
                cout << "Goodbye!" << endl; 
                break; 
            }

            default: 
                cout << "Invalid input" << endl; 
                break; 
        }
    }

}

