

/**
 * @file core/system/compiler.hpp
 * @author Ayush Raj
 * @brief defines Platform Related stuffs
 * @version 0.1
 * @date 2025-11-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */



#ifndef _expp_core_system_compiler_
#define _expp_core_system_compiler_

#include <stdint.h>

namespace expp {
    /**
     * @brief Defines all supported compiler
     * 
     */
    enum class Compiler : uint32_t{
            UNKNOWN      = 0,
            GCC          = 1,
            Clang        = 1 << 2,
            AppleClang   = 1 << 3 | Clang,
            NDKClang     = 1 << 4 | Clang,
            MSVC         = 1 << 5,

            
            
    };
    /**
    * @brief Returns the compiler used for this build.
    *
    * This function is evaluated at compile time and maps the active compiler macros (e.g., GCC, Clang etc) to the corresponding
    * `Compiler` enum value.
    *
    * @return The compile-time detected compiler.
    */
    consteval Compiler getCompiler(){
        Compiler cur = Compiler::UNKNOWN;

        
        #if defined(__clang__)
            #define CLANG
            cur = Compiler::Clang;
            #ifdef __apple_build_version__
                #define APPLE_CLANG
                cur = Compiler::AppleClang;
            #endif
            #ifdef __ANDROID__
                #define NDK_CLANG
                cur = Compiler::NDKClang;
            #endif
            //std::cout << "Using Clang: " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__ << std::endl;
        #elif defined(__GNUC__)
            #define GCC
            cur = Compiler::GCC;
            //std::cout << "Using GCC: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
        #elif defined(_MSC_VER)
            #define MSVC
            cur = Compiler::MSVC;
            //std::cout << "Using MSVC: " << _MSC_VER << std::endl;
        #else
            std::cout << "Unknown compiler" << std::endl;
        #endif

        return cur;
    }

    /**
    * @brief Checks whether the current compiler matches the given one.
    *
    * This function is evaluated at compile time. It compares the supplied
    * compiler value against the compiler of the current build, including
    * handling grouped values such as 'UNKNOWN'.
    *
    * @param comp The Compiler to compare against.
    * @return `true` if the current compiler belongs to the same group or
    *         matches the given value; otherwise `false`.
    */
    consteval bool isCompiler(Compiler comp){
        Compiler cur = getCompiler();
        return (static_cast<uint32_t>(comp) & static_cast<uint32_t>(cur)) == static_cast<uint32_t>(comp);
    }


    /**
     * @brief Defines compile modes
     * 
     */
    enum class CompileMode : uint8_t{
        Debug     = 0,
        Release   = 1,
    };

    /// @brief gets current compilemode
    consteval CompileMode getCompileMode(){
        CompileMode cur = CompileMode::Debug;

        #if defined(NDEBUG)
            #define RELEASE 1
            cur = CompileMode::Release;
        #else
            #define DEBUG 1
            cur = CompileMode::Debug;
        #endif

        return cur;
    }

    /// @brief Check wether current compile mode matches given mode.
    /// @param mode mode to check
    /// @return true if mode is equal to or in same group as current compileMode.
    consteval bool isCompileMode(CompileMode mode){
        CompileMode cur = getCompileMode();
        return (static_cast<uint32_t>(mode) & static_cast<uint32_t>(cur)) == static_cast<uint32_t>(mode);
    }
}

#endif