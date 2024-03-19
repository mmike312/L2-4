//
// Created by Mihai Moldovan on 08.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repo.h"

/**
 * creeaza o structura de top RepoMP
 * @return RepoMP
 */
VectorDinamic *creeaza_vector_dinamic() {
    VectorDinamic *repo_cofetarie = (VectorDinamic *)malloc(sizeof(VectorDinamic));
    repo_cofetarie->capacitate = 5;
    repo_cofetarie->dimensiune = 0;
    repo_cofetarie->elems = (Element *)malloc(5*sizeof(Element));
    return repo_cofetarie;
}

/**
 * cauta o materie prima cu denumirea transmisa prim parametru
 * @param repo_cofetarie RepoMP - structura de date in care se memoreaza materiile prime
 * @param denumire char string - max 30 de caractere - denumirea obiectului care se cauta
 * @return pozitia elementului in structura de date sau -1, daca elementul nu exista
 */
int exista_in_repo(VectorDinamic *repo_cofetarie, char *denumire) {
    for( int i = 0; i < repo_cofetarie->dimensiune; ++i) {
        if (strcmp( ((MateriePrima *)(repo_cofetarie->elems[i]))->denumire, denumire) == 0)
            return i;
    }
    return -1;
}

/**
 * adauga strctura de tip MateriePrima in structura de tip RepoMP
 * @param repo_cofetarie RepoMP - structura care retine materiile prime
 * @param materie_prima MateriePrima - o materie prima
 */
void adaugare_element( VectorDinamic *repo_cofetarie, Element el) {
    int pozitie = exista_in_repo(repo_cofetarie, ((MateriePrima *)(el))->denumire);
    if( pozitie >= 0) {
        ((MateriePrima *)(repo_cofetarie->elems[pozitie]))->cantitate += ((MateriePrima *)(el))->cantitate;
    }
    else {
        if( repo_cofetarie->dimensiune == repo_cofetarie->capacitate) {
            Element *temporar = repo_cofetarie->elems;
            repo_cofetarie->elems = (Element *)malloc(2 * (repo_cofetarie->capacitate * sizeof(Element)));
            for( int i = 0; i < repo_cofetarie->capacitate; ++i)
                repo_cofetarie->elems[i] = temporar[i];

            repo_cofetarie->capacitate = 2 * repo_cofetarie->capacitate;
            free(temporar);
        }
        repo_cofetarie->elems[repo_cofetarie->dimensiune] = el;
        repo_cofetarie->dimensiune++;
    }
}

/**
 * actualizeaza producatorul sau stocul unei materii prime
 * @param repo_cofetarie RepoMP - structura care emmoreaza materiile prime
 * @param denumire_m_p char string - max 30 de caractere - denumirea materiei prime
 * @param producator char string - max 30 de caractere - producatorul cu care se actualizeaza
 * @param stoc int - -1 atunic cand se doreste actualizarea producatorului
 *                   primeste valoare mai mare sau egala cu 0 atunci cand se doreste modificarea stocului materiei prime
 */
int actualizare_materie_prima( VectorDinamic *repo_cofetarie, char denumire_m_p[], char producator[], int stoc) {
    int ind = exista_in_repo(repo_cofetarie, denumire_m_p);
    if( ind == -1) {
        fprintf(stderr, "Materia prima introdusa nu exista!!!");
        return -1;
    }
    if( stoc == -1) {
        set_producator(repo_cofetarie->elems[ind], producator);
    }
    if(stoc >= 0) {
        set_cantitate(repo_cofetarie->elems[ind], stoc);
    }
}

/**
 * cauta o materie prima cu denumirea transmisa prim parametru
 * @param repo_cofetarie RepoMP - structura de date in care se memoreaza materiile prime
 * @param denumire char string - max 30 de caractere - denumirea obiectului care se cauta
 * @return pozitia elementului in structura de date sau -1, daca elementul nu exista
 */
int cautare_materie_prima_dupa_denumire( VectorDinamic *repo_cofetarie, char denumire[]) {
    for( int i = 0; i < repo_cofetarie->dimensiune; ++i)
        if( strcmp(((MateriePrima *)(repo_cofetarie->elems[i]))->denumire, denumire) == 0)
            return i;
    return -1;
}

/**
 * elimina un element din structura RepoMp
 * @param repo_cofetarie  RepoMP - structura care memoreaza toate materiile prime
 * @param denumire char string - denumirea materiei prime care se doreste eliminata
 * raises eerror - daca elementul nu exista in repo
 */
int stergere_element( VectorDinamic *repo_cofetarie, int poz) {
    disctruge_materie_prima((struct MateriePrima *)(repo_cofetarie->elems[poz]));
    for( int i = poz; i < repo_cofetarie->dimensiune - 1; ++i)
        repo_cofetarie->elems[i] = repo_cofetarie->elems[i + 1];
    repo_cofetarie->dimensiune--;
    if( repo_cofetarie->dimensiune < repo_cofetarie->capacitate / 2) {
        Element *temporar = repo_cofetarie->elems;
        repo_cofetarie->elems = (Element *)malloc((repo_cofetarie->capacitate / 2) * sizeof(Element));
        for( int i = 0; i <= repo_cofetarie->dimensiune; i++)
            repo_cofetarie->elems[i] = temporar[i];
        repo_cofetarie->capacitate = repo_cofetarie->capacitate / 2;
        free(temporar);
    }
}


/**
 *
 * @param repo_cofetarie RepoMP - structura care memoreaza materiile prime
 * @return int - numarul materiilor prime din repo
 */
int get_nr_materii_prime(VectorDinamic *repo_cofetarie) {
    return repo_cofetarie->dimensiune;
}

/**
 * returneaza prim marametrul toate_m_p toate materiile prime
 * @param repo_cofetarie
 * @param toate_m_p - lista statica de tip MateriePrima care are numarul de elemnte presetat ca numarul de materii prime din repo
 */
void get_all( VectorDinamic *repo_cofetarie, Element *toate_elementele) {
    for( int i = 0; i < repo_cofetarie->dimensiune; ++i)
        toate_elementele[i] = repo_cofetarie->elems[i];
}