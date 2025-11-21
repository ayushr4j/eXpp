

#include "core/memory/allocation.hpp"
#include "core/memory/memory.hpp"

using namespace expp::memory;

Memory Allocator::Allocation::getReference(size_t offset, size_t size){
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
}


