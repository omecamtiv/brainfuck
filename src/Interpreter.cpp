#include <cstdio>
#include <fstream>

#include "BrainFuck/Interpreter.h"

template <class T>
Interpreter<T>::~Interpreter()
{
    delete[] buffer;
}

template <class T>
char *Interpreter<T>::readFile(std::string fileName)
{
    std::ifstream file(fileName, std::ios::ate);
    if (file.is_open())
    {
        std::streampos size = file.tellg();
        fileSize = long(size);
        buffer = new char[size];

        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        char instructions[int(size)];
    }
    return buffer;
}

template <class T>
void Interpreter<T>::interpret(char *buffer)
{
    char *code = buffer;
    int inLoop, isLooping = 0;
    bool jump = false;

    while (code <= buffer + fileSize)
    {
        if ((inLoop == 0) || (inLoop == isLooping) || (*code == '[') || (*code == ']'))
        {
            switch (*code)
            {
            case '+':
                ++(*ptr);
                break;
            case '-':
                --(*ptr);
                break;
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                ++inLoop;
                if (*ptr)
                {
                    if (!jump)
                    {
                        stack.push(code);
                        ++isLooping;
                    }
                    else
                        --inLoop;
                }
                jump = false;
                break;
            case ']':
                if (*ptr)
                {
                    code = stack.top();
                    jump = true;
                    --code;
                }
                else
                {
                    if (inLoop == isLooping)
                    {
                        --inLoop;
                        --isLooping;
                        stack.pop();
                    }
                    else
                        --inLoop;
                }
                break;
            default:;
            }
        }
        ++code;
    }
}