#include <iostream>
#include "src/filesystem.h"

using namespace std;

int main(){
    filesystem* Filesystem = new filesystem("C");

    for(int i = 0; i < 5; i++){
        Filesystem->mkDir(to_string(i));
    }

    Filesystem->printFolders();
}