void array_fib(int* array, int* limit) {
    if(limit == array ){
        return;
    }
    if(limit - array == 1){
        *array = 1;
        return;
    }
    *array = 1;
    array++;
    *array = 1;
    array++;
    for (int* current = array; current < limit; current = current + 1) {
        *current = *(current-1) + *(current-2);
    }
}
