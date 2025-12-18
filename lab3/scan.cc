#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "scan.h"
#include "_TOK_TAB.h"
using namespace std;

void scan(vector<LEX> & lexemes, const vector<char>&symbols) {
    string isaddsymb("=+-*/()");
    enum state {H,I,D,F,E} cs = H;
    vector<char>::const_iterator i = symbols.begin();
    string b; int j, d;
    int num_line = 1;
    do {
        switch(cs) {
           case H:
            if(*i=='n') ++num_line;
            if (isspace(*i)) ++i;
            else if (isalpha(*i)) {
                b.clear();
                b.push_back(*i++);
                cs=I;
            }
            else if (isaddsymb.find(*i) !=string::npos){
                lexemes.push_back(LEX(NUM_WORD, find_word(string(1, *i++))));
                cs=H;
            }
            else if (isdigit(*i)) {
                d=*i++-'0';
                cs=D;
            }
            else if (*i=='#') cs=F;
            else cs=E;
            break;
            case I:
                if (isalnum(*i)) b.push_back(*i++);
                else {
                    if (j=find_word(b)) lexemes.push_back(LEX(NUM_WORD,j));
                    else {
                        lexemes.push_back(LEX(NUM_ID,make_id(b)));
                    } cs=H;
                }
            break;
            case D:
                if (isdigit(*i))
                    d = 10*d+(*i++)-'0';
                else {
                    lexemes.push_back(LEX(NUM_DIG,make_dig(d)));
                    cs=H;
                }
            break;
        }
    } while (cs!=F && cs!=E);
    if (cs==E) {
        cerr << num_line << ' ';
        throw string("Scanner error");
    }
}
ostream& operator<<(ostream& s, LEX const& l) {
    s << '(';
    switch(l.tab) {
        case NUM_WORD: s << "WORD";
        break;
        case NUM_DIG: s << "DIG";
        break;
        case NUM_ID: s << "ID";
        break;
    }
    s << ',' << l.num << ')';
    return s;
}
