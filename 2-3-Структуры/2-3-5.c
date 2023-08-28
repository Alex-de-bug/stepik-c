/* Вы можете пользоваться этими функциями из предыдущих заданий */

//struct maybe_int64 some_int64(int64_t i) {
//  return (struct maybe_int64) { i, true };
//}

//const struct maybe_int64 none_int64 = { 0 };



//чтение размера
size_t read_size() { size_t i; scanf("%zu", &i); return i; }


//вставка массива
void array_int_fill( int64_t* array, size_t sz );


//чтение массива
struct array_int array_int_read();

//взятие элемента
struct maybe_int64 array_int_get( struct array_int a, size_t i );

//вставка в элемент массива
bool array_int_set( struct array_int a, size_t i, int64_t value );

//написать массив
void array_int_print( struct array_int array );

//минимум в массиве
struct maybe_int64 array_int_min( struct array_int array );

//освобождение массива
void array_int_free( struct array_int a );

//вычесть число из массива
void array_int_normalize( struct array_int array, int64_t m ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    array.data[i] = array.data[i] - m;
  }
}

/*  ---- maybe int[] ---- */

struct maybe_array_int {
  struct array_int value;
  bool valid;
};

//создание массива с подтверждением
struct maybe_array_int some_array_int(struct array_int array) {
  return (struct maybe_array_int) { array, true };
}

//ошибочный массив
const struct maybe_array_int none_array_int = { {NULL, 0}, false };


/*  ---- int[][] ---- */
struct array_array_int {
  struct array_int* data;
  size_t size;
};

/*  --- строки ---  */

//взятие подмассива из массива массивов
struct maybe_array_int array_array_int_get_row( struct array_array_int a, size_t i ) {
  if ( 0 <= i && i < a.size ) { return some_array_int( a.data[i] ); }
  else { return none_array_int; }
}

//установка подмассива в массив
bool array_array_int_set_row( struct array_array_int a, size_t i, struct array_int value ) {
  if (0 <= i && i < a.size) {
    a.data[i] = value;
    return true;
  }
  else { return false; }
}

/*  --- get/set ---  */

//взятие элемента get[i][j]
struct maybe_int64 array_array_int_get( struct array_array_int a, size_t i, size_t j ) {
    return array_int_get(array_array_int_get_row( a, i ).value, j);
}

//вставка элемента set[i][j]
bool array_array_int_set( struct array_array_int a, size_t i, size_t j, int64_t value ) {
    for (size_t k = 0; k < a.size; k++) {
        if(i == k){
            array_int_set(array_array_int_get_row( a, i ).value, j, value);
            return true;
        }
    }
    return false;
}

/*  --- read/print ---  */

//чтение массива массивов
struct array_array_int array_array_int_read() {
    size_t rows;
    rows = read_size();
    struct array_int* arrays = malloc( sizeof(struct array_int) * rows);
    struct array_array_int marray = {.data = arrays, .size = rows};
    for(size_t i = 0; i<rows; i++){
        struct array_int arr = array_int_read();
        marray.data[i] = arr;
    }
    return marray;
}

//печать массива массивов
void array_array_int_print( struct array_array_int array) {
    for (size_t i = 0; i < array.size; i ++) {
        const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
        for(size_t j = 0; j < cur_row.value.size; j++){
            if(array_array_int_get( array, i, j ).valid){
                printf("%" PRId64 " " , array_array_int_get( array, i, j ).value);
            }
        }
        printf("\n");
    }
    
    /*for (size_t i = 0; i < array.size; i ++) {
        const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
        if (cur_row.valid) {
            for(size_t i = 0; j < cur_row.value.size; j++){
                printf("%" PRId64 " " , array_int_get( cur_row.value.size.data, j).value)
            }
            printf("\n");
        }
    }*/
}


/*  --- min/normalize ---  */

// найти минимальный элемент в массиве массивов
struct maybe_int64 array_array_int_min( struct array_array_int array ) {
    struct maybe_int64 minim = none_int64;
    for (size_t i = 0; i < array.size; i ++) {
        const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
        struct maybe_int64 tmp = array_int_min( cur_row.value );
        if(tmp.valid){
            if(i==0){
                minim = tmp;
            }
            if((minim.value) >= (tmp.value)){
                minim = tmp;
            }
        }
        
    }
    //////////
    //printf("%" PRId64 " ", minim.value);
    //printf("\n");
    return minim;
}

// вычесть из всех элементов массива массивов число m
void array_array_int_normalize( struct array_array_int array, int64_t m) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
    if (cur_row.valid) {
         array_int_normalize( cur_row.value, m );
    }
  }
}

//освобождение памяти
void array_array_int_free( struct array_array_int array ) {
    for (size_t i = 0; i < array.size; i ++) {
        struct maybe_array_int cur_row = array_array_int_get_row( array, i );
        array_int_free( cur_row.value );
    }
    if ( array.size > 0 ) {
        free(array.data); 
        array.size = 0;
    }
  
}
