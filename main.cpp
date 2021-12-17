#include "header.hpp"
#include "utility.hpp"
#include "parser.hpp"
#include "expression.hpp"
#include "equation.hpp"

using namespace std;

void input(Equation& eq, Expression& e)
{
    while(true) {
        Token t;
        e = Expression();
        char ch;
        while(cin.get(ch)) {
            if(ch == '\n' || ch == '=') { break; }
            if(!valid_token(ch)) {
                cerr << "[Invalid Token]" << endl;
                e = Expression();
                cinfail();
                break;
            }
            cin.unget();
            t = t.get();
            e.exp.push_back(t);
        }
        if(!e.is_valid(e.exp)) {
            cerr << "[Invalid Expression]" << endl;
            cin.clear();
            continue;
        }
        if(eq.left.size() == 0) {
            eq.left = e.exp;
        } else {
            eq.right = e.exp;
        }
        if(ch == '\n' || (eq.left.size() != 0 && eq.right.size() != 0)) { return; }
    }
}

int main()
{
    while(true) {
        Equation eq;
        Expression e;
        char ch;

        input(eq, e);
        if(eq.right.size() == 0) {
            e.simplify(eq.left);
            print_expression(eq.left);
        } else {
            e.simplify(eq.left);
            e.simplify(eq.right);
            if(eq.many_var()) {
                while(true) {
                    cout << "Find: ";
                    cin >> ch;
                    if(eq.does_exist(ch)) { break; }
                    cerr << "[Where tf is it?]\n";
                }
            } else {
                ch = eq.find_var();
            }
            eq.solve_for(ch);
            print_expression(eq.left);
            cout << " = ";
            e.standard_form(eq.right);
            print_expression(eq.right);
        }
        cout << "\n\nRetry? y/n/c: ";
        cin >> ch;
        cout << endl;
        if(ch == 'y') {
            cinfail();
            continue;
        } else if(ch == 'c') {
            cinfail();
            cls();
            continue;
        } else {
            return 0;
        }
    }
}
