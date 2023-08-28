// Вам доступны эти функции из прошлых заданий
size_t read_size();
void array_int_fill( int64_t* array, size_t size );
int64_t* array_int_read( size_t* size );


void marray_print(int64_t** marray, size_t* sizes, size_t rows) {
    for( size_t i = 0; i < rows; i = i + 1 ) {
        array_int_print( marray[i], sizes[i] );
        print_newline();
    }
}


int64_t** marray_read( size_t* rows, size_t** sizes ) {
    *rows = read_size();
    int64_t** marrays = (int64_t**)malloc(*rows * sizeof( int64_t ));
    //sizes = (size_t**)malloc(sizeof(size_t));
    *sizes = (size_t*)malloc(*rows * sizeof(size_t));
    //size_t size = 0;
    if(marrays && sizes){
        for( size_t i = 0; i < *rows; i++ ){
            //*(sizes[i]) = size;
            marrays[i] = array_int_read((*sizes)+i);
        }
    }

    return marrays;
}
