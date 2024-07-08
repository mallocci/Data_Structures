typedef struct list
{
    int data;
    struct list * next;
} list_s_t;

void add(list_s_t ** head, int item);
void print(list_s_t * head);
void free_all(list_s_t * head);
