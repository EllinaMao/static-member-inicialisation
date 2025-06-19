#include <iostream>

using namespace std;

// 🔹 Global static variable
static int globalStatic = [] {
    cout << "Global static initialized\n";
    return 100;
    }();

void exampleFunction() {
    // 🔹 Local static variable
    static int localStatic = [] {
        cout << "Local static initialized\n";
        return 200;
        }();
    cout << "localStatic = " << localStatic << endl;
}

class MyClass {
public:
    // 🔹 Static class member
    static int classStatic;
};

// Definition and initialization of the static class member
int MyClass::classStatic = [] {
    cout << "Static class member initialized\n";
    return 300;
    }();

int main() {
    cout << "main() starts\n";

    cout << "MyClass::classStatic = " << MyClass::classStatic << endl;

    cout << "Calling exampleFunction()...\n";
    exampleFunction();

    cout << "Calling exampleFunction() again...\n";
    exampleFunction();  // localStatic will not be initialized again

    return 0;
}
