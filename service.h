#ifndef SERVICE_H_
#define SERVICE_H_
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "domain.h"

medicine *create_medicine(char *name, int concentration, int qty, int price);

bool med_same(medicine *a, medicine *b);

void med_rm(medicine *e);

#endif  // SERVICE_H_
