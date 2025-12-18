#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include "_TOK_TAB.h"

using namespace std;

const struct TW : map <string, int>{
    TW(){
        insert(pair<string, int>("if",NUM_IF));
        insert(pair<string, int>("then",NUM_THEN));
        insert(pair<string, int>("read",NUM_READ));
        insert(pair<string, int>("print",NUM_PRINT));
        insert(pair<string, int>("+",NUM_PLUS));
        insert(pair<string, int>("-",NUM_MINUS));
        insert(pair<string, int>("*",NUM_MULT));
        insert(pair<string, int>("/",NUM_FISS));
        insert(pair<string, int>("=",NUM_EQ));
        insert(pair<string, int>("(",NUM_LB));
        insert(pair<string, int>(")",NUM_RB));
    }
} token_word;

map<string,int> token_id;
map<int,int> token_dig;

int find_word(const string&s){
    map<string, int>::const_iterator i = token_word.find(s);
    return i != token_word.end() ? i->second : 0;
}

int make_id (const string& s){
    map<string, int>::iterator i = token_id.find(s);
    if(i != token_id.end())
        return i->second;
    else
        token_id.insert(pair<string,int>(s,token_id.size()+1));
        return token_id.size();

}


int make_dig(int d){
    map<int, int>::const_iterator i = token_dig.find(d);
    if(i != token_dig.end())
        return i->second;
    else
        token_dig.insert(pair<int,int>(d,token_dig.size()+1));
        return token_dig.size();
}


int val_dig(int num){
    map<int,int>::const_iterator i =token_dig.begin();
    for(;i!= token_dig.end(); ++i)
        if(i->second == num)return i->first;
        throw new string("ERROR: constant not found");
    return -1;
}






