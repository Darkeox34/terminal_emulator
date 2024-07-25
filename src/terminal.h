#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <string>

#include "utils.h"
#include "node.h"
#include "filesystem.h"

class Terminal{
public:
    void startup();

    std::string hostname;

    filesystem* Filesystem;

    Terminal(std::string _hostname, filesystem* _Filesystem){
        Filesystem = _Filesystem;
        hostname = _hostname;
        startup();
    }

    void neofetch();

    void executeCommand(std::string command);

    void printHostname();

    void waitingForCommand();

    void ls();

    void clear();

    void cd(std::string directory);

    void mkdir(std::string name);
};

void Terminal::neofetch(){
    std::cout << "                   -`                    antonio@127.0.0.1\n";
    std::cout << "                  .o+`                   ---------------\n";
    std::cout << "                 `ooo/                   OS: Fancy Operative System\n";
    std::cout << "                `+oooo:                  Kernel: 5.15.153.1-microsoft-standard-WSL2\n";
    std::cout << "               `+oooooo:                 Terminal: Terminal Emulator\n";
    std::cout << "               -+oooooo+:                CPU: AMD Ryzen 9 9950X (16) @ 5.759GHz\n";
    std::cout << "             `/:-:++oooo+:               GPU: RTX 4090\n";
    std::cout << "            `/++++/+++++++:              Memory: 444MiB / 63985MiB\n";
    std::cout << "           `/++++++++++++++:\n";
    std::cout << "          `/+++ooooooooooooo/`\n";
    std::cout << "         ./ooosssso++osssssso+`\n";
    std::cout << "        .oossssso-````/ossssss+`\n";
    std::cout << "       -osssssso.      :ssssssso.\n";
    std::cout << "      :osssssss/        osssso+++.\n";
    std::cout << "     /ossssssss/        +ssssooo/-\n";
    std::cout << "   `/ossssso+/:-        -:/+osssso+-\n";
    std::cout << "  `+sso+:-`                 `.-/+oso:\n";
    std::cout << " `++:.                           `-/+/\n";
    std::cout << " .`                                 `/\n";
    waitingForCommand();
}

void Terminal::clear(){
    system("cls");
    waitingForCommand();
}

void Terminal::cd(std::string directory){
    node* newDir = Filesystem->searchSubFolders(directory);
    if(newDir != nullptr){
        Filesystem->current = newDir;
    }
    waitingForCommand();
}

void Terminal::waitingForCommand(){
    printHostname();
    std::string cmd = "";
    std::getline(std::cin, cmd);
    if(cmd == ""){
        std::cout << "\n";
        waitingForCommand();
    }
    else{
        executeCommand(cmd);
    }    
}

void Terminal::executeCommand(std::string command) {
    std::vector<std::string> full_command = cmdParse(command);

    if (full_command.empty()) {
        std::cout << "No command entered.\n";
        return;
    }
    std::string cmd = full_command[0];
    std::string arg = (full_command.size() > 1) ? full_command[1] : "";

    if (cmd == "ls") 
        ls();
    else if(cmd == "cd"){
        if(arg == ".."){
            Filesystem->current = Filesystem->current->content->name != "root" ? Filesystem->getParent() : Filesystem->current;
            waitingForCommand();
        }
        else
            cd(arg);
    }
    else if(cmd == "mkdir")
        mkdir(arg);
    else if (cmd == "clear") 
        clear();
    else if (cmd == "neofetch") 
        neofetch();
    else {
        std::cout << "Command not found! Type help to see the list of commands.\n";
        waitingForCommand();
    }
}


void Terminal::startup(){
    neofetch();
}

void Terminal::printHostname(){
    std::cout << hostname << "@terminal:~$ ";
}

void Terminal::ls(){
    Filesystem->printFolders();
    waitingForCommand();
}
void Terminal::mkdir(std::string name){
    Filesystem->createFolder(name);
    waitingForCommand();
}


#endif