#ifndef _expp_memory_pointer_
#define _expp_memory_pointer_

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "./raw.hpp"


namespace expp {

    namespace memory {

        class Memory;
        
        //pointer points to a region of memory. specified with offset and size.
        class Pointer{
            protected:
                RawMemory raw = {nullptr,0};    //used for raw pointers.
                Memory* mem = &raw;
                size_t offset, size;   
            public:
                template<typename type>
                Pointer(type* obj){
                    if constexpr (std::is_base_of_v<Memory, type>) {
                        mem = obj;
                    }/*else if constexpr (std::is_base_of_v<Type, type>) {
                        
                    }*/else{
                        raw = {obj};
                    }
                };
                
                Pointer(void* ptr, size_t s);

                Pointer(Memory* mem);

                uint8_t& operator[](int64_t s){ return mem->operator[](s); };
                Pointer operator+(size_t offset);

                Pointer operator&(){ return *this; }    //prevent raw pointers of pointer

                
        };
    }

    using Pointer = memory::Pointer;

}



#endif