#include "utility.hpp"
#include "term.hpp"

using namespace std;

Term Term::get()
{
    vector<pair<char, int>> v;
    double d = 1;
    int temp = 1;
    char ch;
    cin.get(ch);
    if(ch == '+' || ch == '-') {
        if(ch == '-')
            temp = -1;
        cin.get(ch);
        if(ch == '(') {
            unget();
            return Term(double(temp));
        }
    }
    if((is_number(ch) || is_letter(ch))) {
        unget();
        if(is_number(ch))
            cin >> d;
        while(cin.get(ch)) {
            if(!is_letter(ch))
                break;
            char c;
            double expo = 1;
            cin.get(c);
            if(c == '^') {
                cin >> expo;
                v.push_back(make_pair(ch, expo));
                continue;
            }
            unget();
            v.push_back(make_pair(ch, expo));
        }
        unget();
        if(d == 0)
            return Term(0.0);
        return Term(d*temp, v);
    } else if(is_operator(ch) && (ch != '+' && ch != '-')) {
        return Term(ch);
    } else {
        cerr << "Unknown Token" << endl;
    }
    return Term();
}

void temp(const vector<pair<char, int>>& v) // delete when done
{
    for(int i = 0; i<v.size(); i++) {
        cout << v[i].first << " | " << v[i].second << endl;
    }
    cout << endl;
}

void Term::remove_dups(vector<pair<char, int>>& v)
{
    for(int i = 1; i<v.size(); i++) {
        if(v[i-1].first == v[i].first) {
            v[i-1].second += v[i].second;
            v.erase(v.begin()+(i));
            if(v[i-1].second == 0)
                v.erase(v.begin()+(i-1));
        }
    }
}
