#include "dinamico.h"
#include <iostream>
using namespace std;

namespace emap {

// ATRIBUICAO / IMPLEMENTACAO
ArrayDinamico* inicializar(int capacidade) {
    ArrayDinamico* arr = new ArrayDinamico;
    arr->dados = new int[capacidade];
    for(int i = 0; i < capacidade; i++) {
        arr->dados[i] = 0;
    }
    arr->capacidade = capacidade;
    arr->tamanho = 0;
    return arr;
}

void deletar(ArrayDinamico* p) {
    delete[] p->dados;
    delete p;
}

void append(ArrayDinamico* p, int value) {
    if(p->capacidade == p->tamanho) {
        resize(p, 2 * p->capacidade);
    }
    p->dados[p->tamanho] = value;
    p->tamanho++;
}

void resize(ArrayDinamico* p, int nova_capacidade) {
    int* novo_dados = new int[nova_capacidade];
    for(int i = 0; i < p->capacidade; i++) {
        novo_dados[i] = p->dados[i];
    }
    delete[] p->dados;
    p->dados = novo_dados;
    p->capacidade = nova_capacidade;
}

void display(ArrayDinamico* p) {
    cout << "Capacidade: " << p->capacidade << endl;
    cout << "Tamanho: " << p->tamanho << endl;
    for(int i = 0; i < p->tamanho; i++) {
        cout << i << ": " << p->dados[i] << endl;
    }
}

}