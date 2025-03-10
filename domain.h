#ifndef DOMAIN_H_
#define DOMAIN_H_

typedef struct {
    char *name;
    int concentration;
    int quantity;
    int price;
} medicine;

typedef struct {
    medicine **arr;
    int size;
} medicine_arr;
#endif  // DOMAIN_H_
