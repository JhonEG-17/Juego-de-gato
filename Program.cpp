#include <iostream>
#include <conio.h>

using namespace std;

char tablero[3][3];
int turno = 0;
string jugador1 = "Player 1";
string jugador2 = "Player 2";

void construirTablero() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "-----------" << endl;
        }
    }
}

void actualizarTurno(int x, int y) {
    if (turno % 2 == 0) {
        tablero[x][y] = 'X';
    } else {
        tablero[x][y] = 'O';
    }
    turno++;
}

char posiblesJugadas() {
    cout << "OPCIONES DE JUEGO:" << endl;
    int contador = 0;

    string opciones = "abcdefghi";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << opciones[contador] << ") [" << i << ", " << j << "]";

            if (tablero[i][j] != '\0') {
                cout << " OCUPADO";
            }

            cout << endl;
            contador++;
        }
    }

    char jugada;
    cout << "Elige una jugada: ";
    jugada = getch();

    return jugada;
}

int verificarJugada(char jugada) {
    if (jugada >= 'a' && jugada <= 'i') {
        int fila, columna;
        switch (jugada) {
            case 'a': fila = 0; columna = 0; break;
            case 'b': fila = 0; columna = 1; break;
            case 'c': fila = 0; columna = 2; break;
            case 'd': fila = 1; columna = 0; break;
            case 'e': fila = 1; columna = 1; break;
            case 'f': fila = 1; columna = 2; break;
            case 'g': fila = 2; columna = 0; break;
            case 'h': fila = 2; columna = 1; break;
            case 'i': fila = 2; columna = 2; break;
        }

        if (tablero[fila][columna] == '\0') {
            actualizarTurno(fila, columna);
            return 1;
        }
    }
    return 0;
}

bool hayGanador() {
    /*Verificar filas y columnas*/
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] != '\0' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return true; /*Hay un ganador en la fila i*/
        }
        if (tablero[0][i] != '\0' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return true; /*Hay un ganador en la columna i*/
        }
    }

    /*Verificar diagonales*/
    if (tablero[0][0] != '\0' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return true; /*Hay un ganador en la diagonal principal*/
    }
    if (tablero[0][2] != '\0' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return true; /*Hay un ganador en la diagonal secundaria*/
    }

    return false; /*No hay ganador*/
}
/*Creamos la funcion de tipo booleano que nos evaluara si se cumple 1 de las cuatro posibilidades que es que hay una fila,
una columna, o diagonal izquierda, o diagonal derecha con 3 caradcteres iguales y asi decir que hay un ganador*/

bool tableroLleno() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '\0') {
                return false; /* Todavía hay espacios vacíos en el tablero*/
            }
        }
    }
    return true; /*El tablero está lleno*/
}
/*Esta funcion verifica que no este lleno nuestro tablero para poder jugar en caso contrario mandara la señal de finalizar el juego
junto con nuestro mensaje 2 dentro del if-else localizado en nuestro int main()*/
int main() {
    
    construirTablero();

    while (!hayGanador() && !tableroLleno()) {
        
        char jugada = posiblesJugadas();
        cout << endl << jugada << endl;

        if (verificarJugada(jugada)) {
            construirTablero();
        } else {
            cout << "Posición ocupada. Intenta de nuevo." << endl;
        }
    }
    /*creamos un while que nos permite repertir un ciclo para que el jugador mientras el tablero
        tenga espacios vacios pueda seguir ingresando jugadas y si este ya se lleno el juego termine o en caso
        de que haya un ganador este tambien termine*/
    
    if (hayGanador()) {
    
        cout << "¡Tenemos un ganador!" << endl;
        /*mensaje 1*/

    } else {

        cout << "El juego ha terminado en empate." << endl;
        /*mensaje 2*/

    }
    /*creamos un if-else en el que evaluamos si hay un ganador el juego mostrara un mensaje que indicara si hay ganador o fuen un empate*/
    return 0;
}