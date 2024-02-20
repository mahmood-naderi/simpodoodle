#pragma once

#include <vector>
#include <string>

enum class TokenType {
    _return,
    lit,
    lit_int,
    semi,
};

struct Token {
    TokenType type;
    std::optional<std::string> value {};
};

class Tokenizer {
public:

    inline explicit Tokenizer(std::string src) : m_src(std::move(src)) {
    
    }

    inline std::vector<Token> tokenize() {
        std::vector<Token> tokens;

        return tokens;
    }

private:
    [[nodiscard]] std::optional<char> peak(int ahead = 1) const {
        if (m_index + ahead >= m_src.length()) {
            return {};
        } else {
            return m_src.at(m_index);
        }
    }

    char consume() {
        return m_src.at(m_index++);
    }

    const std::string m_src;
    int m_index;
    
};
