#include "core/stream/bitstream.hpp"
#include "core/stream/stream.hpp"
#include "core/stream/memorystream.hpp"

#include <cstdint>
#include "iostream"



int main(){

    

    uint8_t arr[] = { 0b11010011, 0b11010110, 0b10101011 } ; 
    ar4j::MemoryReader memReader{ arr };

    uint8_t *ptr = (uint8_t*)&arr;
    std::cout << "OriginalBytes" << (int)ptr[0] << " " << (int)ptr[1] << " " << (int)ptr[2] << "\n";

    ar4j::BitReader reader{&memReader};
    
    uint32_t d = 6778;
    ar4j::Buffer buf{d};
    std::cout << "D " << (void*)buf[0] << " " << (int)buf[1] << " " << (int)buf[2] << " " << (int)buf[3] << "\n";


    uint16_t data;
    reader.readNBits(data, 16, ar4j::BIG_ENDIAN);
    std::cout << data << "\n";
    uint32_t data1;
    reader.readNBits(data1, 2, ar4j::BIG_ENDIAN);
    std::cout << (int)data1 << "\n";
    data1 = 0;
    reader.readNBits(data1, 3, ar4j::BIG_ENDIAN);
    std::cout << (int)data1 << "\n";

    


    return 0;
}