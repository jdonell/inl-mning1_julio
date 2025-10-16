#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;



// ----- Deklaration av funktioner -----
double sum(const double values[], int size);
double average(const double values[], int size);
double highest(const double values[], int size);
double lowest(const double values[], int size);
double varianceSample(const double values[], int size);
double standardDeviationSample(const double values[], int size);
int findIndex(const double values[], int size, double target);
void sortAscending(double values[], int size);
void showMenu();

// ----- Huvudprogram -----
int main() {
    const int SIZE = 5;
    double values[SIZE];
    bool hasValues = false; // har användaren matat in 5 värden?
 
    while (true) {
        showMenu();

        int choice;
        cout << "Välj (1-5): " << std::endl;
        if (!(cin >> choice)) {
            cout << "Ogiltig inmatning. Försök igen." << std::endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // den här får vara kvar för att rensa raden
            continue;
        }
          
        if (choice == 1) {
            // 1. Mata in 5 värden
            cout << "Skriv in 5 tal:" << std::endl;
            for (int i = 0; i < SIZE; i = i + 1) {
                cout << "Tal " << (i + 1) << ": " << std::endl;

                while (!(cin >> values[i])) {
                    cout << "Det där var inte ett tal. Försök igen:" << std::endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            hasValues = true;
            cout << "Sparat!" << std::endl;
            cout << std::endl;
        }
        else if (choice == 2) {
            // 2. Visa statistik
            if (hasValues == false) {
                cout << "Lägg till värden först (val 1)." << std::endl;
                cout << std::endl;
            }
            else {
                cout << "Du skrev in: " << std::endl;
                for (int i = 0; i < SIZE; i = i + 1) {
                    cout << values[i];
                    if (i < SIZE - 1) {
                        cout << ", ";
                    }
                }
                cout << std::endl;

                cout << "Antal: " << SIZE << std::endl;
                cout << "Summa: " << sum(values, SIZE) << std::endl;
                cout << "Medelvärde: " << average(values, SIZE) << std::endl;
                cout << "Högsta: " << highest(values, SIZE) << std::endl;
                cout << "Lägsta: " << lowest(values, SIZE) << std::endl;
                cout << "Varians (stickprov): " << varianceSample(values, SIZE) << std::endl;
                cout << "Standardavvikelse (stickprov): " << standardDeviationSample(values, SIZE) << std::endl;
                cout << std::endl;
            }
        }
        else if (choice == 3) {
            // 3. Sök efter ett värde
            if (hasValues == false) {
                cout << "Lägg till värden först (val 1)." << std::endl;
                cout << std::endl;
            }
            else {
                double target;
                cout << "Sök efter värde:" << std::endl;
                if (!(cin >> target)) {
                    cout << "Ogiltigt värde. Avbryter sökning." << std::endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << std::endl;
                }
                else {
                    int index = findIndex(values, SIZE, target);
                    if (index == -1) {
                        cout << target << " hittades inte." << std::endl;
                        cout << std::endl;
                    }
                    else {
                        cout << target << " hittades på index " << index << "." << std::endl;
                        cout << std::endl;
                    }
                }
            }
        }
        else if (choice == 4) {
            // 4. Sortera stigande (minst -> störst)
            if (hasValues == false) {
                cout << "Lägg till värden först (val 1)." << std::endl;
                cout << std::endl;
            }
            else {
                sortAscending(values, SIZE);
                cout << "Sorterad (stigande): " << std::endl;
                for (int i = 0; i < SIZE; i = i + 1) {
                    cout << values[i];
                    if (i < SIZE - 1) {
                        cout << ", ";
                    }
                }
                cout << std::endl;
                cout << std::endl;
            }
        }
        else if (choice == 5) {
            // 5. Avsluta
            cout << "Avslutar programmet. Hej då!" << std::endl;
            return 0;
        }
        else {
            // Ogiltigt val
            cout << "Välj bara siffrorna 1, 2, 3, 4 eller 5." << std::endl;
            cout << std::endl;
        }
    }
}

// ----- Funktioner -----

void showMenu() {
    cout << "========== MENY ==========" << std::endl;
    cout << "1. Lägg till 5 nya värden" << std::endl;
    cout << "2. Visa statistik" << std::endl;
    cout << "3. Sök efter ett värde" << std::endl;
    cout << "4. Sortera stigande" << std::endl;
    cout << "5. Avsluta" << std::endl;
    cout << "==========================" << std::endl;
}

double sum(const double values[], int size) {
    // Räknar ihop alla tal
    double total = 0.0;

    for (int i = 0; i < size; i = i + 1) {
        total = total + values[i];
    }

    return total;
}

double average(const double values[], int size) {
    // Medelvärde = summa / antal
    if (size == 0) {
        return 0.0;
    }

    double total = sum(values, size);
    double result = total / size;
    return result;
}

double highest(const double values[], int size) {
    // Högsta värdet i arrayen
    double hi = values[0];

    for (int i = 1; i < size; i = i + 1) {
        if (values[i] > hi) {
            hi = values[i];
        }
    }

    return hi;
}

double lowest(const double values[], int size) {
    // Lägsta värdet i arrayen
    double lo = values[0];

    for (int i = 1; i < size; i = i + 1) {
        if (values[i] < lo) {
            lo = values[i];
        }
    }

    return lo;
}

double varianceSample(const double values[], int size) {
    // varians (svåraste delen av hela uppgiften)
    if (size < 2) {
        return 0.0;
    }

    double mean = average(values, size);
    double sumSquares = 0.0;

    for (int i = 0; i < size; i = i + 1) {
        double difference = values[i] - mean;
        double squared = difference * difference;
        sumSquares = sumSquares + squared;
    }

    double result = sumSquares / (size - 1);
    return result;
}

double standardDeviationSample(const double values[], int size) {
    // Standardavvikelse = roten ur variansen (lärde mig det här av goggole)
    double var = varianceSample(values, size);
    double std = sqrt(var);
    return std;
}

int findIndex(const double values[], int size, double target) {
    // Letar efter target och returnerar index, annars -1
    for (int i = 0; i < size; i = i + 1) {
        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}

void sortAscending(double values[], int size) {
    // Bubble sort: jämför grannar/tal i en array
    for (int i = 0; i < size - 1; i = i + 1) {
        for (int j = 0; j < size - 1 - i; j = j + 1) {
            if (values[j] > values[j + 1]) {
                double temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}


