#include <iostream>
using namespace std;

class MeuArray {

protected:
    int capacidade;
    int tamanho;
    int* dados;

public:

    void display() {
        cout << "Capacidade: " << this->capacidade << endl;
        cout << "Tamanho: " << this->tamanho << endl;
        for(int i = 0; i < this->tamanho; i++) {
            cout << i << ": " << this->dados[i] << endl;
        }
    }

};

class ArrayDinamico : public MeuArray {

public:

    ArrayDinamico(int capacidade) { // Python: __init__
        this->dados = new int[capacidade];
        for(int i = 0; i < capacidade; i++) {
            this->dados[i] = 0;
        }
        this->capacidade = capacidade;
        this->tamanho = 0;
    }

    ~ArrayDinamico() { // Python: __del__
        delete[] this->dados;
    }

    void append(int value) {
        if(this->capacidade == this->tamanho) {
            resize(2 * this->capacidade);
        }
        this->dados[this->tamanho] = value;
        this->tamanho++;
    }

    void resize(int nova_capacidade) {
        int* novo_dados = new int[nova_capacidade];
        for(int i = 0; i < this->capacidade; i++) {
            novo_dados[i] = this->dados[i];
        }
        delete[] this->dados;
        this->dados = novo_dados;
        this->capacidade = nova_capacidade;
    }
};


class Notificacao {

    std::string texto;

public:

    Notificacao(std::string texto) {
        this->texto = texto;
    }

    virtual void enviar() = 0; // Metodo abstrato  @abstractmethod

};

class SMS: public Notificacao {

    int telefone;

public:

    SMS(std::string texto, int telefone) : Notificacao(texto) { // super()
        this->telefone = telefone;
    }

    void enviar() override {
        cout << "SMS" << endl;
    }

};

int main() {
    ArrayDinamico a(10);
    a.display();

    SMS sms("OLA");
    sms.enviar();

    SMS n("OLA");
    return 0;
}
