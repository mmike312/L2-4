//
// Created by Mihai Moldovan on 08.03.2024.
//
#include <stdio.h>
#include "validation.h"
#include "service.h"

/**
 * valideaza datele de intrare
 * creaza structura de tip MatreiePrima din cei 3 parametri: denumire_m_p, char producator, cantitate
 * adauga in repo structura creata
 * @param repo_cofetarie RepoMP - structura care memoreaza toate materiile prime
 * @param denumire_m_p char string - max 30 caractere - denumire
 * @param producator char string - max 30 caractere - denumirea producatorilor
 * @param cantitate int - cantitatea de materie prima
 * @return
 */
int adauga_materie_prima( VectorDinamic *repo_cofetarie, char denumire_m_p[], char producator[], int cantitate) {
    int validare = valideaza_materie_prima(denumire_m_p, producator, cantitate);
    if(validare != 1) return -1;
    struct MateriePrima *m_p = creeaza_materie_prima(denumire_m_p, producator, cantitate);
    adaugare_element(repo_cofetarie, m_p);
}

/**
 * modifica materia prima
 * @param repo_cofetarie RepoMP - structura care memoreaza toate materiile prime
 * @param denumire_m_p
 * @param producator
 * @param cantitate
 */
void modifica_materie_prima( VectorDinamic *repo_cofetarie, char denumire_m_p[], char producator[], int cantitate) {
    valideaza_denumire_materie_prima(denumire_m_p);
    if(cantitate == -1) {
        //if(valideaza_producator(producator) == 1)
        actualizare_materie_prima(repo_cofetarie, denumire_m_p, producator, cantitate);
    }
    else {
        //if(valideaza_cantitate(cantitate) == 1)
        actualizare_materie_prima(repo_cofetarie, denumire_m_p, producator, cantitate);
    }
}

/**
 * elimina un element din repo dupa denumirea materiei prime
 * @param repo_cofetarie RepoMP - structura care memoreaza toate materiile prime
 * @param denumire_m_p char string - denumirea elementului de eliminat
 */
int sterge_materie_prima( VectorDinamic*repo_cofetarie, char denumire_m_p[]) {
    //int validare = valideaza_denumire(denumire_m_p);
    //if(validare != 1) return -1;
    int poz = cautare_materie_prima_dupa_denumire(repo_cofetarie, denumire_m_p);
    return stergere_element(repo_cofetarie, poz);
}

/**
 * returneaza prim parametrul toare_materiile prime totalitatea materiilor prime
 * @param repo_cofetarie RepoMP - structura care memoreaza toate materiile prime
 * @param toate_materiile_prime lisat de structuri de tip MateriePrima - parametru de iesire
 */
int vizualizeaza_toate( VectorDinamic *repo_cofetarie, Element *toate_materiile_prime) {
    int numar_m_p = get_nr_materii_prime(repo_cofetarie);
    get_all(repo_cofetarie, toate_materiile_prime);
}

/**
 * returneaza numarul de materii prime
 * @param repo_cofetarie RepoMP - structura care memoreaza toate materiile prime
 * @return numarul de materii prime
 */
int get_lungime( VectorDinamic *repo_cofetarie){
    return get_nr_materii_prime(repo_cofetarie);
}

int vizualizeaza_materii_care_incep_cu_litera(VectorDinamic *repo_cofetarie, Element *toate_materiile_prime, char litera) {
    int numar_m_p = get_nr_materii_prime(repo_cofetarie);

}

int vizualizeaza_materii_care_are_cantitatea_mai_mica_decat( VectorDinamic *repo_cofetarie, Element *toate_materiile_prime, int cantitate) {
        int numar_m_p = get_nr_materii_prime(repo_cofetarie);
}

void ordoneaza_dupa(VectorDinamic *repo_cofetarie, Element *toate_materiile_prime, char camp[], int directie) {
        int numar_m_p = get_nr_materii_prime(repo_cofetarie);
}
