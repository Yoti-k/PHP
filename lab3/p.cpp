#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <stack>  
// na buduschee ):


const int P_DIG = 1;
const int P_ID = 2;
const int P_IDX = 3;
const int P_OP = 4;

const int NUM_PLUS = 10;
const int NUM_MINUS = 11;
const int NUM_MULT = 12;
const int NUM_FISS = 13;
const int NUM_EQ = 20;
const int NUM_PRINT = 21;
const int NUM_GOTO = 22;
const int NUM_IF = 23;

extern std::vector<POLIZ> poliz;
extern std::map<int, int> id;  

void exec() {
    std::stack<POLIZ> s;
    auto p = poliz.begin();
    POLIZ a, b;
    int x, y;

    for (; p != poliz.end(); ++p) {
        if (p->type == P_DIG || p->type == P_ID || p->type == P_IDX) {
            s.push(*p);
        }
        else if (p->type == P_OP) {
            if (p->val == NUM_PLUS ||
                p->val == NUM_MINUS ||
                p->val == NUM_MULT ||
                p->val == NUM_FISS) {
                a = s.top();
                s.pop();
                if (a.type == P_DIG)
                    x = a.val;
                else if (a.type == P_ID)
                    x = id[a.val];

                b = s.top();
                s.pop();
                if (b.type == P_DIG)
                    y = b.val;
                else if (b.type == P_ID)
                    y = id[b.val];

                switch (p->val) {
                    case NUM_PLUS:
                        s.push(POLIZ{P_DIG, x + y});
                        break;
                    case NUM_MINUS:
                        s.push(POLIZ{P_DIG, y - x});
                        break;
                    case NUM_MULT:
                        s.push(POLIZ{P_DIG, x * y});
                        break;
                    case NUM_FISS:
                        s.push(POLIZ{P_DIG, y / x});
                        break;
                }
            }
            else {
                switch (p->val) {
                    case NUM_EQ:
                        a = s.top();
                        s.pop();
                        b = s.top();
                        s.pop();
                        id[b.val] = a.val;
                        break;
                    case NUM_PRINT:
                        a = s.top();
                        s.pop();
                        std::cout << id[a.val] << std::endl;
                        break;
                    case NUM_GOTO:
                        a = s.top();
                        s.pop();
                        p += (a.val - 1) - std::distance(poliz.begin(), p);
                        break;
                    case NUM_IF:
                        b = s.top();
                        s.pop();
                        a = s.top();
                        s.pop();
                        if (!id[a.val])
                            p += (b.val - 1) - std::distance(poliz.begin(), p);
                        break;  
                }
            }
        }
    }
}
