#ifndef _expp_core_context_
#define _expp_core_context_

#include "core/memory/allocator.hpp"


namespace expp {

    class Context{
        protected:
            memory::Allocator* allocator = new memory::Allocator();
            Context* prev = nullptr;
            friend void pushContext(Context& ctx);
            friend void popContext();
        public:
            memory::Allocator* getAllocator(){ return allocator; }
    
    };

    thread_local static Context* context = new Context();
    void pushContext(Context& ctx);
    void popContext();

}

#endif