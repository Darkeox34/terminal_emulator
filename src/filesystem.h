#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "file.h"
#include "folder.h"
#include "node.h"

#include <iostream>

class filesystem{
public:
    std::string name;

    node* root;

    node* current;

    filesystem(std::string name) : name(name){
        root = new node();
        root->content = new folder("root");
        current = root;
    }

    void mkDir(std::string name);

    void printFolders();
};

void filesystem::mkDir(std::string name){
    node* newNode = new node();
    newNode->content = new folder(name);
    newNode->parent = current;
    if(current->linkings[0] != nullptr)
        current->linkings.push_back(newNode);
    else
        current->linkings[0] = newNode;
}

void filesystem::printFolders(){
    for(int i = 0; i < current->linkings.size(); i++){
        std::cout << current->linkings[i]->content->name << std::endl;
    }
}

#endif