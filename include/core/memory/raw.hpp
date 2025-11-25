#ifndef _expp_memory_raw_
#define _expp_memory_raw_


#include "./memory.hpp"
#include <cstddef>
#include <cstdint>

namespace expp {

    namespace memory{


        /**
         * \ingroup Memory 
         * 
         *
         * @brief 
         * 
         */
        class RawMemory : public Memory{
            uint8_t* ptr;
            public:

                template<typename t> 
                RawMemory(t* a){
                    ptr = (uint8_t*) a;
                    alignment = alignof(t);
                    size = size_of(a);
                }

                RawMemory(void* a, size_t s, size_t alignment = 1){
                    ptr = (uint8_t*)a;
                    this->alignment = alignment;
                    size = s;
                }

                uint8_t& operator[](size_t index){
                    return ptr[index];
                }
                
        };

    }

}

#endif