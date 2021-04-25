#include <iostream>
#include <string>
#include "miniGit.hpp"
#include <filesystem>

namespace fs = std::filesystem; 
using namespace fs; 
using namespace std; 

int main(){
    return 0; 
}


miniGit::miniGit(){ //constructor 

}

miniGit::~miniGit(){ //destructor

}

void miniGit::addFile(string fileName){
    //prompt user to enter a file name 
    //check if file name exists if not keep prompting user to enter valid file name 
    //the SLL is checked to see whether file has already been added.
    //file by same name cannot be added twice 
    //a new SLL node gets added containting the name of the input file, repo file, & pointer to next node
    //new repo file should ombine original file name and version number 

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