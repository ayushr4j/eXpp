#ifndef AR4J_STREAM_BITSTREAM_SRC
#define AR4J_STREAM_BITSTREAM_SRC

#include "core/stream/bitstream.hpp"
#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>


/*
    we have i+1 bits in n bytes
    RawIndex    r0 r1 r2 ... ri

    i -> LE LSB -> LE MSB -> |i/8| *8 +  (7-i%8) 


               byte 0                            byte 1                                             byte n
    LE , MSB : b7 b6 b5 ... b0                 |  b15 b14 b13 ... b8                        | ... | b(8n+7) .. bi bi-1 .. b(8n)  
    LE , LSB : b0 b1 b2 ... b7                 |  b8  b9  b10 ... b15                       | ... | b(8n)   .. bi-1 bi   .. b(8n+7)
    BE , MSB : b(8n+7) .. bi   bi-1 .. b(8n)   |  b(8(n-1)+7) .. bi   bi-1 .. b(8(n-1))     | ... | b7 b6 b5 ... b0
    BE , LSB : b(8n)   .. bi-1 bi   .. b(8n+7) |  b(8(n-1))   .. bi-1 bi   .. b((8(n-1))+7) | ... | b0 b1 b2 ... b7
*/

void ar4j::BitReader::readNBits(ar4j::Buffer dst, size_t n, uint32_t flags){

    int inEndianess  = (flags & BitFlags::EndianInMask  ) >> 1;
    int inBitOrder   = (flags & BitFlags::BitOrderInMask) >> 1;
    int outEndianess = (flags & BitFlags::EndianOutMask );
    int outBitOrder  = (flags & BitFlags::BitOrderInMask);

    for(int i = 0; i < dst.size(); i++) dst[i] = 0; // zero all bytes of dst

    int reqSize = n/8 + (n%8 > 0);

    std::cout << "Reading Bits : ";
    for(int i = n-1; i >= 0; i--){

        if(bitCount == 0){
            stream->readNBytes(&byte, 1);
            bitCount = 8; 
        }

        uint8_t bit = (byte & (1 << 7)) >> 7;
        std::cout << (int)bit ;

        size_t byteIndex = i/8;
        if(inEndianess != outEndianess) byteIndex = dst.size() - 1 - byteIndex;

        size_t bitIndex = i%8;
        if(inBitOrder != outBitOrder) bitIndex = 7 - bitIndex;
        
        uint8_t mask = 0xff & (bit << bitIndex);

        dst[byteIndex] = (dst[byteIndex] & ~(1 << bitIndex)) | (bit << bitIndex);

        byte <<= 1;
        bitCount--;


    }
    std::cout << "\n";

    return;

}

void ar4j::BitReader::readNBytes(ar4j::Buffer dst, size_t n, uint32_t flags){
    
    readNBits(dst, n*8, flags);
    
}

void printBytes(const char* msg, ar4j::Buffer SRC){
    std::cout << msg ;
    for(int i = 0; i < SRC.size(); i++){
        std::cout << (int)SRC[i] << " ";
    }
    std::cout << "\n";
}

void ar4j::BitWriter::writeNBits(ar4j::Buffer src, size_t n, uint32_t flags){

    int inEndianess  = (flags & BitFlags::EndianInMask  ) >> 1;
    int inBitOrder   = (flags & BitFlags::BitOrderInMask) >> 1;
    int outEndianess = (flags & BitFlags::EndianOutMask );
    int outBitOrder  = (flags & BitFlags::BitOrderInMask);

    int reqSize = n/8 + (n%8 > 0);

    printBytes("SRC Buffer : ", src);
    

    std::cout << "Byte Order In Out :" << inEndianess << " " << outEndianess << " BitOrder in out : " << inBitOrder << " " << outBitOrder << "\n";

    //for(int i = 0; i < dst.size(); i++) dst[i] = 0; // zero all bytes of dst

    std::cout << "Writing Bits : ";

    for(int i = n-1; i >= 0; i--){

        if(bitCount == 8){
            stream->writeNBytes(&byte, 1);
            byte = 0;
            bitCount = 0;  
        }

        size_t byteIndex = i/8;
        if(inEndianess != outEndianess) byteIndex = src.size() - 1 - byteIndex;

        size_t bitIndex = i%8;
        if(inBitOrder != outBitOrder) bitIndex = 7 - bitIndex;
            
        uint8_t mask = (1 << bitIndex);
        uint8_t bit = (src[byteIndex] & (mask)) >> bitIndex; 
            
        std::cout << (int)bit;

        byte = ((byte << 1) | (bit));
        bitCount++;


    }

    std::cout << "\n";

    return;
    



    
}

void ar4j::BitWriter::writeNBytes(ar4j::Buffer src, size_t n, uint32_t flags){
    
    
    writeNBits(src, n*8, flags);
    

}

#endif