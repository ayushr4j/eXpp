#ifndef _expp_exception_
#define _expp_exception_


#include <exception>
namespace expp {

    class Exception : public std::exception{

    };

    class NotImplemented : public Exception{
        
    };

    class OutOfBound : public Exception{

    };

}

#endif