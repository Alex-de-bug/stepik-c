a = 20 b = 20

//

a = 10 b = 10

//

int a = 10;
int b = 20;
int c = 20;

void main() {
   c = a + b;
   b = a;
   a = b + c;
   printf("a = %d b = %d c = %d", a, b, c);
}

debug: a = 40 b = 10 c = 30

//

int main() {
  int input1 = read_int(); // читаем первое число
  int input2 = read_int(); // читаем второе число

  printf("%d", input1 + input2); // печатаем сумму

  return 0;
}

//

int discriminant(int a, int b, int c) {
    int D = b*b-4*a*c;
    return D ;
}

int root_count( int x ) {
   int D = x;
   if (D > 0){
       return 2;
   }
   if(D == 0){
       return 1;
   }
   return 0;
}

int main() {
    // Считайте три числа в локальные переменные (см. предыдущий шаг)
    int a=0;
    int b=0;
    int c=0;
    a = read_int();
    b = read_int();
    c = read_int();
    int discr = discriminant( a, b, c);


    // выведите результат запуска root_count с аргументами a, b и c.
    printf("%d", root_count(discr));

    return 0;
}
