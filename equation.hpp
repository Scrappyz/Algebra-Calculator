#ifndef EQUATION_HPP_INCLUDED
#define EQUATION_HPP_INCLUDED

class Token;

class Equation {
public:
    Equation() : on_left(false), on_right(false)
    {
        left.clear();
        right.clear();
    }

    std::vector<Token> left;
    std::vector<Token> right;

    void solve_for(const char&);
    bool many_var();
    bool does_exist(const char&);
    char find_var();
private:
    bool on_left;
    bool on_right;
};

#endif // EQUATION_HPP_INCLUDED
