#ifndef DINAMICO_H
#define DINAMICO_H

// DIRETIVA DO PRE-PROCESSADOR

namespace emap {

// PROTOTIPOS
struct ArrayDinamico {
    int capacidade;
    int tamanho;
    int* dados;
};

ArrayDinamico* inicializar(int capacidade);
void deletar(ArrayDinamico* p);
void append(ArrayDinamico* p, int value);
void resize(ArrayDinamico* p, int nova_capacidade);
void display(ArrayDinamico* p);

}

#endif