
#include "image/png/decoder.hpp"
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>

#include "core/buffer/buffer.hpp"
#include "core/stream/bitstream.hpp"
#include "core/stream/memorystream.hpp"


using namespace std;

int main(){

    size_t length;
    char * buffer;

    ifstream is;
    is.open ("../pngtest.png", ios::binary );
    // get length of file:
    is.seekg (0, ios::end);
    length = (int)(is.tellg());
    is.seekg (0, ios::beg);
    // allocate memory:
    buffer = new char [length];
    // read data as a block:
    is.read (buffer,length);
    is.close();

    expp::Buffer buf{ buffer , length};
    expp::MemoryReader memReader{ buf };
    expp::BitReader reader{ &memReader };


    std::cout << "PNGHeader : " << std::hex;
    for(int i = 0; i < 8; i++){
        uint16_t byte = 0;
        reader.readNBits(&byte,8);
        std::cout << (int)byte << " ";
    }
    std::cout << "\n Should be 89 50 4E 47 0D 0A 1A 0A \n";
    std::cout << std::dec ;

    while(true){

        uint32_t length, chunkType, CRC;
        reader.readNBits(&length, 32, expp::BitFlags::BigEndianIn);
        reader.readNBits(&chunkType, 32, expp::BitFlags::BigEndianIn);

        for(int i = 0; i < length; i++){
            uint16_t byte = 0;
            reader.readNBits(&byte,8);
            //std::cout << (int)byte << " ";
        }

        reader.readNBits(&CRC, 32, expp::BitFlags::BigEndianIn);
        std::cout << "Chunk Length " << length << " ChunkType " << std::hex << chunkType << std::dec << " CRC " << CRC << "\n";
        

        break;
    }


    cout << "File Read " << length << " Bytes";


    
}