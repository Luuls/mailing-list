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

    while (option != QUIT) {
        puts("[1] Inserir item no começo da lista\n");
        puts("[2] Inserir item no fim da lista\n");
        puts("[3] Inserir item ordenadamente na lista\n");
        puts("[4] Ordenar lista\n");
        puts("[5] Ver a lista\n");
        puts("[6] Sair");
        scanf("%d", &option);

        if (option == LIST_PRINT) {
            list_print(list);
        }
        else {
            puts("\nInsira os dados da pessoa: ");
            puts("Nome: ");
            fgets(contact.name, MAX_NAME, stdin);
            contact.name[strlen(contact.name) - 1] = '\0';

            puts("Endereco: ");
            fgets(contact.address, MAX_ADDRESS, stdin);
            contact.address[strlen(contact.address) - 1] = '\0';

            puts("Cidade: ");
            fgets(contact.city, MAX_CITY, stdin);
            contact.city[strlen(contact.city) - 1] = '\0';

            puts("CEP: ");
            fgets(contact.zip, MAX_ZIP, stdin);
            contact.zip[strlen(contact.zip) - 1] = '\0';
        }

        switch (option) {
        case LIST_ADD_START:
            if (list_add_start(&list, contact)) {
                system("cls");
                fprintf(stderr, "Problema ao inserir pessoa na lista. Saindo.");
                return 1;
            }

            printf("%s adicionado(a) com sucesso!\n", contact.name);
            break;

        case LIST_ADD_END:
            if (list_add_end(&list, contact)) {
                system("cls");
                fprintf(stderr, "Problema ao inserir pessoa na lista. Saindo.");
                return 1;
            }

            printf("%s adicionado(a) com sucesso!\n", contact.name);
            break;

        case LIST_ADD_ORDENED_NAME:
            if (list_add_ordened_name(&list, contact)) {
                system("cls");
                fprintf(stderr, "Problema ao inserir pessoa na lista. Saindo.");
                return 1;
            }

            printf("%s adicionado(a) com sucesso!\n", contact.name);
            break;
        case LIST_SORT_NAME:
            if (list_sort_name(&list)) {
                puts("Lista organizada com sucesso.\n");
            }
            else {
                puts("Lista possui apenas uma pessoa ou está vazia");
            }
            break;
            
        default:
            break;
        }
    }

    return 0;
}