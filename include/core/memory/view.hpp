
#include "./pointer.hpp"

namespace expp {
    namespace memory {
        
        class View : public Pointer{
            size_t size;
        };
        
    }

    using MemView = memory::View;

    
}