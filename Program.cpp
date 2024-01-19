#include<iostream>

using namespace std;

char tablero[3][3];

int x = 0, y = 0;
/*
Creamos las variables "X" y "Y" de tipo entero para ser utilizadas
en las pociciones de nuestra matriz
*/

void construirTablero() {
    
    for(int i = 0; i < 5; i++) {
        
        for(int j = 0; j < 3; j++) {
            
            if(i < 5 && i % 2 == 1){
                cout << "___";

            }else{
                if(i < 5){
                    cout << " " << tablero[x][y] << " ";
                    /*
                    Ahora sustituimos los "0" dentro de nuestros "[]" por "x,y"
                    para que podamos nosotros llenarlo manualmente
                    */
                   y++;
                   /*
                   Ahora aqui desplazamos a "Y" una pocicion hacia abajo
                   pero esto nos desplasa a la posicion [1][3] de la matriz esto
                   lo solucionamos en la linea de codigo 48 para que inicie en la pocicion [1][0]
                   */
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
            /*
            Colocamos una condicional que hace que cuando x se desplace sea solo
            si es impar la pocicion en la que se desplaza osea una ves que llegue a la tercer posicion 
            */ 
        }
        /*
        para poder hacer que inicie a imprimir en la siguiente posicion
        de la linea siguiente vamos a resetear o reiniciar a "y" en la posicion 0 pero
        a "x" le vamos a desplazar una pocicion paara que este abanze hacia abajo en el tablero
        */
        cout << endl;
        
    }

}

int main(){

    tablero[0][0] = 'a';
    tablero[0][1] = 'b';
    tablero[0][2] = 'c';
    tablero[1][0] = 'd';
    tablero[1][1] = 'e';
    tablero[1][2] = 'f';
    tablero[2][0] = 'g';
    tablero[2][1] = 'h';
    tablero[2][2] = 'i';
    /*
    Para provar que se esta llenando correctamente todo el tablero 
    hacemos uso de un llenado manual preestabecido de la matriz
    tal y como se puede apreciar
    */
    construirTablero();
    
    return 0;
}
