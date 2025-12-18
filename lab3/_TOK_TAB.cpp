#include "_TOK_TAB.cc"

int main(){
    std::cout<<"find_word(+)="<<find_word("+")<<std::endl;
    std::cout<<"find_word(*)="<<find_word("*")<<std::endl;
    std::cout<<"find_word(read)="<<find_word("read")<<std::endl;
    std::cout<<"find_word(print)="<<find_word("print")<<std::endl;

    std::cout<<"make_id(a1)="<<make_id("a1")<<std::endl;
    std::cout<<"make_id(a2)="<<make_id("a2")<<std::endl;
    std::cout<<"make_id(a1)="<<make_id("a1")<<std::endl;

    std::cout<<"make_dig(12)="<<make_dig(12)<<std::endl;
    std::cout<<"make_dig(255)="<<make_dig(255)<<std::endl;
    std::cout<<"make_dig(12)="<<make_dig(12)<<std::endl;

    std::cout<<"val_dig(1)="<<val_dig(1)<<std::endl;
}
