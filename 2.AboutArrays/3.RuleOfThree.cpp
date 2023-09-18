#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string* m_brand;
    string* m_model;
    int* m_year;

public:

    Car(const string& brand, const string& model, int year): 
    m_brand(new string(brand)), 
    m_model(new string(model)), 
    m_year(new int(year)) {
        //Default Const
    }


    Car(const Car& other): 
    m_brand(new string(*other.m_brand)), 
    m_model(new string(*other.m_model)), 
    m_year(new int(*other.m_year)) {
        //copy const
    }


    Car& operator =(const Car& other) { // copy operator "="
        if (this != &other) {
            delete m_brand;
            delete m_model;
            delete m_year;
            m_brand = new string(*other.m_brand);
            m_model = new string(*other.m_model);
            m_year = new int(*other.m_year);
        }
        return *this;
    }


    ~Car() {    // Destructor
        delete m_brand;
        delete m_model;
        delete m_year;
    }


    void display() const {
        cout << "Brand: " << *m_brand << ", Model: " << *m_model << ", Year: " << *m_year << endl;
    }
};

int main() {
    Car car1("Honda", "125", 1999);// default constructor used
    Car car2 = car1; // copy operator used
    Car car3("Suzuki", "Mehran", 2000); // default constructor used
    car3 = car2; // copy operator used

    car1.display();
    car2.display();
    car3.display();

    return 0;
}
