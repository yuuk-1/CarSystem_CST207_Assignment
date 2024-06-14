#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
class person{
    private:
        string id;
        string name;
        string password;
    public:
        person() = default;
        person(string ID, string n, string p){
            id = ID;
            name = n;
            password = p;
        }
        void setID(string ID){
            id = ID;
        }
        string getID(){
            return id;
        }
        void setName(string n){
            name = n;
        }
        string getName(){
            return name;
        }
        void setPassword(string p){
            password = p;
        }
        string getPassword(){
            return password;
        }
};
class allClient{
    private:
        vector <person> clients;
    public:
        allClient(){
            getClient();
        }
        void getClient() {
            string clientPath = "client.txt";
            ifstream clientFile(clientPath);
            if (!clientFile) {
                cout << "Error opening " << clientPath << endl;
            } 
            else {
                string line;
                person client;
                string temp;
                while (getline(clientFile, line)) {
                    stringstream ss(line);
                    getline(ss, temp, ',');
                    client.setID(temp);
                    getline(ss, temp, ',');
                    client.setName(temp);
                    getline(ss, temp, ',');
                    client.setPassword(temp);
                    clients.push_back(client);
                }
            }
        }
        void printClient(){
            for(int i = 0; i < clients.size(); i++){
                cout << clients[i].getID() << clients[i].getName() << endl;
            }
        }
        void sorting(){

        }
        void binarySearch(){

        }
        void linearSearch(){

        }
};
class allCustomer{
    private:
        vector <person> admins;
    public:
        void getAdmin(){
            string adminPath = "admin.txt";
            ifstream adminFile(adminPath);
            if (!adminFile) {
                cout << "Error opening " << adminPath << endl;
            } 
            else {
                string line;
                person admin;
                string temp;
                while (getline(adminFile, line)) {
                    stringstream ss(line);
                    getline(ss, temp, ',');
                    admin.setID(temp);
                    getline(ss, temp, ',');
                    admin.setName(temp);
                    getline(ss, temp, ',');
                    admin.setPassword(temp);
                    admins.push_back(admin);
                }
            }
        }
        void printAdmin(){
            for(int i = 0; i < admins.size(); i++){
                cout << admins[i].getID() << admins[i].getName() << endl;
            }
        }
        void sorting(){
            
        }
        void binarySearch(){

        }
        void linearSearch(){
            
        }
};
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

class Allcar {
private:
    vector<car> cars;
    vector<car> copy_cars;

public:
    Allcar(){
        getCar();
    }
    void getCar() {
        string carPath = "car.txt";
        ifstream carFile(carPath);
        if (!carFile) {
            cout << "Error opening " << carPath << endl;
        } 
        else {
            string line;
            car c;
            while (getline(carFile, line)) {
                stringstream ss(line);
                string temp;
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
        // Implement merge sort here
    }

    void quickSort() {
        copy_cars = cars;
        // Implement quick sort here
    }

    void radixSort() {
        copy_cars = cars;
        // Implement radix sort here
    }

    void selectionSort() {
        copy_cars = cars;
        // Implement selection sort here
    }

    void bubbleSort() {
        copy_cars = cars;
        // Implement bubble sort here
    }

    void linearSearch() {
        // Implement linear search here
    }

    void binarySearch() {
        // Implement binary search here
    }

    void printCars() const {
        for (const auto &c : cars) {
            cout << c.getID() << ", " << c.getBrand() << ", " << c.getColor() << ", "
                 << c.getCountry() << ", " << c.getYear() << ", " << c.getPrice() << endl;
        }
    }
};

int main() {
    Allcar allCars;
    allCars.printCars();
    cout << endl;
    // Adding a new car
    car newCar("TOY949304939", "Toyota", "White", "Japan", "2021", 30000);
    allCars.addCar(newCar);
    allCars.printCars();

    allClient clients;
    clients.printClient();

    return 0;
}
