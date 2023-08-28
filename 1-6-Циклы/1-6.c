int read_int() {
    int res = 0; 
    scanf("%d", &res);
    return res; 
}

int main() {
    /* - прочитайте одно число i с помощью read_int
       - используя цикл while выведите числа от i до 10 включительно;
         после каждого числа должен стоять один пробел
       - если i > 10, выведите одно слово "No"
    */
    int x = read_int();
    if(x>10){
        printf("No");
    }
    while(x<11){
        printf("%d ", x);
        x++;
    }
    


    return 0;
}
