struct Ingresso {
    char letraFileira;
    int numPoltrona;
    int reservada;
};

void criaPoltronas(struct Ingresso p[5][5], int tam);
void menuCinema(struct Ingresso p[5][5], int tam);
void exibirPoltronas(struct Ingresso p[5][5], int tam);
char letraFileira();
int numPoltrona();
void cadastraPoltrona(struct Ingresso p[5][5], int tam, int opcao);
int encontraPoltrona(struct Ingresso p[5][5], int tam, char fileira, int num, int opcao);
