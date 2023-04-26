# include <iostream>
using namespace std;

class DynamicIntegerArray {
    private:
        int *data;
        int size;
    public:
        DynamicIntegerArray(){
            this -> size = 0;
            this -> data = new int[0];
        }
        DynamicIntegerArray(int arr[], int size){
            this -> size = size;
            this -> data = new int[size];
            for(int i = 0; i < size; i++){
                data[i] = arr[i];
            }
        }
        DynamicIntegerArray(const DynamicIntegerArray &o){
            this -> size = o.size;
            this -> data = new int[o.size];
            for (int i = 0; i < size; i++){
                data[i] = o.data[i];
            }
        }

        void redi(int &size, int n){
            size += n;
            int *arr2 = new int[size];
            for (int i = 0; i < size; i++){
                arr2[i] = data[i];
            }
            
            delete[] data;
            data = arr2;
        }

        void PushBack(int num){
            redi(size, 1);
            data[size-1] = num;
        }

        void remover(int pos){
            
            for (int i = 0; i < size-pos; i++){
                int a = data[pos+i];
                data[pos+i-1] = a;
            }
            redi(size,-1);

        }

        void insert(int n, int pos){
            int a = pos-1;
            redi(size, 1);
            for (int i = size; i > a; i--){
                data[i] = data[i-1];
            }
            data[a] = n;
        }

        int getSize() const{
            return size;
        }

        int get(int pos){
            return data[pos];
        }
        ~DynamicIntegerArray(){
            delete[] data;
        }
};

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    DynamicIntegerArray pa(arr, 5);
    cout << "Tenemos un arreglo original de " <<pa.getSize() << " elementos." << endl;
    for (int i = 0; i < pa.getSize(); i++){
        cout << pa.get(i) << " ";
    }
    cout << endl << endl;

    cout << "Usamos el método PushBack para insertar elementos al final del arreglo: \nIntroduzca valor a agregar: ";
    int val, p;
    cin >> val;
    pa.PushBack(val);
    cout << "Ahora el arreglo queda así: \n";
    for (int i = 0; i<pa.getSize(); i++){
        cout << pa.get(i) << " ";
    }
    cout << endl << endl;

    cout << "Usamos el método remover para eliminar elementos del arreglo: \nIntroduzca la posición para remover (contar posición desde el 1): ";
    cin >> p;
    pa.remover(p);
    for (int i = 0; i<pa.getSize(); i++){
        cout << pa.get(i) << " ";
    }
    cout << endl << endl;
    
    cout << "Usamos el método insert para agregar elementos en el arreglo: \nIntroduzca la posición para insertar (contar posición desde el 1): ";
    cin >> p;
    cout << "Introduzca el valor a agregar: ";
    cin >> val;
    pa.insert(val, p);
    for (int i = 0; i<pa.getSize(); i++){
        cout << pa.get(i) << " ";
    }
    cout << endl;
    return 0;

}