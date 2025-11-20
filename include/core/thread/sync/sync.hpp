#ifndef AR4J_SYNC
#define AR4J_SYNC

#include <stdint.h>

namespace ar4j
{
    namespace sync
    {
        /**
         * @brief Base class for synchronization primitives
         * 
         */
        class Sync{
        protected:
            
        public:
            
            virtual bool lock(uint64_t timeout = 0) noexcept = 0;
            virtual void unlock() noexcept = 0;

        };

    } // namespace sync
} // namespace ar4j


#endif //AR4J_SYNC