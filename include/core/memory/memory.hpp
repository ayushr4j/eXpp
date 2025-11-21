#ifndef _expp_core_memory_
#define _expp_core_memory_

#include <stddef.h>

#include "./allocation.hpp"

namespace expp{

    namespace memory {
        /// @brief It acts as a pointer to memory. It supports advanced memory operations such as extending, shrinking memory. splitting memory, inserting memory in between. this works by keeping list connected segments internally. and it automatically defragments them also.
        class Memory{
            protected:
                memory::Allocator::Allocation* alloc;
                size_t offset = 0, size = 0;

                Memory();
                

                friend class Allocator;
            public:
                ~Memory();
            
                /// @brief return byte at given index in memory
                /// @param i index starts at 0. supports negative indexing. -1 = size - 1, -2 size - 2, so on
                /// @return 
                uint8_t operator[](int64_t i);
                
                Memory operator[](int64_t offset, uint64_t size);

                bool operator == (const Memory& mem){
                    if(alloc == mem.alloc && offset == mem.offset){
                        return true;
                    }
                    return false;
                }

                void increaseOffset(int offset){
                    this->offset += offset;
                }
            
        };
    }

    typedef memory::Memory Memory;
    
   
    
} // namespace expp


#endif 