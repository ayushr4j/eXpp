#ifndef AR4J_STREAM_BITSTREAM
#define AR4J_STREAM_BITSTREAM

#include <cstdint>
#include <stdint.h>
#include "core/stream/stream.hpp"

namespace ar4j {

    class BitReader : public Reader{
        protected:
            Reader* stream;
            uint8_t bitOffset = 8, byte = 0;
        public:
            virtual void readNBits(uint8_t* dst, size_t n, uint8_t flags = DEFAULT){
                
                size_t availableBits = 8 - bitOffset;

                size_t toReadBits = n-availableBits;

                size_t toReadBytes = (toReadBits/8) + (toReadBits%8 > 0);

                readNBytes(dst, toReadBytes, flags);


            };

            


            void writeBit(void* dst, size_t bitCount){

            }
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