#include "header.hpp"
#include "parser.hpp"

using namespace std;

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
    case '*':
    case '/':
    case '=':
    case '(':
    case ')':
        return true;
    default:
        return false;
    }
}

void Token::get(Token_stream& ts)
{
    //cout << "get: " << ts.input << endl;

    ts.input >> temp; // to take characters
    if(is_number(temp)) {
        type = 'n';
        ts.input.putback(temp); // putback number char
        ts.input >> num; // then take in to a double type
        ts.input.get(temp);  // to get '\n' as well
        if(is_letter(temp)) {
            var = temp;
            return;
        }
        ts.input.putback(temp);
    } else if(is_letter(temp)) {
        type = 'n';
        num = 1;
        var = temp;
        return;
    } else if(is_operator(temp)) {
        type = temp;
        return;
    }
}
/*
void Token::get()
{
    cin >> temp; // to take characters
    if(is_number(temp)) {
        type = 'n';
        cin.putback(temp); // putback number char
        cin >> num; // then take in to a double type
        cin.get(temp);  // to get '\n' as well
        if(is_letter(temp)) {
            var = temp;
            return;
        }
        cin.putback(temp);
    } else if(is_letter(temp)) {
        type = 'n';
        num = 1;
        var = temp;
        return;
    } else if(is_operator(temp)) {
        type = temp;
        return;
    }
}
*/
