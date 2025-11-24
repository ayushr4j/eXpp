#ifndef _expp_type_serialize_
#define _expp_type_serialize_

#include "core/stream/stream.hpp"

namespace expp {

    class Serializer{
        enum Mode{
            Serialize,
            Deserialize,
        };
    public:
        template<typename Stream>
        void serialize(Mode mode){
            
        };
        virtual void serialize(OutputStream* stream);
        virtual void deserialize(InputStream* stream);

        template<typename T>
        void serialize(T* obj){

        }

    };

    class BinarySerializer : public Serializer{

    };
    class BitSerializer : public Serializer{

    };


    template<typename T>
    concept Serializable = 
        requires (T& obj, Serializer* s) {
        { obj.serialize(s) };                 // member serialize
    }
    ||
    requires (T& obj, Serializer* s) {
        { serialize(s, &obj) };               // free function serialize
    };

}

#endif