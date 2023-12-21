#include <iostream>
#include <string>
using namespace std;

class Recipe {
protected:
    string name;
    string cuisine;
    string ingredients;
    string instructions;
public:
    virtual void prepareIngredients() = 0;
    virtual void cook() = 0;
    virtual void plate() = 0;
    virtual void serve() = 0;
    virtual void showRecipe() = 0;
};

class ItalianPasta : public Recipe {
public:
    void prepareIngredients() { ingredients = "Pasta, Tomato Sauce, Parmesan Cheese"; };
    void cook() { instructions = "Boil pasta, heat tomato sauce, mix and add Parmesan cheese"; };
    void plate() { cout << "Plating Italian Pasta" << endl; };
    void serve() { cout << "Serving Italian Pasta" << endl; };
    void showRecipe() {
        cout << "Name: " << name << endl
             << "Cuisine: " << cuisine << endl
             << "Ingredients: " << ingredients << endl
             << "Instructions: " << instructions << endl;
    }
};

class MexicanTacos : public Recipe {
public:
    void prepareIngredients() { ingredients = "Tortillas, Ground Beef, Lettuce, Tomatoes, Cheese, Salsa"; };
    void cook() { instructions = "Cook ground beef, assemble tacos with ingredients"; };
    void plate() { cout << "Plating Mexican Tacos" << endl; };
    void serve() { cout << "Serving Mexican Tacos" << endl; };
    void showRecipe() {
        cout << "Name: " << name << endl
             << "Cuisine: " << cuisine << endl
             << "Ingredients: " << ingredients << endl
             << "Instructions: " << instructions << endl;
    }
};

class AsianStirFry : public Recipe {
public:
    void prepareIngredients() { ingredients = "Chicken, Vegetables, Soy Sauce, Ginger, Garlic"; };
    void cook() { instructions = "Stir-fry chicken and vegetables, add soy sauce, ginger, and garlic"; };
    void plate() { cout << "Plating Asian Stir-Fry" << endl; };
    void serve() { cout << "Serving Asian Stir-Fry" << endl; };
    void showRecipe() {
        cout << "Name: " << name << endl
             << "Cuisine: " << cuisine << endl
             << "Ingredients: " << ingredients << endl
             << "Instructions: " << instructions << endl;
    }
};

class RecipeFactory {
public:
    static Recipe* createRecipe(int type) {
        Recipe* recipe = nullptr;
        switch (type) {
            case 1: {
                recipe = new ItalianPasta;
                break;
            }
            case 2: {
                recipe = new MexicanTacos;
                break;
            }
            case 3: {
                recipe = new AsianStirFry;
                break;
            }
            default: {
                cout << "Invalid recipe type, please enter another option" << endl;
                return nullptr;
            }
        }
        recipe->prepareIngredients();
        recipe->cook();
        recipe->plate();
        recipe->serve();
        return recipe;
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
        Recipe* r = RecipeFactory::createRecipe(type);
        if (r) {
            r->showRecipe();
            delete r;
        }
    }
    cout << "Exiting..." << endl;
    return 0;
}