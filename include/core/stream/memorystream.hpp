#ifndef AR4J_STREAM_MEMORY_STREAM
#define AR4J_STREAM_MEMORY_STREAM

#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"
#include <algorithm>

namespace ar4j {

    class MemoryReader : public ar4j::Reader{
        Buffer buffer;
        public:
            MemoryReader(Buffer buf) : buffer(buf){
                
            }

            void readNBytes(ar4j::Buffer dst, size_t n, uint8_t flags) override{
                std::copy_n(buffer.data(), n, dst.data());
                buffer = buffer + n;
            }
    };

    class MemoryWriter : public ar4j::Writer{
        Buffer buffer;
        public:
            MemoryWriter(Buffer buf) : buffer(buf){
                
            }

            void writeNBytes(ar4j::Buffer src, size_t n, uint8_t flags) override{
                std::copy_n(src.data(), n, buffer.data());
                buffer = buffer + n;
            }

            
    };


};

#endif