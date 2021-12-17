#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

class Token;

class Expression {
public:
    Expression()
    {
        exp.clear();
    }

    std::vector<Token> exp;

    bool is_valid(const std::vector<Token>&);
    void combine_operator(std::vector<Token>&);
    void standard_form(std::vector<Token>&);
    void simplify(std::vector<Token>&);
    void remove_unused(std::vector<Token>&);
};

#endif // EXPRESSION_HPP_INCLUDED
