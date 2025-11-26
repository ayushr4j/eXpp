#ifndef _expp_ds_intrusive_list_
#define _expp_ds_intrusive_list_

#include "../linked_list.hpp"

namespace expp {



    template<typename t, bool doubleLinked = false, bool circular = false>
    class IntrusiveLinkedList : public LinkedList<t, doubleLinked, circular>{
        protected:
            t* nextListItem = nullptr;
        public:

            t* getNext(){ return nextListItem; }

            void removeItem(t* item);

            t* itemAt(size_t index);
            t* getLast();
            t* getFirst();
            t* itemBefore(t* item);

            void append(t* item);
            void prepend(t* item);
            void insertAt(size_t index, t* item);
            void insertAfter(t* existingItem, t* newItem);
            void insertBefore(t* existingItem, t* newItem);

            void remove(t* item);
            void remove(size_t index);
    };

//impl

    template<typename t>
    t* IntrusiveList<t>::getFirst(){
        return this->getNext();
    }
    template<typename t>
    t* IntrusiveList<t>::getLast(){
        t* ptr = ptr->getNext();
        while(ptr != nullptr && ptr->getNext() != nullptr){
            ptr = ptr->getNext();
            break;
        }
        return ptr;
    }
    template<typename t>
    t* IntrusiveList<t>::itemAt(size_t index){
        size_t i = 0;
        t* ptr = ptr->getNext();
        while(i < index && ptr != nullptr && ptr->getNext() != nullptr){
            ptr = ptr->getNext();
            break;
        }
        if(i != index){
            return nullptr;
        }
        return ptr;
    };
    template<typename t>
    t* IntrusiveList<t>::itemBefore(t* item){
        size_t i = 0;
        t* ptr = ptr->getNext();
        while(ptr != nullptr && ptr->getNext() != nullptr && ptr->getNext() != item){
            ptr = ptr->getNext();
            break;
        }
        if(ptr->getNext() == item){
            return ptr;
        }
        return nullptr;
    };
    

    template<typename t>
    void IntrusiveList<t>::append(t* item){
        t* ptr = this;
        while(ptr->nextListItem != nullptr){
            ptr = ptr->nextListItem;
        }
        ptr->nextListItem = item;
    }; 
    template<typename t>
    void IntrusiveList<t>::prepend(t* item){
        item->nextListItem = this->nextListItem;
        this->nextListItem = item;
    }
    template<typename t>
    void IntrusiveList<t>::insertAt(size_t index, t* item){

    }
    

    template<typename t>
    void IntrusiveList<t>::removeItem(t* item){

        t* next = item->getNext();
        item->nextListItem = nullptr;
        if(getNext() == item){  // if first item is match
            nextListItem = next;
            return;
        }
        t* before = itemBefore(*item);
        if(before != nullptr){
            before->nextListItem = next;
        }
    }
    template<typename t>
    void IntrusiveList<t>::remove(size_t index){

        if(index == 0){
            if(nextListItem == nullptr){ return; }  //list contains no element
            t* next = nextListItem;
            nextListItem = nextListItem->nextListItem;
            next->nextListItem = nullptr;
            return;
        }

        t* item = itemAt(index-1);
        if(item != nullptr){

            t* toRemove = item->nextListItem;
            if(toRemove == nullptr){ 
                return; // nothing to remove;
            }

            t* next = toRemove->nextListItem;
            item->nextListItem = next;
            toRemove->nextListItem = nullptr;


        }

    };

}



#endif