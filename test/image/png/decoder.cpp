
#include "image/png/decoder.hpp"
#include <fstream>
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

    ar4j::Buffer buf{ buffer , length};
    ar4j::MemoryReader memReader{ buf };
    ar4j::BitReader reader{ &memReader };


    std::cout << "PNGHeader : ";
    for(int i = 0; i < 8; i++){
        uint16_t byte = 0;
        reader.readNBits(&byte,8);
        std::cout << (int)byte << " ";
    }
    std::cout << "\n Should be 89 50 4E 47 0D 0A 1A 0A \n";



    cout << "File Read " << length << " Bytes";


    
}