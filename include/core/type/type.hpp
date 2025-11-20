#ifndef AR4J_TYPE_TYPE
#define AR4J_TYPE_TYPE

#include "string"
#include <stddef.h>
#include "core/stream/bitstream.hpp"

namespace ar4j {

    class MappedType{
    protected:
        class Map{
            protected:
                virtual void mapField(std::string name, Buffer* ptr, size_t bits, uint8_t flags); //endianness, bitorder
        
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
            BitReader* reader;
            public:
                virtual void map(void* ptr, size_t bits, uint8_t flags);

        };
        class OutputMapper : public Map{
            BitWriter* writer;
            public:
                virtual void map(void* ptr, size_t bits, uint8_t flags);

        };
    public:
        virtual void map(Map* map) = 0;

    };
    
    

}

#endif //AR4J_TYPE_TYPE