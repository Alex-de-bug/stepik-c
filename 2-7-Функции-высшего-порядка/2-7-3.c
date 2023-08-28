/*
struct list {
    int64_t value;
    struct list* next;
};
*/
/* Вы можете пользоваться следующими функциями */
void print_int64(int64_t i);
struct list* node_create( int64_t value );



/*  Создать новый список, в котором каждый элемент получен из соответствующего
    элемента списка l путём применения функции f */
struct list* list_map( struct list* l, int64_t (f) (int64_t))  {
    struct list* list = (struct list*) l;
    while(list){
        list -> value = f(list -> value);
        list = list -> next;
    }
    return (struct list*) l;
}

struct list* list_copy( const struct list* l ) {
    if(!l){
        return (struct list*)l;
    }
    struct list* old_list = (struct list*) l;
    struct list* new_list = node_create( old_list -> value );
    struct list* ans = new_list;
        new_list -> next = node_create( (old_list -> next) -> value );
        old_list = old_list -> next;
        new_list = new_list -> next;
    while(old_list -> next){
        new_list -> next = node_create( (old_list -> next) -> value );
        old_list = old_list -> next;
        new_list = new_list -> next;
    }
    return ans;
}

struct list* list_abs(const struct list* l)  {
    struct list* copy = list_copy( l );
    return list_map(copy, labs);
}
