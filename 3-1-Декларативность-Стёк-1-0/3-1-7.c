/* Вам доступны:


struct maybe_int64 {
    int64_t value; 
    bool valid; 
};

struct maybe_int64 some_int64(int64_t i);

extern const struct maybe_int64 none_int64;

void maybe_int64_print( struct maybe_int64 i );
struct maybe_int64 maybe_read_int64();
void print_int64(int64_t i)
*/

void interpret_push(struct vm_state* state) {
  stack_push(& state->data_stack, state->ip->as_arg64.arg);
}

void interpret_iread(struct vm_state* state ) {
    struct maybe_int64 tmp = maybe_read_int64();
    if(tmp.valid){
        stack_push(&(state -> data_stack), tmp.value);
    }
}
void interpret_iadd(struct vm_state* state ) {
    struct maybe_int64 tmp1 = stack_pop(&(state -> data_stack));
    struct maybe_int64 tmp2 = stack_pop(&(state -> data_stack));
    if(tmp1.valid && tmp2.valid){
        stack_push(&(state -> data_stack), tmp1.value + tmp2.value);
    } 
}
void interpret_iprint(struct vm_state* state ) {
    struct maybe_int64 tmp = stack_pop(&(state -> data_stack));
    if(tmp.valid){
        print_int64(tmp.value);
    }
}

/* Подсказка: можно выполнять программу пока ip != NULL,
    тогда чтобы её остановить достаточно обнулить ip */
void interpret_stop(struct vm_state* state ) {
    state -> ip = NULL;
}


void (*interpreters[])(struct vm_state*)  = {
  [BC_PUSH] = interpret_push,
  [BC_IPRINT] = interpret_iprint,
  [BC_IREAD] = interpret_iread,
  [BC_IADD] = interpret_iadd,
  [BC_STOP] = interpret_stop
};

void interpret(struct vm_state* state) {
    while((state -> ip) != NULL){
        interpreters[state -> ip -> opcode](state);
        if((state -> ip) != NULL){
            state -> ip ++;
        }
    }
}
