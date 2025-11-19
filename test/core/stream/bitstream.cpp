#include "core/stream/bitstream.hpp"
#include "core/stream/memorystream.hpp"

#include <cstdint>
#include "iostream"



int main(){

    struct Test{

        uint32_t A  = 0b10111010110100;
        uint32_t B  = 2;
        uint32_t C  = 0;
        uint32_t D  = 11;
        uint32_t E  = 256;

        void print(){

            std::cout << "TestData :\n" 
            << "A " << (uint64_t)A << "\n"
            << "B " << (uint64_t)B << "\n"
            << "C " << (uint64_t)C << "\n"
            << "D " << (uint64_t)D << "\n"
            << "E " << (uint64_t)E << "\n";

        }

    } test;

    std::cout << "SizeOF Test " << sizeof(Test) << " : A \n";

    

    

    uint8_t arr[] = { 0, 0, 0, 0, 0, 0 } ; 
    ar4j::MemoryReader memReader{ arr };
    ar4j::MemoryWriter memWriter{ arr };
    ar4j::BitReader reader{&memReader};
    ar4j::BitWriter writer{&memWriter};

    test.print();

    int outFlags = ar4j::BitFlags::LittleEndianOut;
    int inFlags = ar4j::BitFlags::LittleEndianIn;

    writer.writeNBits(&test.A, 14, outFlags);
    writer.writeNBits(&test.B, 2, outFlags);
    writer.writeNBits(&test.C, 1, outFlags);
    writer.writeNBits(&test.D, 5, outFlags);
    writer.writeNBits(&test.E, 9, outFlags);
    writer.flush();

    test.A = 0;
    test.B = 0;
    test.C = 0;
    test.D = 0;
    test.E = 0;
    test.print();

    std::cout << ((uint64_t)arr[0]) << " " << ((uint64_t)arr[1]) << " " << ((uint64_t)arr[2]) << " " << ((uint64_t)arr[3]) << " " << ((uint64_t)arr[4]) << "\n";

    reader.readNBits(&test.A, 14, inFlags);
    reader.readNBits(&test.B, 2, inFlags);
    reader.readNBits(&test.C, 1, inFlags);
    reader.readNBits(&test.D, 5, inFlags);
    reader.readNBits(&test.E, 9, inFlags);

    test.print();

    


    return 0;
}