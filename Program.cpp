#include<iostream>

using namespace std;

char tablero[3][3];
/*
Para colocar los caracteres de X y O que serian nuestras fichas del tablero debemos
diseñar esta matriz que nos permitga almacenar esos caracteres y poder llamarlos
cuando se requiera imprimir en pantalla una ficha dentro de nuestro tablero
*/

void construirTablero() {
    
    for(int i = 0; i < 5; i++) {
        //el primer for es para el eje "x"

        for(int j = 0; j < 3; j++) {
            //este segundo es para el eje "y"

            
            if(i < 5 && i % 2 == 1){
                /*
                Colocamos la condicion i<5 para poder hacer que no se pinten mas "_"
                de los que deberia y a la ves que pueda tener espacio para poner
                los caracteres "X" y "O" sin que se borre o encime en los lugares
                que ocupan los caracteres que conforman nuestro tablero del juego
                */
                cout << "___";
                /*creamos esta funcion para que cuando nuestro constructor llegue
                a la linea 3 ya no imprima el "_" y asi que de bien formado nuestro
                tablero y usamos un else para reemplazar ese espacio vacio
                */

            }else{
                if(i < 5){
                    cout << " " << tablero[0][0] << " ";
                /*
                Ahora modificamos esta seccion agregando un if y dentro de este nuestra mariz para poder hacer que
                nuestros caracteres X y O se impriman dentro de nuestro tablero, para esto
                eliminamos dos espacios de los tres que ya tenia nuestro cout y agregamos lo siguiente
                a la linea de codigo " << tablero[0][0] << " "; "
                */
                }else{
                    cout << "   ";
                    /*
                    Condicionamos el proceso para evitar que al final del tablero se coloquen
                    dos veces los caracteres X y O
                    */
                }

            }

            if(j < 2){

                cout << "|";
                /*
                Para que no quede nuestro tablero finalizando siempre con "_|"
                haremos uso de este otro if que verifica que si estamos en la tercer posicion solo imprima "_"
                en lugar de imprimer "_|"
                */
            }
        }
        
        cout << endl;
        //esto es para dar saltos de linea y asi contruya nuestro "tablero"
    }

}

int main(){

    tablero[0][0] = 'X';
    /*
    Ahora para poder provar que en nuestro tablero se imprime correctamente 
    los caracteres X y O
    */
    construirTablero();
    
    return 0;
}
