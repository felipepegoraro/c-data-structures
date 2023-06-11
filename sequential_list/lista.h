#ifndef LISTA_SEQUENCIAL
#define LISTA_SEQUENCIAL

#include <stdbool.h>

#define MIN_SIZE 5
#define NOT_FOUND -1

typedef struct list {
  int size;
  int length;
  int *items;
} List;

List *list_create(void);
void list_free(List *);
bool list_is_empty(List *);
bool list_is_full(List *);
void list_display(List *);
void list_add(List *, int);
bool list_set(List *, int, int);
bool list_insert(List *, int, int);
int  list_remove(List *, int);
void list_resize(List *, float);

#endif // !LISTA_SEQUENCIAL
