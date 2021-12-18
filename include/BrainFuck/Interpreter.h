#pragma once

#include <stack>
#include <string>

template <class T>
class Interpreter
{
    T array[30000] = {0};
    T *ptr = array;
    std::stack<char *> stack;

    char *buffer;
    long fileSize;

public:
    ~Interpreter();
    char *readFile(std::string fileName);
    void interpret(char *buffer);
};