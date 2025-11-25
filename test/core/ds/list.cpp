#include "core/ds/list.hpp"
#include "iostream"

class TestList : public expp::IntrusiveList<TestList>{
    public:
        int i = 0;

};

int main(){
    TestList list;
    TestList a; a.i = 10;
    list.append(&a);
    std::cout << ((TestList*)list.getNext())->i; 

}