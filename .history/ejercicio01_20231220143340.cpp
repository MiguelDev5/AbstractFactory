#include <iostream>
#include <memory>

using namespace std;

// Abstract Product A
class Aperitivo {
public:
    virtual string serve() const = 0;
    virtual ~Aperitivo() = default;
};

// Concrete Product A1
class Bruschetta : public Aperitivo {
public:
    string serve() const override {
        return "Bruschetta";
    }
};

// Concrete Product A2
class Guacamole : public Aperitivo {
public:
    string serve() const override {
        return "Guacamole";
    }
};

// Abstract Product B
class MainCourse {
public:
    virtual string serve() const = 0;
    virtual ~MainCourse() = default;
};

// Concrete Product B1
class PastaCarbonara : public MainCourse {
public:
    string serve() const override {
        return "Pasta Carbonara";
    }
};

// Concrete Product B2
class ChickenCurry : public MainCourse {
public:
    string serve() const override {
        return "Chicken Curry";
    }
};

// Abstract Factory
class CuisineFactory {
public:
    virtual unique_ptr<Aperitivo> createAppetizer() const = 0;
    virtual unique_ptr<MainCourse> createMainCourse() const = 0;
    virtual ~CuisineFactory() = default;
};

// Concrete Factory 1
class ItalianCuisineFactory : public CuisineFactory {
public:
    unique_ptr<Aperitivo> createAppetizer() const override {
        return make_unique<Bruschetta>();
    }

    unique_ptr<MainCourse> createMainCourse() const override {
        return make_unique<PastaCarbonara>();
    }
};

// Concrete Factory 2
class MexicanCuisineFactory : public CuisineFactory {
public:
    unique_ptr<Aperitivo> createAppetizer() const override {
        return make_unique<Guacamole>();
    }

    unique_ptr<MainCourse> createMainCourse() const override {
        return make_unique<ChickenCurry>();
    }
};

// Client
class Cook {
public:
    void prepareMeal(const CuisineFactory& cuisineFactory) const {
        auto Aperitivo = cuisineFactory.createAppetizer();
        auto mainCourse = cuisineFactory.createMainCourse();

        cout << "Aperitivo: " << Aperitivo->serve() << endl;
        cout << "Main Course: " << mainCourse->serve() << endl;
    }
};

// Usage
int main() {
    ItalianCuisineFactory italianFactory;
    MexicanCuisineFactory mexicanFactory;

    Cook cook;

    cout << "Italian Cuisine:" << endl;
    cook.prepareMeal(italianFactory);

    cout << "\nMexican Cuisine:" << endl;
    cook.prepareMeal(mexicanFactory);

    return 0;
}