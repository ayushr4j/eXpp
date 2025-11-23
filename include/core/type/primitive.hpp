
#include "./type.hpp"
#include <bit>
#include <cstdint>

#include "core/memory/pointer.hpp"

namespace expp {

    enum class bitorder{
        msb_first = 0,
        lsb_first = 1,

        native = msb_first, //generally its msb_first. check if other formats exist
    };

    class Primitive : public Type{

    };

    template <size_t n = 8, std::endian endian = std::endian::native, expp::bitorder bitorder = bitorder::native>
    class Byte : public Primitive{
        Pointer data;
    };

    template<size_t n = 32, std::endian endian = std::endian::native, expp::bitorder bitorder = bitorder::msb_first>
    class Int : public Byte<n,endian,bitorder>{

    };

    template<size_t n = 32, std::endian endian = std::endian::native, expp::bitorder bitorder = bitorder::msb_first>
    class UInt : public Byte<n,endian,bitorder>{

    };

    template<size_t n = 32, std::endian endian = std::endian::native, expp::bitorder bitorder = bitorder::msb_first>
    class Float : public Byte<n,endian,bitorder>{

    };

    class Bool : public Byte<8>{

    };



}