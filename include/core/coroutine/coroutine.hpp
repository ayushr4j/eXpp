#ifndef _expp_coroutine_
#define _expp_coroutine_

#include <coroutine>
#include <future>
#include "iostream"

namespace expp {

    class coroutine;

    extern thread_local std::coroutine_handle<> current_coroutine;
    
    class coroutine{

        struct promise_type;
        std::coroutine_handle<promise_type> handle;
        coroutine(std::coroutine_handle<promise_type> h) : handle(h) {}

        struct promise_type{

            coroutine get_return_object(){
                return coroutine{ std::coroutine_handle<promise_type>::from_promise(*this) }; 
            }

            std::suspend_always initial_suspend() noexcept {
                current_coroutine = std::coroutine_handle<promise_type>::from_promise(*this);
                std::cout << "Initial Suspend\n";
                return {}; 
            }

            std::suspend_always final_suspend() noexcept {
                std::cout << "Final Suspend\n";
                return {};
            }

            void unhandled_exception() {
                std::terminate();
            }

            void await_resume() {
                std::cout << "Coroutine resumed!\n";
            }
            void await_suspend(std::coroutine_handle<>) {
                std::cout << "await Suspend\n";
            }


        };

        
        

        
        

        
    };

    template<typename T>
struct Coroutine {   
        struct promise_type {
        T value;
        std::coroutine_handle<> continuation = nullptr;

        Coroutine get_return_object() {
            return Coroutine{ std::coroutine_handle<promise_type>::from_promise(*this) };
        }

        std::suspend_always initial_suspend() noexcept {
            current_coroutine = std::coroutine_handle<promise_type>::from_promise(*this);
                
            std::cout << "Initial Suspend\n";
            return {}; 
        }

        std::suspend_always final_suspend() noexcept {
            std::cout << "Final Suspend\n";
            if (continuation)
                continuation.resume();
            return {};
        }

        void unhandled_exception() { std::terminate(); }

        // For async operations (co_await)
        template<typename Awaitable>
        auto await_transform(Awaitable&& a) noexcept {
            return std::forward<Awaitable>(a); // pass through
        }

        // For co_yield
        std::suspend_always yield_value(T v) noexcept {
            value = v;
            return {};
        }

        void return_void() noexcept {}
    };

    
        

        // 1) await_ready -> false means "suspend and call await_suspend"
        bool await_ready() noexcept {
            std::cout << "Await_Ready\n";
            // if coroutine already finished, no suspension required
            return !handle || handle.done();
        }

        // 2) await_suspend called with handle of awaiting coroutine
        bool await_suspend(std::coroutine_handle<> awaiting_h) noexcept {
            std::cout << "Await_Suspend\n";
            // Store continuation so that when 'coro' yields/finalizes it resumes the awaiter
            handle.promise().continuation = awaiting_h;
            // resume the producer coroutine to make it produce the next value (or finish)
            handle.resume();
            // returning true means the awaiting coroutine stays suspended until resumed later
            return true;
        }

        // 3) await_resume returns the yielded value
        T await_resume() noexcept {
            std::cout << "Await_Resume\n";
            return current();
        }
    

    Coroutine<T> operator co_await() & noexcept { return *this; }


    std::coroutine_handle<promise_type> handle;

    Coroutine(std::coroutine_handle<promise_type> h) : handle(h) {}

    bool resume() {
        if (!handle.done())
            handle.resume();
        return !handle.done();
    }

    T current() {
        return handle.promise().value;
    }
};




#define CO_AWAIT(fun) \
    current_coro = this;
    //store current handle; fun; co_wait suspend_always{}

}

#endif