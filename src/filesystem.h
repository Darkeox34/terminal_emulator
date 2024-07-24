#include "file.h"
#include "folder.h"
#include "node.h"

class filesystem{
public:
    string name;

    node* root;

    node* current;

    filesystem(string name) : name(name){
        root->data = new folder("root");
        current = root;
    }
};