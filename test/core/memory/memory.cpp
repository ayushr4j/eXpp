
#include "core/memory/memory.hpp"
#include "core/exception.hpp"
#include "core/memory/allocator.hpp"
#include "core/exception.hpp"

#include "cstdint"
#include <cstdint>

class TestAllocation : public expp::memory::Memory{
public:
    TestAllocation(){};
    uint8_t a;
    uint8_t& get(size_t i){ return  a;}
};

class A{
    public:
    int x = 4;

    virtual void print(){
        std::cout << "A : " << x << " " << " \n";
    }
};
class B : public A{
    public:
    int y = 5;

    virtual void print(){
        std::cout << "B : " << x << " " << y << " \n";
    }
};
class Base{
    public:
    virtual A* create(){ return new A(); }
    virtual void test(A* a){ a->print(); }
};
class Derived : public Base{
    public:
    virtual B* create(){ return new B(); }
    virtual void test(B* b){ b->print(); }
};



int main(){

    Base *ptr = new Derived();
    A* a = ptr->create();
    ptr->test(a);
    

    expp::memory::Allocator *allocator = new expp::memory::Allocator();
    expp::memory::Memory* mem = allocator->allocate(1024,1);
    expp::Pointer memory = mem;

    try{
        uint8_t data = memory[1023];
        std::cout << "DataRead : " << (int)data << " ";
        memory[1023] = 'A';
        data = memory[1023];
        std::cout << "DataRead : " << (int)data << " ";

    }catch(expp::OutOfBound& ex){
        std::cout << ex;
    }

    expp::memory::Memory* newMem = new TestAllocation();

    //allocator->deallocate(mem);
    //allocator->deallocate(newMem);

}