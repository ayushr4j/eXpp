#ifndef _expp_core_memory_allocator_
#define _expp_core_memory_allocator_

#include <stddef.h>
#include "./memory.hpp"
#include "./pointer.hpp"

namespace expp{

    namespace memory{

        /// @brief Base class for Allocator (allocates memory and manages it)
        /// \todo implement segmented allocations to be used for complex memory operation
        class Allocator{
        protected:

            friend class Allocation;
            
        public:
            
            virtual Pointer allocate(size_t size, size_t alignment = 1);
            virtual void deallocate(Pointer mem);

        };

        

    } // namespace memory
    
} // namespace name


#endif 