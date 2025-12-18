#include "_TOK_TAB.h"
#include "scan.h"
#include "p.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<LEX> test;
    vector<LEX>::const_iterator it;
    setlocale(0, "rus");
    const string s1 = "print  #";

    cout << "Тест 1 - Вывод: ";
    vector<char> vc1(s1.begin(), s1.end());
    scan(test, vc1);
    for (it = test.begin(); it != test.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    ::i = test.begin();

    try {
        while (::i != test.end()) {
            S();
        }
        cout << "Разбор успешно завершён." << endl;
    }
    catch (const string& err_msg) {
        cerr << "Ошибка разбора: " << err_msg << endl;
    }
    catch (const exception& e) {
        cerr << "Стандартная ошибка: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Неизвестная ошибка." << endl;
    }

    return 0;
}
