#include <iostream>
#include <string>
using namespace std;

// Abstract Product A: CheckBox
class CheckBox {
public:
    virtual void draw() = 0;
    virtual ~CheckBox() = default;
};

// Concrete Product A1: WindowsCheckBox
class WindowsCheckBox : public CheckBox {
public:
    void draw() override {
        cout << "Dibujando el CheckBox de Windows" << endl;
    }
};

// Concrete Product A2: MacCheckBox
class MacCheckBox : public CheckBox {
public:
    void draw() override {
        cout << "Dibujando el CheckBox de Mac" << endl;
    }
};

// Abstract Product B: Button
class Button {
public:
    virtual void draw() = 0;
    virtual ~Button() = default;
};

// Concrete Product B1: WindowsButton
class WindowsButton : public Button {
public:
    void draw() override {
        cout << "Dibujando el botón de Windows" << endl;
    }
};

// Concrete Product B2: MacButton
class MacButton : public Button {
public:
    void draw() override {
        cout << "Dibujando el botón de Mac" << endl;
    }
};

// Abstract Factory
class GUIFactory {
public:
    virtual CheckBox* crearCheckBox() = 0;
    virtual Button* crearBoton() = 0;
    virtual ~GUIFactory() = default;
};

// Concrete Factory 1: WindowsFactory
class WindowsFactory : public GUIFactory {
public:
    CheckBox* crearCheckBox() override {
        return new WindowsCheckBox();
    }

    Button* crearBoton() override {
        return new WindowsButton();
    }
};

// Concrete Factory 2: MacFactory
class MacFactory : public GUIFactory {
public:
    CheckBox* crearCheckBox() override {
        return new MacCheckBox();
    }

    Button* crearBoton() override {
        return new MacButton();
    }
};

// Concrete Factory 3: LinuxFactory
class LinuxFactory : public GUIFactory {
public:
    CheckBox* crearCheckBox() override {
        // In Linux, we may have a different type of CheckBox
        cout << "Dibujando el checkbox de Linux" << endl;
        return nullptr;
    }

    Button* crearBoton() override {
        // In Linux, we may have a different type of Button
        cout << "Dibujando el botón de Linux" << endl;
        return nullptr;
    }
};

// Client Code
void createUI(GUIFactory* factory) {
    CheckBox* checkBox = factory->crearCheckBox();
    Button* button = factory->crearBoton();

    checkBox->draw();
    button->draw();

    delete checkBox;
    delete button;
}

int main() {
    GUIFactory* windowsFactory = new WindowsFactory();
    GUIFactory* macFactory = new MacFactory();
    GUIFactory* linuxFactory = new LinuxFactory();

    cout << "Creando la interfaz de windows:" << endl;
    createUI(windowsFactory);

    cout << "Creando la interfaz de Mac:" << endl;
    createUI(macFactory);

    cout << "Creando la interfaz de Linux:" << endl;
    createUI(linuxFactory);

    delete windowsFactory;
    delete macFactory;
    delete linuxFactory;

    return 0;
}
