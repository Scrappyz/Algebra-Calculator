#include "utility.hpp"
#include "term.hpp"

using namespace std;

void Utility::cls()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void Utility::cinfail()
{
    cin.clear();
    cin.ignore(256, '\n');
}

void Utility::unget(int n)
{
    for(int i = 0; i<n; i++)
        cin.unget();
}

bool Utility::is_letter(char ch)
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

bool Utility::is_number(char ch)
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

bool Utility::is_operator(char ch)
{
    switch(ch) {
    case '+':
    case '-':
    case '(':
    case ')':
    case '/':
    case '^':
        return true;
    default:
        return false;
    }
}
