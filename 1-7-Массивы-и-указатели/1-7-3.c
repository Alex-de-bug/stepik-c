void normalize( int* pt ) {
   if(*pt == 0 ){
       return;
   }
   while(*pt%2==0){
       *pt = *pt/2;
   }
}
