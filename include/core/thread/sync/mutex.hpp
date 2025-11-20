#ifndef AR4J_MUTEX
#define AR4J_MUTEX

#include "sync.hpp"
#include <mutex>
#include <thread>

namespace ar4j
{
    namespace sync
    {
        
        /**
         * @brief Helps synchronise between multiple thread.
         * 
         */
        class Mutex : public Sync {
        protected:

            std::mutex mutex;

        public:

            /**
             * @brief tries to lock mutex for given amount of time. if aquired returns true; if not returns false; the mutex must not be owned by current thread.
             * 
             * @param timeout_ms timeout time in milliseconds
             * @return true 
             * @return false 
             */
            virtual bool lock(uint64_t timeout_ms = 0) noexcept{
                bool locked = mutex.try_lock();             //try to lock
                uint64_t time = 0;                          //counter for passed time
                uint64_t step = timeout_ms/10;              //divides timeout in 10parts // may cause slower checks for larger timeperiods 
                step += (step == 0);                        //if step is less than 0, make step 1
                std::chrono::milliseconds interval(step);   
                while(time < timeout_ms && !locked){                   
                    std::this_thread::sleep_for(interval);  //wait for step time
                    locked = mutex.try_lock();              //try to lock again
                    time+=step;                             //increment passed time
                }
                return locked;
            }

            /**
             * @brief unlocks the mutex.
             * 
             */
            virtual void unlock() noexcept{
                mutex.unlock();
            }

            

        };


    } // namespace sync
} // namespace ar4j


#endif //AR4J_MUTEX