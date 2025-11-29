#include "core/coroutine/coroutine.hpp"

thread_local std::coroutine_handle<> expp::current_coroutine = nullptr;