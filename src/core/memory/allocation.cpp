

#include "core/memory/allocation.hpp"
#include "core/memory/allocator.hpp"
#include "core/exception.hpp"
#include <cstddef>

using namespace expp::memory;


Allocation::Allocation(Allocator *allocator) : allocator(allocator){
    
};

uint8_t& Allocation::get(size_t i){
    if(i >= size) throw OutOfBound(i,size);
    return data[i];
}

Allocation::~Allocation(){

    if(refCount > 0){
        
    }

    allocator->deallocate(this);
}

void Allocation::pointerCreated( [[maybe_unused]] Pointer *pointer){ refCount++; }
void Allocation::pointerDestroyed( [[maybe_unused]] Pointer *pointer) { 
    refCount--; 
    allocator->removeAllocation(this);
}

void Allocation::deallocate(){
    allocator->deallocate(this);             
}



/*Memory Allocator::Allocation::getReference(size_t offset, size_t size){
    Memory memory;
    memory.alloc = this;
    memory.offset = offset;
    memory.size = size;
    referenceCount++;
    return memory;
}

void Allocator::Allocation::releaseReference(Memory& mem){
    referenceCount--;
    if(referenceCount == 0 && alloc != nullptr){
        alloc->deallocate(this);
    }
}*/


