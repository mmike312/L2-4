#include <stdio.h>
#include <stdlib.h>
#include "domain.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include <unistd.h>
#include "tests.h"

void start() {
    VectorDinamic *r_c = creeaza_vector_dinamic();
    run(r_c);
}

int main() {
    run_all_tests();
    //start();
}

