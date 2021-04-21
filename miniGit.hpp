#ifndef MINIGIT_HPP
#define MOVIETREE_HPP

#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <filesystem> 

using namespace std; 

struct singlyNode;
struct doublyNode{
    int commitNumber;
    singlyNode *head; 
    singlyNode *previous; 
    singlyNode *next;
};

struct singlyNode{
    string fileName; //name of local file
    string fileVersion; //name of file in .minigit folder 
    singlyNode *next;
};

class miniGit{
    private:
    public:
    miniGit(); //constructor
    ~miniGit();//destructor
    void adddFile(); //add file to repo
    void removeFile(); //remove file from repo 
    void commitChanges(); 
    void checkout(); //checkout any of the previous versions of the repo 

}; 

#endif // !MINIGIT_HPP