#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//�����ڷ� �������� �����
class Car {
protected:
    int speed; // �ӵ�
    int maxSpeed; // �ִ� �ӵ�
    int distance; // �̵� �Ÿ�

public:
    Car(int maxSpeed) : maxSpeed(maxSpeed), speed(0), distance(0) { }
    virtual void Move() = 0; //���� �Լ����
    int GetSpeed() { return speed; }
    int GetDistance() { return distance; }
    void SetDistance(int dist) { distance = dist; }
    virtual string GetName() = 0; // ������ġ�� ���� �Լ�
};

class SportsCar : public Car {
public:
    SportsCar() : Car(200) { }
    void Move() {
        speed = rand() % (maxSpeed + 1); // 0~200������ ������ �ӵ� ����
        distance += speed; // �̵� �Ÿ� ����  //���� ������ �ȵ�
    }
    string GetName() { 
        return "SportsCar"; 
    }
};

class Truck : public Car {
public:
    Truck() : Car(100) { }
    void Move() {
        speed = rand() % (maxSpeed + 1); // 0~100km/h ������ ������ �ӵ� ����
        distance += speed; // �̵� �Ÿ� ����      //04.26 ���� �ȵ�...
    }
    string GetName() {
        return "Truck"; 
    }
};

class Bus : public Car {
public:
    Bus() : Car(150) { }
    void Move() {
        speed = rand() % (maxSpeed + 1); // 0~150km/h ������ ������ �ӵ� ����
        distance += speed; // �̵� �Ÿ� ����
    }
    string GetName() { 
        return "Bus"; 
    }
};


int main() {
    srand((unsigned int)time(NULL)); // rand() �Լ� �ʱ�ȭ

    int raceTime, numRaces;
    cout << "Enter race time (in seconds): ";
    cin >> raceTime;
    cout << "Enter number of races: ";
    cin >> numRaces;
    double car1Distance = 0;
    double car2Distance = 0;

    int sportsCarWins = 0, truckWins = 0, busWins = 0;
    double sportsCarDistance = 0, truckDistance = 0, busDistance = 0;
    //���⼭ ���� �ڵ尡 �� �� �̻��������ϴµ�...

    for (int i = 0; i < numRaces; i++) {
        Car* car1 = nullptr;                //Car* car1,car2 
        Car* car2 = nullptr;
        int carType1, carType2;
        /*double car1Distance = 0;
        double car2Distance = 0;*/

        // �� ���� �ڵ��� ������ �Է� ���� ���ڷ� 
        cout << "\nRace " << i + 1 << endl;
        cout << "Enter car 1 type: ";
        cin >> carType1;
        cout << "Enter car 2 type: ";
        cin >> carType2;

        // �ڵ��� ��ü�� �����ϰ� �����Ϳ� ����
        if (carType1 == 1)
            car1 = new SportsCar();
        else if (carType1 == 2)
            car1 = new Truck();
        else if (carType1 == 3)
            car1 = new Bus();

        if (carType2 == 1)
            car2 = new SportsCar();
        else if (carType2 == 2)
            car2 = new Truck();
        else if (carType2 == 3)
            car2 = new Bus();
    
        // ���� ����
        int time = 0;
        while (time < raceTime) {
            // �� �ڵ����� �ӵ��� ����ϰ� �̵��� �Ÿ��� ����
            double car1Speed = car1->GetSpeed();
            double car2Speed = car2->GetSpeed();
            car1Distance += car1Speed * 1000 / 3600;
            car2Distance += car2Speed * 1000 / 3600;
        }

        // �ڵ��� ����ڿ� �Ÿ� ���
        cout << "\nWinner: ";
        if (car1Distance > car2Distance) {          //if���� �ȵ��ư�... car1Distance�� 2Distance �� �Ѵ� 0��.
            cout << "Car 1" << endl;
            if (carType1 == 1)
                sportsCarWins++;
            else if (carType1 == 2)
                truckWins++;
            else if (carType1 == 3)
                busWins++;
        }
        else {
            cout << "Car 2" << endl;
            if (carType2 == 1)
                sportsCarWins++;
            else if (carType2 == 2)
                truckWins++;
            else if (carType2 == 3)
                busWins++;
        }

        cout << "Car 1 distance: " << car1Distance << " meters" << endl;
        cout << "Car 2 distance: " << car2Distance << " meters" << endl;

        // �Ҵ�� �ڵ��� ��ü�� ����
        delete car1;
        delete car2;
    }
}