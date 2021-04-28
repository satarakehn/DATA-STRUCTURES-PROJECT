#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "miniGit.hpp"
#include <filesystem>

namespace fs = std::filesystem; 
using namespace fs; 
using namespace std; 




miniGit::miniGit(){ //constructor 
    currVersion = new doublyNode; // current version of our repository 
    head = NULL; //head of current version (SLL) 

    fs::create_directory(".minigit"); //creates our new directory
}

void destroySLL(singlyNode* head) //helper function for destructor and memory allocated with SLL
{
    if(head == NULL)
    {
        return; 
    }
    else 
    {
        destroySLL(head->next);
        delete head; 
    }

}

void destroy_DLL(doublyNode* currVersion)//helper function for destructor and memory allocated with DLL 
{
    if(currVersion == NULL)
    {
        return; 
    }
    else 
    {
        destroy_DLL(currVersion->next);
        delete currVersion; 
    }

}

miniGit::~miniGit(){ //destructor

    destroySLL(head); //calling our helper functions 
    destroy_DLL(currVersion);
    
}

bool miniGit::isEmpty()
{
    return (head == NULL); //using a premade function 'isEmpty' to check if linked list is empty 
}

bool miniGit::addFile(string fileName){

    bool file_exists = false; //settings file esists false 
    singlyNode* curr = head; //assinging curr as the head of linked list 
    singlyNode* previous = head; 

    if(fs::exists(fileName)) //this is checking if file already exists 
    {
        if(fs::is_regular_file(fileName))//cplusplus, checks if file status/path is regular file
        {
            file_exists = true; 
        }
        else 
        {
            file_exists = false; 
        }
    }


    
    if(!file_exists) //if the file doesnt exist 
    {
        if(curr != NULL) //edge case to check if the file already exists
            {
                if(curr->fileName == fileName)
                    {
                        cout << "File already exists." << endl; 
                        return false; 
                    }
                else
                    {
                        previous = curr; 
                        curr = curr->next; 
                    }
            }
        if(head == NULL)
            {
                head = new singlyNode; 
                head->fileName = fileName; 
                head->fileVersion = "0";
                head->next = NULL; 
                cout <<"File successfully added." << endl;
                return true; 
            }

            previous->next = new singlyNode; 
            previous->next->fileName = fileName; 
            previous->next->fileVersion = "0"; 
            cout << "File successfully added." << endl; 
    }

    return false; 

}


void miniGit::removeFile(string filename){
    //prompt user ot enter a file name 
    //check the SLL for whether the file exists in the current version of the repo
    //if found delete the SLL node 


    singlyNode* temp = head; 
    singlyNode* previous = NULL; 

    if(isEmpty())
    { //check if list is empty 
        cout << "No files exist." << endl; 
        return; 
    }

    if(filename == temp->fileName){ //checking if file name is the head
        head = temp->next; //assigning head to a new node 
        delete temp; 
        return; 
    }
    else 
    {
        while(temp != NULL)
        {
            if(filename == temp->fileName)
            {//were at the node aka file we reached 
                previous->next = temp->next; 
                delete temp; 
                return; 
            }
            previous = temp;
            temp = temp->next; 
            cout << "File successfully deleted." << endl;
        }
        cout << "No files exists. " << endl; //when we exit while loop 
    }
 
} 

void Copy(string inputName, string outputName){ // Function that copies an input file over to some output file
    fstream inputFile;
    ofstream outputFile;
    string line;
    inputFile.open(inputName);
    outputFile.open(outputName , ios_base::app);

    while (!inputFile.eof()){ // Loop through the input file and add all the lines to the output file
        getline(inputFile, line);
        outputFile << line << endl;
    }
    inputFile.close();
    outputFile.close();
}

string incrementVersion(string fileVersion){ // Function that increments the version number on the file name string
    char ch1, ch2;
    ch1 = fileVersion[fileVersion.length()-6];
    ch2 = fileVersion[fileVersion.length()-5]; // Grabs the two digits representing version number

    int totalNum = ch1*10 + ch2 + 1; // increments the number represented by the two digits
    string num = to_string(totalNum);
    return fileVersion.substr(0, fileVersion.length()-6) + num + fileVersion.substr(fileVersion.length()-6, fileVersion.length()); // attaches back the version number, along with the file type.
        
}
void miniGit::commitChanges(int commitNum){
    //the current sll should be traversed in it entirety for every node 
    //check whether the fileversion exists 
    //if file version does not exist, copy the file from current directory 
    //the new copied file should get name from the node's fileversion member 
    // if file version does exist check whether the current directory file has been changed 
    //if file is unchanged, do nothing 
    // if file is changed, copy the file from current directory and give it the name with incremeneted version number 
    //update the SLL node member fileVersion to the incremeneted name 
    //once all files have been scanned, create a new DLL node of the repo 
    //an exat copy of the SLL from prev node should be copied into the new DLL node 
    //the commit number of the new DLL node will be the prev node commit number incremented by one


    singlyNode *tmp = currVersion->head; // dummy node used to traverse the single linked list
    while (tmp!=NULL){

        if (!fs::exists(tmp->fileVersion)){ // If the file doesn't exist in .minigit, we add it from the main directory
            Copy(tmp->fileName, tmp->fileVersion);
        }

        else{ // Checking if all the lines of the files are the same, we stop whenever we reach the end of a file
            fstream file1(tmp->fileName);
            fstream file2(tmp->fileVersion);
            string line1 = "";
            string line2 = "";
            bool fileSame = true;
            while (!file1.eof() && !file2.eof()){
                getline(file1, line1);
                getline(file2, line2);
                if (line1 != line2){
                    fileSame = false;
                    break;
                }
            }

            if (!fileSame){ // If the files are the same, we increment the version number on the file name, and reassign the node
                tmp->fileVersion = incrementVersion(tmp->fileVersion);
                Copy(tmp->fileName, tmp->fileVersion);
            }
            file1.close();
            file2.close();
        }

        tmp = tmp->next;

    }

    currVersion->commitNumber++; // iterating through the linked list
    

} 


void miniGit::checkout(int commitNumber){
    // -> this is referencing continuing sentence on next line 
    //if user chooses to checout a version, the should be prompted to enter a commit number 
    //if commit number is valid, the files in current directory should be overwritten by the ->
    //corresponding files from the .minigit directory 
    //good idea to issue a warning to user that they will lose their local changes if they checkout different ->
    //version before making a commit with their current local changes 
    //you will need to search through the DLL for a node with a matching commit number 
    //you must disallow add/remove/commit operations when the current version is different from the most ->
    // recent commit (aka the last DLL node)
    cout << "Warning: You will lose your local changes if you checkout a different version before making a commit with current local changes." << endl;
    cout << "Your current version is: " << currVersion->commitNumber << endl;
    
    doublyNode *tmp = currVersion;
    while (tmp != NULL && tmp->commitNumber != commitNumber){ // While iterating, we either want to stop where the commit version can be found, or reach the end of the list 
        if (tmp->commitNumber > commitNumber)
            tmp = tmp->previous;
        else
            tmp = tmp->next;
    }
    if (tmp == NULL){ // If we reach the end without seeing the commit version, then the commit number was invalid and does not exist
        cout << "Please enter a valid commit number:" << endl;
    }
    else{ // We now traverse through and copy every file from this commit version
        currVersion = tmp;
        singlyNode *temp = currVersion->head;
        while (temp!=NULL){
            Copy(temp->fileVersion, temp->fileName);
            temp = temp->next;
        }
    }

} 
