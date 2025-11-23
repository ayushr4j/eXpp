#ifndef _expp_core_memory_allocator_
#define _expp_core_memory_allocator_

#include <stddef.h>
#include "./memory.hpp"

namespace expp{

    namespace memory{

        class Memory;
        
       

        /// @brief Allocates Contiguous Memory Segments and returns a Reference to it.
        /// \todo implement segmented allocations to be used for complex memory operation
        class Allocator{
        protected:

            /**
            * @brief Holds actual allocated raw pointer and total size of allocation. Must not be used directly.
            * 
            */
            class Allocation;


            friend class Allocation;
            friend class MemoryObject;
            friend class Memory;

            virtual Allocation* createAllocation(size_t size, size_t alignment = 1);
            virtual void deallocate(Allocation* allocation);
            

        public:
            
            virtual Memory allocate(size_t size, size_t alignment = 1);
            virtual void deallocate(Memory mem);

        };

        

    } // namespace memory
    
} // namespace name


#endif 