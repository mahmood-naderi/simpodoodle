#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Wrong usage <simp> ..." << std::endl;
        std::cerr << "Correct usage : simp <file_name>" << std::endl;
        return EXIT_FAILURE;
    } 


    std::fstream input(argv[1], std::ios::in);
    std::stringstream contentStream;
    contentStream << input.rdbuf();
    input.close();
    std::string content = contentStream.str();

    std::cout << content;

    return EXIT_SUCCESS;
}
