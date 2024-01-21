#include<iostream>

using namespace std;

char tablero[3][3];

void construirTablero() {
    
    int x = 0, y = 0;

    for(int i = 0; i < 6; i++) {
        
        for(int j = 0; j < 3; j++) {
            
            if(i < 5 && i % 2 == 1){
                
                cout << "___";

            }else{

                if(i < 5){
                    
                    cout << " " << tablero[x][y] << " ";
                    y++;

                }else{

                    cout << "   ";
                    
                }

            }

            if(j < 2){

                cout << "|";
                
            }
        }

        y = 0;

        if(i % 2 == 0){
            x++;
        }
        
        cout << endl;
        
    }

}

void posiblesMovimientos(){
    cout << "Elige tu proximo movimiento: " << endl;
    /*
    Colocamos un mensaje para darle instrucciones al jugador
    */
    int contador = 0;
    /*
    Creamos un contador para que este se encargue de acomodar los incisos u opciones
    de forma que quede asi
    a [0][0]
    b [0][1]
    etc...
    */
    string opciones = "abcdefghi";
    /*
    Iniciamos un string donde colocaremos las opciones posibles del usuario
    enlistadas por incisos a,b,c,d,e etc...
    */
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << opciones[contador] << ") [" << i << ", " << j << "]";
            /*
            para mostrar en pantalla las posiciones disponibles en el tablero usamos un cout
            en el que estructuramos un mensaje usando nuestro contador de nuestras opciones
            y concatenando asi este mismo con las pociciones de nuestra matriz
            */
            if(tablero[i][j] != NULL){
                cout << " OCUPADO";
                /*
                Es necesario que si una iocion o posicion esta ocupada ya
                no se pueda usar por lo que usaremos este mensaje utilizando la condicional if
                y asi que el juego al comprobar que la posicion es diferente de NUll o que esta llena
                entonces nos dira que esta ocupada
                */
            }
            cout << endl;

            contador++;
            /*
            colocamos contador ++ para poder hacer que cada que se repita el ciclo avanze una posicion
            en nuestras opciones y asi pueda ir mostrando a, b , c, etc...
            */
        }
    }
    /*
    iniciamos el for para poder avanzar en las pociciones que tenemos disponibles
    y asi el programa nos pueda mostrar que opciones tenemos
    */
}
/*
se crea una funcion tipo void para poder colocar un mensaje al jugador 
en el que se le solicite ingresar un movimiento o una jugada en una de las posiciones
que estan disponibles
*/

int main(){

    /*tablero[0][0] = 'X';
    tablero[0][1] = '0';
    tablero[0][2] = 'X';*/
    /*
    Para comprobar que nuestro sistema esta correcto y avisa cuando este tiene un lugar ocupado
    vamos a llenar manualmente algunas casillas y correr el programa a fin de ver el resultado esperadon en pantalla
    */
    posiblesMovimientos();
    construirTablero();
    
    return 0;
}
