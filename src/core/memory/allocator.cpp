

#include "core/memory/allocator.hpp"
#include "core/memory/allocation.hpp"
#include "core/memory/memory.hpp"
#include "core/memory/pointer.hpp"
#include "stddef.h"

#include <new>  //used for in place new operator on apple clang

using namespace expp::memory;

Pointer Allocator::allocate(size_t size, size_t alignment){
    
    size_t requiredSize = sizeof(Allocation) + alignof(Allocation) + size + alignment;  //required size for allocation object + data

    uint8_t* raw = new uint8_t[requiredSize];
    uint64_t addr = (uint64_t)raw;
    uint64_t offset = addr % alignof(Allocation);
    uint8_t* ptr = raw + offset;                          

    Allocation* alloc = new (ptr) Allocation();
    
    ptr = ptr + sizeof(Allocation);
    offset = ((uint64_t)ptr) % alignment;
    ptr = ptr + offset;

    alloc->raw = raw;
    alloc->alloc = this;
    alloc->size = size;
    alloc->alignment = alignment;
    alloc->data = ptr;

    return Pointer{alloc};

}

void Allocator::deallocate(Pointer mem){
    //delete[] mem;
}



