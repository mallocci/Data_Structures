#include<stdio.h>
#include<stdlib.h>

#include"datas.h"

void add_s(list_s_t ** head, int item)
{
    if (*head == NULL) {
        *head = (list_s_t *)malloc(sizeof(list_s_t));
        if (*head == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        (*head)->data = item;
        (*head)->next = (*head);
    } else {
        list_s_t *current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = (list_s_t *)malloc(sizeof(list_s_t));
        current->next->data = item;
        current->next->next = (*head);
    }
}

void print_s(list_s_t * head)
{
    list_s_t * current = head;
    do {
        printf("%d\n", current->data);
        current = current->next;
    } while (current != head);
}

void free_all_s(list_s_t * head)
{
    list_s_t * current = head;
    list_s_t * temp;
    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}