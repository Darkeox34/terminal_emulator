#include "basecontent.h"
#include <vector>

class node{
public:
    baseContent* data;
    std::vector<node*> linkings;
    node* parent;

    node(){
        linkings.push_back(nullptr);
    }
};