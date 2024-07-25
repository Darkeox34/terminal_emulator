#include "filesystem.h"

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
    std::cout << "Your current folder's name is: " << current->content->name << std::endl;
    std::cout << "This folder contains " << current->linkings.size() << " folders!" << std::endl;
    for(int i = 0; i < current->linkings.size(); i++){
        std::cout << current->linkings[i]->content->name << std::endl;
    }
}