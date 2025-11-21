#ifndef _expp_io_file_
#define _expp_file_

#include "core/stream/stream.hpp"
#include <cstdint>

namespace expp {

    namespace file {
        
        class File : public Stream, public Seekable{
            protected:

            public:
                void open(const char* filepath);

                void readNBytes(void* dst, size_t n, uint8_t flags);
        };

    }

}

#endif