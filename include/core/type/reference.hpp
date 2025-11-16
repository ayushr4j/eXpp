#ifndef AR4J_REFERENCE
#define AR4J_REFERENCE

namespace ar4j
{
    //no namespace for ease of using basic types. basic types are most commonly used part of frameworks
    
    
    class A{
        int a;
        float b;
        double c;
        struct {
            int a; 
            float b;
            double c;
        } d;
    };

    

    template<typename t>
    class Reference{
        
        template<typename R>
        Reference<R> operator->();

        template<typename R>
        Reference<R> operator->*(R t::*member);


    };

        
            
} // namespace ar4j

    
#endif //AR4J_REFERENCE