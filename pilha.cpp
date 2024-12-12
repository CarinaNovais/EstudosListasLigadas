#include <iostream>

using namespace std;

typedef struct No {
    int info;
    struct No* prox;
} Pilha;

Pilha* inicializar() {
    return nullptr;
}

Pilha* inserir(Pilha * topo, int valor){
    
    //declarando ponteiro e apontando para primeira pos dos nós ligados
    Pilha* novo = new No;
    
    novo->info = valor;
    novo->prox = topo;
    return novo;

}

Pilha* remover(Pilha* topo, int* valor){
    if (topo == nullptr) return nullptr;
    
    *valor = topo->info;
    Pilha* temp = topo->prox;
    delete topo;
    return temp;
}

/*Pilha* exibir(){
    Pilha* p = topo;
    while (p != nullptr) {
        std::cout << p->info << " ";
        p = p->prox;
    }
    cou<<endl;
}*/

/*Pilha * liberar_momoria(){
    Pilha* p = topo;
    while (p != nullptr) {
        Pilha* temp = p->prox;
        delete p;
        p = temp;
    }
}*/

int main (){
    //declarando ponteiro tipo pilha e apoontado para null
    Pilha * pilha = inicializar();
    
    int info;
    
    //inserindo elementos
    for(int i = 0; i<4; i++){
        cin>>info;
        pilha = inserir(pilha, info);
    }
    while (pilha != nullptr) {
        pilha = remover(pilha, &info);
        cout << info << " ";  
    }
    cout << endl;
    

    return 0;
}