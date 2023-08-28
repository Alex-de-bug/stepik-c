int is_square(int x){
    int i=0;
    if(x<0){
        return 0;
    }
    while(i<99999){
        if(i*i==x){
            return 1;
        }
        i++;
    }
    return 0;
}
