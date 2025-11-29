#pragma once

typedef struct element {
    char value;
    struct element *next;
    struct element *prev;
} Element;

typedef struct list {
    Element *head;
    Element *current;
    int current_pos;
    int size;
} List;

List* start();
void add(List *l, char character);
void add_pos(List *l, char character, int position);
char get(List *l, int position);
void set(List *l, int position, char character);
char delete(List *l, int position);
int empty(List *l);
int size(List *l);
void print(List *l);
void destroy(List *l);
