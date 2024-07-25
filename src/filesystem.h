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

    void createFolder(std::string _name);

    void printFolders();
};

void filesystem::createFolder(std::string _name){
    node* newNode = new node();
    newNode->content = new folder(_name);
    newNode->parent = current;
    if(current->linkings[0] != nullptr)
        current->linkings.push_back(newNode);
    else
        current->linkings[0] = newNode;
}

void filesystem::printFolders(){
    if(current->linkings[0] == nullptr)
        return;
    else{
        for(int i = 0; i < current->linkings.size(); i++){
            std::cout << current->linkings[i]->content->name << std::endl;
        }
    }
}

#endif