#include<stdio.h>
#include<stdlib.h>

#include"datas.h"

void add_d(list_d_t ** head, int item)
{
    if (*head == NULL) {
        *head = (list_d_t *)malloc(sizeof(list_d_t));
        if (*head == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        (*head)->data = item;
        (*head)->prev = (*head);
        (*head)->next = (*head);
    } else {
        list_d_t *current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = (list_d_t *)malloc(sizeof(list_d_t));
        current->next->data = item;
        current->next->prev = current;
        current->next->next = (*head);
        (*head)->prev = current->next;
    }
}

void print_d(list_d_t * head)
{
    list_d_t * current = head;
    do {
        printf("%d\n", current->data);
        current = current->next;
    } while (current != head);
}

void free_all_d(list_d_t * head)
{
    list_d_t * current = head;
    list_d_t * temp;
    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}