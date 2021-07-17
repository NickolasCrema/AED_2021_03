//
// Created by nickolas on 15/07/2021.
//
#include <stdio.h>
#include "arvoreB.h"
#include "arquivo.h"

int buscarPos(NoB* no, int info, int *pos){
    for((*pos) = 0; (*pos) < no->numChaves; (*pos)++){
        if(info == no->chave[(*pos)].info)
            return 1;
        else if(info < no->chave[(*pos)].info)
            break;
    }
    return 0;
}

int splitB(FILE* arq, NoB* no, Chave* chavePromovida){
    NoB* novoNo = (NoB*) malloc(sizeof(NoB));
    int metadeChaves = no->numChaves/2;
    novoNo->numChaves = no->numChaves - metadeChaves - 1;
    no->numChaves = metadeChaves;
    *chavePromovida = no->chave[metadeChaves];
    novoNo->filhos[0] = no->filhos[metadeChaves+1];
    for(i=0; i < novoNo->numChaves; i++){
        novoNo->chave[i] = no->chave[metadeChaves + 1 + i];
        novoNo->filhos[i+1] = no->filhos[metadeChaves + 2 + i];
    }
    novoNo->pai = no->pai;
    //TODO no compreendo
}

NoB* mudarNo(FILE* arq, int posNo){
    NoB* aux = (NoB*) malloc(sizeof(NoB));
    aux = lerNo(arq, posNo);
    if(aux->numChaves!=-1){
        return aux;
    }
    return NULL;
}

void adicionaDireita(FILE* arq, NoB* no, int pos, Chave chave, int subarvore){
    int i;
    for(i=no->numChaves; i>pos; i--){
        no->chave[i] = no->chave[i-1];
        no->filhos[i+1] = no->filhos[i];
    }
    no->chave[pos] = chave;
    no->filhos[pos+1] = subarvore;
    no->numChaves++;
    escreverNo(arq, no, pos);
}

int overflow(NoB* no){
    return (no->numChaves == ORDEM);
}

int ehFolha(NoB* no){
    return (no->filhos[0] == NULL);
}

int vazia(NoB* no){
    return (no==NULL);
}

//calcula a altura da arvore B
int altura(FILE* arq, NoB* no){
    int altura=0;
    NoB* aux;
    CabecalhoArvore* cab = lerCabecalhoArvore(arq);
    aux = lerNo(arq, cab->raiz);
    for(;aux->filhos[0]!=-1; altura++){
        aux = aux->filhos[0];
    }
    return altura+1;
}

void inserirAux(FILE* arq, NoB* no, Chave chave){
    int posChave;
    if(!buscarPos(no, chave, &posChave)){ //chave não está no nó atual
        if(ehFolha(no)){
            adicionaDireita(arq, no, &posChave, chave, -1);
        }
        else{
            no = no->filhos[posChave];
            inserirAux(arq, no, chave);
            if(overflow(no)){
                Chave m;
                int nosplit = splitB(arq, no, &m);
                //TODO no compreendo
            }
        }
    }
}

void inserir(FILE* arq, NoB* no, Chave chave){
    CabecalhoArvore* cab = lerCabecalhoArvore(arq);
    int i;
    if(cab->topo == 0){
        cab->topo = 1;
        cab->raiz = 0;
        no->chave[0] = chave;
        for(i=0; i<ORDEM; i++){
            no->filhos[i] = -1;
        }
        no->numChaves = 1
      //this->setPos(0); pos=???????
    }
    else{
        no = mudarNo(cab->raiz);
        inserirAux(chave);
        if(overflow(no)){
            Chave chavePromovida;
            int noSplit;
            noSplit = splitB(arq, no, &chavePromovida);
            NoB* novaRaiz = (NoB*)malloc(sizeof(NoB));
            novaRaiz->chave = chavePromovida;
           // novaRaiz->filhos[0] = this->pos  //this->pos=?????
           novaRaiz->filhos[1] = noSplit;
           novaRaiz->numChaves = 1;
           if(cab->posLivre == -1){ //inserir no topo
               novaRaiz->pai = -1;
               escreverNo(arq, novaRaiz, cab->topo);
               cab->raiz = cab->topo;
               no = mudarNo(cab->topo);
               cab->topo++;
           }
           else{
               NoB* temp = (NoB*)malloc(sizeof(NoB));
               temp = lerNo(arq, cab->posLivre);
               escreverNo(arq, novaRaiz, cab->posLivre);
               cab->raiz = cab->posLivre;
               novaRaiz->pai = cab->raiz;
               cab->posLivre = temp->pai;
           }
           NoB* filho = (NoB*)malloc(sizeof(NoB));
           for(i=0; i<no->numChaves+1; i++){
               filho = lerNo(arq, no->filhos[i]);
               if(filho->numChaves!=-1){
                   //filho->pai = this->pos //this->pos=?????
                   escreverNo(arq, no->filhos[i]);
               }
           }
        }
    }
    escreveCabecalhoArvore(cab);
    //escreverNo(arq, no, this->pos); this->pos=????
}

//Função que imprime uma chave da árvore
void printVetB(Chave v[], int n){
    int i;
    printf("[");
    for(i=0; i<n; i++){
        if(i<n-1)
            printf("%d,", v[i].info);
        else
            printf("%d ", v[i].info)
    }
    printf("]");
}

//Função que imprime um nível da árvore
void imprimirPorNivel(NoB* no, int nivel, int atual){
    if(nivel==atual){
        printVetB(no->chave, no->numChaves);
    }
    else{
        int i, posVoltar;
//        NoB* aux = (NoB*) malloc(sizeof(NoB));
//        aux = no;
        if(atual<=nivel){
            for(i=0; i<no->numChaves+1 && no->filhos[i] != -1; i++){
                no = no->filhos[i];
                imprimirPorNivel(nivel, atual+1);
                no = no->pai;
            }
        }
    }
}

