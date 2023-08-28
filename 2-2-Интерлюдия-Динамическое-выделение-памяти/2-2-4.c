int64_t* array_int_min( int64_t* array, size_t size ) {
    int64_t* ans = array;
    for(int64_t i = 0; i < size; i++){
        if(array[i]<*ans){
            ans = array + i;
        }
    }
    
    return ans;
}
