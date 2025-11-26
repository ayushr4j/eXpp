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

                mutable Allocation* allocations;
                
                virtual void removeAllocation(Allocation* allocation) const;

                friend class Allocation;
            public:
                
                virtual Allocation* allocate(size_t size, size_t alignment = 1);
                virtual void deallocate(Allocation* mem) const;

        };

        /// \todo implement segmented allocations to be used for complex memory operation

        

    } // namespace memory
    
} // namespace name


#endif 