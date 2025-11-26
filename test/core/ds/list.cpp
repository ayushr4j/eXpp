#include "core/ds/intrusive_list.hpp"
#include "iostream"

class TestList : public expp::IntrusiveList<TestList>{
    public:
        int i = 0;

};

template<typename t>
class Test{
    t a;
};

int main(){
    
    Test<int> d;
    Test<int*> e;
    
    TestList list;
    TestList a; a.i = 10;
    list.append(&a);
    std::cout << ((TestList*)list.getNext())->i; 

}