#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "functions.h"

void criaPoltronas(struct Ingresso p[5][5], int tam) {
    for(int i=0; i<tam; i++) {
        for(int j=0; j<tam; j++) {
            p[i][j].reservada = 0;
            p[i][j].letraFileira = i+65;
            p[i][j].numPoltrona = j+1;
        }
    }
}

void menuCinema(struct Ingresso p[5][5], int tam) {
    int opcao;

    do {
        printf("\n-=-=-=- CINE PANAMBI -=-=-=-\n\n");
        printf("1 - Reservar\n");
        printf("2 - Comprar\n");
        printf("3 - Cancelar reserva\n");
        printf("4 - Confirmar reserva\n");
        printf("5 - Sair\n");
        printf("\nEscolha uma das opções acima: ");
        scanf("%d", &opcao);
        printf("----------------------------\n");

        switch(opcao) {
            case 1:
                cadastraPoltrona(p, tam, opcao);
                break;
            case 2:
                cadastraPoltrona(p, tam, opcao);
                break;
            case 3:
                cadastraPoltrona(p, tam, opcao);
                break;
            case 4:
                cadastraPoltrona(p, tam, opcao);
                break;
            case 5:
                printf("\nPrograma encerrado!\n");
                break;
            default:
                printf("\nCódigo inválido!\n");
        }
    } while(opcao != 5);

}

void exibirPoltronas(struct Ingresso p[5][5], int tam) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    printf("\n----------------------------\n ");
    SetConsoleTextAttribute(hConsole, 240);
    printf("           TELA            \n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("----------------------------\n");

    for(int i=0; i<tam; i++) {
        for(int j=0; j<tam; j++) {
            if(p[i][j].reservada == 0) {
                SetConsoleTextAttribute(hConsole, 10);
                printf("[%c%d]  ", p[i][j].letraFileira, p[i][j].numPoltrona);
            } else if(p[i][j].reservada == 1) {
                SetConsoleTextAttribute(hConsole, 6);
                printf("[%c%d]  ", p[i][j].letraFileira, p[i][j].numPoltrona);
            } else if(p[i][j].reservada == 2) {
                SetConsoleTextAttribute(hConsole, 4);
                printf("[%c%d]  ", p[i][j].letraFileira, p[i][j].numPoltrona);
            }
        }
        printf("\n");
    }

    SetConsoleTextAttribute(hConsole, 15);
}

char letraFileira() {
    char fileira;

    fflush(stdin);
    printf("\nDigite a letra da fileira: ");
    scanf("%c", &fileira);

    return fileira;
}

int numPoltrona() {
    int num;

    fflush(stdin);
    printf("Digite o número da poltrona: ");
    scanf("%d", &num);

    return num;
}

void cadastraPoltrona(struct Ingresso p[5][5], int tam, int opcao) {
    exibirPoltronas(p, tam);

    char fileira = letraFileira();
    int num = numPoltrona();
    int flag = encontraPoltrona(p, tam, fileira, num, opcao);

    if(flag == 0) {
        system("cls");
        exibirPoltronas(p, tam);
        printf("\nPoltrona não encontrada!\n");
    } else if(flag == 1) {
        system("cls");
        exibirPoltronas(p, tam);
        printf("\nPoltrona reservada com sucesso!\n");
    } else if(flag == 2) {
        system("cls");
        exibirPoltronas(p, tam);
        printf("\nPoltrona comprada com sucesso!\n");
    } else if(flag == 3) {
        system("cls");
        exibirPoltronas(p, tam);
        printf("\nReserva da poltrona cancelada!\n");
    } else if(flag == 4) {
        system("cls");
        exibirPoltronas(p, tam);
        printf("\nReserva da poltrona comprada com sucesso!\n");
    } else if(flag == 5) {
        system("cls");
        exibirPoltronas(p, tam);
        printf("\nEssa poltrona ja foi reservada!\n");
    } else if(flag == 6) {
        system("cls");
        exibirPoltronas(p, tam);
        printf("\nEssa poltrona ja foi comprada!\n");
    }

}

int encontraPoltrona(struct Ingresso p[5][5], int tam, char fileira, int num, int opcao) {
    int flag = 0;

    for(int i=0; i<tam; i++) {
        for(int j=0; j<tam; j++) {
            if(fileira == p[i][j].letraFileira && num == p[i][j].numPoltrona) {
                if(p[i][j].reservada == 0 && opcao == 1) {
                    p[i][j].reservada = 1;
                    flag = 1;
                } else if(p[i][j].reservada == 0 && opcao == 2) {
                    p[i][j].reservada = 2;
                    flag = 2;
                } else if(p[i][j].reservada == 1 && opcao == 3) {
                    p[i][j].reservada = 0;
                    flag = 3;
                } else if(p[i][j].reservada == 1 && opcao == 4) {
                    p[i][j].reservada = 2;
                    flag = 4;
                } else if(p[i][j].reservada == 1 && opcao == 1) {
                    flag = 5;
                } else if(p[i][j].reservada == 1 && opcao == 2) {
                    flag = 5;
                } else if(p[i][j].reservada == 2 && opcao == 1) {
                    flag = 6;
                } else if(p[i][j].reservada == 2 && opcao == 2) {
                    flag = 6;
                }
            }
        }
    }

    return flag;
}
