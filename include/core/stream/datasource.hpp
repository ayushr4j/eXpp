

#include <stdint.h>


namespace ar4j {
    
    class DataSource{

    };

    class InputSource : public DataSource{
        
    public:

        virtual size_t read(void* buf, size_t bytes, uint64_t timeout = -1 ) = 0;
        
        
    };
    class OutputSource : public DataSource{
    public:

        virtual size_t write(void* buf, size_t bytes) = 0;

    };
    

    class SeekableSource : public DataSource{

    };

    class File : InputSource,OutputSource,SeekableSource{

    };


}