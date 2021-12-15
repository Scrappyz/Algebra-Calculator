#include "header.hpp"
#include "parser.hpp"

using namespace std;

bool Token::is_number(const char& ch)
{
    switch(ch) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;
    default:
        return false;
    }
}

bool Token::is_operator(const char& ch)
{
    switch(ch) {
    case '+':
    case '-':
    case '(':
    case ')':
    case '/':
    case '=':
        return true;
    default:
        return false;
    }
}

bool Token::is_letter(const char& ch)
{
    switch(ch) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        return true;
    default:
        return false;
    }
}

Token Token::get()
{
    char ch;
    cin.get(ch);
    if(is_number(ch)) {
        cin.unget();
        double d;
        cin >> d;
        cin.get(ch);
        if(is_letter(ch)) {
            char v = ch;
            return Token(d, v);
        }
        cin.unget();
        return Token(d);
    } else if(is_operator(ch)) {
        return Token(ch);
    } else if(is_letter(ch)) {
        return Token(1, ch);
    } else {
        cerr << "Unknown token" << endl;
    }
}
