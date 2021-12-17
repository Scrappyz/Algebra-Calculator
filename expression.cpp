#include "header.hpp"
#include "utility.hpp"
#include "parser.hpp"
#include "expression.hpp"

using namespace std;

bool Expression::is_valid(const vector<Token>& v)
{
    //Token t;
    for(int i = 0; i<v.size(); ++i) {
        if(i == 0 && v[i].type == '-' && v[i+1].type != 'n') {
            return false;
        }
    }
    return true;
}

void Expression::combine_operator(vector<Token>& v) // combines '+' or '-' to the number next to them eg: - | 0 | to n | -4
{                                                   // to make simplification easier
    for(int i = 0; i<v.size(); ++i) {
        if(v[i].type == '+') {
            v.erase(v.begin()+i);
        } else if(v[i].type == '-') {
            v[i+1].num *= -1;
            v.erase(v.begin()+i);
        }
    }
}

void Expression::remove_unused(vector<Token>& v) // removes useless tokens like zeros
{
    for(int i = 0; i<v.size(); ++i) {
        if(is_operator(v[i].type) || v[i].num == 0) {
            v.erase(v.begin()+i);
            i--;
        }
    }
}

void Expression::standard_form(vector<Token>& v) // sorts variables into standard form
{
    for(int i = 1; i<v.size(); ++i) {
        if(v[i].var < v[i-1].var && v[i].num < v[i-1].num && v[i].var != '\0') { // sorts in alphabetical and numerical order
            swap(v[i], v[i-1]);
        } else if(v[i-1].var == '\0') { // if its a constant, move to the end of expression
            swap(v[i-1], v[v.size()-1]);
        }
    }
}

void Expression::simplify(vector<Token>& v)
{
    combine_operator(v);
    for(int i = 0; i<v.size(); ++i) {
        if(v[i].type == 'n') {
            for(int j = i+1; j<v.size(); ++j) {
                if(v[j].type == 'n' && v[j].var == v[i].var) {
                    v[i].num += v[j].num; // because of combine_operator(), '+' and '-' will solve themselves
                    v.erase(v.begin()+j);
                    j--; // so we dont miss an element when erasing
                }
            }
        }
    }
    remove_unused(v);
    standard_form(v);
}
