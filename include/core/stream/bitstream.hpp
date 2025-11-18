#ifndef AR4J_STREAM_BITSTREAM
#define AR4J_STREAM_BITSTREAM

#include <cstdint>
#include <stdint.h>
#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"


namespace ar4j {

    class BitReader : public Reader{
        protected:
            Reader* stream;
            uint8_t bitOffset = 8, byte = 0;
        public:
            BitReader(Reader* stream){
                this->stream = stream;
            }

            virtual void readNBits(Buffer dst, size_t n, uint8_t flags = DEFAULT);

            virtual void readNBytes(Buffer dst, size_t n, uint8_t flags = DEFAULT);
            
    };
    class BitWriter : public Writer{
        protected:
            Writer* stream;
            uint8_t bitOffset = 0, byte = 0;
        public:
            virtual void writeNBits(void* dst, size_t n, uint8_t flags = DEFAULT);
    };


}

#endif