# BRAINFUCK INTERPRETER:

This is a BrainFuck interpreter written in C++ language.  
Brainfuck is an esoteric programming language created in 1993 by Urban Müller.  

## Dependency:

The program requires [Boost](https://www.boost.org/) library to work.  
Make sure it is installed in the system.

## How to install:

To compile the program from source [CMake](https://cmake.org/) has to be installed in system.  

1. Clone the repo or download and extract the compressed file.  
2. Open the folder.  
3. Run the installation script by `./install.sh`.  

To uninstall run `sudo make uninstall` from build directory.  

## How to use:

Running the program is easy.  
To run your code:  
```
brainfuck <path-to-file>
```

## Language design:

The brainfuck language uses a simple machine model consisting of the program and instruction pointer, as well as a one-dimensional array of at least 30,000 byte cells initialized to zero; a movable data pointer (initialized to point to the leftmost byte of the array); and two streams of bytes for input and output (most often connected to a keyboard and a monitor respectively, and using the ASCII character encoding).  

### Commands:

The eight language commands each consists of a single character:
```
'>' = Increment the data pointer (to point to the next cell to the right).
'<' = Decrement the data pointer (to point to the next cell to the left).
'+' = Increment (increase by one) the byte at the data pointer.
'-' = Decrement (decrease by one) the byte at the data pointer.
'.' = Output the byte at the data pointer.
',' = Accept one byte of input, storing its value in the byte at the data pointer.
'[' = If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
']' = If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.
```
### Some rules:

- Any arbitrary character besides the 8 listed above should be ignored by the compiler or interpretor.  
Characters besides the 8 operators should be considered as comments.
- All memory blocks on the "array" are set to zero at the beginning of the program.  
And the memory pointer starts out on the very left most memory block.
- Loops may be nested as many times as you want. But all '[' must have a corresponding ']'.

### Extra features:

This interpreter supports multiple sizes for the cells in array.  
The default size is 8 bits but can be changed to 16 or 32 bits by passing the `--cell-size` argument.  