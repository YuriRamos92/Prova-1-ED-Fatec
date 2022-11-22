#include "Fila.h"

Fila::Fila() {
    inicio = NULL;
    fim = NULL;
    cont = 0;
}

bool Fila::vazia() {
    return (inicio == NULL);
}

bool Fila::cheia() {
    return false;
}

bool Fila::inserir(string auxNome, int auxFolhas) {

    if(folhasDisponiveis < auxFolhas){
        return false;
    }
    PonteiroElemento p;

    p = new elemento;

    p->id = cont + 1;
    cont++;

    folhasDisponiveis -= auxFolhas;
    p->nomeArquivo = auxNome;
    p->folhas = auxFolhas;

    if (vazia()) {
        inicio = p;
        fim = p;
    } else {
        fim->proximoElemento = p;
        fim = p;
    }
    p->proximoElemento = NULL;
    return true;
}

bool Fila::remover(int &auxId, string &auxNome, int &auxFolhas) {
    PonteiroElemento p;
    if (vazia())
        return false;

    auxId = inicio->id;
    auxNome = inicio->nomeArquivo;
    auxFolhas = inicio->folhas;

    p = inicio;
    inicio = inicio->proximoElemento;
    delete p;
    if (inicio == NULL)
        fim = NULL;
    return true;
}

string Fila::listar() {
	// Implementar listagem da fila de impressão;
    // Retornar string no formato:
	// <idImpressao1> - <nomeArquivo1> - <folhas1>\n
	// <idImpressao2> - <nomeArquivo2> - <folhas2>\n
	//
	// Seu código aqui	
        if(vazia()){
            return "";
        }
        
        int x, y;
        string z;
        Fila auxFila;
        string retorno = "";
        while(remover(auxIDF, axNomeF, auxfolhasDisponiveis)){
            retorno = retorno + to_string(auxIDF) + " - ";
            retorno = retorno + axNomeF + " - ";
            retorno = retorno + to_string(auxfolhasDisponiveis) + "\n";
            cont--;
            auxFila.inserirFolhas(auxfolhasDisponiveis);
            auxFila.inserir(axNomeF,auxfolhasDisponiveis);
        }
        while(auxFila.remover(auxIDF, axNomeF, auxfolhasDisponiveis)){
            inserirFolhas(auxfolhasDisponiveis);
            inserir(auxfolhasDisponiveis, auxNomeF, auxIDF);
        }

        return retorno;
}


bool Fila::inserirFolhas(int auxFolhas) {
    folhasDisponiveis = auxFolhas + folhasDisponiveis;


    return true;
}

int Fila::listarFolhas() {
    // Retorna o total de folhas disponíveis na impressora;
	// Seu código aqui
    return folhasDisponiveis;

}
