#ifndef _expp_core_type_
#define _expp_core_type_

#include "core/stream/stream.hpp"
#include "string"
#include <stddef.h>
#include "core/memory/pointer.hpp"


namespace expp {

    

    /*class Serializable{

        public:

            virtual void serialize(Serializer* serializer);
            
    };*/

    class Type{
        protected:
            memory::Pointer* ptr;
            friend class memory::Pointer;
        public:

            virtual void getSizeBits();

        

    };

    class MappedType{
    protected:
        class Map{
            protected:
                virtual void mapField(std::string name, Pointer ptr, size_t bits, uint8_t flags); //endianness, bitorder
        
            public:
                template<typename type>
                void map(std::string name, type* ptr, uint32_t flags){

                    if(dynamic_cast<MappedType*>(ptr)){
                        ptr->map(name,this);
                    }else{
                        mapField(name, ptr, sizeof(type)*8, flags);
                    }

                }

                template<typename type>
                void map(std::string name, type* ptr, size_t bits, uint32_t flags){

                    if(dynamic_cast<MappedType*>(ptr)){
                        ptr->map(name,this);
                    }else{
                        mapField(name, ptr, bits, flags);
                    }

                }
        };
        class InputMap : public Map{
            InputStream* stream;
            public:
                virtual void map(void* ptr, size_t bits, uint8_t flags);

        };
        class OutputMapper : public Map{
            OutputStream* writer;
            public:
                virtual void map(void* ptr, size_t bits, uint8_t flags);

        };
    public:
        virtual void map(Map* map) = 0;

    };
    
    

}

#endif 