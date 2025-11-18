#ifndef AR4J_STREAM_BITSTREAM
#define AR4J_STREAM_BITSTREAM

#include <bit>
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"


namespace ar4j {

    class BitHelper{
        bool BigEndian = (std::endian::native == std::endian::big);
        bool MSBFirst = true;
        
    public:
        
        uint8_t& getByte(Buffer buf, size_t index){
            if(BigEndian){
                return buf[buf.size()-1-index];
            }else return buf[index];
        }

        void readBytes(Buffer dst, size_t offset, Buffer src, size_t bits){

            size_t a = bits/8;
            size_t b = bits%8;

            b = 8*(b == 0) + b;
            a = a - 1*(b==8);
            size_t total = a + 1;



            //i need b bits
            //b[i] refers to ith bit. i goes from 0 to b-1. 0th is least significant bit.

        };

        uint8_t operator[](size_t index){

        }
        
    };

    class BitReader : public Reader{
        protected:
            Reader* stream;
            uint8_t bitOffset = 8, byte = 0;
        public:
            BitReader(Reader* stream){
                this->stream = stream;
            }

            virtual void readNBits(Buffer dst, size_t n, uint8_t flags = DEFAULT);

            virtual void readNBytes(Buffer dst, size_t n, uint8_t flags = DEFAULT);
            
    };
    class BitWriter : public Writer{
        protected:
            Writer* stream;
            uint8_t bitOffset = 0, byte = 0;
        public:
            BitWriter(Writer* stream){
                this->stream = stream;
            }
            virtual void writeNBits(Buffer src, size_t n, uint8_t flags = DEFAULT);
            virtual void writeNBytes(Buffer src, size_t n, uint8_t flags = DEFAULT);

            void flush(){
                if(bitOffset < 8){
                    writeNBytes(&byte, 1);
                    bitOffset = 8;
                    byte = 0;
                }
                    
                    
            }
    };


}

#endif