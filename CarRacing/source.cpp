#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//강의자료 바탕으로 만들기
class Car {
protected:
    int speed; // 속도
    int maxSpeed; // 최대 속도
    int distance; // 이동 거리

public:
    Car(int maxSpeed) : maxSpeed(maxSpeed), speed(0), distance(0) { }
    virtual void Move() = 0; //가상 함수사용
    int GetSpeed() { return speed; }
    int GetDistance() { return distance; }
    void SetDistance(int dist) { distance = dist; }
    virtual string GetName() = 0; // 만병통치약 가상 함수
};

class SportsCar : public Car {
public:
    SportsCar() : Car(200) { }
    void Move() {
        speed = rand() % (maxSpeed + 1); // 0~200사이의 랜덤한 속도 설정
        distance += speed; // 이동 거리 누적  //현재 누적이 안됨
    }
    string GetName() { 
        return "SportsCar"; 
    }
};

class Truck : public Car {
public:
    Truck() : Car(100) { }
    void Move() {
        speed = rand() % (maxSpeed + 1); // 0~100km/h 사이의 랜덤한 속도 설정
        distance += speed; // 이동 거리 누적      //04.26 현재 안됨...
    }
    string GetName() {
        return "Truck"; 
    }
};

class Bus : public Car {
public:
    Bus() : Car(150) { }
    void Move() {
        speed = rand() % (maxSpeed + 1); // 0~150km/h 사이의 랜덤한 속도 설정
        distance += speed; // 이동 거리 누적
    }
    string GetName() { 
        return "Bus"; 
    }
};


int main() {
    srand((unsigned int)time(NULL)); // rand() 함수 초기화

    int raceTime, numRaces;
    cout << "Enter race time (in seconds): ";
    cin >> raceTime;
    cout << "Enter number of races: ";
    cin >> numRaces;
    double car1Distance = 0;
    double car2Distance = 0;

    int sportsCarWins = 0, truckWins = 0, busWins = 0;
    double sportsCarDistance = 0, truckDistance = 0, busDistance = 0;
    //여기서 부터 코드가 쫌 씩 이상해지긴하는데...

    for (int i = 0; i < numRaces; i++) {
        Car* car1 = nullptr;                //Car* car1,car2 
        Car* car2 = nullptr;
        int carType1, carType2;
        /*double car1Distance = 0;
        double car2Distance = 0;*/

        // 두 대의 자동차 종류를 입력 받음 숫자로 
        cout << "\nRace " << i + 1 << endl;
        cout << "Enter car 1 type: ";
        cin >> carType1;
        cout << "Enter car 2 type: ";
        cin >> carType2;

        // 자동차 객체를 생성하고 포인터에 대입
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
    
        // 경주 시작
        int time = 0;
        while (time < raceTime) {
            // 각 자동차의 속도를 계산하고 이동한 거리를 누적
            double car1Speed = car1->GetSpeed();
            double car2Speed = car2->GetSpeed();
            car1Distance += car1Speed * 1000 / 3600;
            car2Distance += car2Speed * 1000 / 3600;
        }

        // 자동차 우승자와 거리 출력
        cout << "\nWinner: ";
        if (car1Distance > car2Distance) {          //if문이 안돌아감... car1Distance와 2Distance 가 둘다 0임.
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

        // 할당된 자동차 객체를 삭제
        delete car1;
        delete car2;
    }
}