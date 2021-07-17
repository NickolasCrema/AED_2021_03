//
// Created by nickolas on 15/07/2021.
//

#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "produto.h"
#include "arvoreB.h"

//Função que escreve o cabeçalho no arquivo binário de produtos
void escreveCabecalhoProduto(CabecalhoProduto* cab, FILE* arq);

//Função que lê o cabeçalho no arquivo binário de produtos
CabecalhoProduto* lerCabecalhoProduto(FILE* arq);

//Função que escreve o cabeçalho no arquivo binário de árvore
void escreveCabecalhoArvore(CabecalhoArvore* cab, FILE* arq);

//Função que lê o cabeçalho no arquivo binário de árvore
CabecalhoProduto* lerCabecalhoArvore(FILE* arq);

//Função que escreve o arquivo binário vazio de produtos
void escreveArquivoProdutoVazio(FILE* arq);

//Função que escreve o arquivo binário vazio de árvore
void escreveArquivoArvoreVazio(FILE* arq);

//Função que escreve um produto na posição indicada no arquivo binário de produtos
void escreveProduto(FILE* arq, Produto* produto, int pos);

//Função que lê um produto do arquivo binário de produtos
Produto lerProduto(FILE* arq, int pos);

//Função que escreve um nó na posição indicada no arquivo binário de árvore
void escreverNo(FILE* arq, NoB* no, int pos);

//Função que lê um nó do arquivo binário de árvore
NoB* lerNo(FILE* arq, int pos);



#endif //ARQUIVO_H
