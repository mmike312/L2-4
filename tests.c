//
// Created by Mihai Moldovan on 19.03.2024.
//
#include "tests.h"
#include <assert.h>
#include <string.h>
#include "validation.h"

void test_validation() {
    int err = valideaza_materie_prima("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                                      -1);
    assert(err == -1);
    err = valideaza_denumire_materie_prima("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    assert(err == -1);
    err = valideaza_producator("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    assert(err == -1);
    err = valideaza_cantitate(-1);
    assert(err == -1);
    int ok = valideaza_producator("aaaaaaaaaaa");
    assert(ok == 1);
    ok = valideaza_cantitate(1);
    assert(ok == 1);
}

void test_domain() {
    struct MateriePrima *a = creeaza_materie_prima("a", "b", 1);
    char denumire_got[31];
    get_denumire(a, denumire_got);
    assert(strcmp(denumire_got, "a") == 0);
    get_producator(a, denumire_got);
    assert(strcmp(denumire_got, "b") == 0);
    int cantitate_got;
    get_cantitate(a, &cantitate_got);
    assert(cantitate_got == 1);

}

void test_repo() {
    VectorDinamic *repo = creeaza_vector_dinamic();
    struct MateriePrima *a, *b, *c, *d, *e, *f;
    a = creeaza_materie_prima("a", "a", 1);
    b = creeaza_materie_prima("b", "a", 1);
    c = creeaza_materie_prima("c", "a", 1);
    d = creeaza_materie_prima("d", "a", 1);
    e = creeaza_materie_prima("e", "a", 1);
    f = creeaza_materie_prima("f", "a", 1);

    adaugare_element(repo, a);
    adaugare_element(repo, a);
    adaugare_element(repo, b);
    adaugare_element(repo, c);
    adaugare_element(repo, d);
    adaugare_element(repo, e);
    adaugare_element(repo, f);

    assert(repo->dimensiune == 6);
    assert(repo->capacitate == 10);
    int poz = cautare_materie_prima_dupa_denumire(repo, "a");
    stergere_element(repo, poz);
    assert(repo->dimensiune == 5);
    poz = cautare_materie_prima_dupa_denumire(repo, "b");
    stergere_element(repo, poz);
    assert(repo->dimensiune == 4);
    poz = cautare_materie_prima_dupa_denumire(repo, "z");
    //stergere_element(repo, poz);
    assert(repo->dimensiune == 4);
    assert(repo->capacitate == 5);
    actualizare_materie_prima(repo, "d", "d", -1);
    //testam actualizarea unui element care nu exista
    int err = actualizare_materie_prima(repo, "z", "d", -1);
    assert(err == -1);
    poz = cautare_materie_prima_dupa_denumire(repo, "d");
    assert(strcmp(((struct MateriePrima *)(repo->elems[poz]))->producator, "d") == 0);
    err = cautare_materie_prima_dupa_denumire(repo, "z");
    assert(err == -1);
    actualizare_materie_prima(repo, "d", "", 4000);
    assert(((struct MateriePrima *)(repo->elems[poz]))->cantitate == 4000);
    int nr_elemente = get_nr_materii_prime(repo);
    //check
    Element toate[nr_elemente];
    get_all(repo, toate);


    printf("%s\n",((struct MateriePrima *)(toate[poz]))->denumire);
    printf("%s\n",((struct MateriePrima *)(repo->elems[poz]))->denumire);


    assert(repo->dimensiune == nr_elemente);
    assert(strcmp(((struct MateriePrima *)(toate[0]))->denumire, ((struct MateriePrima *)(repo->elems[0]))->denumire) == 0);
    assert(strcmp(((struct MateriePrima *)(toate[1]))->denumire, ((struct MateriePrima *)(repo->elems[1]))->denumire) == 0);
    assert(strcmp(((struct MateriePrima *)(toate[2]))->denumire, ((struct MateriePrima *)(repo->elems[2]))->denumire) == 0);
}

void test_service() {
    //adaugare
    VectorDinamic *repo = creeaza_vector_dinamic();
    assert(repo->capacitate == 5);
    assert(repo->dimensiune == 0);
    adauga_materie_prima(repo, "a", "a", 1);
    adauga_materie_prima(repo, "b", "a", 1);
    adauga_materie_prima(repo, "c", "a", 1);
    adauga_materie_prima(repo, "d", "a", 1);
    adauga_materie_prima(repo, "e", "a", 1);
    adauga_materie_prima(repo, "f", "a", 1);
    assert(repo->dimensiune == 6);
    //assert(repo->capacitate == 10);
    //sterge
    sterge_materie_prima(repo, "a");
    assert(repo->dimensiune == 5);
    sterge_materie_prima(repo, "b");
    assert(repo->dimensiune == 4);
    sterge_materie_prima(repo, "c");
    assert(repo->dimensiune == 3);
    assert(repo->capacitate == 5);
    //modifica
    modifica_materie_prima(repo, "d", "d", -1);
    int poz = cautare_materie_prima_dupa_denumire(&repo, "d");
    assert(strcmp(((struct MateriePrima *)(repo->elems[poz]))->producator, "d") == 0);
    modifica_materie_prima(repo, "d", "", 4000);
    assert(((struct MateriePrima *)(repo->elems[poz]))->cantitate == 4000);
    int nr_elemente = get_lungime(repo);
    Element toate[nr_elemente];
    vizualizeaza_toate(repo, toate);
    assert(repo->dimensiune == nr_elemente);
    assert(strcmp(((struct MateriePrima *)(toate[poz]))->denumire, ((struct MateriePrima *)(repo->elems[poz]))->denumire) == 0);
    assert(strcmp(((struct MateriePrima *)(toate[poz]))->denumire, ((struct MateriePrima *)(repo->elems[poz]))->denumire) == 0);
    assert(strcmp(((struct MateriePrima *)(toate[poz]))->denumire, ((struct MateriePrima *)(repo->elems[poz]))->denumire) == 0);
}


void run_all_tests() {
    test_validation();
    test_domain();
    test_repo();
    test_service();
    printf("Teste realizate cu succes!!!\n");
}
