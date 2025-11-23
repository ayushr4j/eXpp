#ifndef AR4J_STREAM
#define AR4J_STREAM


#include <cstdint>
#include <stdint.h>
#include "core/memory/pointer.hpp"

namespace expp {
    
    namespace StreamFlags{
        enum StreamFlags : uint32_t{
            
            Default = 0
        };
        
    }


    class Stream{

    };   

    class InputStream : public Stream{
        public:
            virtual void readNBytes(Pointer dst, size_t n, uint32_t flags = StreamFlags::Default){};

            template<typename type>
            void operator >> (type& obj);
    };
    class OutputStream : public Stream{
        public:
            virtual void writeNBytes(Pointer src, size_t n, uint32_t flags = StreamFlags::Default){};

            template<typename type>
            void operator << (type& obj);
    };
    class IOStream : public InputStream, public OutputStream{

    };
    


    //think of better name
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