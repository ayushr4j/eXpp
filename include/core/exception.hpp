#ifndef _expp_exception_
#define _expp_exception_


#include <exception>
namespace expp {

    class Exception : public std::exception{
            const char* str;
        public:
            Exception(const char* msg) : str(msg){};

            virtual const char* getMessage(){ return str; }
    };

    class NotImplemented : public Exception{
        public:
            NotImplemented(const char* msg) : Exception(msg){}
    };

    class OutOfBound : public Exception{
        public:
            OutOfBound(const char* msg) : Exception(msg){}
    };

    

}

#endif