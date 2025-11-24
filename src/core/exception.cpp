
#include "core/exception.hpp"
#include "ostream"

std::ostream& operator << (std::ostream& stream, expp::Exception& e){
        e.output(stream);
        return stream;
}