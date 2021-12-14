#ifndef PARSER_HPP_INCLUDED
#define PARSER_HPP_INCLUDED

using namespace std;

class Token_stream;

class Token {
public:
    Token() : type(), num(), var() {}

    string input;
    char temp;
    string buffer;

    char type;
    double num;
    char var;

    void get(Token_stream&);
    void putback();
    bool is_number(const char&);
    bool is_letter(const char&);
    bool is_operator(const char&);
};

class Token_stream {
public:
    stringstream input;
    string buffer;

    char temp;
};

#endif // PARSER_HPP_INCLUDED
