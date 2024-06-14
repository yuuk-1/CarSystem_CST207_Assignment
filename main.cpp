#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class car {
private:
    string id;
    string brand;
    string color;
    string country;
    string year;
    int price;

public:
    car() = default;

    car(string ID, string BRAND, string COLOUR, string COM, string YOM, int PRICE) {
        id = ID;
        brand = BRAND;
        color = COLOUR;
        country = COM;
        year = YOM;
        price = PRICE;
    }

    void setID(string ID) {
        id = ID;
    }

    string getID() const {
        return id;
    }

    void setBrand(string b) {
        brand = b;
    }

    string getBrand() const {
        return brand;
    }

    void setColor(string c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    void setCountry(string c) {
        country = c;
    }

    string getCountry() const {
        return country;
    }

    void setYear(string y) {
        year = y;
    }

    string getYear() const {
        return year;
    }

    void setPrice(string p) {
        price = stoi(p);
    }

    void setPrice(int p) {
        price = p;
    }

    int getPrice() const {
        return price;
    }
};

class allCar {
private:
    vector<car> cars;
    vector<car> copy_cars;

public:
    void getCar() {
        string carPath = "car.txt";
        ifstream carFile(carPath);
        if (!carFile) {
            cout << "Error opening " << carPath << endl;
        } 
        else {
            string line;
            while (getline(carFile, line)) {
                stringstream ss(line);
                string temp;
                car c;
                getline(ss, temp, ',');
                c.setID(temp);
                getline(ss, temp, ',');
                c.setBrand(temp);
                getline(ss, temp, ',');
                c.setColor(temp);
                getline(ss, temp, ',');
                c.setCountry(temp);
                getline(ss, temp, ',');
                c.setYear(temp);
                getline(ss, temp, ',');
                c.setPrice(temp);
                cars.push_back(c);
            }
        }
    }

    void addCar(const car &c) {
        cars.push_back(c);
    }

    void mergeSort() {
        copy_cars = cars;
    }

    void quickSort() {
        copy_cars = cars;
    }

    void radixSort() {
        copy_cars = cars;
    }

    void selectionSort() {
        copy_cars = cars;
    }

    void bubbleSort() {
        copy_cars = cars;
    }

    void linearSearch(const string &id) {
    }

    void binarySearch(const string &id) {
    }
};

int main() {
    allCar allCars;
    allCars.getCar();

    return 0;
}
