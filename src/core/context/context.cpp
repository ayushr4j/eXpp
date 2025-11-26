
#include "core/context/context.hpp"


//thread_local static expp::Context* expp::context = new expp::Context();

void expp::pushContext(Context& ctx){
        ctx.prev = context;
        context = &ctx;        
}
void expp::popContext(){
    context = context->prev;
}