#ifndef _expp_core_buffer_
#define _expp_core_buffer_

#include <cstddef>
#include <cstdint>
#include <stdint.h>

namespace expp {
    
    class Buffer{
        protected:
            uint8_t* data_;
            size_t offset = 0, capacity = 0;
        public:
        
            uint8_t& operator[](size_t i){ return data_[offset + i]; };  //throw error if greater than size

            Buffer operator[](size_t offset, size_t size);
            
            
            template<typename Type>
            Buffer(Type* a){
                data_ = (uint8_t*)a;
                capacity = sizeof(Type);
            }

            Buffer(void* ptr, size_t size){
                data_ = (uint8_t*)ptr;
                capacity = size;
            }


            Buffer operator + (size_t s){ Buffer buf = *this; buf.offset += s; return buf; } //throw error if offset is more than size.
            
            size_t size(){ return capacity-offset; }

            uint8_t* data(){ return data_+offset; }


            void reset(){
                offset = 0;
            }
    
    };

}

#endif