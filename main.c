#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "linked_list.h"

int main() {
    puts("Bem vindo(a) a lista de enderecamento!\n\n");

    int option = -1;
    MAIL_LIST list = NULL;
    MAIL_CONTACT contact;

    while (1) {
        puts("[1] Inserir item no comeco da lista");
        puts("[2] Inserir item no fim da lista");
        puts("[3] Inserir item ordenadamente na lista");
        puts("[4] Ordenar lista");
        puts("[5] Ver a lista6");
        puts("[6] Sair");
        scanf("%d", &option);
        fflush(stdin);
        if (option == QUIT) {
            return 0;
        }

        if (option == LIST_PRINT) {
            list_print(list);
        }
        else if (option == LIST_SORT_NAME) {
            if (list_sort_name(&list)) {
                puts("Lista organizada com sucesso.\n");
            }
            else {
                puts("Lista possui apenas uma pessoa ou esta vazia");
            }
        }
        else {
            puts("\nInsira os dados da pessoa: ");
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
        }

        switch (option) {
        case LIST_ADD_START:
            if (list_add_start(&list, contact)) {
                printf("%s adicionado(a) com sucesso!\n", contact.name);
                break;
            }
            else {
                system("cls");
                fprintf(stderr, "Problema ao inserir pessoa na lista. Saindo.");
                return 1;
            }

        case LIST_ADD_END:
            if (list_add_end(&list, contact)) {
                printf("%s adicionado(a) com sucesso!\n", contact.name);
                break;
            }
            else {
                system("cls");
                fprintf(stderr, "Problema ao inserir pessoa na lista. Saindo.");
                return 1;
            }

        case LIST_ADD_ORDENED_NAME:
            if (list_add_ordened_name(&list, contact)) {
                printf("%s adicionado(a) com sucesso!\n", contact.name);
                break;
            }
            else {
                system("cls");
                fprintf(stderr, "Problema ao inserir pessoa na lista. Saindo.");
                return 1;
            }
            
        default:
            break;
        }
    }

    return 0;
}