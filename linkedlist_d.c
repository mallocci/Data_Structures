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
        (*head)->prev = NULL;
        (*head)->next = NULL;
    } else {
        list_d_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (list_d_t *)malloc(sizeof(list_d_t));
        current->next->data = item;
        current->next->prev = current;
        current->next->next = NULL;
    }
}

void print_d(list_d_t * head)
{
    list_d_t * current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void free_all_d(list_d_t * head)
{
    list_d_t * temp = head;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}