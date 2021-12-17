#ifndef UTILITY_HPP_INCLUDED
#define UTILITY_HPP_INCLUDED

class Token;

void print_token(const std::vector<Token>&);
void print_expression(const std::vector<Token>&);
bool is_operator(const char&);
bool is_number(const char&);
bool is_letter(const char&);
bool valid_token(const char&);
void cinfail();
void cls();

#endif // UTILITY_HPP_INCLUDED
