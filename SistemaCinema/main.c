#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "functions.h"

#define TAM 5

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    SetConsoleTextAttribute(hConsole, 15);
    setlocale(LC_ALL, "Portuguese");

    struct Ingresso salaCinema[5][5];

    criaPoltronas(salaCinema, TAM);

    menuCinema(salaCinema, TAM);

    return 0;
}
