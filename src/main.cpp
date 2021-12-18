#include <iostream>
#include <cstdint>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "BrainFuck/Interpreter.h"
#include "Interpreter.cpp"
#include "ver.h"

namespace po = boost::program_options;
namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
    std::string fileName;
    int cellSize;

    po::options_description desc("Usage: brainfuck [options]\nAllowed options");
    desc.add_options()("help,h", "show help message")("version,v", "show version info")("cell-size", po::value<int>()->default_value(8), "specify cell size")("input-file", po::value<std::string>(), "input file");

    po::positional_options_description pos;
    pos.add("input-file", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(pos).run(), vm);
    po::notify(vm);

    if (vm.count("version"))
    {
        std::cout << "BrainFuck Interpreter" << std::endl
                  << "Version: " << ver << std::endl;
        return 0;
    }
    else if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }
    else if (!vm.count("input-file"))
    {
        std::cerr << desc << std::endl;
        return 1;
    }

    fileName = vm["input-file"].as<std::string>();
    cellSize = vm["cell-size"].as<int>();

    fs::path filePath(fileName);

    if (!fs::exists(filePath) || !fs::is_regular_file(filePath))
    {
        std::cerr << "[Error] The file does not exists" << std::endl;
        return 1;
    }

    switch (cellSize)
    {
    case 8:
    {
        Interpreter<uint8_t> interpreter;
        char *instructions = interpreter.readFile(fileName);
        interpreter.interpret(instructions);
        break;
    }
    case 16:
    {
        Interpreter<uint16_t> interpreter;
        char *instructions = interpreter.readFile(fileName);
        interpreter.interpret(instructions);
        break;
    }
    case 32:
    {
        Interpreter<uint32_t> interpreter;
        char *instructions = interpreter.readFile(fileName);
        interpreter.interpret(instructions);
        break;
    }
    default:;
    }
    return 0;
}