
#include "core/memory/utils.hpp"

void copy(Pointer src, Pointer dst, size_t n){
            for(int64_t i = n-1; i >= 0; i--){
                dst[i] = src[i];
            }
        }