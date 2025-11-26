
#include "core/memory/utils.hpp"
#include "core/context/context.hpp"
#include "core/exception.hpp"
#include "core/memory/pointer.hpp"

namespace expp {

    void memory::copy(Pointer src, Pointer dst, size_t n){
        for(int64_t i = n-1; i >= 0; i--){
            dst[i] = src[i];
        }
    }

    Pointer memory::allocate(size_t size, size_t alignment){
        return context->getAllocator()->allocate(size, alignment);
    }
    void memory::deallocate(Pointer ptr){
        Memory* mem = *ptr;
        if (auto d = dynamic_cast<Allocation*>(mem)) {
            // ptr is actually 
            d->deallocate();
        }else{
            throw Exception("Attempted to Deallocate non allocated Memory");
        }
    }
}