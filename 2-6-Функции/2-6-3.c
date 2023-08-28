enum move_dir { MD_UP, MD_RIGHT, MD_DOWN, MD_LEFT, MD_NONE };

struct list {
    struct list* next;
    void (*handler)(move_dir);
};
struct list* node_create( void (*handler)(move_dir) ) {
    struct list* ans = malloc(sizeof(struct list));
    *ans = (struct list) {.handler = handler, .next = NULL};
    return ans;
} 

void list_add_front( struct list** old, void (*re)(move_dir) ) {
    struct list* ans = node_create( re );
    (*ans).next = *old;
    *old = ans;
}

void list_destroy( struct list* list ) {
    if(list == NULL){
        return;
    }
    list_destroy((*list).next);
    //printf("% " PRId64, (*list).value);
    free(list);
    return;
}


// Робот и его callback'и
// callback'ов может быть неограниченное количество
struct robot {
    const char* name;
    struct list* actions;
    
};

// Определите тип обработчика событий move_callback с помощью typedef
typedef void (move_callback)(move_dir);


// Добавить callback к роботу, чтобы он вызывался при движении
// В callback будет передаваться направление движения
void register_callback(struct robot* robot, move_callback new_cb) {
    if((robot -> actions)){
        list_add_front(&(robot -> actions), new_cb);
        return;
    } 
    (robot -> actions) = malloc(sizeof(struct list));
    *(robot -> actions) = (struct list){.handler = new_cb, .next = NULL};
    
}

// Отменить все подписки на события.
// Это нужно чтобы освободить зарезервированные ресурсы
// например, выделенную в куче память
void unregister_all_callbacks(struct robot* robot) {
    list_destroy( (robot -> actions) );
}

// Вызывается когда робот движется
// Эта функция должна вызвать все обработчики событий
void move(struct robot* robot, enum move_dir dir) {
    //((robot -> actions).handler)(dir);
    
    
    struct list* alist = (*robot).actions;
    while(alist){
        ((*alist).handler)(dir);
        alist = alist -> next;
    }
    
}
