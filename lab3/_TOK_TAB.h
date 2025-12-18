#ifndef _TOK_TAB
#define _TOK_TAB
#include <map>
#include <string>
using namespace std;

enum{NUM_WORD=1, NUM_DIG, NUM_ID};
enum{NUM_IF=1,NUM_THEN,NUM_READ,NUM_PRINT,NUM_PLUS,NUM_MINUS,NUM_MULT,NUM_FISS,NUM_EQ, NUM_LB, NUM_RB, NUM_GOTO, NUM_ELSE};
enum{P_ID=1, P_IDX, P_OP, P_DIG};



extern const struct TW token_word;
extern map <string,int> token_id;
extern map <int,int> token_dig;

int find_word(const string&);
int make_id(const string&);
int make_dig(int);
int val_dig(int num);

#endif
