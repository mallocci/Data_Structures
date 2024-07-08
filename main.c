#include<stdio.h>
#include<stdlib.h>

#include"datas.h"

enum {
    S_LIST = 's',
    D_LIST = 'd'
};

enum {
    ADD,
    PRINT,
    EXIT
};

int main()
{
    void * head = NULL;
    char ch;
    printf("Choose list type: ");
    scanf(" %c", &ch);
    if (ch != S_LIST && ch != D_LIST) {
        printf("\nType Error!\n");
        return 1;
    }

    for (;;) {
        int value;
        scanf("%d", &value);
        switch (value)
        {
        case ADD:
            printf("\nEnter data to add: ");
            int data;
            scanf("%d", &data);
            add(ch, head, data);
            break;
        case PRINT:
            printf("\nPrint data:\n");
            print(ch, head);
            break;
        case EXIT:
            printf("\nExit!\n");
            free_all(ch, head);
            printf("Free memory!\n");
            return 0;
        default:
            break;
        }
    }

    return 0;
}