// position -- адрес указателя на первый элемент E в массиве,
// для которого predicate(E) выполняется.
// Функция возвращает 0 если элемент не найден.
int array_contains(int* array, int* limit, int** position) {
   for(int* tmp = array; tmp <= limit; tmp++){
       if(predicate(*tmp)){
           *position = tmp;
           return 1;
       }
   }
   return 0;
}
