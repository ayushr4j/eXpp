
#include "core/memory/utils.hpp"
#include "core/memory/pointer.hpp"

namespace expp {
    namespace memory {
        
        void copy(Pointer src, Pointer dst, size_t n){
            for(int64_t i = n-1; i >= 0; i--){
                dst[i] = src[i];
            }
        }



    }

    Pointer memory::allocate(size_t s, size_t alignment){

    }
    void deallocate(Pointer mem){
        
    }
}