#ifndef P_H
#define P_H

#include "_TOK_TAB.h"
#include "scan.h"
#include <vector>
#include <set>

using namespace std;
struct POLIZ {
  POLIZ(int _1=0,int _2=0):
    type(_1),val(-2){}
    int type;
    int val;
};

extern vector<LEX> poliz_lex;
extern vector<LEX>::iterator i;
extern set<int> id_With_val;

int val_dig(int num);
void add_P(int type, int val);
int idx_P();
void add_idx_P(int idx);
void S();
void E();
void T();
void F();

#endif
