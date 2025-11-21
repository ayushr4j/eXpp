#include "core/memory/memory.hpp"


expp::memory::Memory::~Memory(){
    if(alloc != nullptr){
        alloc->releaseReference(*this);
        alloc = nullptr;
    }

}

