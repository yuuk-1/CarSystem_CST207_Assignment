#include <iostream>
#include <string>
#include <unordered_map>

class LoginSystem {
private:
    std::unordered_map<std::string, std::string> credentials;
public:
    LoginSystem() {
        // In a real application, credentials should be securely stored and hashed
        credentials["admin"] = "password123";
    }

    bool login() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        if (credentials.find(username) != credentials.end() && credentials[username] == password) {
            return true;
        } else {
            std::cout << "Invalid credentials.\n";
            return false;
        }
    }
};

class Menu {
public:
    void displayMenu() {
        std::cout << "1. Add a new car\n";
        std::cout << "2. Modify car data\n";
        std::cout << "3. Display all cars\n";
        std::cout << "4. Sort cars\n";
        std::cout << "5. Search for a car by ID\n";
        std::cout << "6. Track the number of cars sold\n";
        std::cout << "7. Remove a car record\n";
        std::cout << "8. Sort cars by best-selling brand\n";
        std::cout << "9. Generate a bill\n";
        std::cout << "10. Search for issued bills\n";
        std::cout << "11. Generate purchase report\n";
        std::cout << "12. Exit\n";
    }
};


#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class Car {
public:
    std::string carID;
    std::string brand;
    std::string color;
    std::string country;
    int year;
    double price;

    Car(std::string brand, std::string color, std::string country, int year, double price) 
        : brand(brand), color(color), country(country), year(year), price(price) {
        generateCarID();
    }

    void generateCarID() {
        srand(time(0));
        int randomNum = rand() % 1000000;
        carID = brand.substr(0, 3) + std::to_string(randomNum);
    }

    static void addCar(std::vector<Car>& cars) {
        std::string brand, color, country;
        int year;
        double price;

        std::cout << "Enter brand: ";
        std::cin >> brand;
        std::cout << "Enter color: ";
        std::cin >> color;
        std::cout << "Enter country of manufacture: ";
        std::cin >> country;
        std::cout << "Enter year of manufacture: ";
        std::cin >> year;
        std::cout << "Enter price: ";
        std::cin >> price;

        Car car(brand, color, country, year, price);
        cars.push_back(car);

        std::ofstream outfile("cars.txt", std::ios::app);
        outfile << car.carID << " " << car.brand << " " << car.color << " " << car.country << " "
                << car.year << " " << car.price << std::endl;
        outfile.close();
    }

    static void displayCars(const std::vector<Car>& cars) {
        for (const auto& car : cars) {
            std::cout << "ID: " << car.carID << ", Brand: " << car.brand
                      << ", Color: " << car.color << ", Country: " << car.country
                      << ", Year: " << car.year << ", Price: " << car.price << std::endl;
        }
    }

    static void sortCarsByBrand(std::vector<Car>& cars) {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.brand < b.brand;
        });
    }

    static void sortCarsByPrice(std::vector<Car>& cars) {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price < b.price;
        });
    }

    static Car* searchByID(std::vector<Car>& cars, const std::string& id) {
        for (auto& car : cars) {
            if (car.carID == id) {
                return &car;
            }
        }
        return nullptr;
    }
};

int main() {
    LoginSystem loginSystem;
    Menu menu;
    std::vector<Car> cars;

    if (!loginSystem.login()) {
        return 0;
    }

    int choice;
    while (true) {
        menu.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                Car::addCar(cars);
                break;
            case 2:
                // Implement modify car data functionality
                break;
            case 3:
                Car::displayCars(cars);
                break;
            case 4:
                // Implement sorting functionality
                break;
            case 5:
                {
                    std::string id;
                    std::cout << "Enter car ID: ";
                    std::cin >> id;
                    Car* car = Car::searchByID(cars, id);
                    if (car) {
                        std::cout << "Car found: " << car->brand << " " << car->color << " " << car->country << " "
                                  << car->year << " " << car->price << std::endl;
                    } else {
                        std::cout << "Car not found.\n";
                    }
                }
                break;
            case 6:
                // Implement track number of cars sold functionality
                break;
            case 7:
                // Implement remove car record functionality
                break;
            case 8:
                // Implement sort cars by best-selling brand functionality
                break;
            case 9:
                // Implement generate bill functionality
                break;
            case 10:
                // Implement search for issued bills functionality
                break;
            case 11:
                // Implement generate purchase report functionality
                break;
            case 12:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

