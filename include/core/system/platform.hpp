/**
 * @file core/system/platform.hpp
 * @author Ayush Raj
 * @brief defines Platform Related stuffs
 * @version 0.1
 * @date 2025-11-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _expp_core_system_platform_
#define _expp_core_system_platform_

#include <stdint.h>

namespace expp {
    /**
     * @brief Defines all supported platforms
     * 
     */
    enum class Platform : uint32_t{
            Windows  = 1,
            Unix     = 1 << 1,
            UnixLike = 1 << 3,
            Linux    = 1 << 4 | UnixLike,
            ChromeOS = 1 << 5 | Linux, 
            Android  = 1 << 6 | Linux,
            Apple    = 1 << 7,
            Mac      = 1 << 8 | Unix | Apple,
            IOS      = 1 << 9 | UnixLike | Apple,

    };
    /**
    * @brief Returns the platform of current build.
    *
    * This function is evaluated at compile time and maps the active build
    * configuration macros (e.g., WINDOWS, ANDROID etc) to the corresponding
    * `Platform` enum value.
    *
    * @return The compile-time detected target platform.
    */
    consteval Platform getPlatform(){
        Platform cur = Platform::Unix;

        #if defined(__APPLE__)
            #include <TargetConditionals.h>
            #if TARGET_OS_OSX
                cur = Platform::Mac;
                #define MAC
            #elif TARGET_OS_IOS
                cur = Platform::IOS;
                #define IOS
            #endif
            // macOS or iOS (need extra check below)
        #elif defined(__linux__)
            cur = Platform::Linux;
            #define LINUX

            #if defined( CHROMEOS_BUILD)
                cur = Platform::ChomreOS
                #define CHROMEOS
            #elif defined __ANDROID__
                cur = Platform::Android;
                #define ANDROID
            #endif
        #elif defined(_WIN32) || defined(_WIN64)
            cur = Platform::Windows;
            #define WINDOWS
        #endif

        

        return cur;
    }

    /**
    * @brief Checks whether the current platform matches the given one.
    *
    * This function is evaluated at compile time. It compares the supplied
    * platform value against the platform of the current build, including
    * handling grouped values such as 'UNIX'.
    *
    * @param plat The Platform to compare against.
    * @return `true` if the current platform belongs to the same group or
    *         matches the given value; otherwise `false`.
    */
    consteval bool isPlatform(Platform plat){
        Platform cur = getPlatform();
        return (static_cast<uint32_t>(plat) & static_cast<uint32_t>(cur)) == static_cast<uint32_t>(plat);
    }
}

#endif