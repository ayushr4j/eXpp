#ifndef _expp_memory_utils_
#define _expp_memory_utils_

#include "core/memory/pointer.hpp"
#include <cstdint>

namespace expp {

    /**
     * \todo implement more copy function to directly copy from (memory,pointer,view) to (memory,pointer,view).\n
     * also handle overlapping copy, segmented copy, performance. 
     */


    
    
    namespace memory {

        /**
        * @brief Copies n bytes from src to dst pointer (backward copy to handle overlap)
        * 
        * @param src 
        * @param dst 
        * @param s 
        */
        void copy(Pointer src, Pointer dst, size_t n);

        Pointer allocate();
        void deallocate(Pointer ptr);
    }
    

}

#endif