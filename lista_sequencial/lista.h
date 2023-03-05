#ifndef LISTA_SEQUENCIAL
#define LISTA_SEQUENCIAL

#include <stdbool.h>

typedef struct list List;

List *list_create(void);
void list_free(List *);
bool list_is_empty(List *);
bool list_is_full(List *);
void list_display(List *);
void list_add(List *, int);
bool list_set(List *, int, int);
bool list_insert(List *, int, int);
bool list_remove(List*, int);
void list_resize(List *);

#endif // !LISTA_SEQUENCIAL
