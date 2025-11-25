

namespace expp {

    template<typename t>
    class ListInteface{

    public:
        virtual t* getNext();

        virtual void removeItem(t* item);

        virtual t* itemAt(size_t index);
        virtual t* getLast();
        virtual t* getFirst();
        virtual t* itemBefore(t* item);

        virtual void append(t* item);
        virtual void prepend(t* item);
        virtual void insertAt(size_t index, t* item);
        virtual void insertAfter(t* existingItem, t* newItem);
        virtual void insertBefore(t* existingItem, t* newItem);

        virtual void remove(t* item);
        virtual void remove(size_t index);   
    }

}