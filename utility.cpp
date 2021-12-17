#include "header.hpp"
#include "utility.hpp"
#include "parser.hpp"

using namespace std;

class Token;

void cls()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void cinfail()
{
    cin.clear();
    cin.ignore(256, '\n');
}

void print_token(const vector<Token>& v) // print tokens for debug
{
    for(int i = 0; i<v.size(); ++i) {
        cout << v[i].type << " | " << v[i].num << " | " << v[i].var << endl;
    }
}

void print_expression(const vector<Token>& v) // prints the expression
{
    for(int i = 0; i<v.size(); ++i) {
        if(v[i].num > 0 && i != 0) {
            cout << '+';
        }
        if(v[i].num != 1 || v[i].var == '\0' && v[i].num == 1) {
            cout << v[i].num;
        }
        if(v[i].var != '\0') {
            cout << v[i].var;
        }
    }
}

bool is_letter(const char& ch)
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

bool is_number(const char& ch)
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
    case '0':
        return true;
    default:
        return false;
    }
}

bool is_operator(const char& ch)
{
    switch(ch) {
    case '+':
    case '-':
    case '(':
    case ')':
    case '/':
        return true;
    default:
        return false;
    }
}

bool valid_token(const char& ch)
{
    if(is_operator(ch) || is_letter(ch) || is_number(ch)) {
        return true;
    }
    return false;
}
