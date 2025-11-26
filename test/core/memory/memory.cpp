
#include "core/memory/memory.hpp"
#include "core/exception.hpp"
#include "core/memory/allocator.hpp"
#include "core/exception.hpp"

#include "cstdint"
#include <cstdint>





int main(){


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

    //expp::memory::Memory* newMem = new TestAllocation();

    //allocator->deallocate(mem);
    //allocator->deallocate(newMem);

}