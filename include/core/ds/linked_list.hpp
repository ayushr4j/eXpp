#ifndef _expp_ds_list_
#define _expp_ds_list_

#include "./iterator.hpp"

namespace expp {

    template<typename t, bool doubleLinked = false, bool circular = false>
    class LinkedList{
        t node;
        LinkedList<t, doubleLinked, circular>* nodes[1 + doubleLinked];
        
    public:
        class Iterator;
        
        
        virtual t* getNext();

        virtual void removeItem(t* item);

        virtual t* get(size_t index = 0);
        virtual t* getLast();
        virtual t* getFirst();
        virtual t* itemBefore(t* item);
        virtual t* itemAfter(t* item);

        virtual void append(t* item);
        virtual void prepend(t* item);
        virtual void insertAt(size_t index, t* item);
        virtual void insertAfter(t* existingItem, t* newItem);
        virtual void insertBefore(t* existingItem, t* newItem);

        virtual void remove(t* item);
        virtual void remove(size_t index);
    };

    

    template<typename t, bool doubleLinked, bool circular>
    class LinkedList<t,doubleLinked,circular>::Iterator : public expp::Iterator<t>{
        protected:
            LinkedList<t, doubleLinked, circular> *list, *cur;
        public:
            Iterator(LinkedList<t,doubleLinked,circular>* list){
                this->list = list;
            }
            
            bool atStart(){
                return cur == list;
            }
            bool atEnd(){
                return cur->getNext() == nullptr || cur->getNext() == list;
            }
            
            bool next(){
                if(!atEnd()){
                    cur = cur->getNext();
                    return true;
                }else return false;
            }

            bool prev(){
                if constexpr (doubleLinked) {
                    if(!atStart()){
                        cur = list->itemBefore(cur);
                        return true;
                    }
                    return false;
                }else{
                    expp::Iterator<t>::prev();
                }
                
            }
            
    };

}

#endif