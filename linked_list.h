#include <stdbool.h>

#define MAX_NAME 40
#define MAX_ADDRESS 50
#define MAX_CITY 15
#define MAX_ZIP 10

typedef struct MailNode {
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char city[MAX_CITY];
    char zip[MAX_ZIP];
    struct MailNode* next;
} MailNode;

typedef MailNode* MAIL_LIST;    //usado para criar um ponteiro para o primeiro item da lista
typedef MailNode MAIL_CONTACT;  //usado para ler informações sobre o contato e passá-lo para funções de adição

/*****************************************************************************
 * adiciona item no começo da lista     *
 *                                                                          *
 * entrada: um ponteiro para uma lista e um contato     *
 *                                                                          *
 * saída: verdadeiro se adicionado com sucesso ou falso caso contrário      *
 *****************************************************************************/
bool list_add_start(MAIL_LIST* head, MAIL_CONTACT contact);

/*****************************************************************************
 * adiciona item no fim da lista     *
 *                                                                          *
 * entrada: um ponteiro para uma lista e um contato     *
 *                                                                          *
 * saída: verdadeiro se adicionado com sucesso ou falso caso contrário      *
 *****************************************************************************/
bool list_add_end(MAIL_LIST* head, MAIL_CONTACT contact);

/*****************************************************************************
 * adiciona item em ordem alfabética na lista     *
 *                                                                          *
 * entrada: um ponteiro para uma lista e um contato     *
 *                                                                          *
 * saída: verdadeiro se adicionado com sucesso ou falso caso contrário      *
 *****************************************************************************/
bool list_add_ordened_name(MAIL_LIST* head, MAIL_CONTACT contact);

/*****************************************************************************
 * ordena a lista em ordem alfabética     *
 *                                                                          *
 * entrada: um ponteiro para uma lista     *
 *                                                                          *
 * saída: retorna falso caso a lista esteja vazia ou tenha apenas um item      *
 *****************************************************************************/
bool list_sort_name(MAIL_LIST *head);

/*****************************************************************************
 * imprime todos os items na tela     *
 *                                                                          *
 * entrada: uma lista     *
 *                                                                          *
 * saída: nada      *
 *****************************************************************************/
void list_print(MAIL_LIST head);