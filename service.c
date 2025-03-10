#include <stdlib.h>

#include "domain.h"
#include "service.h"

medicine *create_medicine(char *name, int concentration, int qty, int price) {
    medicine *a = malloc(sizeof(medicine));
    a->name = name;
    a->concentration = concentration;
    a->quantity = qty;
    a->price = price;
    return a;
}

bool med_same(medicine *a, medicine *b) {
    return strcmp(a->name, b->name) == 0 &&
           a->concentration == b->concentration;
}

void med_rm(medicine *e) {
    free(e->name);
    free(e);
}
