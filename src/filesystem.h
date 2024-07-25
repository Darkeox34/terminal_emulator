#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "file.h"
#include "folder.h"
#include "node.h"
#include "utils.h"

#include <iostream>

class filesystem{
public:
    std::string name;

    node* root;

    node* current;

    filesystem(std::string name) : name(name){
        root = new node();
        root->content = new folder("home");
        current = root;
    }

    std::string getPath();

    node* getParent();

    void createFolder(std::string _name);

    node* searchSubFolders(std::string name);

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

node* filesystem::getParent(){
    return current->parent;
}

std::string filesystem::getPath(){
    if(current->content->name == "home")
        return "~";
    std::string path = "";
    node* tmp = current;
    while(tmp->content->name != "home"){
        path = "/" + tmp->content->name + path;
        tmp = tmp->parent;
    }
    
    return "/home" + path + "/";
}

node* filesystem::searchSubFolders(std::string _name){
    for(int i = 0; i < current->linkings.size(); i++){
        if(current->linkings[i]->content->name == _name){
            return current->linkings[i];
        }
    }
    std::cout << "Directory not found!\n";
    return nullptr;
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