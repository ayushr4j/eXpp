#ifndef _expp_core_stream_memorystream_
#define _expp_core_stream_memorystream_

#include "core/stream/stream.hpp"
#include "core/memory/pointer.hpp"
#include <algorithm>

namespace expp {

    class MemoryInputStream : public InputStream{
        Pointer memory;
        public:
            MemoryInputStream(Pointer mem) : memory(mem){
                
            }

            void readNBytes(Pointer dst, size_t n, uint32_t flags) override{
                //std::copy_n(memory.data(), n, dst.data());
                //buffer = buffer + n;
            }
    };

    class MemoryOutputStream : public OutputStream{
        Pointer memory;
        public:
            MemoryOutputStream(Pointer mem) : memory(mem){}

            void writeNBytes(Pointer src, size_t n, uint32_t flags) override{
                //std::copy_n(src.data(), n, buffer.data());
                //buffer = buffer + n;
            }

            
    };


};

#endif