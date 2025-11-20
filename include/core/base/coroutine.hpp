#ifndef AR4J_COROUTINE
#define AR4J_COROUTINE

#include <coroutine>

namespace ar4j {

   
    template<typename t>
    class Coroutine{
    public:
        
        struct promise;
        using handle_type = std::coroutine_handle<promise>;
        using promise_type = promise;
            
        struct promise{
            t value_;
            Coroutine<t> get_return_object() { return {handle_type::from_promise(*this)}; }
            std::suspend_always initial_suspend() noexcept { return {}; }
            std::suspend_always final_suspend() noexcept { return {}; }
            void return_void() {}
            void unhandled_exception() {}

            template<std::convertible_to<t> From> // C++20 concept
            std::suspend_always yield_value(From&& from)
            {
                value_ = std::forward<From>(from); // caching the result in promise
                return {};
            }
        };

        handle_type h_;

        Coroutine(handle_type h) : h_(h){}


    };

    


    Coroutine<int> test(){

        co_yield 1;

    }

}

#endif //AR4J_COROUTINE