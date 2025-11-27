#ifndef _expp_core_context_
#define _expp_core_context_

#include "core/memory/allocator.hpp"


namespace expp {

    class Context{
        protected:
            memory::Allocator* allocator = new memory::Allocator();
            thread_local static Context* prev;
            friend void pushContext(Context& ctx);
            friend void popContext();
        public:
            memory::Allocator* getAllocator(){ return allocator; }
    
    };

    extern thread_local Context* context ;
    void pushContext(Context& ctx);
    void popContext();

}

#endif