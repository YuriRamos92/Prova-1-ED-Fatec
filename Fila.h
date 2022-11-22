class Fila {
    private:
        struct elemento {
            int id;
            string nomeArquivo;
            int folhas;
            elemento* proximoElemento;
        };
        typedef elemento *PonteiroElemento;
        int folhasDisponiveis=0;
        int cont=0;
        PonteiroElemento inicio;
        PonteiroElemento fim;
    public:
        Fila();
        bool vazia();
        bool cheia();
        // alterar
        bool inserir(string auxNome, int auxFolhas);
        bool remover(int &auxId, string &auxNome, int &auxFolhas);
        // implementar
        string listar();
        int listarFolhas();
        bool inserirFolhas(int auxFolhas);
};
