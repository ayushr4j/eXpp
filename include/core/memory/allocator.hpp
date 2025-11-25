#ifndef _expp_core_memory_allocator_
#define _expp_core_memory_allocator_

#include <cstddef>
#include <stddef.h>
#include "./memory.hpp"
#include "./pointer.hpp"
#include "./allocation.hpp"

namespace expp{

    namespace memory{

        /// @brief Base class for Allocator (allocates memory and manages it)
        /// \todo seperate allocation header and actual allocation (for ease of changing memory)
        class Allocator{
            protected:

                Allocation* start = nullptr;
                friend class Allocation;
            public:
                
                virtual Allocation* allocate(size_t size, size_t alignment = 1) = 0;
                virtual void deallocate(Allocation* mem) = 0;

        };

        /// \todo implement segmented allocations to be used for complex memory operation

        

    } // namespace memory
    
} // namespace name


#endif 