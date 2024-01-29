#include <iostream>
#include <conio.h>
/*Agregamos nuestra libreria conio.h para poder hacer uso correcto de las nuevas funciones*/

using namespace std;

char tablero[3][3];
int turno = 0;
string jugador1 = "Player 1";
string jugador2 = "Player 2";
/*Creamos los nombres de los jugadore,
para este caso vamos a ingresar nombres predeterminados*/

void construirTablero() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";
            if(j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if(i < 2) {
            cout << "-----------" << endl;
        }
    }
}
/*Modificamos la funcion tipo void para poder hacer que el tablero se contruya correctamente
sin errores como aparecia en el tutorial ya que anteriormente el tablero se imprimia deformado a partir de la 4ta linea
de impresion en la 4ta linea de la terminal*/

void actualizarTurno(int x, int y) {
    if (turno % 2 == 0) {
        tablero[x][y] = 'X';
    } else {
        tablero[x][y] = 'O';
    }
    turno++;
}
/*CREAMOS ESTA FUNCION PARA QUE EL PROGRAMA SEA CAPAS DE VERIFICAR SI YA ESTA OCUPADA UNA DE LAS
POSICIONES DEL TABLERO DE FORMA AUTOMATICA CADA VES QUE SE INGRESA UNA NUEVA JUGADA O UN NUEVO MOVIMIENTO*/

char posiblesJugadas() {
    cout << "OPCIONES DE JUEGO:" << endl;
    int contador = 0;
    
    string opciones = "abcdefghi";
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << opciones[contador] << ") [" << i << ", " << j << "]";
            
            if(tablero[i][j] != '\0') {
                cout << " OCUPADO";
            }

            cout << endl;
            contador++;
        }
    }
    
    char jugada;
    cout << "Elige una jugada: ";
    /*agregadmos este mensaje a nuestras instrucciones para escoger un movimiento o jugada*/
    jugada = getch();
    /*creamos un getch para poder ingresar la opcion jugada al sistema*/
    return jugada;
}
/*Modificamos el tipo de funcion void por un tipo char y colocamos la funcion getch();
para poder hacer que se incerte automaticamente la opcion apenas el jugador precione la opcion deseada*/

int verificarJugada(char jugada) {
    if(jugada >= 'a' && jugada <= 'i') {
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
            /*Se corrigieron las comparaciones de ocupación del tablero en verificarJugada.*/
        }
        /*este switch nos verifica que cada opcion de nuestro juego se ingrese en la posicion en nuestro tablero
        esto lo repetimos en cada caso pero para cada opcion a,b,c,d,e, etc.*/
        if(tablero[fila][columna] == '\0') {
            /*Se cambió la comparación de NULL a '\0' para verificar si una posición está vacía debido a que null puede generar
            errores al querer compilar.*/
            actualizarTurno(fila, columna);
            return 1;
        }
        /*este otro if una ves que se a creado una nueva jugada y verificado su ingreso verifica que esta no este ocupada
        haciendo uso de la funcion creada previamente "actualizarTurno" */
    }
    return 0;
}

int main() {

    /*Eliminamos las posiciones predeterminadas que tenia el tablero
    para poder ingresarlas manualmente*/

    construirTablero();
    /*llamamos primero a nuestra funcion construir tablero para poder mostrarlo al jugador*/

    char jugada = posiblesJugadas();
    cout << endl << jugada << endl;
    /*ahora llamamos a la funcionn posibles jugadas para mostrarle al
    jugador cuales son las opciones que tiene disponibles para posteriormente imprimmirla en pantalla*/

    if(verificarJugada(jugada)) {
        construirTablero();
        /*Una ves recibida la jugada verificamos que esta no se haya utilizado aun para ello
        vamos a utilizar un if que verifica y si no esta ocupado mediante la llamada de nuestra funcion
        "verificarJugada" que evalua nuestra variable jugada y si esta esta vacia imprimira el tablero actualizado
        con la nueva jugada ya en el mismo*/
    } else {
        cout << "Posición ocupada. Intenta de nuevo." << endl;
        /*En el caso de que un jugador seleccione una opcion que no este disponible
        y para que los usuarios sepan que la posicion esta ocupada
        se agregó un mensaje para informar al jugador si la posición está ocupada.*/
    }

    return 0;
}