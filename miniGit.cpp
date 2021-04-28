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

void destroySLL(singlyNode* head)
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

void destroy_DLL(doublyNode* currVersion)
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

    destroySLL(head);
    destroy_DLL(currVersion);
    
}

bool miniGit::isEmpty()
{
    return (head == NULL);
}

bool miniGit::addFile(string fileName){

    bool file_exists = false; 
    singlyNode* curr = head;
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

void Copy(string inputName, string outputName){
    fstream inputFile;
    ofstream outputFile;
    string line;
    inputFile.open(inputName);
    outputFile.open(outputName , ios_base::app);

    while (!inputFile.eof()){
        getline(inputFile, line);
        outputFile << line << endl;
    }
    inputFile.close();
    outputFile.close();
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
    while (tmp != NULL && tmp->commitNumber != commitNumber){
        if (tmp->commitNumber > commitNumber)
            tmp = tmp->previous;
        else
            tmp = tmp->next;
    }
    if (tmp == NULL){
        cout << "Please enter a valid commit number:" << endl;
    }
    else{
        currVersion = tmp;
        singlyNode *temp = currVersion->head;
        while (temp!=NULL){
            Copy(temp->fileVersion, temp->fileName);
            temp = temp->next;
        }
    }


} 
