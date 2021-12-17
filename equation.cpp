#include "header.hpp"
#include "utility.hpp"
#include "parser.hpp"
#include "equation.hpp"

using namespace std;

bool Equation::does_exist(const char& ch) // checks if variable ch is in the equation
{
    for(int i = 0; i<left.size(); ++i) {
        if(left[i].var == ch) {
            on_left = true;
            return true;
        }
    }
    for(int i = 0; i<right.size(); ++i) {
        if(right[i].var == ch) {
            on_right = true;
            return true;
        }
    }
    return false;
}

void Equation::solve_for(const char& ch) // ch is the variable we are trying to find
{
    if(ch == '\0') { return; } // if ch is an empty character, skip this function

    if(on_right) {  // if ch is on the right, move it to the left
        for(int i = 0; i<right.size(); ++i) {
            if(right[i].var == ch) {
                right[i].num *= -1;
                left.insert(left.begin(), right[i]);
                right.erase(right.begin()+i);
            }
        }
    }
    for(int i = 0; i<left.size(); ++i) { // 1st phase: combines all ch variables from the right to the left
        if(left[i].var == ch) {
            for(int j = 0; j<right.size(); ++j) {
                if(right[j].var == ch) {
                    left[i].num -= right[j].num;
                    right.erase(right.begin()+j);
                }
            }
        }
    }
    /*
    cout << "1st:\n";
    print_expression(left);
    cout << "=";
    print_expression(right);
    cout << endl;
    */
    for(int i = 0; i<right.size(); ++i) { // 2nd phase: combines all non ch variables from the left to the right
        for(int j = 0; j<left.size(); ++j) {
            if(left[j].var != ch && left[j].var == right[i].var) {
                right[i].num -= left[j].num;
                left.erase(left.begin()+j);
                j--; // so we dont miss an element
            }
        }
    }
    /*
    cout << "\n2nd:\n";
    print_expression(left);
    cout << "=";
    print_expression(right);
    cout << endl;
    */
    for(int i = 0; i<left.size(); ++i) { // 3rd phase: leftover non ch variables will be moved to the right side
        if(left[i].var != ch) {
            left[i].num *= -1;
            right.push_back(left[i]);
            left.erase(left.begin()+i);
            i--; // so we dont miss an element
        }
    }
    /*
    cout << "\n3rd:\n";
    print_expression(left);
    cout << "=";
    print_expression(right);
    cout << endl;
    */
    for(int i = 0; i<right.size(); ++i) { // divide all on the right by the ch's coefficient on the left
        right[i].num /= left[0].num;
    }
    left[0].num /= left[0].num; // divide ch's coefficient by itself

}

bool Equation::many_var() // checks if there are multiple unique variables (left and right must be simplified)
{
    int counter = 0;
    char ch;
    for(int i = 0; i<left.size(); ++i) {
        if(left[i].var != '\0') {
            counter++;
            ch = left[i].var;
        }
        if(counter >= 2) { return true; }
    }
    for(int i = 0; i<right.size(); ++i) {
        if(right[i].var != '\0' && right[i].var != ch) {
            counter++;
        }
        if(counter >= 2) { return true; }
    }
    return false;
}

char Equation::find_var() // will be called if there is only 1 unique variable in the equation and then finds it
{
    for(int i = 0; i<left.size(); ++i) {
        if(left[i].var != '\0') {
            return left[i].var;
        }
    }
    for(int i = 0; i<right.size(); ++i) {
        if(right[i].var != '\0') {
            return right[i].var;
        }
    }
    return '\0';
}
