#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

class Token {
public:
    Token() : type(), num(), var() {}
    Token(char ch) : type(ch), num(), var() {}
    Token(double n) : type('n'), num(n), var() {}
    Token(double n, char v) : type('n'), num(n), var(v) {}

    char type;
    double num;
    char var;

    Token get();
};

#endif // PARSER_HPP_INCLUDED
