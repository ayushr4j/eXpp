#ifndef _expp_core_log_
#define _expp_core_log_

#include <iostream>

namespace expp{

    namespace log{

        enum class LogLevel : uint8_t{
            Debug, Info, Warn, Error
        };
        
        /**
         * @brief Logger class provides the base for Debug logging
         * 
         * 
         */
        class Logger{
            
            public:

                virtual void log(LogLevel level, const char* logString){
                    std::cerr << logString;
                }

        };

        Logger* instance = new Logger();

        template <typename Arg, typename... Args>
        void log(LogLevel level, Arg arg, Args... args){
            instance->log(level,arg,args...);
        };
        template <typename Arg, typename... Args>
        void log(Arg arg, Args... args){
            log(LogLevel::Debug, arg, args...)
        };

        template <typename Arg, typename... Args>
        void logi(Arg arg, Args... args){
            log(LogLevel::Info, arg, args...);
        };
        template <typename Arg, typename... Args>
        void logd(Arg arg, Args... args){
            log(LogLevel::Debug, arg, args...);
        };
        template <typename Arg, typename... Args>
        void logw(Arg arg, Args... args){
            log(LogLevel::Warn, arg, args...);
        };
        template <typename Exception, typename Arg, typename... Args>
        void loge(Exception, Arg arg, Args... args){
            log(LogLevel::Error, arg, args...);
        };



        

    }


    
    

}

#endif 