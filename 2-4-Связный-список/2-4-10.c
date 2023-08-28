struct maybe_int64 maybe_read_int64() {
    int64_t value = 0;
    if((scanf("%" SCNd64, &value)) > 0){ 
        return some_int64(value);
    }
    return none_int64;
}
