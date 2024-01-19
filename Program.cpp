#include<iostream>

using namespace std;

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
                cout << "   ";
                /*
                con esto podemos sustituir el "_" y asi no se crear el error de sinaxtis
                en el que quedarias "||" juntos y asi se mostraria como " | | " al llegar a la tercer linea
                */
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

    construirTablero();
    
    return 0;
}
