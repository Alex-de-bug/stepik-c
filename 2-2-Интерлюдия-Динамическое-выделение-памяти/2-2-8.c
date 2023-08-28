// Вам доступны следующие функции:
size_t read_size();
int64_t* array_int_min( int64_t* array, size_t size );
void marray_free( int64_t** marray, size_t rows );
void marray_print(int64_t** marray, size_t* sizes, size_t rows);





void array_int_fills( int64_t* array, size_t size ) {
    for(int64_t i = 0; i < size; i++ ){
        scanf("%" SCNd64, &array[i]);
    }
}

int64_t* array_int_reads( size_t* size ) {
    scanf("%zu" , size);
    int64_t* massive = malloc(sizeof( int64_t ) * (*size));
    array_int_fills(massive ,*size);
    return massive;
}

int64_t** marray_reads( size_t* rows, size_t** sizes ) {
    scanf("%zu", rows);
    int64_t** marrays = (int64_t**)malloc(*rows * sizeof( int64_t ));
    *sizes = (size_t*)malloc(*rows * sizeof(size_t));
    if(marrays && sizes){
        for( size_t i = 0; i < *rows; i++ ){
            marrays[i] = array_int_reads((*sizes)+i);
        }
    }

    return marrays;
}




// Указатель на минимальное из двух чисел.
// если хотя бы одно число NULL, то возвращать второе
// если оба числа NULL результат NULL
int64_t* int64_ptr_min(int64_t* x, int64_t* y) {
    if(!*x){
        if(!*y){
            return NULL;
        }else{
            return y;
        }
    }else{
        if(!*y){
            return NULL;
        }else{
            if(*y<*x){
                return y;
            }
            if(*x<*y){
                return x;
            }
            return x;
        }
    }
}

// Вернуть адрес минимального элемента массива массивов
int64_t* marray_int_min( int64_t** marray, size_t* sizes, size_t rows ) {
    int64_t* ans = *marray;
    for( size_t i = 0; i < rows; i++ ) {
        if(sizes[i] != 0) {
            for (size_t j = 0; j < sizes[i]; j++) {
                int64_t* tmp = int64_ptr_min(ans, *(marray + i) + j);
                if(tmp){
                    ans = tmp;
                }
            }
        }
    }
    return ans;
}



// Вычесть m изо всех элементов массива
void marray_normalize( int64_t** marray, size_t* sizes, size_t rows, int64_t m ) {
    for( size_t i = 0; i < rows; i++ ) {
        for(size_t j = 0; j<sizes[i]; j++){
            if(marray[i][j]!=0){
                marray[i][j]-=m;
            }
        }
    }
    marray_print(marray, sizes, rows);
}

// Прочитать, найти минимум и нормализовать массив, вывести результат
void perform() {
    size_t* rows = (size_t*) malloc(sizeof(size_t));
    size_t** sizes = (size_t**) malloc(sizeof(size_t));
    int64_t** main_marray = marray_reads(rows, sizes);
    int64_t* minim = marray_int_min(main_marray, *sizes, *rows);
    marray_normalize(main_marray, *sizes, *rows, *minim);
    marray_free( main_marray, *rows );
    free(*sizes);
    free(sizes);
    free(rows);
    //free(minim);
}
