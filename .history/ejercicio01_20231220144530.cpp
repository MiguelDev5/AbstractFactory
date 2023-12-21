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
        return "Papa Rellena";
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
class Chicharrones : public PlatoPrincipal {
public:
    string serve() const override {
        return "Chicharrones";
    }
};

// Concrete Product B2
class CuyChactao : public PlatoPrincipal {
public:
    string serve() const override {
        return "CuyChactao";
    }
};

// Abstract Factory
class CocinaFactory {
public:
    virtual unique_ptr<Aperitivo> crearAperitivo() const = 0;
    virtual unique_ptr<PlatoPrincipal> crearPlatilloPrincipal() const = 0;
    virtual ~CocinaFactory() = default;
};

// Concrete Factory 1
class ItalianCuisineFactory : public CocinaFactory {
public:
    unique_ptr<Aperitivo> crearAperitivo() const override {
        return make_unique<PapaRellena>();
    }

    unique_ptr<PlatoPrincipal> crearPlatilloPrincipal() const override {
        return make_unique<Chicharrones>();
    }
};

// Concrete Factory 2
class MexicanCuisineFactory : public CocinaFactory {
public:
    unique_ptr<Aperitivo> crearAperitivo() const override {
        return make_unique<Tamal>();
    }

    unique_ptr<PlatoPrincipal> crearPlatilloPrincipal() const override {
        return make_unique<CuyChactao>();
    }
};

// Client
class Cook {
public:
    void prepareMeal(const CocinaFactory& CocinaFactory) const {
        auto Aperitivo = CocinaFactory.crearAperitivo();
        auto PlatoPrincipal = CocinaFactory.crearPlatilloPrincipal();

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