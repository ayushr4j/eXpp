#include "core/stream/bitstream.hpp"
#include "core/stream/stream.hpp"
#include "core/stream/memorystream.hpp"

#include <cstdint>
#include "iostream"



int main(){

    struct Test{

        uint32_t A  = 6;
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

    

    

    uint8_t arr[] = { 0, 0, 0 } ; 
    ar4j::MemoryReader memReader{ arr };
    ar4j::MemoryWriter memWriter{ arr };
    ar4j::BitReader reader{&memReader};
    ar4j::BitWriter writer{&memWriter};

    test.print();

    writer.writeNBits(test.A, 3);
    writer.writeNBits(test.B, 2);
    writer.writeNBits(test.C, 1);
    writer.writeNBits(test.D, 5);
    writer.writeNBits(test.E, 9);
    writer.flush();

    test.A = 0;
    test.B = 0;
    test.C = 0;
    test.D = 0;
    test.E = 0;
    test.print();

    std::cout << (void*) arr[0] << " " << (void*) arr[1] << " " << (void*) arr[2] << "\n";

    reader.readNBits(test.A, 3);
    reader.readNBits(test.B, 2);
    reader.readNBits(test.C, 1);
    reader.readNBits(test.D, 5);
    reader.readNBits(test.E, 9);

    test.print();



    uint16_t data;
    reader.readNBits(data, 5, ar4j::BigEndian);
    std::cout << data << "\n";
    uint32_t data1;
    reader.readNBits(data1, 3, ar4j::BigEndian);
    std::cout << (int)data1 << "\n";
    data1 = 0;
    reader.readNBits(data1, 8, ar4j::BigEndian);
    std::cout << (int)data1 << "\n";
    data1 = 0;
    reader.readNBits(data1, 3, ar4j::BigEndian);
    std::cout << (int)data1 << "\n";

    


    return 0;
}