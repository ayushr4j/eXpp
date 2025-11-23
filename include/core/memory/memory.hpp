#ifndef _expp_core_memory_
#define _expp_core_memory_

#include <cstdint>
#include <stddef.h>


#include "./allocation.hpp"
#include "./pointer.hpp"
#include "./view.hpp"

namespace expp{

    /**
     * \defgroup Memory Memory
     * \ref Memory class provides inteface to access memory. Subclasses of Memory is used for different kinds of memory. (RawMemory, AllocatedMemory, GarbageCollectedMemory, File base Memory etc)\n
     * \ref Pointer class provides interface to access memory. It is contains pointer to Memory and a offset initially at 0. \n
     * \ref MemView class is derived from pointer and i lets you access only a portion of memory. It also has a size, a offset and size (to provide a view of memory).
     */

    namespace memory {
        /// @brief It acts as a pointer to memory. It supports advanced memory operations such as extending, shrinking memory. splitting memory, inserting memory in between. this works by keeping list connected segments internally. and it automatically defragments them also.
        
        //rename memory to pointer ?
        

        /**
         * \ingroup Memory
         * @brief 
         * 
         */
        class Memory{
            protected:
                //memory::Allocator::Allocation* alloc; allocation should inherit Memory,
                
                friend class Allocator;
            public:
                Memory();
                ~Memory();
            
                /// @brief return byte at given index in memory
                /// @param i index starts at 0. supports negative indexing. -1 = size - 1, -2 size - 2, so on
                /// @return 
                virtual uint8_t operator[](int64_t i);
                virtual Memory operator[](int64_t offset, uint64_t size);



                /*bool operator == (const Memory& mem){
                    if(alloc == mem.alloc){
                        return true;
                    }
                    return false;
                }*/

            
        };
    
        
        

    }

    typedef memory::Memory Memory;
    
   
    
} // namespace expp


#endif 