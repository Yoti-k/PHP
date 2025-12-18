#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <set>
#include "p.h"

using namespace std;

vector<POLIZ> poliz;
vector<LEX>::iterator i;
set<int> id_With_val;

int p1, p2;

void add_P(int type, int val) {
    poliz.push_back(POLIZ(type, val));
}

int idx_P() {
    return poliz.size() - 1;
}

void add_idx_P(int idx) {
    poliz[idx].val = poliz.size();
}

void add_IF() {
    add_P(P_ID, i->num);
    add_P(P_IDX, -1);
    p1 = idx_P();
    add_P(P_OP, NUM_IF);
}

void add_ELSE() {
    add_P(P_IDX, -2);
    p2 = idx_P();
    add_P(P_OP, NUM_GOTO);
    add_idx_P(p1);
}

void S() {
    if (i == vector<LEX>::iterator()) {
        throw string("S: итератор не инициализирован");
    }

    if (i->tab == NUM_WORD && i->num == NUM_IF) {
        ++i;
        if (i == vector<LEX>::iterator() || i->tab != NUM_ID) {
            throw string("S усл. опер: ожидается идентификатор после IF");
        }
        if (id_With_val.find(i->num) == id_With_val.end()) {
            throw string("sem_if: Переменная без значения");
        }
        add_P(P_ID, i->num);
        add_P(P_IDX, -1);
        p1 = idx_P();
        add_P(P_OP, NUM_IF);
        ++i;
        if (i == vector<LEX>::iterator() || !(i->tab == NUM_WORD && i->num == NUM_THEN)) {
            throw string("S усл. опер: ожидается THEN");
        }
        ++i;
        S();
        add_P(P_OP, NUM_GOTO);
        add_idx_P(p1);
        if (i == vector<LEX>::iterator() || !(i->tab == NUM_WORD && i->num == NUM_ELSE)) {
            throw string("S усл. опер: ожидается ELSE");
        }
        ++i;
        S();
        add_idx_P(p2);
    }
    else if (i->tab == NUM_ID) {
        int memo_num = i->num;
        add_P(P_ID, memo_num);
        ++i;
        if (i == vector<LEX>::iterator() || !(i->tab == NUM_WORD && i->num == NUM_EQ)) {
            throw string("S присв.: ожидается оператор = после идентификатора");
        }
        ++i;
        E();
        id_With_val.insert(memo_num);
        add_P(P_OP, NUM_EQ);
    }
    else if (i->tab == NUM_WORD && i->num == NUM_PRINT) {
        ++i;
        if (i == vector<LEX>::iterator() || i->tab != NUM_ID) {
            throw string("S: после print ожидается идентификатор");
        }
        if (id_With_val.find(i->num) == id_With_val.end()) {
            throw string("sem_print: Переменная без значения");
        }
        add_P(P_ID, i->num);
        add_P(P_OP, NUM_PRINT);
        ++i;
    }
    else {
        throw string("S: нераспознанная конструкция. Текущий токен: tab=" +
                   to_string(i->tab) + ", num=" + to_string(i->num));
    }
}

void E() {
    T();
    while (i != vector<LEX>::iterator() &&
           (i->num == NUM_PLUS || i->num == NUM_MINUS)) {
        int num_op = i->num;
        ++i;
        T();
        add_P(P_OP, num_op);
    }
}

void T() {
    F();
    while (i != vector<LEX>::iterator() &&
           i->tab == NUM_WORD &&
           (i->num == NUM_MULT || i->num == NUM_FISS)) {
        int num_op = i->num;
        ++i;
        F();
        add_P(P_OP, num_op);
    }
}

void F() {
    if (i == vector<LEX>::iterator()) {
        throw string("F: достигнут конец входных данных");
    }
    if (i->tab == NUM_DIG) {
        add_P(P_DIG, val_dig(i->num));
        ++i;
    }
    else if (i->tab == NUM_ID) {
        if (id_With_val.find(i->num) == id_With_val.end()) {
            throw string("sem_F: Переменная без значения");
        }
        add_P(P_ID, i->num);
        ++i;
    }
    else if (i->tab == NUM_WORD && i->num == NUM_LB) {
        ++i;
        E();
        if (i == vector<LEX>::iterator() || !(i->tab == NUM_WORD && i->num == NUM_RB)) {
            throw string("F: ожидается правая скобка");
        }
        ++i;
    }
    else {
        throw string("F: ожидается цифра, идентификатор или левая скобка. "
                    "Текущий токен: tab=" + to_string(i->tab) +
                    ", num=" + to_string(i->num));
    }
}
