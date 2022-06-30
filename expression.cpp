#include "utility.hpp"
#include "term.hpp"
#include "expression.hpp"

using namespace std;

bool Expression::is_valid(const vector<Term>& v)
{
    int l_parentheses = 0;
    int r_parentheses = 0;
    for(int i = 0; i<v.size(); ++i) {
        if(v[i].type == '(')
            l_parentheses++;
        else if(v[i].type == ')')
            r_parentheses++;
        if(l_parentheses < r_parentheses) {
            cerr << "[Improper Grouping]" << endl;
            return false;
        }
    }
    if(l_parentheses != r_parentheses) {
        cerr << "[Missing Parenthesis]" << endl;
        return false;
    }
    return true;
}

bool Expression::is_distributed(const vector<Term>& v)
{
    for(int i = 0; i<v.size(); i++) {
        if(v[i].type == '(')
            return false;
    }
    return true;
}

bool Expression::compare_var(const Term& t2, const Term& t1) // arguments passed are automatically generated
{                                                           // should always have 2 parameters, parameters should not be array types
    if(t2.var.size() == 0 || (t1.var.size() == 0 && t2.var.size() == 0))
        return false;
    else if(t1.var.size() == 0)
        return true;
    else
        for(int i = 0; i<t1.var.size(); i++) {
            if((t1.var[i].second < t2.var[i].second) || (t1.var[i].first > t2.var[i].first))
                return true;
        }
    return false;
}

vector<pair<char, int>> Expression::combine_var(vector<pair<char,int>> v1, const vector<pair<char,int>>& v2)
{
    for(int i = 0; i<v2.size(); i++) {
        v1.push_back(v2[i]);
    }
    return v1; // if called from distribute, constructor will automatically be called, sorting the variables
}

void Expression::standard_form(vector<Term>& v) // rearranges expression into standard form
{
    sort(v.begin(), v.end(), compare_var); // pass an array type for 1st & 2nd arg, 3rd arg needs to return bool
}                                           // no need to pass args on the 3rd parameter

void Expression::distribute(vector<Term>& v)
{
    while(!is_distributed(v)) {
        vector<Term> temp;
        int lpar1 = -1, rpar1 = -1; // points to the position of parenthesis
        int lpar2 = -1, rpar2 = -1;
        int prev_par = -1;

        for(int i = 0; i<v.size(); i++) { // set pointers
            if(v[i].type == '(' && v[lpar1].type != '(') {
                lpar1 = i;
            }
            if(v[lpar1].type == '(' || v[lpar2].type == '(') {
                for(int j = i+1; j<v.size(); j++) {
                    if(v[j].type == ')') {
                        if(v[rpar1].type == ')')
                            rpar2 = j;
                        else
                            rpar1 = j;
                        i = j;
                        break;
                    } else if(v[j].type == '(') { // finds another left parenthesis after another
                        prev_par = lpar1;
                        lpar1 = j;
                        i = j;
                        break;
                    }
                }
            }
            if(v[rpar1].type != ')')
                continue;
            if(v[rpar1+1].type == '(' && v[lpar2].type != '(' && rpar1+1 < v.size()) {
                lpar2 = rpar1+1;
                i = lpar2;
            } else {
                break;
            }
        }

        for(int i = 0; i<lpar1-1; i++) { // copy tokens up to '('
            temp.push_back(v[i]);
        }
        //cout << "v1: "; print_exp(v); cout << endl;
        //cout << "Temp1: "; print_exp(temp); cout << endl;
        if(lpar2 > -1) {
            for(int i = lpar1-1; i<lpar1+1; i++)
                temp.push_back(v[i]);
        }
        //cout << "v2: "; print_exp(v); cout << endl;
        //cout << "Temp2: "; print_exp(temp); cout << endl;

        if(lpar2 == -1 && rpar2 == -1) { // if eg: 4(2x+1)
            for(int i = lpar1+1; i<rpar1; i++) {
                if(v[lpar1-1].type == 'n' && v[i].type == 'n') {
                    temp.push_back(Term(v[lpar1-1].num * v[i].num, combine_var(v[lpar1-1].var, v[i].var)));
                }
            }
        } else { // if eg: (4x+2)(2x+1)
            for(int i = lpar1+1; i<rpar1; i++) {
                for(int j = lpar2+1; j<rpar2; j++) {
                    if(v[i].type == 'n' && v[j].type == 'n') {
                        temp.push_back(Term(v[i].num * v[j].num, combine_var(v[i].var, v[j].var)));
                    }
                }
            }
        }
        if(lpar2 > -1)
            temp.push_back(Term(')'));

        int ntemp = 0;
        if(rpar2 > -1)
            ntemp = rpar2+1;
        else
            ntemp = rpar1+1;
        for(int i = ntemp; i<v.size(); i++) {
            temp.push_back(v[i]);
        }
        //cout << "Temp End: "; print_exp(temp); cout << endl;
        v = temp;
        //cout << "V End: ";
        print_exp(v); cout << endl;
    }
}

void Expression::combine_like_terms(vector<Term>& v)
{
    for(int i = 0; i<v.size(); i++) {
        if(v[i].type == 'n') {
            for(int j = i+1; j<v.size(); j++) {
                if(v[j].type == 'n' && v[i].var == v[j].var) {
                    v[i].num += v[j].num;
                    v.erase(v.begin()+j);
                    j--; // so we dont miss an element when erasing
                    print_exp(v); cout << endl;
                }
            }
        }
    }
}

void Expression::simplify(vector<Term>& v)
{
    distribute(v);
    combine_like_terms(v);
    standard_form(v);
}

void Expression::print_exp(const vector<Term>& v, bool debug) // prints the expression
{                                                               // bool parameter is defaulted to false
    if(debug) { // parsed display for debugging
        for(int i = 0; i<v.size(); i++) {
            cout << "[" << i << "] | ";
            cout << v[i].type << " | " << v[i].num << " | ";
            for(int j = 0; j<v[i].var.size(); j++) {
                cout << v[i].var[j].first;
                if(v[i].var[j].second > 1 || v[i].var[j].second < 0)
                    cout << "^" << v[i].var[j].second;
            }
            cout << endl;
        }
    } else { // normal display
        for(int i = 0; i<v.size(); i++) {
            if(i != 0 && v[i].num > 0 && v[i-1].type != '(')
                cout << '+';
            if(v[i].type == 'n' && (v[i].num != 1 || v[i+1].type != '('))
                cout << v[i].num;
            else if(is_operator(v[i].type))
                cout << v[i].type;
            if(v[i].var.size() != 0) {
                for(int j = 0; j<v[i].var.size(); ++j) {
                    cout << v[i].var[j].first;
                    if(v[i].var[j].second > 1 || v[i].var[j].second < 0)
                        cout << "^" << v[i].var[j].second;
                }
            }
        }
    }
}
