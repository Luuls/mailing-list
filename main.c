#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    MAIL_LIST list = NULL;
    MAIL_CONTACT contact;

    for (int i = 0; i < 3; i++) {
        printf("\nInsira os dados da pessoa %d: \n", i + 1);
        printf("Nome: ");
        fgets(contact.name, MAX_NAME, stdin);
        contact.name[strlen(contact.name) - 1] = '\0';
        fflush(stdin);

        printf("Endereco: ");
        fgets(contact.address, MAX_ADDRESS, stdin);
        contact.address[strlen(contact.address) - 1] = '\0';
        fflush(stdin);

        printf("Cidade: ");
        fgets(contact.city, MAX_CITY, stdin);
        contact.city[strlen(contact.city) - 1] = '\0';
        fflush(stdin);

        printf("CEP: ");
        fgets(contact.zip, MAX_ZIP, stdin);
        contact.zip[strlen(contact.zip) - 1] = '\0';
        fflush(stdin);

        if (!list_add_ordened_name(&list, contact)) {
            fprintf(stderr, "Erro ao inserir pessoa. Saindo.");
            return 1;
        }
    }

    system("cls");
    list_print(list);

    return 0;
}