// Мы хотим, чтобы в структуре user хранились ссылки только на строчки из кучи.
typedef struct { char* addr; } string_heap ;

/*  Тип для идентификаторов пользователей
    и его спецификаторы ввода и вывода для printf */
typedef uint64_t uid;
#define PRI_uid PRIu64
#define SCN_uid SCNu64

enum city {C_SARATOV, C_MOSCOW, C_PARIS, C_LOS_ANGELES, C_OTHER};

/*  Массив, где элементам перечисления сопоставляются их текстовые представления */
const char* city_string[] = {
  [C_SARATOV] = "Saratov",
  [C_MOSCOW] = "Moscow",
  [C_PARIS] = "Paris",
  [C_LOS_ANGELES] = "Los Angeles",
  [C_OTHER] = "Other"
};


struct user {
  const uid id;
  const string_heap name;
  enum city city;
};

/* Сортировать массив пользователей по полю uid по возрастанию */
int int64_comparer_for_uid( const struct user* x, const struct user* y ) {
  if (x -> id > y -> id) return 1;
  if (x -> id < y -> id) return -1;
  return 0;
}
int int64_void_comparer_for_uid(const void* x, const void* y ) {
  return int64_comparer_for_uid(x, y);
}
void users_sort_uid(struct user users[], size_t sz) {
  qsort( users, sz,  sizeof(struct user), int64_void_comparer_for_uid );
}



/* Сортировать массив пользователей по полю name */
/* Порядок строк лексикографический; можно использовать компаратор 
   строк -- стандартную функцию strcmp */
int int64_comparer_for_name( const struct user* x, const struct user* y ) {
  return strcmp((x->name).addr, (y->name).addr);
}
int int64_void_comparer_for_name(const void* x, const void* y ) {
  return int64_comparer_for_name(x, y);
}

void users_sort_name(struct user users[], size_t sz) {
  qsort( users, sz,  sizeof(struct user), int64_void_comparer_for_name );
}





/* Сортировать массив по _текстовому представлению_ города */

int int64_comparer_for_country( const struct user* x, const struct user* y ) {
  return strcmp(city_string[(x->city)], city_string[(y->city)]);
}
int int64_void_comparer_for_country(const void* x, const void* y ) {
  return int64_comparer_for_country(x, y);
}
void users_sort_city(struct user users[], size_t sz) {
  qsort( users, sz,  sizeof(struct user), int64_void_comparer_for_country );
}
