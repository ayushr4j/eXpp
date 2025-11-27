

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

    alloc->nextAllocation = allocations;
    allocations = alloc;

    return alloc;
}

void Allocator::removeAllocation(Allocation* alloc) const {
    if(allocations == alloc){
        allocations = alloc->nextAllocation;
        alloc->nextAllocation = nullptr;
    }else{
        Allocation* ptr = alloc;
        while(ptr->nextAllocation != nullptr && ptr->nextAllocation != alloc){
            ptr = alloc->nextAllocation;
        }
        if(ptr->nextAllocation == alloc){
            ptr->nextAllocation = alloc->nextAllocation;
            alloc->nextAllocation = nullptr;
        }
    }

    delete alloc;
}

void Allocator::deallocate(Allocation* alloc) const{
    
    alloc->size = 0;
    alloc->alignment = 0;
    delete [] alloc->data;
    alloc->data = nullptr;

    if(alloc->refCount == 0) removeAllocation(alloc);
}



thread_local expp::memory::Allocator* expp::memory::currentAllocator = new expp::memory::Allocator();
thread_local expp::memory::Allocator* expp::memory::Allocator::prev = nullptr;

void expp::memory::pushAllocator(expp::memory::Allocator& alloc){
        alloc.prev = currentAllocator;
        currentAllocator = &alloc;        
}
void expp::memory::popAllocator(){
    currentAllocator = currentAllocator->prev;
}
