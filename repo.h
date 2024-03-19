//
// Created by Mihai Moldovan on 08.03.2024.
//

#ifndef COFETARIE_REPO_H
#define COFETARIE_REPO_H
#include "domain.h"
#include <stdlib.h>

typedef void* Element;
typedef struct VectorDinamic {
    int capacitate;
    int dimensiune;
    Element *elems;
}VectorDinamic;

VectorDinamic *creeaza_vector_dinamic();
void adaugare_element( VectorDinamic *repo_cofetarie, Element el);
int actualizare_materie_prima( VectorDinamic *repo_cofetarie, char denumire_m_p[], char producator[], int stoc);
int cautare_materie_prima_dupa_denumire( VectorDinamic *repo_cofetarie, char denumire[]);
int stergere_element( VectorDinamic *repo_cofetarie, int poz);
int get_nr_materii_prime(VectorDinamic *repo_cofetarie);
void get_all( VectorDinamic *repo_cofetarie, Element *toate_elementele);
#endif //COFETARIE_REPO_H
