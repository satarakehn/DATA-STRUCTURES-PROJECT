#ifndef MINIGIT_HPP
#define MOVIETREE_HPP

#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <filesystem> 

using namespace std; 
//namespace fs = std::filesystem; 




struct singlyNode{
    std::string fileName; //name of local file
    std::string fileVersion; //name of file in .minigit folder 
    singlyNode *next;
};

struct doublyNode{
    int commitNumber;
    singlyNode *head; 
    doublyNode *previous; 
    doublyNode *next;
};

class miniGit{
    private:
    singlyNode* head; 
    doublyNode* currVersion; //keep track of current version 

    public:
    miniGit(); //constructor
    ~miniGit();//destructor
    bool isEmpty(); 
    bool addFile(string fileName); //add file to repo
    void removeFile(string filename); //remove file from repo 
    void commitChanges(int); 
    void checkout(int commitNumber); //checkout any of the previous versions of the repo 
    
}; 

#endif // !MINIGIT_HPP
