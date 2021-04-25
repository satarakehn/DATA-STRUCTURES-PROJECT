#ifndef MINIGIT_HPP
#define MOVIETREE_HPP

#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <filesystem> 

using namespace std; 
//namespace fs = std::filesystem; 


struct singlyNode;
struct doublyNode{
    int commitNumber;
    singlyNode *head; 
    singlyNode *previous; 
    singlyNode *next;
};

struct singlyNode{
    std::string fileName; //name of local file
    std::string fileVersion; //name of file in .minigit folder 
    singlyNode *next;
};

class miniGit{
    private:

    public:
    miniGit(); //constructor
    ~miniGit();//destructor
    void addFile(string); //add file to repo
    void removeFile(string); //remove file from repo 
    void commitChanges(); 
    void checkout(int); //checkout any of the previous versions of the repo 
    

}; 

#endif // !MINIGIT_HPP