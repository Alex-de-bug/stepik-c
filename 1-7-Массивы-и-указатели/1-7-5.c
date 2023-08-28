void array_reverse(int* array, int size) {
    int tmp = 0;
    for (int i = 0; i < size-1; ) {
        if(i > (size-1)/2){
            break;
        }
        tmp = array[i];
        array[i] = array[size-1 - i];
        array[size - 1 - i] = tmp;
        i++;
    }
}

void array_reverse_ptr(int* array, int* limit) {
    int test_mas[100] = { 0 };
    int* c = test_mas;
    for (int* current = limit-1; current >= array; current = current - 1) {
        *c = *current;
        c++;
        
      
    }
    c = test_mas;
    for (int* current = array; current < limit; current = current + 1) {
        *current = *c;
        c++;
    }
}
