#include <iostream>
#include "src/filesystem.h"
#include "src/terminal.h"

using namespace std;

int main(){
    filesystem* Filesystem = new filesystem("C");
    Terminal* terminal = new Terminal("antonio", Filesystem);
}