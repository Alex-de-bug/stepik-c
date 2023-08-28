// вы можете реализовать эти функции для более удобного считывания чисел
int64_t read_int64();
size_t read_size();

// заполнить уже выделенный массив array размера size числами
// числа нужно считывать из потока ввода
void array_int_fill( int64_t* array, size_t size ) {
    for(int64_t i = 0; i < size; i++ ){
        scanf("%" SCNd64, &array[i]);
    }
}

// Считать размер массива в *size, выделить память под массив и заполнить его числами, вызвав array_int_fill
int64_t* array_int_read( size_t* size ) {
    scanf("%zu" , size);
    int64_t* massive = malloc(sizeof( int64_t ) * (*size));
    if(massive) array_int_fill(massive, *size);
    return massive;
}
