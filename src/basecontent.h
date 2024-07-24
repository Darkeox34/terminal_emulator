#include <iostream>

class baseContent{
public:
    virtual ~baseContent() = default;
    std::string name;
    baseContent(std::string name): name(name){}
};