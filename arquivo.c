//
// Created by nickolas on 15/07/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arquivo.h"

void escreveCabecalhoProduto(CabecalhoProduto* cab, FILE* arq){
    fseek(arq, 0, SEEK_SET);
    fwrite(cab, sizeof(CabecalhoProduto), 1, arq);
}

CabecalhoProduto* lerCabecalhoProduto(FILE* arq){
    CabecalhoProduto* cab;
    fseek(arq, 0, SEEK_SET);
    fread(cab, sizeof(CabecalhoProduto), 1, arq);
    return cab;
}

void escreveCabecalhoArvore(CabecalhoArvore* cab, FILE* arq){
    fseek(arq, 0, SEEK_SET);
    fwrite(cab, sizeof(CabecalhoArvore), 1, arq);
}

CabecalhoProduto* lerCabecalhoArvore(FILE* arq){
    CabecalhoProduto* cab;
    fseek(arq, 0, SEEK_SET);
    fread(cab, sizeof(escreveCabecalhoArvore()), 1, arq);
    return cab;
}

void escreveArquivoProdutoVazio(FILE* arq){
    CabecalhoProduto* cab;
    cab->posLivre = -1;
    cab->topo = 0;
    fseek(arq, 0, SEEK_SET);
    fwrite(cab, sizeof(CabecalhoProduto), 1, arq);
}

void escreveArquivoArvoreVazio(FILE* arq){
    CabecalhoArvore* cab;
    cab->posLivre = -1;
    cab->topo = 0;
    cab->raiz = -1;
    fseek(arq, 0, SEEK_SET);
    fwrite(cab, sizeof(CabecalhoArvore), 1, arq);
}

void escreveProduto(FILE* arq, Produto* produto, int pos){
    fseek(arq, sizeof(CabecalhoProduto) + (pos*sizeof(Produto)), SEEK_SET);
    fwrite(livro, sizeof(Produto), 1, arq);
}

Produto lerProduto(FILE* arq, int pos){
    Produto* produto;
    fseek(arq, sizeof(CabecalhoProduto) + (pos*sizeof(Produto)), SEEK_SET);
    fread(produto, sizeof(Produto), 1, arq);
    return produto;
}

void escreverNo(FILE* arq, NoB* no, int pos){
    fseek(arq, sizeof(CabecalhoArvore) + (pos*sizeof(NoB)), SEEK_SET);
    fwrite(no, sizeof(NoB), 1, arq);
}

NoB* lerNo(FILE* arq, int pos){
    NoB* no;
    fseek(arq, sizeof(CabecalhoArvore) + (pos*sizeof(NoB)), SEEK_SET);
    fread(no, sizeof(NoB), 1, arq);
    return no;
}