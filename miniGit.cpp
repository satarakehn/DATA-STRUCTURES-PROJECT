#include <iostream>
#include "miniGit.hpp"
#include <filesystem>
using namespace std; 

miniGit::miniGit(){ //constructor 

};

miniGit::~miniGit(){ //destructor

}

void miniGit::addFile(string filename){
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
    singlyNode* curr = head;
    while (curr != 0) //loop through the linked list
    {
        if (curr->fileName == filename) //search through the linked list to find if there is a matching file name
        {
            cout << "file already exists." << endl;
        }
    }
   if (fs::exists(filename))
   {
       cout << "file exists in current directory" << endl;
   }
   else
    {
            singlyNode *newfile = new singlyNode; //create a new singly list node
            newfile->fileName = filename; //the filename for this new file is the filename added.
            newfile->next = 0; //add a new file

        if (curr == 0) //if there haven't been any files in the linked list yet
        {

            newfile->next = head;  //the new file ends up pointing to the head
            head = newfile; //the head becomes the new file
            newfile->fileVersion = fileName + "_00"; //stores a version of the file with _00 as the original

        }
        else
        {
          
            while(curr->next != NULL) //add the file node at the end of the linked list
            {
                curr = curr->next; //keep iterating until curr hits NULL
                curr->next = newfile; //insert at the end of the file
            }
           newfile->fileVersion = fileName + "_00"; //this should be the name of the file in the .minigit version
        }
    }
    
    


}
void miniGit::removeFile(string fileName){
    //prompt user ot enter a file name 
    //check the SLL for whether the file exists in the current version of the repo
    //if found delete the SLL node 
} 

void miniGit::commitChanges(){
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
