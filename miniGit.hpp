#ifndef MINIGIT_HPP
#define MOVIETREE_HPP

#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>

using namespace std; 

struct singlyNode;
struct doublyNode{
    int commitNumber;
    singlyNode *head; 
    singlyNode *previous; 
    singlyNode *next;
};

struct singlyNode{
    string fileName; 
    string fileVersion; 
    singlyNode *next;


};

class miniGit{
    private:
    public:
    miniGit(); //constructor
    ~miniGit();//destructor

}; 

#endif // !MINIGIT_HPP