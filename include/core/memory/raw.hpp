#ifndef _expp_memory_raw_
#define _expp_memory_raw_

#include "./memory.hpp"
#include <cstdint>

namespace expp {

    namespace memory{

        class Raw : public Memory{
            uint8_t* ptr; size_t size;

            
        };

    }

}

#endif