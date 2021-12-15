#include "header.hpp"
#include "parser.hpp"
#include "expression.hpp"

using namespace std;

bool Expression::is_valid(const vector<Token>& v)
{
    Token t;
    for(int i = 0; i<v.size(); ++i) {
        if(t.is_operator(v[i].type) && t.is_operator(v[i+1].type) || t.is_letter(v[i].var) && t.is_letter(v[i+1].var)) {
            throw "error";
        }
    }
}

void Expression::simplify(vector<Token>& v)
{
    if(v[0].type == '-') { // makes - | 2 |  to n | -2 |
        v[1].num *= -1;
        v.erase(v.begin());
    }
    for(int i = 0; i<v.size(); ++i) {
            if(v[i].type == 'n') {
                for(int j = i+1; j<v.size(); ++j) {
                    if(v[j].var == v[i].var && v[j].type == 'n') { // checks if its the same variable and if its a number
                        switch(v[j-1].type) { // checks the operator before it
                        case '+':
                            v[i].num += v[j].num;
                            break;
                        case '-':
                            v[i].num -= v[j].num;
                            break;
                        }
                        v.erase(v.begin()+(j-1), v.begin()+(j+1)); // erases the number and the operator
                        j--; // resets iterator so it wont skip any other number
                    }
                }
            }
    }

    for(int i = 0; i<v.size(); ++i) {
        if(i == 0 && v[i].num == 0 && v[i+1].type == '+') {
            v.erase(v.begin()+i, v.begin()+(i+2));
        } else if(i == 0 && v[i].num == 0 && v[i+1].type == '-') {
            v.erase(v.begin()+i);
        }
        if(i != 0 && v[i].num == 0) {
            v.erase(v.begin()+i, v.begin()+(i+1));
        }
    }
}
