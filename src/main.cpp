#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <vector>

enum class TokenType {
    _return,
    lit,
    lit_int,
    semi
};

struct Token {
    TokenType type;
    std::optional<std::string> value {};
};

std::vector<Token> tokenize(const std::string& str){
    std::vector<Token> tokens {};
    std::string buf = "";

    for (int i = 0; i < str.length(); ++i){
        char c = str.at(i);
        if (std::isalpha(c)) {
            buf.push_back(c);
            ++i;
            while (std::isalnum(str.at(i))) {
                buf.push_back(str.at(i));
                ++i;
            }
            --i;
            tokens.push_back({.type = TokenType::lit, .value = buf});
            buf.clear();
        } else if (std::isdigit(c)) {
            buf.push_back(c);
            ++i;
            while(std::isdigit(str.at(i))) {
                buf.push_back(str.at(i));
                ++i;
            }
            --i;
            tokens.push_back({.type = TokenType::lit_int, .value = buf});
            buf.clear();
        } else if (std::isspace(c)) {
            continue;
        }
    }   

    return tokens;
}

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
    std::vector<Token> tokens = tokenize(content);
    for (const Token& token : tokens) {
        std::cout << *token.value << std::endl;
    }
    return EXIT_SUCCESS;
}
