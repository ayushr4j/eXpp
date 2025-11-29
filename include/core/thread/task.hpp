#ifndef _expp_core_thread_task_
#define _expp_core_thread_task_

#include "core/context/context.hpp"
namespace expp {

    namespace thread {

        class Task{
            protected:
                Context contex;
            
            public:
                Task(Context& context) : contex(context) {}
                
                void execute();
            

        };

    }

}

#endif