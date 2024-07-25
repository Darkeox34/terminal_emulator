#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include "basecontent.h"

class folder: public baseContent{
public:
    folder(std::string name): baseContent(name){}
};

#endif