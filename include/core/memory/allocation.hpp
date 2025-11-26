#ifndef _expp_core_memory_allocation_
#define _expp_core_memory_allocation_


#include "./memory.hpp"


#include <cstddef>
#include <cstdint>
#include <stddef.h>
#include <stdint.h>
#include <atomic>

namespace expp
{
    namespace memory{

        class Allocator;
        

        /// @brief this is reperesents raw memory allocation and it also counts number of references to it and automatically deallocates when reference count goes to 0. 
        class Allocation : public Memory{
            protected:
                /// @brief allocator that was used to allocate this Allocation
                const Allocator* allocator = nullptr; 
                Allocation* nextAllocation = nullptr; 
                std::atomic<size_t> refCount = 0;
                
                /// data refers to address in this memory which fulfils given alignment requirment and is of size bytes.
                uint8_t *data;   

                Allocation(Allocator *allocator);

                friend class Memory;
                friend class Allocator;

                void pointerCreated(Pointer *pointer) override;
                void pointerDestroyed(Pointer *pointer) override;

            public:

                virtual ~Allocation();

                virtual uint8_t& get(size_t i) override;

                Pointer operator&();

                virtual void deallocate();

        };



    }
} // namespace ar4j


#endif 