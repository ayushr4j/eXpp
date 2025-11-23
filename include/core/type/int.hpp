
#include "/type.hpp"
#include <bit>
#include <cstdint>

namespace expp {

    enum class bitorder{
        msb_first = 0,
        lsb_first = 1,

        native = msb_first, //generally its msb_first. check if other formats exist
    };

    template <size_t n = 8, std::endian endian = std::endian::native, expp::bitorder bitorder = bitorder::msb_first>
    class Byte : public Type{
        uint8_t data[n/8 + (n%8 > 0)];
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


}