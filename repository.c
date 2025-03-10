#include <stdlib.h>

#include <cstdlib>

#include "domain.h"
#include "repository.h"
#include "service.h"

medicine_arr *create_repo() {
    medicine_arr *arr = malloc(sizeof(medicine_arr));
    arr->arr = malloc(sizeof(medicine *) * 100);
    return arr;
}

void add_medicine(medicine_arr *arr, medicine *e) {
    medicine **med_arr = arr->arr;
    int arr_sz = arr->size;
    // handle resize if too small
    if (arr_sz % 100 == 99) {
        medicine **new_arr = realloc(med_arr, arr_sz + 101);
        if (new_arr == NULL) return;
        arr->arr = new_arr;
    }

    for (int i = 0; i < arr_sz; i++)
        if (med_same(med_arr[i], e)) {
            med_arr[i]->quantity += e->quantity;
            med_arr[i]->price = e->price;
            return;
        }

    med_arr[arr_sz] = e;
    arr->size++;
}

void modify_medicine(medicine_arr *arr, medicine *new_values) {
    medicine **med_arr = arr->arr;
    int med_sz = arr->size;
    for (int i = 0; i < med_sz; i++)
        if (med_same(med_arr[i], new_values)) {
            med_arr[i] = new_values;
            return;
        }
}

void remove_medicine(medicine_arr *arr, medicine *identifier) {
    medicine **med_arr = arr->arr;
    int med_sz = arr->size;
    for (int i = 0; i < med_sz; i++)
        if (med_same(med_arr[i], identifier)) {
            med_rm(identifier);
            return;
        }
}
