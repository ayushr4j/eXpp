#ifndef _expp_core_log_
#define _expp_core_log_

#include <iostream>

namespace expp{

    namespace log{

        enum class LogLevel : uint8_t{
            Debug,  //debug only logs in debug build 
            Info,   //used to log information, like device info, some configuration etc
            Warn,   //used to log warning, Something unusual happened (can be ignored).
            Error   //used to log error, A failure occurred (should not be ignored).
        };
        
        /**
         * @brief Base class for Debug Logger
         * 
         * 
         */
        class Logger{
            protected:
                static Logger* instance;
            public:

                static Logger* getInstance(){ return instance; }
                static void    setInstance(Logger* inst){ instance = inst; }

                virtual void log(LogLevel level, const char* logString);

                template<typename Arg, typename... Args>
                void log(LogLevel level, Arg& arg, Args... args);

        };
        
        
        

        template <typename... Args>
        void log(LogLevel level,  Args... args){
            Logger::getInstance()->log(level,args...);
        };
        template <typename... Args>
        void log(Args... args){
            log(LogLevel::Debug, args...);
        };

        template <typename... Args>
        void logi(Args... args){
            log(LogLevel::Info, args...);
        };
        template <typename... Args>
        void logd(Args... args){
            log(LogLevel::Debug, args...);
        };
        template < typename... Args>
        void logw(Args... args){
            log(LogLevel::Warn, args...);
        };
        template <typename... Args>
        void loge(Args... args){
            log(LogLevel::Error, args...);
        };

    }


    
    

}

#endif 