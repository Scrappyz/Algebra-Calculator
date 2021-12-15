#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

class Token;

class Equation {
public:
    Equation()
    {
        left.clear();
        right.clear();
    }

    std::vector<Token> left;
    std::vector<Token> right;
};

#endif // EXPRESSION_HPP_INCLUDED
