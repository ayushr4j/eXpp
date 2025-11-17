#ifndef AR4J_STREAM_BITSTREAM
#define AR4J_STREAM_BITSTREAM

#include <stdint.h>
#include "core/stream/stream.hpp"

namespace ar4j {

    class BitStream : Stream{
        protected:
            void* data;
            size_t offset;

        public:

            virtual void process(void* dst, size_t size, uint16_t flags);

    }

}

#endif