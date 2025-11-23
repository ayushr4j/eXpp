#ifndef _expp_system_build_type_
#define _expp_system_build_type_

#include "stdint.h"
#include <cstdint>

namespace expp {
    class BuildType{
        public:
            /**
            * @brief Defines compile modes
            * 
            */
            enum : uint8_t{
                Debug     = 0,
                Release   = 1,
            };

            /// @brief Check wether current compile mode matches given mode.
            /// @param mode mode to check
            /// @return true if mode is equal to or in same group as current compileMode.
            consteval bool operator == (BuildType type){
                
                return (this->type & type.type) == this->type;
            }
        protected:
            /// @brief gets current buildType
            consteval uint32_t getBuildType(){
                uint32_t cur = BuildType::Debug;

                #if defined(NDEBUG)
                    #define RELEASE 1
                    cur = BuildType::Release;
                #else
                    #define DEBUG 1
                    cur = BuildType::Debug;
                #endif

                return cur;
            }
            uint8_t type = getBuildType();
    };
}

#endif