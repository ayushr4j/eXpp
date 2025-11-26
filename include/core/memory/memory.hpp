#ifndef _expp_core_memory_base_
#define _expp_core_memory_base_

#include <cstddef>
#include <cstdint>
#include <stddef.h>

namespace expp{

    /**
     * \defgroup Memory Memory
     * \ref Allocator : Allocates memory and keeps track of all allocation.
     * \ref Memory : Represents memory of given size with given alignment requirment. Subclasses of Memory is used for different kinds of memory. (RawMemory, AllocatedMemory, GarbageCollectedMemory, File base Memory etc)\n
     * \ref Pointer : Helps access memory. It is contains pointer to Memory and a offset initially at 0. \n
     * \ref Allocation: class Memory allocated through Allocator class.
     * \ref RawMemory : Memory not allocated through Allocator
     *  \dot
     *  digraph example {
     *      
     *      Memory [ label="Memory"];
     *      RawMemory [ label="RawMemory"]
     *      Pointer [ label = "Pointer" ]
     *      Allocator [ label = "Allocator"]
     *      Allocation [ label = "Allocation" ]
     *      
     *      Pointer -> Memory;
     *      Memory -> RawMemory;
     *      Memory -> Allocation;
     *      Allocator -> Allocation; 
     *  }
     *  \enddot
     */

    namespace memory {
        
        class Pointer;

        /**
         * \ingroup Memory
         * @brief 
         * 
         */
        class Memory{
            protected:

                /// size is the required size of allocation (excluding any padding, header).
                /// alignment is the alignment requirement for this Allocation. this might be used when moving this memory to other location.
                size_t size = 0, alignment = 1;

                
                friend class Pointer;

                virtual void pointerCreated( [[maybe_unused]] Pointer* pointer){};
                virtual void pointerDestroyed( [[maybe_unused]] Pointer* pointer){};

            public:
                
                virtual ~Memory(){};
            
                /// @brief return byte at given index in memory
                /// @param i index starts at 0. supports negative indexing. -1 = size - 1, -2 size - 2, so on
                /// @return 
                
                uint8_t& get(int64_t i){ return get((size_t)(i + (i < 0)*(size-1+2*i)));  }
                virtual uint8_t& get(size_t i) = 0;

                virtual size_t getSize(){ return size; }
                virtual size_t getAlignment(){ return alignment; }


                
        };
    
        
        

    }

    typedef memory::Memory Memory;
    
   
    
} // namespace expp


#endif 