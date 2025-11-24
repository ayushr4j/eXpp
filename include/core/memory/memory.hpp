#ifndef _expp_core_memory_base_
#define _expp_core_memory_base_

#include <cstddef>
#include <cstdint>
#include <stddef.h>

namespace expp{

    /**
     * \defgroup Memory Memory
     * \ref Memory class provides inteface to access memory. Subclasses of Memory is used for different kinds of memory. (RawMemory, AllocatedMemory, GarbageCollectedMemory, File base Memory etc)\n
     * \ref Pointer class provides interface to access memory. It is contains pointer to Memory and a offset initially at 0. \n
     * 
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

            public:
                
                virtual ~Memory(){};
            
                /// @brief return byte at given index in memory
                /// @param i index starts at 0. supports negative indexing. -1 = size - 1, -2 size - 2, so on
                /// @return 
                uint8_t& operator[](int64_t i){ return operator[]( i + (i < 0)*(size-1+2*i)); };
                virtual uint8_t& operator[](size_t i) = 0;


                virtual size_t getSize(){ return size; }
                virtual size_t getAlignment(){ return alignment; }
        };
    
        
        

    }

    typedef memory::Memory Memory;
    
   
    
} // namespace expp


#endif 