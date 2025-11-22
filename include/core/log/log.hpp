#ifndef _expp_core_log_
#define _expp_core_log_

#include <iostream>

namespace expp{

    namespace log{

        enum class LogLevel : uint8_t{
            Debug, Info, Warn, Error
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

                virtual void log(LogLevel level, const char* logString){
                    std::cerr << logString;
                }

        };
        
        
        

        template <typename Arg, typename... Args>
        void log(LogLevel level, Arg arg, Args... args){
            Logger::getInstance()->log(level,arg,args...);
        };
        template <typename Arg, typename... Args>
        void log(Arg arg, Args... args){
            log(LogLevel::Debug, arg, args...);
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