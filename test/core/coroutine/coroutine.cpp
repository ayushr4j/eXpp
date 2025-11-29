#include "core/coroutine/coroutine.hpp"
#include "core/thread/task.hpp"
#include <coroutine>




expp::Coroutine<int> test(){
    std::cout << "inside Test\n";

    std::cout << "Suspending\n";
    co_await std::suspend_always{};
    std::cout << "Resumed\n";
    
}




int main(){

    test().resume();

    char c;
    std::cin >> c;

    expp::current_coroutine.resume();

    std::cin.ignore();

}