#include <stdio.h>
#include <stdlib.h>

typedef struct midde
{
    int data;
    struct midde *next;
} Midde;

void input(Midde **head, int data)
{
    Midde *midde = (Midde *)malloc(sizeof(Midde));
    midde->data = data;
    midde->next = NULL;
    if (*head == NULL)
    {
        (*head) = midde;
        return;
    }
    Midde *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = midde;
}

void display(Midde *head)
{
    Midde *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void freeList(Midde *head)
{
    Midde *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int number_of_elements;
    scanf("%d", &number_of_elements);
    Midde *head = NULL;
    for (int i = 0; i < number_of_elements; i++)
    {
        int data;
        scanf("%d", &data);
        input(&head, data);
    }
    display(head);
    freeList(head);
    return 0;
}
