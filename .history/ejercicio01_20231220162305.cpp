#include <iostream>
#include <string>
using namespace std;

class Receta {
protected:
    string nombre;
    string cocina;
    string ingredientes;
    string instrucciones;
public:
    virtual void prepararIngredientes() = 0;
    virtual void cocinar() = 0;
    virtual void plato() = 0;
    virtual void servir() = 0;
    virtual void mostrarReceta() = 0;
};

class RocotoRelleno : public Receta {
public:
    void prepararIngredientes() { ingredientes = "Rocoto, Cebolla, Carno, Queso, Aceituna, Huevo"; };
    void cocinar() { instrucciones = "Cortar las tapitas a los rocotos y retirar las pepas y las venas ..."; };
    void plato() { cout << "Emplatar rocoto relleno" << endl; };
    void servir() { cout << "Servirrocoto relleno" << endl; };
    void mostrarReceta() {
        cout << "nombre: " << nombre << endl
             << "cocina: " << cocina << endl
             << "ingredientes: " << ingredientes << endl
             << "instrucciones: " << instrucciones << endl;
    }
};

class Adobo : public Receta {
public:
    void prepararIngredientes() { ingredientes = "Chicha, Carne de chancho, ajíes, cebolla, rocoto"; };
    void cocinar() { instrucciones = "Empieza adobando las carnes. En un bowl coloca las piezas de cerdo y vierte encima ..."; };
    void plato() { cout << "Emplatar adobo" << endl; };
    void servir() { cout << "Servir adobo" << endl; };
    void mostrarReceta() {
        cout << "nombre: " << nombre << endl
             << "cocina: " << cocina << endl
             << "ingredientes: " << ingredientes << endl
             << "instrucciones: " << instrucciones << endl;
    }
};

class AsianStirFry : public Receta {
public:
    void prepararIngredientes() { ingredientes = "Chicken, Vegetables, Soy Sauce, Ginger, Garlic"; };
    void cocinar() { instrucciones = "Stir-fry chicken and vegetables, add soy sauce, ginger, and garlic"; };
    void plato() { cout << "Plating Asian Stir-Fry" << endl; };
    void servir() { cout << "Serving Asian Stir-Fry" << endl; };
    void mostrarReceta() {
        cout << "nombre: " << nombre << endl
             << "cocina: " << cocina << endl
             << "ingredientes: " << ingredientes << endl
             << "instrucciones: " << instrucciones << endl;
    }
};

class RecipeFactory {
public:
    static Receta* createRecipe(int type) {
        Receta* Receta = nullptr;
        switch (type) {
            case 1: {
                Receta = new RocotoRelleno;
                break;
            }
            case 2: {
                Receta = new Adobo;
                break;
            }
            case 3: {
                Receta = new AsianStirFry;
                break;
            }
            default: {
                cout << "Invalid Receta type, please enter another option" << endl;
                return nullptr;
            }
        }
        Receta->prepararIngredientes();
        Receta->cocinar();
        Receta->plato();
        Receta->servir();
        return Receta;
    }
};

int main() {
    int type;
    while (1) {
        cout << endl << "Enter a type (1 to 3) or '0' to exit" << endl;
        cin >> type;
        if (!type) {
            break;
        }
        Receta* r = RecipeFactory::createRecipe(type);
        if (r) {
            r->mostrarReceta();
            delete r;
        }
    }
    cout << "Exiting..." << endl;
    return 0;
}