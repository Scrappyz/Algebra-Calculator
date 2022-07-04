#ifndef TERM_HPP_INCLUDED
#define TERM_HPP_INCLUDED

using namespace std;

class Term : public Utility {
public:
    char type;
    double num;
    vector<pair<char, int>> var; // variable and exponent

    Term() : type(), num(), var() {}
    Term(char ch) : type(ch), num(), var() {} // if operator eg: '+'
    Term(double n) : type('n'), num(n), var() {} // if number eg: 2
    Term(double n, const vector<pair<char, int>>& v) : type('n'), num(n), var(v) // if num and var eg: 2xyz
    {
        if(var.size() > 1) {
            sort(var.begin(), var.end());
            remove_dups(var);
        }
    }

    Term get();
    void clean(vector<Term>&);
    void remove_dups(vector<pair<char, int>>&);
};

#endif // TERM_HPP_INCLUDED
