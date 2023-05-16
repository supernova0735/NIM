#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

//Declarando variables
// Variable para determinar decisión de juego
char decision = ' ';
// Variable bandera para determinar si hay ganador
int bandera = 0;
//Variables para determinar si el jugador 1 o el jugador 2 ganaron la partida
bool ganador1 = false, ganador2 = false, empate = false;
//Variables que determinarán la disponibilidad de las filas
bool fila1 = true, fila2 = true, fila3 = true;
//Variable para determinar ejecución del programa
bool juego = true;
bool reset = false;
//Variables que contendrán el número disponible de fichas en cada fila
int fichas1 = 3, fichas2 = 5, fichas3 = 7;
//Variable contador para determinar los turnos de los jugadores
int turno = 1;
//Variables para el marcador
int puntos1, puntos2;
//Variables que contendrán los nombres de los jugadores
string jugador1, jugador2;

//Función para graficar

void gotoxy(int x, int y) {
    COORD coord = { 0,0 };
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Función para imprimir NIM en pantalla

void nim() {

    char icono = 219;
    for (int i = 0; i <= 5; i++)
    {
        //Patas N
        gotoxy(15, i + 8);
        cout << icono;
        gotoxy(20, i + 8);
        cout << icono;
        //Pendiente N
        gotoxy(15 + i, 8 + i);
        cout << icono;
        //I
        gotoxy(26, i + 8);
        cout << icono;
        gotoxy(27, i + 8);
        cout << icono;
        //M
        if (i >= 0 && i <= 3) {
            gotoxy(33 + i, 8 + i);
            cout << icono;
        }
        else
        {
            gotoxy(33 + i, 14 - i);
            cout << icono;
        }
        gotoxy(33, i + 8);
        cout << icono;
        gotoxy(39, i + 8);
        cout << icono;
    }
}

//Función para imprimir el marcador en pantalla

void marcador() {
    gotoxy(6, 4);
    cout << jugador1 << ": " << puntos1;
    gotoxy(40, 4);
    cout << jugador2 << ": " << puntos2;
}

//Función para imprimir las fichas en pantalla

void fichas() {
    //Variables que determinan las dimensiones de las fichas y el espacio entre ellas
    int ancho = 2;
    int espacio = 4;
    char icono = 219;

    //Declarando variable que medirá los espacios entre las fichas al imprimirlas

    //Imprimiendo fila 1

    //Imprimiendo las fichas existentes

    for (int i = 1; i <= fichas1; ++i) { //For para imprimir solo las fichas disponibles
        //Imprimiendo fichas
        for (int k = 0; k <= ancho - 1; ++k) {
            gotoxy(18 + k + espacio * i, 9);
            cout << icono;
        }
    }

    //Imprimiendo fila 2

    //Imprimiendo las fichas existentes

    for (int i = 1; i <= fichas2; ++i) { //For para imprimir solo las fichas disponibles
        //Imprimiendo fichas
        for (int k = 0; k <= ancho - 1; ++k) {
            gotoxy(14 + k + espacio * i, 11);
            cout << icono;
        }
    }

    //Imprimiendo fila 3

    //Imprimiendo las fichas existentes

    for (int i = 1; i <= fichas3; ++i) { //For para imprimir solo las fichas disponibles
        //Imprimiendo fichas
        for (int k = 0; k <= ancho - 1; ++k) {
            gotoxy(10 + k + espacio * i, 13);
            cout << icono;
        }
    }
}

//Función para imprimir el tablero en pantalla

void tablero() {
    
   //Imprimiendo bordes del tablero
    char esquinaizquierdasuperior = 201;
    char esquinaderechasuperior = 187;
    char esquinaizquierdainferior = 200;
    char esquinaderechainferior = 188;
    char horizontal = 205;
    char vertical = 186;

    //Imprimiendo esquinas
    gotoxy(2,2);
    cout<<esquinaizquierdasuperior;
    gotoxy(52,2);
    cout<<esquinaderechasuperior;
    gotoxy(2,25);
    cout<<esquinaizquierdainferior;
    gotoxy(52,25);
    cout<<esquinaderechainferior;

    //Imprimiendo bordes horizontales
    for (int i = 3; i <= 51 ; ++i) {
        gotoxy(i,2);
        cout<<horizontal;
        gotoxy(i,25);
        cout<<horizontal;
    }
    //Imprimiendo bordes verticales
    for (int i = 3; i <= 24 ; ++i) {
        gotoxy(2,i);
        cout<<vertical;
        gotoxy(52,i);
        cout<<vertical;
    }
}

//Función para resetear las variables

void resetear() {
    bandera = 0;
    fila1 = true, fila2 = true, fila3 = true;
    fichas1 = 3, fichas2 = 5, fichas3 = 7;
    turno = 1;
    decision = 0;
}

void replay() {
    bandera = 0;
    ganador1 = false, ganador2 = false;
    fila1 = true, fila2 = true, fila3 = true;
    fichas1 = 3, fichas2 = 5, fichas3 = 7;
    turno = 1;
    decision = 0;
    puntos1 = 0;
    puntos2 = 0;
    empate = false;
}

//Función para determinar ganador

void ganador() {
    // DETERMINANDO GANADOR

    // Caso 1: Ultima ficha en fila 3
    if (fila1 == false && fila2 == false && fichas3 == 1) {
        if (turno % 2 == 0) {
            ganador2 = true;
            ganador1 = false;
            empate = false;
        }
        else {
            ganador1 = true;
            ganador2 = false;
            empate = false;
        }

        if (turno % 2 == 0) {
            puntos2 += 3;
        }
        else {
            puntos1 += 3;
        }
        fila3 = 0;
        bandera = 1;
    }
    // Caso 2: Ultima ficha en fila 2
    else if (fila1 == false && fila3 == false && fichas2 == 1) {
        if (turno % 2 == 0) {
            ganador2 = true;
            ganador1 = false;
            empate = false;
        }
        else {
            ganador1 = true;
            ganador2 = false;
            empate = false;
        }

        if (turno % 2 == 0) {
            puntos2 += 3;
        }
        else {
            puntos1 += 3;
        }
        fila2 = 0;
        bandera = 1;
    }
    // Caso 3: Ultima ficha en fila 1
    else if (fila2 == false && fila3 == false && fichas1 == 1) {
        if (turno % 2 == 0) {
            ganador2 = true;
            ganador1 = false;
            empate = false;
        }
        else {
            ganador1 = true;
            ganador2 = false;
            empate = false;
        }

        if (turno % 2 == 0) {
            puntos2 += 3;
        }
        else {
            puntos1 += 3;
        }
        fila1 = 0;
        bandera = 1;
    }
    // Caso 4: Harakiri (Empate)
    else if (fila1 == false && fila2 == false && fila3 == false) {
        if (turno % 2 == 0) {
            ganador1 = false;
            ganador2 = false;
            empate = true;
        }
        else {
            ganador2 = false;
            ganador1 = false;
            empate = true;
        }

        if (turno % 2 == 0) {
            puntos1 += 1;
            puntos2 += 1;
        }
        else {
            puntos1 += 1;
            puntos2 += 1;
        }
        bandera = 1;
    }
}

//Función principal

int main() {
    while (juego) {
        if (ganador1 == false && ganador2 == false && empate == false) {
            reset = false;
            system("cls");
            nim();
            tablero();
            //Solicitando información de los jugadores
            gotoxy(6, 17);
            cout << "Ingrese el nombre del jugador 1: " << endl;
            gotoxy(6, 19);
            cin >> jugador1;
            gotoxy(6, 21);
            cout << "Ingrese el nombre del jugador 2: " << endl;
            gotoxy(6, 23);
            cin >> jugador2;
        }
        else if (ganador1) {
            system("cls");
            nim();
            tablero();
            marcador();
            gotoxy(6, 17);
            cout << jugador1 << " ha ganado" << endl;
            gotoxy(6, 19);
            cout << "Presione cualquier tecla para una revancha";
            gotoxy(6, 20);
            cout << "Presione 1 para crear nueva partida";
            gotoxy(6, 21);
            cout << "Presione 0 para finalizar el juego";
            gotoxy(6, 23);
            decision = _getch();
            if (decision == '1') {
                replay();
                reset = true;
            }
            else if (decision == '0') {
                juego = 0;
                system("cls");
                break;
            }
            else {
                resetear();
            }
        }
        else if (ganador2) {
            system("cls");
            nim();
            tablero();
            marcador();
            gotoxy(6, 17);
            cout << jugador2 << " ha ganado" << endl;
            gotoxy(6, 19);
            cout << "Presione cualquier tecla para una revancha";
            gotoxy(6, 20);
            cout << "Presione 1 para crear nueva partida";
            gotoxy(6, 21);
            cout << "Presione 0 para finalizar el juego";
            gotoxy(6, 23);
            decision = _getch();
            if (decision == '1') {
                replay();
                reset = true;
            }
            else if (decision == '0') {
                juego = 0;
                system("cls");
                break;
            }
            else{
                resetear();
            }
        }
        else if (empate) {
            system("cls");
            nim();
            tablero();
            marcador();
            gotoxy(6, 17);
            cout << "E M P A T E" << endl;
            gotoxy(6, 19);
            cout << "Presione cualquier tecla para una revancha";
            gotoxy(6, 20);
            cout << "Presione 1 para crear nueva partida";
            gotoxy(6, 21);
            cout << "Presione 0 para finalizar el juego";
            gotoxy(6, 23);
            decision = _getch();
            if (decision == '1') {
                replay();
                reset = true;
            }
            else if (decision == '0') {
                juego = 0;
                system("cls");
                break;
            }
            else {
                resetear();
            }
        }

        //While para repetir el programa hasta que no haya fichas por jugar en las filas
        while ((fila1 || fila2 || fila3) && reset == false) {
            system("cls");
            tablero();
            fichas();
            marcador();
            gotoxy(25, 4);
            cout << "N I M";
            //Determinando de quién es el turno
            string jugadorActual = (turno % 2 == 0 ? jugador2 : jugador1);
            gotoxy(6, 17);
            cout << "Es el turno de " << jugadorActual << "." << endl;

            //  jugador selecciona una fila y retira objetos
            int filaSeleccionada, objetosRetirados;
            gotoxy(6, 19);
            cout << "Seleccione una fila (1, 2 o 3): ";
            cin >> filaSeleccionada;
            if ((filaSeleccionada == 1 && fila1) || (filaSeleccionada == 2 && fila2) || (filaSeleccionada == 3 && fila3)) {
                gotoxy(6, 21);
                cout << "Numero de fichas a retirar: ";
                cin >> objetosRetirados;
                if (filaSeleccionada == 1) {
                    if (objetosRetirados > 0 && objetosRetirados <= fichas1) {
                        //Retira fichas del tablero
                        fichas1 -= objetosRetirados;
                        if (fichas1 == 0){
                            fila1 = false;
                        }
                        ganador();
                        turno++;
                        if (bandera == 1) {
                            if (ganador1)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << jugador1 << " ha ganado" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            if (ganador2)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << jugador2 << " ha ganado" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            if (empate)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << "E M P A T E" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            break;
                        }
                    }
                }
                else if (filaSeleccionada == 2) {
                    if (objetosRetirados > 0 && objetosRetirados <= fichas2) {
                        //Retira fichas del tablero
                        fichas2 -= objetosRetirados;
                        if (fichas2 == 0) {
                            fila2 = false;
                        }
                        ganador();
                        turno++;
                        if (bandera == 1) {
                            if (ganador1)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << jugador1 << " ha ganado" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            if (ganador2)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << jugador2 << " ha ganado" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            if (empate)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << "E M P A T E" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            break;
                        }
                    }
                }
                else if (filaSeleccionada == 3) {
                    if (objetosRetirados > 0 && objetosRetirados <= fichas3) {
                        //Retira fichas del tablero
                        fichas3 -= objetosRetirados;
                        if (fichas3 == 0){
                            fila3 = false;
                        }
                        ganador();
                        turno++;
                        if (bandera == 1) {
                            if (ganador1)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << jugador1 << " ha ganado" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            if (ganador2)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << jugador2 << " ha ganado" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            if (empate)
                            {
                                system("cls");
                                tablero();
                                fichas();
                                marcador();
                                gotoxy(25, 4);
                                cout << "N I M";
                                gotoxy(6, 17);
                                cout << "E M P A T E" << endl;
                                gotoxy(6, 19);
                                system("pause");
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}