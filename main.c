#include<stdio.h>
#include<stdlib.h>

#include"datas.h"

int main()
{
    list_s_t * head = NULL;

    for (;;) {
        int value = 0;
        scanf("%d", &value);
        switch (value)
        {
        case 1:
            printf("\nEnter data to add: ");
            int data;
            scanf("%d", &data);
            add(&head, data);
            break;
        case 2:
            printf("\nPrint data:\n");
            print(head);
            break;
        case 3:
            printf("\nExit!\n");
            free_all(head);
            printf("Free memory!\n");
            return 0;
        default:
            break;
        }
    }

    return 0;
}