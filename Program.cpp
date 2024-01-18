#include<iostream>

using namespace std;

void construirTablero() {
    
    for(int i = 0; i < 3; i++) {
        //el primer for es para el eje "x"

        for(int j = 0; j < 3; j++) {
            //este segundo es para el eje "y"

            cout << "_|";
            //esto es lo que se imprime de nuestro tablero

        }
        
        cout << endl;
        //esto es para dar saltos de linea y asi contruya nuestro "tablero"
    }

}

int main(){

    construirTablero();
    
    return 0;
}
