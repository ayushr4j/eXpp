#ifndef _expp_core_stream_memorystream_
#define _expp_core_stream_memorystream_

#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"
#include <algorithm>

namespace expp {

    class MemoryReader : public Reader{
        Buffer buffer;
        public:
            MemoryReader(Buffer buf) : buffer(buf){
                
            }

            void readNBytes(Buffer dst, size_t n, uint32_t flags) override{
                std::copy_n(buffer.data(), n, dst.data());
                buffer = buffer + n;
            }
    };

    class MemoryWriter : public Writer{
        Buffer buffer;
        public:
            MemoryWriter(Buffer buf) : buffer(buf){
                
            }

            void writeNBytes(Buffer src, size_t n, uint32_t flags) override{
                std::copy_n(src.data(), n, buffer.data());
                buffer = buffer + n;
            }

            
    };


};

#endif