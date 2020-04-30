#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class worker {
private:
    string name;
    int exp, hwage, hours, salary, premy;
public:
    void setN(string name) {
        this->name = name;
    }
    void setH(int hours) {
        this->hours = hours;
    }
    void setW(int hwage) {
        this->hwage = hwage;
    }
    void setE(int exp) {
        this->exp = exp;
    }
    string getN() {
        return name;
    }
    int getE() {
        return exp;
    }
    int getW() {
        return hwage;
    }
    int getH() {
        return hours;
    }
    void file() {
        ofstream fout;
        fout.open("Workers.txt");
        fout.close();
        cout << "Информация о работнике была записана в файл Workers.txt";
    }
    int salcount() {
        salary = hours * hwage;
        return salary;
    }
    int premcount() {
        if (exp <= 1) {
            premy = 0;
        }
        else if (exp <= 3) {
            premy = salary / 100 * 5;
        }
        else if (exp <= 5) {
            premy = salary / 100 * 8;
        }
        else {
            premy = salary / 100 * 15;
        }
        return premy;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    worker worker1;
    string n;
    int e, w, h;
    cout << "Фамилия:";
    cin >> n;
    worker1.setN(n);
    cout << endl << "Стаж:";
    cin >> e;
    worker1.setE(e);
    cout << endl << "Часовая заработная плата:";
    cin >> w;
    worker1.setW(w);
    cout << endl << "Количество отработанных часов:" << endl;
    cin >> h;
    worker1.setH(h);
    cout << endl << worker1.getN() << endl;
    cout << "Опыт:" << worker1.getE() << endl;
    cout << "Часовая заработная плата:" << worker1.getW() << endl;
    cout << "Количество отработанных часов:" << worker1.getH() << endl;
    cout << "Заработная плата:" << worker1.salcount() << endl;
    cout << "Премия:" << worker1.premcount() << endl;
    return 0;
}
