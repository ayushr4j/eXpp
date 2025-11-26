#include "core/context/context.hpp"

#include "iostream"

int main(){

    std::cout << expp::context->getAllocator();

    expp::Context* ctx = new expp::Context();
    expp::pushContext(*ctx);
    expp::popContext();
    return 0;
}