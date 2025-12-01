#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

List* start() {
    List *l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->current = NULL;
    l->current_pos = 0;
    l->size = 0;
    return l;
}

int empty(List *l) {
    return l->size == 0;
}

void add(List *l, char character) {

    Element *e = malloc(sizeof(Element));
    e->value = character;
    e->prev = NULL;

    if (empty(l)) {
        e->next = NULL;
        l->head = e;
    } else {
        Element *oldHead = l->head;
        l->head = e;
        e->next = oldHead;
        oldHead->prev = e;
    }

    l->size++;
}

void add_pos(List *l, char character, int position) {

    if (empty(l)) {
        printf("List is empty!\n");
        return;
    }

    if (position <= 0 || position > l->size) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        add(l, character);
        return;
    }

    Element *e = malloc(sizeof(Element));
    e->value = character;

    Element *curr = l->head;
    Element *prev = NULL;

    for (int i = 1; i < position; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = e;
    e->prev = prev;

    e->next = curr;
    curr->prev = e;

    l->size++;
}

char get(List *l, int position) {

    if (empty(l)) {
        printf("List is empty!\n");
        return '\0';
    }

    if (position <= 0 || position > l->size) {
        printf("Invalid position!\n");
        return '\0';
    }

    if (l->current == NULL) {
        l->current = l->head;
        l->current_pos = 1;
    }

    if (position == l->current_pos) {
        return l->current->value;
    }

    Element *aux = l->current;
    int i = l->current_pos;

    if (position > l->current_pos) {
        while (aux != NULL) {
            if (i == position) {
                l->current = aux;
                l->current_pos = i;
                return aux->value;
            }
            aux = aux->next;
            i++;
        }
    }

    if (position < l->current_pos) {
        while (aux != NULL) {
            if (i == position) {
                l->current = aux;
                l->current_pos = i;
                return aux->value;
            }
            aux = aux->prev;
            i--;
        }
    }

    return '\0';
}

void set(List *l, int position, char character) {

    char found = get(l, position);

    if (found != '\0') {
        l->current->value = character;
    }
}

char delete(List *l, int position) {

    if (empty(l)) {
        printf("List is empty!\n");
        return '\0';
    }

    if (position <= 0 || position > l->size) {
        printf("Invalid position!\n");
        return '\0';
    }

    Element *curr = l->head;

    if (position == 1) {
        char c = curr->value;
        l->head = curr->next;

        if (l->head != NULL)
            l->head->prev = NULL;

        free(curr);
        l->size--;

        l->current = NULL;
        l->current_pos = 0;

        return c;
    }

    Element *prev = NULL;

    for (int i = 1; i < position; i++) {
        prev = curr;
        curr = curr->next;
    }

    char c = curr->value;

    prev->next = curr->next;

    if (curr->next != NULL)
        curr->next->prev = prev;

    free(curr);

    l->size--;
    l->current = NULL;
    l->current_pos = 0;

    return c;
}

int size(List *l) {
    return l->size;
}

void print(List *l) {
    if (empty(l)) {
        printf("List is empty!\n");
        return;
    }

    Element *e = l->head;

    printf("List (size %d):\n", l->size);

    while (e != NULL) {
        printf("%c <-> ", e->value);
        e = e->next;
    }

    printf("NULL\n");
}

void destroy(List *l) {
    if (l == NULL) return;

    Element *curr = l->head;
    Element *next;

    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(l);
}
