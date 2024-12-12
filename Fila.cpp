#include <iostream>
using namespace std;

typedef struct No {
    int info;
    struct No* prox;
} Lista;

Lista* inicializar() {
    return nullptr;
}

// Função para inserir no final da lista
Lista* inserir(Lista* lista, int valor) {
    Lista* novo = new No;
    novo->info = valor;
    novo->prox = nullptr;

    if (lista == nullptr) {
        // Se a lista estiver vazia, o novo nó é o início
        return novo;
    }
    
    //esta apontando para o primeiro elemento da lista 
    Lista* p = lista;
    
    // Caso contrário, percorre até o último nó
    while (p->prox != nullptr) {
        p = p->prox;
    }

    // Inserir o novo nó no final da lista apontando para null
    p->prox = novo;
    return lista;
}

// Função para remover o primeiro elemento da lista e retornar o novo início da lista
Lista* remover(Lista* lista) {
    if (lista == nullptr) return nullptr;
    
    Lista* temp = lista;
    lista = lista->prox;
    cout << temp->info << " "; 
    delete temp;
    
    return lista;
}

/*void liberar(Lista* lista) {
    Lista* p = lista;
    while (p != nullptr) {
        Lista* temp = p->prox;
        delete p;
        p = temp;
    }
}*/

int main() {
    Lista* lista = inicializar(); 
    int valor;

    for(int i = 0; i < 4; i++) {
        cin >> valor;
        lista = inserir(lista, valor);
    }

    while (lista != nullptr) {
        lista = remover(lista);
    }

    cout << endl;
    return 0;
}
