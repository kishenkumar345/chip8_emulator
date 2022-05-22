#include <cstdint>
#include <fstream>
#include "chip8_VM.h"

#include <iostream> //Debug

void chip8VM::loadROM(const char* rom)
{
    //Read file as binary and move to end of file
    std::ifstream file(rom, std::ios::binary | std::ios::ate);
    
    if(file.is_open())
    {
        //Get file size and create an array of the same size
        std::streampos size = file.tellg();
        char* buffer = new char[size];
        //Go to the beggining of the file and fill array with file content
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();
        //Add file content into memory
        for(long i = 0; i < size; ++i)
        {
            memory[0x200 + i] = buffer[i];
        }
        //Delete to avoid null pointer
        delete[] buffer;
    }
}

void chip8VM::CPU()
{
    PC = memory[0x200];
    x =
    y =  

    switch(PC)
    {
        case 0x00E0:
            break;
        case 0x00EE:
            break;
        case 0x0FFF:
            //0NNN
            break;
        case 0x1000:
            //1NNN
            break;
        case 0x2000:
            //2NNN
            break;
        case 0x3000:
            //3XKK
            break;
        case 0x4000:
            //4XKK
            break;
        case 0x5000:
            //5XY0
            break;
        case 0x6000:
            //6XKK
            break;
        case 0x7000:
            //7XKK
            break;
        case 0x8000:
            switch(PC & 0xF) //PC & 0x000F
            {
                case 0x0:
                //8XY0
                    break;
                case 0x1:
                //8XY1
                    break;
                case 0x2:
                //8XY2
                    break;
                case 0x3:
                //8XY3
                    break;
                case 0x4:
                //8XY4
                    break;
                case 0x5:
                //8XY5
                    break;
                case 0x6:
                //8XY6
                    break;
                case 0x7:
                //8XY7
                    break;
                case 0xE:
                //8XYE
                    break;
            }
            break;
        case 0x9000:
            //9XY0
            break;
        case 0xA000:
            //ANNN
            break;
        case 0xB000:
            //BNNN
            break;
        case 0xC000:
            //CXNN
            break;
        case 0xD000:
            //DXYN
            break;
        case 0xE000:
            switch(PC & 0xF)
            {
                case 0xE:
                    //EX9E
                    break;
                case 0x1:
                    //EXA1
                    break;
            }
            break;
        case 0xF000:
            switch(PC & 0xFF)
            {
                case 0x07:
                    //FX07
                    break;
                case 0x0A:
                    //FX0A
                    break;
                case 0x15:
                    //FX15
                    break;
                case 0x18:
                    //FX18
                    break;
                case 0x1E:
                    //FX1E
                    break;
                case 0x29:
                    //FX29
                    break;
                case 0x33:
                    //FX33
                    break;
                case 0x55:
                    //FX55
                    break;
                case 0x65:
                    //FX65
                    break;
            }
            break;
    }
}