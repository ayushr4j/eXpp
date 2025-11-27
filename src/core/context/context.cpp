
#include "core/context/context.hpp"


thread_local expp::Context* expp::context = new expp::Context();
thread_local expp::Context* expp::Context::prev = nullptr;

void expp::pushContext(Context& ctx){
        ctx.prev = context;
        context = &ctx;
        memory::pushAllocator(*ctx.allocator);
}
void expp::popContext(){
    context = context->prev;
    memory::popAllocator();
}