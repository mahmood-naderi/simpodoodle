#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

#include "./tokenization.hpp"

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

//    std::cout << content;
    Tokenizer tokenizer(std::move(content));
    std::vector<Token> tokens = tokenizer.tokenize();
    for (const Token& token : tokens) {
        std::cout << *token.value << std::endl;
    }
    return EXIT_SUCCESS;
}
