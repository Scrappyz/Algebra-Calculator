#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

using namespace std;

class Expression : public Term {
public:
    vector<Term> exp;

    Expression() : Term(), exp() {}

    bool is_valid(const vector<Term>&); // helper functions
    bool is_distributed(const vector<Term>&);
    static bool compare_var(const Term&, const Term&);
    vector<pair<char, int>> combine_var(vector<pair<char,int>>, const vector<pair<char,int>>&);

    void standard_form(vector<Term>&);
    void distribute(vector<Term>&);
    void combine_like_terms(vector<Term>&);
    void simplify(vector<Term>&);
    void print_exp(const vector<Term>&, bool = false);
};

#endif // EXPRESSION_HPP_INCLUDED
