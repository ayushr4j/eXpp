#ifndef _expp_core_utils_
#define _expp_core_utils_

#include "core/stream/stream.hpp"
#include "core/exception.hpp"

namespace expp {
    namespace utils{

        
        /**
         * @brief serialize converts given object to stream
         * 
         * @tparam Type 
         * @param stream stream where object will be written to
         * @param obj object to convert
         */
        template<typename Stream, typename Type>
        void serialize(Stream* stream, Type* obj){


            throw NotImplemented("This type doesn't support serialize. implement void serialize(Stream* steam, Type* obj);");
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

