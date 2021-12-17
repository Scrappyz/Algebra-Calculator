#include "header.hpp"
#include "utility.hpp"
#include "parser.hpp"

using namespace std;

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
            return Token(d, ch);
        }
        cin.unget();
        return Token(d);
    } else if(is_operator(ch)) {
        return Token(ch);
    } else if(is_letter(ch)) {
        return Token(1, ch);
    } else {
        cerr << "Unknown Token" << endl;
    }
}
