#ifndef _expp_exception_
#define _expp_exception_


#include <cstddef>
#include <exception>
#include <ostream>
#include <type_traits>


#include "iostream"

namespace expp {

    
    
    

    class Exception : public std::exception{
        protected:
            std::string msg;
        public:
            virtual void setMessage(std::string msg){ this->msg = msg; }
            virtual std::string getMessage(){ return msg; }

            virtual void output (std::ostream& stream){
                stream << "Exception : " << msg;
            }

    };

    

    class NotImplemented : public Exception{
        public:
            NotImplemented(const char* msg){
                this->msg = msg;
            }
    };

    class OutOfBound : public Exception{
        size_t index, size;
        public:
            OutOfBound(size_t index, size_t size, const char* msg = ""){
                this->index = index;
                this->size = size;

                this->msg = msg;
            }

            virtual void output (std::ostream& stream){
                stream << "OutOfBound Exception : index " << index << " >= size " << size << " ";
            }

            


    };

    

}

std::ostream& operator << (std::ostream& stream, expp::Exception& e);

#endif