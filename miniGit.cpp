#include <iostream>
#include <string>
#include "miniGit.hpp"
#include <filesystem>

namespace fs = std::filesystem; 
using namespace fs; 
using namespace std; 



miniGit::miniGit(){ //constructor 
    head = NULL; 
}

miniGit::~miniGit(){ //destructor

}

bool miniGit::isEmpty()
{
    return (head == NULL);
}

void miniGit::addFile(string filename)
{
       //prompt user to enter a file name 
    //check if file name exists if not keep prompting user to enter valid file name 
    //the SLL is checked to see whether file has already been added.
    //file by same name cannot be added twice 
    //a new SLL node gets added containting the name of the input file, repo file, & pointer to next node
    //new repo file should ombine original file name and version number 
    /*
 A new SLL node gets added containing the name of the input file, name of the repos-itory file, as well as a pointer to the next node. 
 The repository file name should bethe combination of the original file name and the version number.  
 For example, if userfilehelp.txt is added, the new file to be saved in the .minigit repository should be named help00.txt, 
 where 00 is the version number.  (The initial file version should be 00.) 

    //1. Check if the file exists in the current directory
    //2. Check if file exists in the singly linked list
    //3. Add a new singly linked list node with a file and fileversion "00" because that is the original
 
    */
   doublyNode *m;
   singlyNode *curr;
   curr = m->head; //get the head of the single node


    singlyNode *newfile = new singlyNode; //create a new singly linked list node
    newfile->fileName = filename; //this points to the filename
    newfile->next = NULL; //pointing to null

     int pos = filename.length();
     string fileversionname = filename.substr(0, pos - 4);
     string newfilename = fileversionname + "_00" + ".txt";
     newfile->fileVersion = newfilename;



    if (curr == NULL) 
    {
        newfile = curr;
        newfile->next = curr->next;
    }
    else
    {
    
     while (curr != NULL)
     {
        curr = curr->next; 
        newfile = curr;
     }
    }
 

}


void miniGit::removeFile(string filename){
    //prompt user ot enter a file name 
    //check the SLL for whether the file exists in the current version of the repo
    //if found delete the SLL node 


    singlyNode* temp = head; 
    singlyNode* previous = NULL; 

    if(isEmpty()){ //check if list is empty 
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
        }
        cout << "No files exists. " << endl; //when we exit while loop 
    }
 
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


} 
