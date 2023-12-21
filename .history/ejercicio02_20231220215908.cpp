#include <iostream>
#include <string>
using namespace std;

class CheckBox {
public:
    virtual void draw() = 0;
    virtual ~CheckBox() = default;
};

class WindowsCheckBox : public CheckBox {
public:
    void draw() override {
        cout << "Dibujando el CheckBox dewindows" << endl;
    }
};

// Concrete Product A2: MacCheckBox
class MacCheckBox : public CheckBox {
public:
    void draw() override {
        cout << "Drawing Mac CheckBox" << endl;
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
        cout << "Drawing Windows Button" << endl;
    }
};

// Concrete Product B2: MacButton
class MacButton : public Button {
public:
    void draw() override {
        cout << "Drawing Mac Button" << endl;
    }
};

// Abstract Factory
class GUIFactory {
public:
    virtual CheckBox* createCheckBox() = 0;
    virtual Button* createButton() = 0;
    virtual ~GUIFactory() = default;
};

// Concrete Factory 1: WindowsFactory
class WindowsFactory : public GUIFactory {
public:
    CheckBox* createCheckBox() override {
        return new WindowsCheckBox();
    }

    Button* createButton() override {
        return new WindowsButton();
    }
};

// Concrete Factory 2: MacFactory
class MacFactory : public GUIFactory {
public:
    CheckBox* createCheckBox() override {
        return new MacCheckBox();
    }

    Button* createButton() override {
        return new MacButton();
    }
};

// Concrete Factory 3: LinuxFactory
class LinuxFactory : public GUIFactory {
public:
    CheckBox* createCheckBox() override {
        // In Linux, we may have a different type of CheckBox
        cout << "Drawing Linux CheckBox" << endl;
        return nullptr;
    }

    Button* createButton() override {
        // In Linux, we may have a different type of Button
        cout << "Drawing Linux Button" << endl;
        return nullptr;
    }
};

// Client Code
void createUI(GUIFactory* factory) {
    CheckBox* checkBox = factory->createCheckBox();
    Button* button = factory->createButton();

    checkBox->draw();
    button->draw();

    delete checkBox;
    delete button;
}

int main() {
    GUIFactory* windowsFactory = new WindowsFactory();
    GUIFactory* macFactory = new MacFactory();
    GUIFactory* linuxFactory = new LinuxFactory();

    cout << "Creating UI for Windows:" << endl;
    createUI(windowsFactory);

    cout << "\nCreating UI for Mac:" << endl;
    createUI(macFactory);

    cout << "\nCreating UI for Linux:" << endl;
    createUI(linuxFactory);

    delete windowsFactory;
    delete macFactory;
    delete linuxFactory;

    return 0;
}
