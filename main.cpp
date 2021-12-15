#include "header.hpp"
#include "expression.hpp"
#include "parser.hpp"
#include "equation.hpp"

using namespace std;

void print(const vector<Token>& v)
{
    for(int i = 0; i<v.size(); ++i) {
        cout << v[i].type << " | " << v[i].num << " | " << v[i].var << endl;
    }
}

void print_expression(const vector<Token>& v)
{
    for(int i = 0; i<v.size(); ++i) {
        cout << v[i].num << v[i].var << v[i].type;
    }
}

/*void input(Expression& e)
{
    Token t;
    char ch;
    while(true) {
        cin.get(ch);
        if(ch == '\n' || ch == '=') { break; }
        cin.unget();
        e.exp.push_back(t.get());
    }
    e.is_valid(e.exp);
    /*while(true) {
        cin.get(ch);
        if(ch == '\n') { break; }
        cin.unget();
        eq.right.push_back(t.get());
    }*/
//}

int main()
{
    Equation eq;
    Expression e;

    input(e);
    print(e.exp);
    cout << "============" << endl;
    //print(eq.right);

    e.simplify(e.exp);
    print(e.exp);
}
