/*
struct list {
    int64_t value;
    struct list* next;
};
*/
void print_int64(int64_t i);

struct list* node_create( int64_t value );
void list_destroy( struct list* list );


/*  Сгенерировать список длины sz с помощью значения init и функции f
 Результат: init, f(init), f(f(init)), ... */
struct list* list_iterate( int64_t init, size_t sz, int64_t(f)(int64_t)) {
    if(sz!=0){
        int64_t tmp = init;
        struct list* list = node_create( tmp );
        struct list* result = list;
        sz--;
        while(sz != 0){
            sz--;
            tmp = f(tmp);
            list -> next = node_create( tmp );
            list = list -> next;
        }
        return result;
    }
    return NULL;
}
