/*
    多态案例2 制作饮品

*/
#include <iostream>

using namespace std;

class AbstraceDrinking
{
    public:
        virtual void Boid() = 0;
        virtual void Brew() = 0;
        virtual void PourInCup() = 0;
        virtual void PutSomething() = 0;

        void makeDrink()
        {
            Boid();
            Brew();
            PourInCup();
            PutSomething();
        }
};

class Coffee : public AbstraceDrinking
{
    public:
        virtual void Boid() 
        {
            cout << "煮水" << endl;
        }
        virtual void Brew() 
        {
            cout << "泡咖啡" << endl;
        }
        virtual void PourInCup() 
        {
            cout << "倒水" << endl;
        }
        virtual void PutSomething() 
        {
            cout << "加雀巢" << endl;
        }

};

class Tea : public AbstraceDrinking
{
    public:
        virtual void Boid() 
        {
            cout << "煮水" << endl;
        }
        virtual void Brew() 
        {
            cout << "泡茶" << endl;
        }
        virtual void PourInCup() 
        {
            cout << "倒水" << endl;
        }
        virtual void PutSomething() 
        {
            cout << "加茶叶" << endl;
        }

};

void doWork(AbstraceDrinking *abs)
{
    abs->makeDrink();
    delete abs;
}

void test01()
{
    doWork(new Coffee);
    cout << "--------------------------------" << endl;
    doWork(new Tea);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

