in:

int a = 10;
if (a > 5) { printf("1"); }
if (a > 8) { printf("2"); }
if (a > 3) { printf("3"); }

out:

123
//

in:
int a = 10;
if (a > 5) { printf("9"); }
else {
   if (a > 8) { printf("2"); }
   if (a > 3) { printf("3"); }
}

out:

9
//

in:
printf("%d", 990 > 33 * 31);

out:
0
//

true:

4>3
(44 > 99) || (99 > 44)
//

true:

(1 < 3) > 0
1 && 9
0 || 9
//

// Возвращает 1 если в числе одна цифра, иначе 0
int is_single_digit(int n) {
    if (n < 0) {
        return 0;
    }
    if (n > 9) {
            return 0;
    }

        return 1;

}

// Возвращает 1 если в числе ровно две цифры, иначе 0
int is_double_digit(int n) {
    if (n < 10) {
        return 0;
    }
    else {
        if (n > 99) {
            return 0;
        }
        else {

                return 1;

        }
    }
}

//

in:

int print( int i ) {
   printf("Hello!");
   return !i; // вернуть "не i":
              // если i равен нулю, то вернуть 1
              // а если i не ноль, вернуть 0
}

ans:

4 < 3 || print(42) || print(88)
4 > 3 && print(10)
print(0) && print(9)

//

int is_sorted3(int a, int b, int c) {

  if(a<b && b<c){
      return 1;
  }
  if(a>b && b>c){
      return -1;
  }
   return 0;

}

//

int max3(int a, int b, int c) {
 if (a>b){
     if(a>c){
         return a;
     }else{
         return c;
     }
 }else{
     if(b>c){
             return b;
         }else{
             return c;
         }
 }

}

//

void fizzbuzz(int x){
    if(x<=0){printf("no");}
    if(x>0 && x%3==0){
        if(x%5==0){
            printf("fizzbuzz");
        }else{ printf("fizz");}
    }else{
        if(x>0 && x%5==0){
            printf("buzz");
        }
    }
}

