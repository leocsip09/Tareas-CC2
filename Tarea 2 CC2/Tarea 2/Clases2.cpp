# include <iostream>
using namespace std;

class Personaje {
    private:
        string nombre, especie, genero;
        int edad;
        bool poderes, ficticio;
    public:
        void setEdad(int e){edad = e;}
        void setNombre(string nom){nombre = nom;}
        void setEspecie(string esp){especie = esp;}
        void setGenero(string gen){genero = gen;}
        void setPoderes(bool pod){poderes = pod;}
        void setRealidad(bool fic){ficticio = fic;}
        int getEdad(){return edad;}
        string getNombre(){return nombre;}
        string getEspecie(){return especie;}
        string getGenero(){return genero;}
        string getPoderes(){
            string f = "Falso";
            string v = "Verdadero";
            if (poderes == 0){
                return f;
            }else{
                return v;}}
        string getRealidad(){
            string f = "Falso";
            string v = "Verdadero";
            if (ficticio == 0){
                return f;
            }else{
                return v;}
        }
};


class DynamicArrayPersonajes {
    private:
        int tamaño;
        Personaje *personajes;

        void redi(int &tamaño, int n){
            tamaño += n;
            Personaje *arrPer = new Personaje[tamaño];
            for (int i = 0; i < tamaño; i++){
                arrPer[i] = personajes[i];
            }
            delete[] personajes;
            personajes = arrPer;
        }
    public:

        DynamicArrayPersonajes(){
            this -> tamaño = 0;
            this -> personajes = new Personaje[0];
        }

        DynamicArrayPersonajes(Personaje arr[], int tam){
            this -> tamaño = tam;
            this -> personajes = new Personaje[tamaño];
            for (int i = 0; i < tamaño; i++){
                personajes[i] = arr[i];
            }
        }

        void PushBack(Personaje per){
            redi(tamaño, 1);
            personajes[tamaño-1] = per;
        }

        void remover(int pos){
            if(pos >= 0 && pos < tamaño){
                for(int i = pos; i < tamaño; i++){
                    personajes[i] = personajes[i+1];
                }
            }
            redi(tamaño, -1);
        }

        void insert(Personaje per, int pos){
            redi(tamaño, 1);
            for(int i = tamaño-1; i > pos; i--){
                personajes[i] = personajes[i-1];
            }
            personajes[pos] = per;
        }

        void imprimirTodo(){ //Use para mostrar todos los datos de todos los personajes a la vez
            for(int i = 0; i < tamaño; i++){
                cout << "Personaje " << i+1 << ":" << endl;
                cout << "Nombre: " << personajes[i].getNombre() << endl;
                cout << "Edad: " << personajes[i].getEdad() << endl;
                cout << "Género: " << personajes[i].getGenero() << endl;
                cout << "Especie: " << personajes[i].getEspecie() << endl;
                cout << "¿Es real?: " << personajes[i].getRealidad() << endl;
                cout << "Poderes: " << personajes[i].getPoderes() << endl << endl;
            }
        }

        // Use para mostrar los datos de solo un personaje, especificar posición
        void imprimirDatosPersonaje(int pos){ 
            cout << "Nombre: " << personajes[pos].getNombre() << endl;
            cout << "Edad: " << personajes[pos].getEdad() << endl;
            cout << "Género: " << personajes[pos].getGenero() << endl;
            cout << "Especie: " << personajes[pos].getEspecie() << endl;
            cout << "¿Es real?: " << personajes[pos].getRealidad() << endl;
            cout << "Poderes: " << personajes[pos].getPoderes() << endl << endl;
        }

};

int main(){

    Personaje p1, p2, p3;

    p1.setNombre("Goku");
    p1.setEdad(30);
    p1.setEspecie("Saiyajin");
    p1.setGenero("Masculino");
    p1.setPoderes(true);
    p1.setRealidad(false);

    p2.setNombre("María");
    p2.setEdad(78);
    p2.setEspecie("Humano");
    p2.setGenero("Femenino");
    p2.setPoderes(false);
    p2.setRealidad(true);

    p3.setNombre("Steve");
    p3.setEdad(25);
    p3.setEspecie("Humano");
    p3.setGenero("Masculino");
    p3.setPoderes(false);
    p3.setRealidad(false);

    Personaje arr[] = {p1, p2, p3};
    DynamicArrayPersonajes persArr(arr, 3);

    cout << endl << "Vamos a mostrar el arreglo original: " << endl;
    persArr.imprimirTodo();

    cout << endl << "Podemos agregar un personaje nuevo al final con el método pushBack: ";
    Personaje p4;
    string nombre, especie, genero;
    int edad;
    bool poderes, real;
    cout << "Ingrese datos para su nuevo personaje en el siguiente orden: " << endl;
    cout << "Nombre, edad, especie, género, ¿Tiene poderes? (bool 0 o 1), ¿Es real? (bool 0 o 1)" << endl;
    cin >> nombre >> edad >> especie >> genero >> poderes >> real;
    p4.setNombre(nombre);
    p4.setEdad(edad);
    p4.setEspecie(especie);
    p4.setGenero(genero);
    p4.setPoderes(poderes);
    p4.setRealidad(real);
    persArr.PushBack(p4);
    cout << endl << "Ahora el arreglo queda así: " << endl;
    persArr.imprimirTodo();

    cout << endl << "También podemos quitar un personaje nuevo con el método remover: " << endl;
    cout << "Ingrese la posición del personaje que desea retirar del arreglo: ";
    int pos;
    cin >> pos;
    persArr.remover(pos-1);
    cout << "Ahora el arreglo queda así: " << endl;
    persArr.imprimirTodo();

    cout << endl << "Finalmente, también podemos insertar un personaje con el método insert: ";
    Personaje p5;
    cout << "Ingrese datos para su nuevo personaje en el siguiente orden: " << endl;
    cout << "Nombre, edad, especie, género, ¿Tiene poderes? (bool 0 o 1), ¿Es real? (bool 0 o 1)" << endl;
    cin >> nombre >> edad >> especie >> genero >> poderes >> real;
    p5.setNombre(nombre);
    p5.setEdad(edad);
    p5.setEspecie(especie);
    p5.setGenero(genero);
    p5.setPoderes(poderes);
    p5.setRealidad(real);
    cout << endl << "Ingrese la posición en la que desea insertar su personaje: ";
    cin >> pos;
    persArr.insert(p5, pos-1);
    cout << "Ahora el arreglo queda así: " << endl;
    persArr.imprimirTodo();

    return 0;
}