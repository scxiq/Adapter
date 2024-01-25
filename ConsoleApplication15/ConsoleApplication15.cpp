#include <iostream>

// Старий інтерфейс, який потрібно адаптувати
class OldInterface {
public:
    virtual void oldMethod() const {
        std::cout << "Old Method\n";
    }
};

// Новий інтерфейс, який очікує клас Client
class NewInterface {
public:
    virtual void newMethod() const {
        std::cout << "New Method\n";
    }
};

// Адаптер, який забезпечує взаємодію між OldInterface та NewInterface
class Adapter : public NewInterface, private OldInterface {
public:
    void newMethod() const override {
        oldMethod(); // Викликаємо старий метод через адаптер
    }
};

// Клас, який використовує NewInterface
class Client {
public:
    void useInterface(const NewInterface& interface) const {
        interface.newMethod();
    }
};

int main() {
    // Використання адаптера для взаємодії старого інтерфейсу з новим інтерфейсом
    Adapter adapter;
    Client client;

    // Використання нового інтерфейсу через адаптер
    client.useInterface(adapter);

    return 0;
}
