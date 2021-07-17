//
// Created by nickolas on 15/07/2021.
//

#ifndef ARVOREB_H
#define ARVOREB_H

#define ORDEM 5

typedef struct{
    int info;
    int posProduto;
}Chave;

typedef struct {
    int posProduto[ORDEM];
    int filhos[ORDEM+1];
    Chave chave[ORDEM];
    int numChaves;
    int pai;
}NoB;

typedef struct{
    int topo, posLivre, raiz;
}CabecalhoArvore;

#endif //ARVOREB_H
