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
class PapaRellena : public Aperitivo {
public:
    string serve() const override {
        return "PapaRellena";
    }
};

// Concrete Product A2
class Tamal : public Aperitivo {
public:
    string serve() const override {
        return "Tamal";
    }
};

// Abstract Product B
class PlatoPrincipal {
public:
    virtual string serve() const = 0;
    virtual ~PlatoPrincipal() = default;
};

// Concrete Product B1
class PastaCarbonara : public PlatoPrincipal {
public:
    string serve() const override {
        return "Pasta Carbonara";
    }
};

// Concrete Product B2
class ChickenCurry : public PlatoPrincipal {
public:
    string serve() const override {
        return "Chicken Curry";
    }
};

// Abstract Factory
class CuisineFactory {
public:
    virtual unique_ptr<Aperitivo> createAppetizer() const = 0;
    virtual unique_ptr<PlatoPrincipal> createMainCourse() const = 0;
    virtual ~CuisineFactory() = default;
};

// Concrete Factory 1
class ItalianCuisineFactory : public CuisineFactory {
public:
    unique_ptr<Aperitivo> createAppetizer() const override {
        return make_unique<PapaRellena>();
    }

    unique_ptr<PlatoPrincipal> createMainCourse() const override {
        return make_unique<PastaCarbonara>();
    }
};

// Concrete Factory 2
class MexicanCuisineFactory : public CuisineFactory {
public:
    unique_ptr<Aperitivo> createAppetizer() const override {
        return make_unique<Tamal>();
    }

    unique_ptr<PlatoPrincipal> createMainCourse() const override {
        return make_unique<ChickenCurry>();
    }
};

// Client
class Cook {
public:
    void prepareMeal(const CuisineFactory& cuisineFactory) const {
        auto Aperitivo = cuisineFactory.createAppetizer();
        auto PlatoPrincipal = cuisineFactory.createMainCourse();

        cout << "Aperitivo: " << Aperitivo->serve() << endl;
        cout << "Main Course: " << PlatoPrincipal->serve() << endl;
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