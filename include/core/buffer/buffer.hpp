#ifndef AR4J_BUFFER_BUFFER
#define AR4J_BUFFER_BUFFER

#include <stdint.h>

namespace ar4j {
    
    class Buffer{
        protected:
            void* data;
            size_t offset, size, capacity;
        public:
        
            uint8_t operator[](size_t i);

            Buffer operator[](size_t offset, size_t size);
            
    };

}

#endif