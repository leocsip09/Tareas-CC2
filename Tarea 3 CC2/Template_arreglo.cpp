#include <iostream>
using namespace std;

template <class Tipo>
class DynamicArray {
   private:
    int tamaño;
    Tipo *datos;

    void redi(int &tamaño, int n){
        tamaño += n;
        Tipo *Datos2 = new Tipo[tamaño];
        for (int i = 0; i < tamaño; i++){
            Datos2[i] = datos[i];
        }
        delete[] datos;
        datos = Datos2;
    }

   public:
    DynamicArray() {
        this -> tamaño = 0;
        this -> datos = new Tipo[tamaño];
    }

    DynamicArray(Tipo arr[], int tam){
        this -> tamaño = tam;
        this -> datos = new Tipo[tamaño];
        for (int i = 0; i < tamaño; i++){
            datos[i] = arr[i];
        }
    }
    void PushBack(Tipo dat){
        redi(tamaño, 1);
        datos[tamaño-1] = dat;
    }
    void remover(int pos){
        for(int i = pos; i<tamaño; i++){
            datos[i] = datos[i+1];
        }
        redi(tamaño, -1);
    }
    void insert(Tipo dat, int pos){
        redi(tamaño, 1);
        for(int i = tamaño-1; i > pos; i--){
            datos[i] = datos[i-1];
        }
        datos[pos] = dat;
    }
    int get_tam(){
        return tamaño;
    }
    Tipo operator[](int pos) {
        return datos[pos];
    }



};

//Clase Personaje de la anterior tarea:
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
            if (poderes == 0){return f;}
            else{return v;}}
        string getRealidad(){
            string f = "Falso";
            string v = "Verdadero";
            if (ficticio == 0){return f;}
            else{return v;}
        }
        
};

int main() {
    //Para arreglo dinámico de enteros
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    for (int i = 0; i < arr.get_tam(); i++) {
        cout << arr[i] << " \n";
    }
    cout << endl;

    //Para arreglo dinámico de la clase Personaje
    DynamicArray<Personaje> pers;
    Personaje p1, p2, p3, p4; //Solo será el nombre por cuestión de practicidad
    p1.setNombre("Goku");
    p2.setNombre("María");
    p3.setNombre("Steve");
    pers.PushBack(p1);
    pers.PushBack(p2);
    pers.PushBack(p3);
    for (int i = 0; i < pers.get_tam(); i++) {
        cout << pers[i].getNombre() << " \n";
    }

    string nombre;
    cout << "Introduzca nuevo nombre: ";
    cin >> nombre;
    p4.setNombre(nombre);
    pers.insert(p4, 2);
    for (int i = 0; i < pers.get_tam(); i++) {
        cout << pers[i].getNombre() << " \n";
    }
    cout << endl;

    //Para arreglo dinámico de cadenas
    DynamicArray<string> palabras;
    palabras.PushBack("Hola, ");
    palabras.PushBack("¿Cómo ");
    palabras.PushBack("estás?");
    for (int i = 0; i < palabras.get_tam(); i++) {
        cout << palabras[i] << " \n";
    }
    cout << endl;

    return 0;
}