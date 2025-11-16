#ifndef AR4J_TYPE_TYPE
#define AR4J_TYPE_TYPE

#include "core/memory/memory.hpp"
#include "string"
#include <cstdint>
#include <bit>


namespace ar4j {

    
    class Type{

        static thread_local Memory cur_mem;
        static thread_local size_t offset, size;    //will be set by Constructor;

        Memory memory;
        struct{
            std::endian endianness : 1 = std::endian::big;
            uint8_t bitOrder : 1 = 0; //0 lsb 1st
            uint8_t bitOffset : 3 = 0;
            uint8_t bitLength : 3 = 7; // length is actualLength - 1;
        } flags;
        
        virtual size_t getAlignment(){ return 8;};
        virtual size_t getSize(){ return 0;};

        void init(const Memory mem);
        
    public:
        /// @brief create a type at given memory. align it using getAlignment() and validate using getSize()
        Type(const Memory mem = cur_mem); 
        
        


    };


    class Array : public Type{

    };
    class LittleEndian : public Type{

    };

    class Bit : public Type{
        virtual size_t getAlignment(){ return 1; }
        virtual size_t getSize(){ return 1; }
    };
    class Byte : public Type{
        virtual size_t getAlignment(){ return 8; }
        virtual size_t getSize(){ return 8; }
    };
    class Int : public Type{

    };
    class Float : public Type{

    };

    

    template<typename t>
    class NativeType{

    };

    class DynamicType{
        
    };
    class StaticType{

    };

    /// @brief Variable is Combination of Memory and Type.
    class Variable{  
        Type type;
        Memory memory;
    };

}

#endif //AR4J_TYPE_TYPE