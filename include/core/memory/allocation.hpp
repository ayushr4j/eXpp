#ifndef _expp_core_memory_allocation_
#define _expp_core_memory_allocation_


#include "./allocator.hpp"

#include <stddef.h>
#include <stdint.h>
#include <atomic>

namespace expp
{
    namespace memory{

        /// @brief this is reperesents raw memory allocation and it also counts number of references to it and automatically deallocates when reference count goes to 0. 
        class Allocator::Allocation{
            protected:
                /// @brief allocator that was used to allocate this Allocation
                Allocator* alloc = nullptr;   
                /// size is the required size of allocation (excluding any padding, header).
                /// alignment is the alignment requirement for this Allocation. this might be used when moving this memory to other location.
                size_t size, alignment = 1;

                /// raw holds the raw allocated space of this allocation. after which Memory Segment resides (may be padded to meet alignment requirement). data refers to address in this memory which fulfils given alignment requirment and is size bytes.
                uint8_t *data, *raw;   

                /// stores number of references created for this memory. help in automatic garbage collection
                std::atomic<size_t> referenceCount = 0;

                
                Allocation(){};

                /// @brief Returns Memory Object for this allocation. also increases refrecene count for the allocation
                /// @param offset offset from which this reference starts
                /// @param size size of memory for this reference.
                /// @return 
                Memory getReference(size_t offset, size_t size);
                
                void releaseReference(Memory&);

                friend class Memory;
                friend class Allocator;

            public:

                Memory operator&();

        };



    }
} // namespace ar4j


#endif 