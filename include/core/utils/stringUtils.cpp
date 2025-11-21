#ifndef _expp_core_utils_strings_
#define _expp_core_utils_strings_

#include <string>
#include <vector>

namespace expp {

    namespace utils{
        /**
        * @brief used to convert any type to its string  for serialization(escaped).
        * 
        * @param obj 
        * @return String representation of obj
        */
        template<typename type>
        std::string to_string(const type&& obj){

        }

        /**
        * @brief used to get back desired type from string representation.
        * 
        * @param string must be the string representation of the type. if not it will throw exception
        * @return type object constructed from string
        */
        template<typename type>
        type from_string(const std::string&& string){
            
        }

        /**
         * @brief serialize function helps to serialize
         * 
         * @tparam Arg 
         * @tparam Args 
         * @param arg 
         * @param args 
         * @return std::string 
         */
        
        template<typename Arg, typename... Args>
        std::string serialize(const Arg&& arg,const Args&&... args){
            std::string str = to_string(arg);
            if(sizeof...(args) > 0){
                str += ", " + serialize(args...);
            }
            return str;
        }

        std::vector<std::string> deserialize(std::string string){

        }
    }

    

}

#endif //AR4J_STRING_UTILS



