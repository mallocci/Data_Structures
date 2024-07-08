#define add(ch, head, data) \
    do { \
        if ((ch) == S_LIST) { \
            add_s((list_s_t **)&head, (data)); \
        } else if ((ch) == D_LIST) { \
            add_d((list_d_t **)&head, (data)); \
        } else { \
            printf("\nType Error!\n"); \
        } \
    } while (0)

#define print(ch, head) \
    do { \
        if ((ch) == S_LIST) { \
            print_s((head)); \
        } else if ((ch) == D_LIST) { \
            print_d((head)); \
        } else { \
            printf("\nType Error!\n"); \
        } \
    } while (0)

#define free_all(ch, head) \
    do { \
        if ((ch) == S_LIST) { \
            free_all_s((head)); \
        } else if ((ch) == D_LIST) { \
            free_all_d((head)); \
        } else { \
            printf("\nType Error!\n"); \
        } \
    } while (0)

typedef struct list_s
{
    int data;
    struct list_s * next;
} list_s_t;

typedef struct list_d
{
    int data;
    struct list_d * prev;
    struct list_d * next;
} list_d_t;

void add_s(list_s_t ** head, int item);
void print_s(list_s_t * head);
void free_all_s(list_s_t * head);

void add_d(list_d_t ** head, int item);
void print_d(list_d_t * head);
void free_all_d(list_d_t * head);

