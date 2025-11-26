#ifndef _expp_ds_iterator_
#define _expp_ds_iterator_

#include "core/exception.hpp"
namespace expp {

    template<typename t>
    class Iterator{

        public:
            virtual bool atStart();
            virtual bool atEnd();
            virtual bool next();
            virtual bool prev(){
                throw NotImplemented("This iterator doesn't support backward iteration.");
            };

            virtual t* operator->();
    };
    
    
    

}

#endif