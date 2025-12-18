#ifndef _SCAN
#define _SCAN
#include <vector>
struct LEX{
    LEX(int _tab, int _num):
    tab(_tab), num(_num) {};
    int tab;
    int num;
};
void scan(std::vector<LEX>&,const std::vector<char>&);
std::ostream & operator<<(std::ostream&, LEX const&);
#endif
