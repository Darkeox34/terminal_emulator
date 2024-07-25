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
        root->data = new folder("root");
        current = root;
    }
};

#endif