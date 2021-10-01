#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

static void set_new_contact(MailNode *new_contact, MAIL_CONTACT contact) {
    strcpy(new_contact->name, contact.name);
    strcpy(new_contact->address, contact.address);
    strcpy(new_contact->city, contact.city);
    strcpy(new_contact->zip, contact.zip);
}

bool list_add_start(MAIL_LIST *head, MAIL_CONTACT contact) {
    MailNode *new_node = (MailNode *)malloc(sizeof(MailNode));
    if (new_node == NULL) {
        return false;
    }

    new_node->next = *head;
    *head = new_node;

    set_new_contact(new_node, contact);

    return true;
}

bool list_add_end(MAIL_LIST *head, MAIL_CONTACT contact) {
    if (*head == NULL) {
        if (list_add_start(head, contact)) {
            return true;
        }
        else {
            return false;
        }
    }

    MailNode *curr_node = *head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }

    MailNode *new_node = (MailNode *)malloc(sizeof(MailNode));
    curr_node->next = new_node;
    new_node->next = NULL;

    set_new_contact(new_node, contact);
    return true;
}

bool list_add_ordened_name(MAIL_LIST *head, MAIL_CONTACT contact) {
    MailNode *before = NULL;
    MailNode *after = *head;

    while (after != NULL && strcmp(contact.name, after->name) > 0) {
        before = after;
        after = after->next;
    } //runs through the list and find the insert point

    MailNode *new_node = (MailNode *)malloc(sizeof(MailNode));
    if (new_node == NULL) {
        return false;
    } //error checking

    if (before == NULL) {
        if (list_add_start(head, contact)) {
            return true;
        }
        else {
            return false;
        }
    } //inserts at start if the list is empty or has one element that is higher than the input

    //else, inserts in the middle or end;
    new_node->next = before->next;
    before->next = new_node;

    set_new_contact(new_node, contact);
    return true;
}

bool list_sort_name(MAIL_LIST *head) {
    if (*head == NULL || (*head)->next == NULL) {
        return false;
    }

    MailNode *list_end = NULL;
    MailNode *curr_node = *head;
    MailNode *next_node = curr_node->next->next;

    while (list_end != *head) {
        if (curr_node == *head) {
            //ORDENA ESSA MERDA vambora vamo
        }
        while (strcmp(next_node->name, curr_node->name) > 0)
    }
}

void list_print(MAIL_LIST head) {
    int i = 1;
    for (MailNode *curr_node = head;
        curr_node != NULL;
        curr_node = curr_node->next, i++) {
        printf("\nPessoa %d: \n", i);
        printf("Nome: %s\n", curr_node->name);
        printf("Endereco: %s\n", curr_node->address);
        printf("Cidade: %s\n", curr_node->city);
        printf("CEP: %s\n", curr_node->zip);
    }
}