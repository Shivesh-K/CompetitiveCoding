#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// we want to store person type records in the linked list

struct person
{
    char name[50];
    int age;
};

struct node
{
    struct person per; // data part of node contains person record
    struct node *next; // self referential pointer
};

// Function to input a person data (name and age)

struct person getdata()
{
    struct person p;
    printf("\n Enter name:");
    scanf("%s", p.name);
    printf("\n Enter age:");
    scanf("%d", &p.age);
    return p;
}

// Functio  to create a new node and to add name and age to that node.

struct node *create_node(struct person p)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->per = p;
    temp->next = NULL;
    return temp;
}

//Function to insert a new node at beginning of the linked list.

struct node *insert_begin(struct node *head, struct person p)
{
    struct node *temp = create_node(p);
    if (head != NULL)
        temp->next = head;

    return temp;
}

//Function to insert a new node at end of the linked list.

struct node *insert_end(struct node *head, struct person p)
{
    struct node *cur = head;
    struct node *temp = create_node(p);
    if (head == NULL)
        head = temp;
    else
    {
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
    }
    return head;
}

// function to delete a record from the linked list based on name.

struct node *delete_name(struct node *head, char *n)
{
    struct node *cur, *prev;
    struct node *temp;
    if (head == NULL)
    {
        printf("\nThe list is empty...");
        return NULL;
    }
    else
    {
        cur = prev = head;
        if ((strcmp(head->per.name, n)) == 0)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            while (cur != NULL)
            {
                if ((strcmp(cur->per.name, n)) == 0)
                {
                    prev->next = cur->next;
                    free(cur);
                    break;
                }
                else
                {
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
        if (cur == NULL)
            printf("\n Such person with name: %s does not exist...", n);
        return head;
    }
}

// function to delete a record from the linked list based on age.

struct node *delete_age(struct node *head, int age)
{
    struct node *cur, *prev;
    struct node *temp;
    if (head == NULL)
    {
        printf("\nThe list is empty");
        return NULL;
    }
    else
    {
        cur = prev = head;

        if (head->per.age == age)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        else
            while (cur != NULL)
            {
                if (cur->per.age == age)
                {
                    prev->next = cur->next;
                    free(cur);
                    break;
                }
                else
                {
                    prev = cur;
                    cur = cur->next;
                }
            }
        if (cur == NULL)
            printf("\n Such person with age: %d does not exist...", age);
        return head;
    }
}

void display_list(struct node *head)
{
    printf("head-> ");
    while (head != NULL)
    {
        printf("%s|%d -> ", head->per.name, head->per.age);
        head = head->next;
    }
    printf("NULL\n");
}

void split_list(struct node *head)
{
    struct node *groups[4] = {NULL, NULL, NULL, NULL};

    int age;
    while (head)
    {
        age = head->per.age;
        if (age >= 0 && age <= 18)
            groups[0] = insert_begin(groups[0], head->per);
        else if (age >= 19 && age <= 44)
            groups[1] = insert_begin(groups[1], head->per);
        else if (age >= 45 && age <= 60)
            groups[2] = insert_begin(groups[2], head->per);
        else if (age >= 61)
            groups[3] = insert_begin(groups[3], head->per);

        head = head->next;
    }

    printf("\nAge 0 to 18\n");
    display_list(groups[0]);

    printf("\nAge 19 to 44\n");
    display_list(groups[1]);

    printf("\nAge 45 to 60\n");
    display_list(groups[2]);

    printf("\nAge 65+\n");
    display_list(groups[3]);
}

int instruction()
{
    int choice;

    printf("\nMain Menu");
    printf("\n1. Insert in beginning of a linked list");
    printf("\n2. Insert at end of  a linked list");
    printf("\n3. Delete a record from a linked list based on name:");
    printf("\n4. Delete a record from a linked list based on age:");
    printf("\n5. Display Linked list");
    printf("\n6. Split linked list");
    printf("\n7. Quit from Menu");
    printf("\n Enter your choice[1-6]:");
    scanf("%d", &choice);
    return choice;
}

void main()
{
    struct node *head = NULL;
    struct person p;
    char name[50];
    char *n;
    int choice, age;
    while (1)
    {
        choice = instruction();
        switch (choice)
        {
        case 1:
            printf("\n Enter person details:");
            p = getdata();
            head = insert_begin(head, p);
            break;

        case 2:
            printf("\n Enter person details:");
            p = getdata();
            head = insert_end(head, p);
            break;

        case 3:
            printf("\n Enter name of person:");
            scanf("%s", name);
            head = delete_name(head, name);
            if (head == NULL)
                printf("\n Such record does not exist:");
            break;

        case 4:
            printf("\n Enter age of person:");
            scanf("%d", &age);
            head = delete_age(head, age);
            if (head == NULL)
                printf("\n Such record does not exist:");
            break;

        case 5:
            display_list(head);
            break;

        case 6:
            split_list(head);
            break;

        case 7:
            printf("\n exit from the program menu...");
            exit(0);

        default:
            printf("\n Enter correct menu choice[1-6]:");
        }
    }
}
