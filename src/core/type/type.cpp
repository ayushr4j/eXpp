#ifndef AR4J_TYPE_SRC
#define AR4J_TYPE_SRC

#include "core/type/type.hpp"
#include "core/memory/memory.hpp"

void ar4j::Type::init(const Memory mem){
    if(mem == cur_mem){
        memory = mem;
        offset += getSize();
        memory.increaseOffset(offset);
    }else{
        memory = mem;
        cur_mem = mem;
        offset = 0;
        size = getSize();
    }
}

ar4j::Type::Type(const Memory mem) : memory(mem){
    init(memory);
}

#endif