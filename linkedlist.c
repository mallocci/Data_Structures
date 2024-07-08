#include<stdio.h>
#include<stdlib.h>

#include"datas.h"

void add(list_s_t ** head, int item)
{
    if (*head == NULL) {
        *head = (list_s_t *)malloc(sizeof(list_s_t));
        if (*head == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        (*head)->data = item;
        (*head)->next = NULL;
    } else {
        list_s_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (list_s_t *)malloc(sizeof(list_s_t));
        current->next->data = item;
        current->next->next = NULL;
    }
}

void print(list_s_t * head)
{
    list_s_t * current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void free_all(list_s_t * head)
{
    list_s_t * temp = head;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}