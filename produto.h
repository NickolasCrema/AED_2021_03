//
// Created by nickolas on 15/07/2021.
//

#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct { //estrutura de produto
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char localizacao[100];
}Produto;

typedef struct {
    int topo, posLivre;
}CabecalhoProduto;

#endif //PRODUTO_H
