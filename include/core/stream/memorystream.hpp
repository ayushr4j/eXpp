#ifndef AR4J_STREAM_MEMORY_STREAM
#define AR4J_STREAM_MEMORY_STREAM

#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"

namespace ar4j {

    class MemoryReader : public ar4j::Reader{
        Buffer buffer;
        public:
            MemoryReader(Buffer buf) : buffer(buf){
                
            }

            void readNBytes(ar4j::Buffer dst, size_t n, uint8_t flags) override{
                memcpy(dst.data(), buffer.data(), n);
                buffer = buffer + n;
            }
    };

    class MemoryWriter : public ar4j::Writer{
        Buffer buffer;
        public:
            MemoryWriter(Buffer buf) : buffer(buf){
                
            }

            void writeNBytes(ar4j::Buffer src, size_t n, uint8_t flags) override{
                memcpy(buffer.data(), src.data(), n);
                buffer = buffer + n;
            }
    };


};

#endif