struct list {
  int64_t value;
  struct list* next;
};

struct list* node_create( int64_t value ) {
    struct list* ans = malloc(sizeof(struct list));
    *ans = (struct list) {.value = value, .next = NULL};
    return ans;
}
