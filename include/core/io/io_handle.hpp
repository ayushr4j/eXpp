#ifndef _expp_core_io_handle_
#define _expp_core_io_handle_

#include "core/memory/pointer.hpp"
#include "core/thread/task.hpp"

namespace expp {

    namespace io {

        class InputHandle{
            public:
                virtual void read(Pointer dst, thread::Task callback);
        };
        class OutputHandle{
            public:
                virtual void write(Pointer src, thread::Task callback);
        };
        class IOHandle : public InputHandle, public OutputHandle{

        };

        

    }

}

#endif