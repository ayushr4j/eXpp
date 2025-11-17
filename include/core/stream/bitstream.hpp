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
                
                //n = k*8 + m ; k bytes and m bits
                size_t k = n/8;
                size_t m = n%8;

                size_t total = k + (m>0);

                size_t startOffset = m <= availableBits;
                size_t byteCount = k + (m > availableBits); // if available bits is less than m, we need to read extra byte.

                dst[0] = 0;
                readNBytes(dst + startOffset, byteCount );

                size_t shiftCount = abs(availableBits - m);

                uint8_t lastByte = dst[startOffset + byteCount-1];

                dst[total-1] >>= shiftCount;
                for(int i = total-2; i >= 0; i++){

                    dst[i+1] += dst[i] << (8-shiftCount);  //shifting causes other bits to become 0. preserving old result of dst[i+1]
                    dst[i] >>= shiftCount;

                }

                //all bits should be now aligned to last bit.
                //now append available bits to result
            

                


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