

#include "core/memory/allocation.hpp"
#include "core/memory/allocator.hpp"
#include "core/exception.hpp"
#include <cstddef>

using namespace expp::memory;


Allocation::Allocation(Allocator *allocator){
                    this->allocator = allocator;
                    this->next = allocator->start;
                    allocator->start = this;
                };

uint8_t& Allocation::operator[](size_t i){
    if(i >= size) throw OutOfBound(i,size);
    return data[i];
}

Allocation::~Allocation(){
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


