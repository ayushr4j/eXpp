#ifndef AR4J_STREAM_BITSTREAM
#define AR4J_STREAM_BITSTREAM

#include <bit>
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"

#include <iostream>



namespace ar4j {


    namespace BitFlags{
        enum BitFlags : uint32_t{
            NativeEndian = int(std::endian::native == std::endian::big) << 8,
            BigEndian =    1 << 8,
            LittleEndian = 0 << 8,
            EndianMask = 0b1 << 8,
            
            NativeEndianOut = NativeEndian,
            BigEndianOut =    BigEndian,
            LittleEndianOut = LittleEndian,
            EndianOutMask = EndianMask,

            NativeEndianIn = NativeEndianOut << 1,
            BigEndianIn = BigEndianOut << 1,
            LittleEndianIn = LittleEndianOut << 1,
            EndianInMask = EndianOutMask << 1,

            MSBFirst = 0 << 10,
            LSBFirst = 1 << 10,
            BitOrderMask = 0b1 << 10,

            MSBFirstOut = MSBFirst,
            LSBFirstOut = LSBFirst,
            BitOrderOutMask = BitOrderMask,

            MSBFirstIn = MSBFirst << 1,
            LSBFirstIn = LSBFirst << 1,
            BitOrderInMask = BitOrderMask << 1,

            Peek = 1 << 12,   //only affects read. this causes read to not advance stream's offset
            
            Default = NativeEndianIn | NativeEndianOut | MSBFirstIn | MSBFirstOut,
        };
    }
    
    class BitReader : public Reader{
        protected:
            Reader* stream;
            uint8_t bitCount = 0, byte = 0;
        public:
            BitReader(Reader* stream){
                this->stream = stream;
            }

            virtual void readNBits(Buffer dst, size_t n, uint32_t flags = BitFlags::Default);
            virtual void readNBytes(Buffer dst, size_t n, uint32_t flags = StreamFlags::Default);
            
    };
    class BitWriter : public Writer{
        protected:
            Writer* stream;
            uint8_t bitCount = 0, byte = 0;
        public:
            BitWriter(Writer* stream){
                this->stream = stream;
            }
            virtual void writeNBits(Buffer src, size_t n, uint32_t flags = BitFlags::Default);
            virtual void writeNBytes(Buffer src, size_t n, uint32_t flags = StreamFlags::Default);

            void flush(){

                if(bitCount > 0){

                    
                    std::cout << "Flushing " << (int)byte << " BitCount " << (int)bitCount << "\n";

                    uint8_t flushBits = 0;
                    writeNBits(&flushBits, 8-flushBits);
                    
                }
                    
            }
    };


}

#endif