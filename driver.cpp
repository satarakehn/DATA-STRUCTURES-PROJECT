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
    int input = 0;  
    string filename; 

    while(!quit){

        displayMenu();
        getline(cin, userinput);

        bool isDigit = (userinput[0]=='0' || userinput[0]=='1' || userinput[0]=='2' || userinput[0]=='3' || userinput[0]=='4' || userinput[0]=='5');
        if (isDigit)
            input = stoi(userinput);
        else
            input = -1;

        switch(input)
        {
            case 1: {
                //miniGit s;
                if(!fs::exists(filename))
                { 
                    //if the file does not exist in the current directory
                    cout << "Enter a filename to be added: " << endl;
                    getline(cin, filename);
                    s.addFile(filename); 
                }
            
            
                break; 
            }
            case 2: {
                //miniGit s;
                string filename;
                cout << "Enter a filename to be deleted:" << endl;
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
                string answer;
                int commitNumber; 
                cout << "Would you like to commit changes now?" << endl;
                cout << "Choose 1 for yes and 2 for no" << endl;
                getline(cin, answer);
                
                if (answer[0] == '1')
                {
                    s.commitChanges(commitNumber); 
                }
                else
                {
                    displayMenu(); //returns to menu if user chooses no 
                }
                break; 
            }
            case 4: {
                int versionNumber;
                string enteredNumber;
                cout << "Enter a commit number (version number):" << endl; //if user chooses the checkout a version 
                getline(cin, enteredNumber);
                bool isInt = (userinput[0]=='0' || userinput[0]=='1' || userinput[0]=='2' || userinput[0]=='3' || userinput[0]=='4' || userinput[0]=='5' || userinput[0]=='6' || userinput[0]=='7' || userinput[0]=='8' || userinput[0]=='9');
                if (isInt){
                    versionNumber = stoi(enteredNumber);
                    s.checkout(versionNumber);
                }
                else
                    cout << "Please enter a valid commit number:" << endl;
 
                break; 
            }
            case 5: {
                //quit function 
                cout << "Goodbye!" << endl;
                quit = true; 
                break; 
            }

            default: 
                cout << "Invalid input." << endl;  //if user enters anything other then options 1-5 
                break; 
        }
    }

}

