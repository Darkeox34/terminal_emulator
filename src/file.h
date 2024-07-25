#ifndef FILE_H
#define FILE_H

#include <iostream>
#include "basecontent.h"

class file: public baseContent{
public:
    file(std::string name): baseContent(name){}

    std::string data;
};

#endif