#ifndef AR4J_STREAM
#define AR4J_STREAM

#include <bit>
#include <corecrt_malloc.h>
#include <cstdint>
#include <stdint.h>
#include "core/buffer/buffer.hpp"

namespace ar4j {

    enum StreamFlags : uint8_t{
        NATIVE_ENDIAN = int(std::endian::native),
        BIG_ENDIAN =    int(std::endian::big),
        LITTLE_ENDIAN = int(std::endian::little),
        ENDIAN_MASK = 0b1,

        MSB_FIRST = 0 << 1,
        LSB_FIRST = 1 << 1,
        BIT_ORDER_MASK = 0b10,

        PEEK = 1 << 2,   //only affects read. this causes read to not advance stream's offset
        
        DEFAULT = NATIVE_ENDIAN | MSB_FIRST
    };
    

    class Reader{
        public:
            virtual void readNBytes(Buffer dst, size_t n, uint8_t flags = DEFAULT){};
    };
    class Writer{
        public:
            virtual void writeNBytes(Buffer src, size_t n, uint8_t flags = DEFAULT){};
    };
    class Stream : public Reader, public Writer{

    };
    
    class ISeekable {
        public:
            virtual void seeki(size_t offset);
            virtual size_t telli();
    };
    class OSeekable {
        public:
            virtual void seeko(size_t offset);
            virtual size_t tello();
    };
    class Seekable : public ISeekable, public OSeekable{

    };

}


#endif