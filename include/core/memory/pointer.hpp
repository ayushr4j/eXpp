#ifndef _expp_memory_pointer_
#define _expp_memory_pointer_

#include <cstddef>
#include <cstdint>

#include "./raw.hpp"

namespace expp {

    namespace memory {

        class Memory;
        class Raw;

        class Pointer{
            protected:
                Raw raw;    //used for raw pointers.
                Memory* mem = &raw;
                size_t offset, size;  
            public:
                template<typename type>
                Pointer(type* obj);
                Pointer(void* ptr, size_t s);

                uint8_t& operator[](size_t s);
                

                Pointer operator+(size_t offset); 

                
        };
    }

    using Pointer = memory::Pointer;

    

    



}



#endif