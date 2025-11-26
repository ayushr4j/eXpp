
#include "core/memory/pointer.hpp"


expp::memory::Pointer::Pointer(Memory* mem){
    this->mem = mem;
    this->mem->pointerCreated(this);
}

expp::memory::Pointer::Pointer(void* ptr, size_t s){
    raw = RawMemory(ptr,s);
    mem->pointerCreated(this);
}