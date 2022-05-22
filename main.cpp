#include <iostream>
#include <algorithm>
#include <filesystem>
#include "interpreter/chip8_VM.h"


int main()
{
    chip8VM instance;

    int counter = 1;
    std::string fileName;
    std::string* fileList = new std::string[100];

    std::cout << "\nChoose a ROM to Load\n" << std::endl;
    for(const auto & entry : std::filesystem::directory_iterator("."))
    {
        fileName = entry.path();
        fileName.erase(0,2);
        std::cout << counter << ". " << fileName << std::endl;
        fileList[counter] = fileName;
        counter++;
    }
    std::cout << "\n" << std::endl;
    
    while(true)
    {
        int fileIndex;
        std::cin >> fileIndex;
        
        if(fileList[fileIndex].find(".ch8") != std::string::npos)
        {
            const char* cvFileName = fileList[fileIndex].data();
            instance.loadROM(cvFileName);
            delete[] fileList;
            break;
        }
        else
        {
            std::cout << "Not the correct ROM type, select file with the .ch8 extension\n" << std::endl;
        }
    }

    instance.CPU();
    
    return 0;
}