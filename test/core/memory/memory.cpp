
#include "core/memory/memory.hpp"
#include "core/exception.hpp"
#include "core/memory/allocator.hpp"
#include "core/exception.hpp"

#include "cstdint"


int main(){

    expp::memory::Allocator allocator;
    expp::Pointer memory = allocator.allocate(1024,1);

    try{
        uint8_t data = memory[1023];
        std::cout << "DataRead : " << (int)data << " ";
        memory[1023] = 'A';
        data = memory[1023];
        std::cout << "DataRead : " << (int)data << " ";

    }catch(expp::OutOfBound& ex){
        std::cout << ex;
    }

}