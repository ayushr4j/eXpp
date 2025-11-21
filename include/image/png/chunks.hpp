#ifndef _expp_image_png_chunks_
#define _expp_image_png_chunks_


#include "core/type/type.hpp"
#include <cstdint>
namespace expp {
    namespace image {
        namespace png {
            
            

            class Chunk : public MappedType{
                protected:
                    uint32_t length;
                    uint32_t chunkType;
                    uint32_t crc;

                    void computeCRC();

                public:
                    
                    bool isCritical();
                    bool isPrivate();
                    bool isSafeToCopy();

                    void map(Map* map){
                        mapChunk(map);
                        computeCRC();
                    };

                    virtual void mapChunk(Map* map){

                    }

            };
            class IHDR : Chunk{
                protected:
                    uint32_t width;
                    uint32_t height;
                    uint8_t bitDepth;
                    uint8_t colorType;
                    uint8_t compressionMethod;
                    uint8_t filterMethod;
                    uint8_t interlaceMethod;
                public:

                    void mapChunk(Map* map);
            };

             

        }
    }
}

#endif