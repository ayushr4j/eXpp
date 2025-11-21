/**
 * @file core/system/architecture.hpp
 * @author Ayush Raj
 * @brief defines Architecutre related stuffs
 * @version 0.1
 * @date 2025-11-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _expp_base_
#define _expp_base_

#include <cstdint>
#include <stdint.h>


namespace expp {

    

    /**
     * @brief Defines all supported Architectures
     * 
     */
    enum class Architecture : uint32_t{
        _32bit = 1,
        _64bit = 1 << 1,
        x86    = 1 << 2 | _32bit,
        x64    = 1 << 3 | _64bit,

        arm    = 1 << 4,
        arm32  = 1 << 5 | arm | _32bit,
        arm64  = 1 << 6 | arm | _64bit,
        
        
        OTHER,
    };
    /**
    * @brief Returns the architecture for which this code is being compiled.
    *
    * This function is evaluated at compile time and maps the active build
    * configuration macros (e.g., X86, X64, ARM, ARM64, etc) to the corresponding
    * `Architecture` enum value.
    *
    * @return The compile-time detected target architecture.
    */
    consteval Architecture getArchitecture(){
        Architecture cur = Architecture::OTHER;

        #if defined __i386__ || defined _M_IX86
            #define X86
            cur = Architecture::x86; 
        #elif defined __x86_64__ || defined (_M_X64) || defined _M_AMD64
            #degine X64
            cur = Architecture::x64;
        #elif defined __arm__ || defined __arm || defined _M_ARM
            #define ARM32
            cur = Architecture::arm32;
        #elif defined __aarch64__ || defined __arm64__ || defined _M_ARM64
            #define ARM64
            cur = Architecture::arm64;
        #endif
        return cur;
    }
    /**
    * @brief Checks whether the current architecture matches the given one.
    *
    * This function is evaluated at compile time. It compares the supplied
    * architecture value against the architecture of the current build, including
    * handling grouped values such as `_32bit` and `_64bit`.
    *
    * @param arch The architecture to compare against.
    * @return `true` if the current architecture belongs to the same group or
    *         matches the given value; otherwise `false`.
    */
    consteval bool isArchitecture(Architecture arch){
        Architecture cur = getArchitecture();
        return (static_cast<uint32_t>(arch) & static_cast<uint32_t>(cur)) == static_cast<uint32_t>(arch);
    }



};

#endif