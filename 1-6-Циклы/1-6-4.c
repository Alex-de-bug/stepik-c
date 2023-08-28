int is_prime(int n){
    if(n<=1) return 0;
    int i = 2;
    while (i < n) {
        if (n % i == 0){ return 0 ;}
        i++;
    }
    return 1;
}
