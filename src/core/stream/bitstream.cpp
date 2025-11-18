#ifndef AR4J_STREAM_BITSTREAM_SRC
#define AR4J_STREAM_BITSTREAM_SRC

#include "core/stream/bitstream.hpp"
#include "core/stream/stream.hpp"
#include "core/buffer/buffer.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>


void ar4j::BitReader::readNBits(ar4j::Buffer dst, size_t n, uint8_t flags){
    size_t availableBits = 8 - bitOffset;

    std::cout << "Reading " << n << "Bits Available " << availableBits << "Bits Value" << (int)byte << "\n";
    
    //n = k*8 + m ; k bytes and m bits
    size_t k = n/8;
    size_t m = n%8;

    std::cout << k << "Bytes " << m << "Bits\n"; 

    size_t total = k + (m>0);

    Buffer DST = dst + (dst.size()-total); 

    std::cout << total << "Bytes in total\n";

    size_t startOffset = m <= availableBits;
    size_t byteCount = k + (m > availableBits); // if available bits is less than m, we need to read extra byte.

    std::cout << "ReadNBytes " << startOffset << " " << byteCount << "\n";

    DST[0] = byte;
    if(byteCount > 0)
        stream->readNBytes(DST + startOffset, byteCount );

    

    std::cout << "ReadBytes : ";
    for(int i = 0; i < total; i++){
        std::cout << (int)DST[i] << " ";
    }
    std::cout << "\n";

    size_t shiftCount = (((int)availableBits - (int)m)%8 + 8)%8;

    std::cout << "ShiftCount " << shiftCount << "\n";

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

    std::cout << "Carry " << (int)byte << " BitOffset " << (int)bitOffset << "\n";

    std::cout << "FinalBytes : ";
    for(int i = 0; i < total; i++){
        std::cout << (int)DST[i] << " ";
    }

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
    readNBits(dst, n*8, flags);
}

#endif