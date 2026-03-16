#include "dinamico.h"
using namespace emap;

int main() {
    ArrayDinamico* p = inicializar(4); // Inicializo
    append(p, 10);
    append(p, 20);
    append(p, 30);
    append(p, 50);
    display(p);
    append(p, 80);
    display(p);
    deletar(p);
    return 0;
}