#ifndef AR4J_STREAM_BITSTREAM_SRC
#define AR4J_STREAM_BITSTREAM_SRC

#include "core/stream/bitstream.hpp"
#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>


void ar4j::BitReader::readNBits(ar4j::Buffer dst, size_t n, uint8_t flags){
    size_t availableBits = 8 - bitOffset;

    //std::cout << "Reading " << n << "Bits Available " << availableBits << "Bits Value" << (int)byte << "\n";
    
    //n = k*8 + m ; k bytes and m bits
    size_t k = n/8;
    size_t m = n%8;

    m = 8*(m == 0) + m;
    k = k - 1*(m==8);

    //std::cout << k << "Bytes " << m << "Bits\n"; 

    size_t total = k + 1;

    Buffer DST = dst + (dst.size()-total); 

    //std::cout << total << "Bytes in total\n";

    size_t startOffset = m <= availableBits;
    size_t byteCount = k + (m > availableBits); // if available bits is less than m, we need to read extra byte.

    //std::cout << "ReadNBytes " << startOffset << " " << byteCount << "\n";

    DST[0] = byte;
    if(byteCount > 0)
        stream->readNBytes(DST + startOffset, byteCount, NATIVE_ENDIAN);

    

    //std::cout << "ReadBytes : ";
    for(int i = 0; i < total; i++){
        //std::cout << (int)DST[i] << " ";
    }
    //std::cout << "\n";

    size_t shiftCount = (((int)availableBits - (int)m)%8 + 8)%8;

    //std::cout << "ShiftCount " << shiftCount << "\n";

    uint8_t lastByte = DST[total-1];

    uint8_t carry = 0;
    if(m > availableBits){
        carry = byte << (8-shiftCount);
    }
    
    for(int i = 0; i < total; i++){

        uint64_t nextCarry = DST[i] << (8-shiftCount);
        DST[i] = (DST[i] >> shiftCount) + carry;
        carry = nextCarry;
    }

    
    bitOffset = 8-shiftCount;
    byte = carry >> (8-shiftCount);

    //std::cout << "Carry " << (int)byte << " BitOffset " << (int)bitOffset << "\n";

    //std::cout << "FinalBytes : ";
    for(int i = 0; i < total; i++){
        //std::cout << (int)DST[i] << " ";
    }
    //std::cout << "\n";

    //handle endianess and bitOrder

    if((flags & ENDIAN_MASK) != NATIVE_ENDIAN){ //if endianess flag doesn't match native endianess reserve byte order
        size_t size = dst.size();
        
        for(int i = 0; i < size/2; i++){
            uint8_t temp = dst[i];
            dst[i] = dst[size-1-i];
            dst[size-1-i] = temp;
        }
    }

}

void ar4j::BitReader::readNBytes(ar4j::Buffer dst, size_t n, uint8_t flags){
    if(bitOffset == 8){
        stream->readNBytes(dst, n, flags);
    }else{
        readNBits(dst, n*8, flags);
    }

}

void printBytes(const char* msg, ar4j::Buffer SRC){
    std::cout << msg ;
    for(int i = 0; i < SRC.size(); i++){
        std::cout << (int)SRC[i] << " ";
    }
    std::cout << "\n";
}

void ar4j::BitWriter::writeNBits(ar4j::Buffer src, size_t n, uint8_t flags){

    static thread_local uint8_t bytes[1024*1024*4];
    Buffer buffer{bytes};

    if((flags & ENDIAN_MASK) != BIG_ENDIAN){ //if endianess flag doesn't match native endianess reserve byte order
        size_t size = src.size();
        
        for(int i = 0; i < size/2; i++){
            uint8_t temp = src[i];
            src[i] = src[size-1-i];
            src[size-1-i] = temp;
        }
    }

    printBytes("src Bytes : ", src);

    buffer[0] = byte;

    size_t k = n/8;
    size_t m = n%8;

    m = 8*(m == 0) + m;
    k = k - 1*(m==8);
    size_t total = k + 1;

    std::cout << total << "Bytes = " << k << "Bytes " << m << "Bits\n"; 

    

    size_t availableBits = 8 - bitOffset;

    Buffer SRC = src + (src.size() - total);

    printBytes("SRC Bytes : ", SRC);


    return;


    if(m > availableBits){



    }

    if(m == availableBits){
        std::cout << "CASE 0\n";
        buffer[0] = byte + ((SRC[0] << bitOffset) >> bitOffset);
        stream->writeNBytes(buffer, 1);
        stream->writeNBytes(SRC, k);
    }else if( m < availableBits){
        std::cout << "CASE 1\n";
        size_t shiftCount = (availableBits - m);
        std::cout << "ShiftCount " << shiftCount << "\n";
        buffer[0] = byte + (SRC[0] << (shiftCount));

        for(int i = 1; i < SRC.size(); i++){

            buffer[i-1] += (buffer[i] >> (8-shiftCount));
            buffer[i] <<= shiftCount;

        }

        stream->writeNBytes(buffer, SRC.size()-1);

        byte = buffer[SRC.size() - 1];
        bitOffset = (8-shiftCount);

    }else{  // m > availableBits
        std::cout << "CASE 2\n";
        size_t shiftCount = (m - availableBits);
        buffer[0] = byte + (SRC[0] >> shiftCount);

        uint8_t carry = SRC[0] << (8-shiftCount);
        int i = 1;
        for(i = 1; i < SRC.size(); i++){

            uint8_t carryNext = buffer[i] << (8-shiftCount);

            buffer[i] = (buffer[i] >> shiftCount) + carry;

            carry = carryNext;
        }
        stream->writeNBytes(buffer, SRC.size()-1);

        i--;
        
        byte = carry;
        bitOffset = (shiftCount);

    }

    std::cout << "Written Bytes : ";
    for(int i = 0; i < SRC.size(); i++){
        std::cout << (int)buffer[i] << " ";
    }
    std::cout << "\n";


    
    //reconvert endianess back to native
    if((flags & ENDIAN_MASK) != NATIVE_ENDIAN){ //if endianess flag doesn't match native endianess reserve byte order
        size_t size = src.size();
        
        for(int i = 0; i < size/2; i++){
            uint8_t temp = src[i];
            src[i] = src[size-1-i];
            src[size-1-i] = temp;
        }
    }

}

void ar4j::BitWriter::writeNBytes(ar4j::Buffer src, size_t n, uint8_t flags){
    
    if(bitOffset == 0){
        stream->writeNBytes(src, n, flags);
    }else{
        writeNBits(src, n*8, flags);
    }

}

#endif