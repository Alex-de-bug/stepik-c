size_t count_zeroes( const void* data, size_t sz ) 
{
    size_t count = 0;
    const int8_t* ptr;
    ptr = data;
    
    for(size_t i = 0; i < sz; i++)
    {
        if(*(ptr + i) == 0)
            count++;
    }
    
    return count;
}
