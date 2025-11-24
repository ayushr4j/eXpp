
#include "./type.hpp"
#include <bit>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <sys/stat.h>

#include "core/memory/pointer.hpp"

namespace expp {



    enum class Endian : uint8_t{
        BE = 1,
        LE = 1 << 1,
        Native = (std::endian::native == std::endian::big),
        


        LE_LSB = 1<<1 | LE,
        BE_LSB = 1<<1 | BE,
        
        //native = msb_first, //generally its msb_first. check if other formats exist
    };

    //return true if 'b' is equal to 'a' or a subset of 'a'
    bool operator == (Endian a, Endian b){
        

        return (static_cast<uint8_t>(a) & static_cast<uint8_t>(b)) == static_cast<uint8_t>(b);
    };

    template<typename T>
    concept HasStaticSize =
    requires {
        { T::sizeBits } -> std::convertible_to<size_t>;
    };

    template<typename T>
    concept HasRuntimeSize =
    requires {
        { &T::getSizeBits };
    };


    template<typename t>
    size_t size_bits(const t& a){ //returns size in bits

        if constexpr (HasStaticSize<t>) {
            return t::sizeBits;
        }else if constexpr (HasRuntimeSize<t>) {
            return a.getSizeBits();
        }else{
            return sizeof(a);
        }

    }

    template<typename t>
    size_t size_of(const t&& a){   
        size_t size = size_bits<t>(a);
        return size/8 + (size%8 > 0);
    }

    

    class Primitive : public Type{

    };

    template <size_t n = 8, Endian endian = Endian::Native>
    class Bits : public Primitive{
        Pointer data;
        size_t offset = 0;

        static constexpr size_t sizeBits = n;
        

        public:

            template<typename t>
            uint8_t* getByte(int i){

            }

            void operator << (size_t shift){

            }
            void operator >> (size_t shift){

            }
    };


    template<size_t n = 32, Endian endian = Endian::Native>
    class Int : public Bits<n,endian>{

    };

    template<size_t n = 32, Endian endian = Endian::Native>
    class UInt : public Bits<n,endian>{

    };

    template<size_t n = 32, Endian endian = Endian::Native>
    class Float : public Bits<n,endian>{

    };

    class Bool : public Bits<1>{

    };



}