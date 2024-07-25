#ifndef BASECONTENT_H
#define BASECONTENT_H

#include <iostream>

class baseContent{
public:
    virtual ~baseContent() = default;
    std::string name;
    baseContent(std::string name): name(name){}
};

#endif