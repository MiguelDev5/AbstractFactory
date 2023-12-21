#include <iostream>
#include <memory>

// Abstract Product A
class Appetizer {
public:
    virtual std::string serve() const = 0;
    virtual ~Appetizer() = default;
};

// Concrete Product A1
class Bruschetta : public Appetizer {
public:
    std::string serve() const override {
        return "Bruschetta";
    }
};

// Concrete Product A2
class Guacamole : public Appetizer {
public:
    std::string serve() const override {
        return "Guacamole";
    }
};

// Abstract Product B
class MainCourse {
public:
    virtual std::string serve() const = 0;
    virtual ~MainCourse() = default;
};

// Concrete Product B1
class PastaCarbonara : public MainCourse {
public:
    std::string serve() const override {
        return "Pasta Carbonara";
    }
};

// Concrete Product B2
class ChickenCurry : public MainCourse {
public:
    std::string serve() const override {
        return "Chicken Curry";
    }
};

// Abstract Factory
class CuisineFactory {
public:
    virtual std::unique_ptr<Appetizer> createAppetizer() const = 0;
    virtual std::unique_ptr<MainCourse> createMainCourse() const = 0;
    virtual ~CuisineFactory() = default;
};

// Concrete Factory 1
class ItalianCuisineFactory : public CuisineFactory {
public:
    std::unique_ptr<Appetizer> createAppetizer() const override {
        return std::make_unique<Bruschetta>();
    }

    std::unique_ptr<MainCourse> createMainCourse() const override {
        return std::make_unique<PastaCarbonara>();
    }
};

// Concrete Factory 2
class MexicanCuisineFactory : public CuisineFactory {
public:
    std::unique_ptr<Appetizer> createAppetizer() const override {
        return std::make_unique<Guacamole>();
    }

    std::unique_ptr<MainCourse> createMainCourse() const override {
        return std::make_unique<ChickenCurry>();
    }
};

// Client
class Cook {
public:
    void prepareMeal(const CuisineFactory& cuisineFactory) const {
        auto appetizer = cuisineFactory.createAppetizer();
        auto mainCourse = cuisineFactory.createMainCourse();

        std::cout << "Appetizer: " << appetizer->serve() << std::endl;
        std::cout << "Main Course: " << mainCourse->serve() << std::endl;
    }
};

// Usage
int main() {
    ItalianCuisineFactory italianFactory;
    MexicanCuisineFactory mexicanFactory;

    Cook cook;

    std::cout << "Italian Cuisine:" << std::endl;
    cook.prepareMeal(italianFactory);

    std::cout << "\nMexican Cuisine:" << std::endl;
    cook.prepareMeal(mexicanFactory);

    return 0;
}