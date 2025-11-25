

#include "core/memory/allocator.hpp"
#include "core/memory/allocation.hpp"
#include "stddef.h"

using namespace expp::memory;

Allocation* Allocator::allocate(size_t size, size_t alignment){
    
    size_t requiredSize = size + alignment; 
    uint8_t* data = new uint8_t[requiredSize];
    
    Allocation* alloc = new Allocation(this);
    
    alloc->size = size;
    alloc->alignment = alignment;
    alloc->data = data;

    return alloc;
}

void Allocator::deallocate(Allocation* alloc){
    
    alloc->size = 0;
    alloc->alignment = 0;
    delete [] alloc->data;
    alloc->data = nullptr;
}



