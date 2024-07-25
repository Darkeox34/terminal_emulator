#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

void log(const std::string& message){
    std::cout << "[-] " << message << std::endl;
}

std::string reverseString(std::string toreverse){
    std::string temp = "";
    for(int i = toreverse.length()-1; i >= 0; i--){
        temp += toreverse[i];
    }
    return temp;
}

std::vector<std::string> cmdParse(const std::string& cmd){
    std::vector<std::string> command;
    std::string temp;
    
    for(int i = 0; i < cmd.length(); ++i){
        if(cmd[i] != ' '){
            temp += cmd[i];
        } else {
            if(!temp.empty()){
                command.push_back(temp);
                temp.clear();
            }
        }
    }
    if(!temp.empty()){
        command.push_back(temp);
    }

    return command;
}

#endif
