#include "header.hpp"
#include "parser.hpp"

using namespace std;

/*string remove_zeros(string str)
{
    str.erase ( str.find_last_not_of('0') + 1, string::npos );
    if(str[str.size()-1] == '.') {
        str.erase ( str.find_last_not_of('.') + 1, string::npos );
    }
    return str;
}*/

double primary(Token&);
double term(Token&);
double expression(Token&);
double equation(Token&, const char&);

double equation(Token& t, const char& var) // solves for variable
{
    //double constant = expression(t, '');
    double left = expression(t);
    double right;
    while(true) {
        right -= left;
    }
}

double expression(Token& t) // combines like terms
{
    double c = term(t);

}

double term(Token& t) // distributes if needed
{
    double c = primary(t);
}

double primary(Token& t) // gets numbers
{
    //t.get();
    //if(t.type == 'n' && t.var == )
}

int main()
{
    Token t;
    Token_stream ts;
    string str;
    cin >> str;
    ts.input << str;
    char ch;
    while(ts.input.get(ts.temp)) {
        if(ch == '\n') { break; }
        ts.input.unget();
        t = Token();
        t.get(ts);
        cout << t.type << " | " << t.num << " | " << t.var << endl;
    }
}
