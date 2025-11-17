#ifndef AR4J_FILE_FILE
#define AR4J_FILE_FILE

#include "core/stream/stream.hpp"
#include <cstdint>

namespace ar4j {

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