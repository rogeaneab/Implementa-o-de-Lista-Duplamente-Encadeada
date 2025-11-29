#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

    List *l = start();

    add(l, '@');
    add(l, '#');
    add(l, '$');
    add(l, '%');

    print(l);

    set(l, 4, '*');
    print(l);

    printf("Elemento na posição 3: %c\n", get(l, 3));

    printf("Removendo posição 2: %c\n", delete(l, 2));
    print(l);

    destroy(l);

    return 0;
}
