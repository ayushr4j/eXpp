#ifndef _expp_core_utils_
#define _expp_core_utils_

#include "core/stream/stream.hpp"
#include <exception>
#include <immintrin.h>
namespace expp {
    namespace utils{

        
        /**
         * @brief serialize converts given object to stream
         * 
         * @tparam Type 
         * @param stream stream where object will be written to
         * @param obj object to convert
         */
        template<typename Type>
        void serialize(OutputStream* stream, Type* obj){
            throw NotImplemented("This type doesn't support deserialize. implement void serialize(OutputStream* steam, Type* obj);");
        }


        /**
         * @brief deserialize constructs object from stream
         * 
         * @tparam Type 
         * @param stream stream from where object will be read
         * @param obj object to construct
         */
        template<typename Type>
        void deserialize(InputStream* stream, Type* obj){
            throw NotImplemented("This type doesn't support deserialize. implement void deserialize(InputStream* steam, Type* obj);");
        }

    } //utils
} //expp


#endif 

