#ifndef NODE_H
#define NODE_H

#include <vector>
#include "basecontent.h"

class node{
public:
    baseContent* content;
    std::vector<node*> linkings;
    node* parent;

    node(){
        linkings.push_back(nullptr);
    }
};

#endif