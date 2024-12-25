#include <iostream>
using namespace std;

class Device {
protected:
    string dimensions;
    double weight;

public:
    Device(string d, double we) : dimensions(d), weight(we) {}

    void device_info() {
        cout << "Dimensions of the device: " << dimensions << endl;
        cout << "Weight of the device: " << weight << "g" << endl;
    }
};

class Phone : virtual public Device {
protected:
    string screen_size;
    double battery_life;

public:
    Phone(string ss, double bl, string dim, double wght)
        : Device(dim, wght), screen_size(ss), battery_life(bl) {}

    void phone_info() {
        cout << "Screen size of Phone: " << screen_size << endl;
        cout << "Battery life of Phone: " << battery_life << " hours" << endl;
    }

    void phone_call() {
        cout << "Phone is making a call" << endl;
    }

    void phone_sms() {
        cout << "Phone is sending a message" << endl;
    }
};

class Computer : virtual public Device {
protected:
    double power_intake;

public:
    Computer(double pi, string dim, double we)
        : Device(dim, we), power_intake(pi) {}

    void comp_info() {
        cout << "Power intake of Computer: " << power_intake << " kW/h" << endl;
        device_info();
    }

    void cmp_call() {
        cout << "Computer is making a call" << endl;
    }

    void cmp_sms() {
        cout << "Computer is sending an SMS" << endl;
    }
};

class SmartPhone : public Phone, public Computer {
protected:
    string model_name;
    double price;

public:
    SmartPhone(string mn, double pr, double pw_in, double bL, string scrss, string dim, double we)
        : Device(dim, we), Phone(scrss, bL, dim, we), Computer(pw_in, dim, we),
          model_name(mn), price(pr) {}

    void smartphone_info() {
        cout << "SmartPhone Info:" << endl;
        cout << "Model name: " << model_name << endl;
        cout << "Price: " << price << endl;
        phone_info();
        comp_info();
    }

    void operations() {
        phone_call();
        phone_sms();
        cmp_call();
        cmp_sms();
    }
};

int main() {
    SmartPhone sp("XYZ30", 10000, 0.2, 3000, "6.5 inches", "102 x 203 x 8 mm", 500);
    sp.smartphone_info();
    sp.operations();

    return 0;
}
