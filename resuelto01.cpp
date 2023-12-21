#include <iostream>
#include <string>
using namespace std;

class Toy {
protected:
    string name;
    float price;
public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;
};

class Car: public Toy {
public:
    void prepareParts() { cout << "Preparando partes de Car" << endl;   };
    void combineParts() { cout << "Combinando partes de Car" << endl; };
    void assembleParts() { cout << "ensamblando partes de Car" << endl; };
    void applyLabel() { cout << "aplicando etiquetado de Car" << endl; };
    void showProduct() { cout << "Name: " << name << endl << "Price: " << price << endl; };
};

class Bike : public Toy {
public:
    void prepareParts() { cout << "Preparando partes de Bike" << endl; };
    void combineParts() { cout << "Combinando partes de Bike" << endl; };
    void assembleParts() { cout << "ensamblando partes de Bike" << endl; };
    void applyLabel() { cout << "aplicando etiquetado de Bike" << endl; };
    void showProduct() { cout << "Name: " << name << endl << "Price: " << price << endl; };
};

class Plane : public Toy {
public:
    void prepareParts() { cout << "Preparando partes de Plane" << endl; };
    void combineParts() { cout << "Combinando partes de Plane" << endl; };
    void assembleParts() { cout << "ensamblando partes de Plane" << endl; };
    void applyLabel() { cout << "aplicando etiquetado de Plane" << endl; };
    void showProduct() { cout << "Name: " << name << endl << "Price: " << price << endl; };
};

class ToyFactory {
public:
    static Toy * createToy(int type) {
        Toy * toy = NULL;
        switch (type) {
            case 1: {
                toy = new Car;
                break;
            }
            case 2: {
                toy = new Bike;
                break;
            }
            case 3: {
                toy = new Plane;
                break;
            }
            default: {
                cout << "invalido TOY type, ingresa otra opcion" << endl;
                return NULL;
            }
        }
        toy -> prepareParts();
        toy -> combineParts();
        toy -> assembleParts();
        toy -> applyLabel();
        return toy;
    }
};

int main() {
    int type;
    while (1) {
        cout << endl << "Ingresa un tipo (1 a 3) o '0' para salir" << endl;
        cin >> type;
        if (!type) {
            break;
        }
        Toy * v = ToyFactory::createToy(type);
        if (v) {
            v -> showProduct();
            delete v;
        }
    }
    cout << "Saliendo..." << endl;
    return 0;
}