int is_whitespace(char c) { return c == ' ' || c == '\t' || c == '\n'; }

int string_count(char* str) { 
   int counter = 0;
   int tmp = 0;
   while(str[tmp]!=0){
       counter++;
       tmp++;
   }
   return counter;
}

int string_words(char* str)  {
    int counter = 0;
    int tmp = 0;
    while(str[tmp]!=0){
       if(( tmp!=0 && is_whitespace(str[tmp]) && !is_whitespace(str[tmp-1]))){
       counter++;}
       tmp++;
   }
    if(tmp!=0 && str[tmp]==0 && str[tmp-1]!=32){
        counter++;
    }
    return counter;
}
