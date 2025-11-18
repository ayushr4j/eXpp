#ifndef AR4J_STREAM
#define AR4J_STREAM

#include <bit>
#include <cstdint>
#include <stdint.h>
#include "core/buffer/buffer.hpp"

namespace ar4j {

    enum StreamFlags : uint8_t{
        NativeEndian = int(std::endian::native == std::endian::big),
        BigEndian =    1,
        LittleEndian = 0,
        EndianMask = 0b1,

        MSBFirst = 0 << 1,
        LSBFirst = 1 << 1,
        BitOrderMask = 0b10,

        PEEK = 1 << 2,   //only affects read. this causes read to not advance stream's offset
        
        DEFAULT = NativeEndian | MSBFirst
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