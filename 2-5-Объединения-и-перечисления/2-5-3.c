struct heap_string {
  char* addr;
};

// скопировать в кучу
struct heap_string halloc( const char* s ){
    struct heap_string ans = (struct heap_string){NULL};
    ans.addr = malloc(sizeof(s)+sizeof("\0"));
    for(size_t i = 0; i < sizeof(s)+sizeof("\0"); i++){
        ans.addr[i] = s[i];
    }
    
    return ans;
}

// освободить память
void heap_string_free( struct heap_string h ){
    free(h.addr);
}
