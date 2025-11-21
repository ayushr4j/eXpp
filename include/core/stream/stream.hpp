#ifndef AR4J_STREAM
#define AR4J_STREAM


#include <cstdint>
#include <stdint.h>
#include "core/buffer/buffer.hpp"

namespace expp {
    
    namespace StreamFlags{
        enum StreamFlags : uint32_t{
            
            Default = 0
        };
        
    }
    

    class Reader{
        public:
            virtual void readNBytes(Buffer dst, size_t n, uint32_t flags = StreamFlags::Default){};
    };
    class Writer{
        public:
            virtual void writeNBytes(Buffer src, size_t n, uint32_t flags = StreamFlags::Default){};
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