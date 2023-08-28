// Вам доступна функция
struct list* node_create( int64_t value );

void list_add_front( struct list** old, int64_t value ) {
    struct list* ans = node_create( value );
    (*ans).next = *old;
    *old = ans;
}
