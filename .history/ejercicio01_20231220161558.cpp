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
    virtual void cook() = 0;
    virtual void plate() = 0;
    virtual void serve() = 0;
    virtual void showRecipe() = 0;
};

class ItalianPasta : public Receta {
public:
    void prepararIngredientes() { ingredientes = "Pasta, Tomato Sauce, Parmesan Cheese"; };
    void cook() { instrucciones = "Boil pasta, heat tomato sauce, mix and add Parmesan cheese"; };
    void plate() { cout << "Plating Italian Pasta" << endl; };
    void serve() { cout << "Serving Italian Pasta" << endl; };
    void showRecipe() {
        cout << "nombre: " << nombre << endl
             << "cocina: " << cocina << endl
             << "ingredientes: " << ingredientes << endl
             << "instrucciones: " << instrucciones << endl;
    }
};

class MexicanTacos : public Receta {
public:
    void prepararIngredientes() { ingredientes = "Tortillas, Ground Beef, Lettuce, Tomatoes, Cheese, Salsa"; };
    void cook() { instrucciones = "Cook ground beef, assemble tacos with ingredientes"; };
    void plate() { cout << "Plating Mexican Tacos" << endl; };
    void serve() { cout << "Serving Mexican Tacos" << endl; };
    void showRecipe() {
        cout << "nombre: " << nombre << endl
             << "cocina: " << cocina << endl
             << "ingredientes: " << ingredientes << endl
             << "instrucciones: " << instrucciones << endl;
    }
};

class AsianStirFry : public Receta {
public:
    void prepararIngredientes() { ingredientes = "Chicken, Vegetables, Soy Sauce, Ginger, Garlic"; };
    void cook() { instrucciones = "Stir-fry chicken and vegetables, add soy sauce, ginger, and garlic"; };
    void plate() { cout << "Plating Asian Stir-Fry" << endl; };
    void serve() { cout << "Serving Asian Stir-Fry" << endl; };
    void showRecipe() {
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
                Receta = new ItalianPasta;
                break;
            }
            case 2: {
                Receta = new MexicanTacos;
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
        Receta->cook();
        Receta->plate();
        Receta->serve();
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
            r->showRecipe();
            delete r;
        }
    }
    cout << "Exiting..." << endl;
    return 0;
}