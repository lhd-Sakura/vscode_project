/*
    全局函数做友元



*/

#include <iostream>
using namespace std;

class Building
{
    friend void goodGay(Building &building);

private:
    /* data */
    string m_BedRoom;

public:
    Building(/* args */);
    ~Building();

    string m_SittingRoom;
};

Building::Building(/* args */)
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

Building::~Building()
{
}

void goodGay(Building &building)
{

    cout << "好基友正在访问：" << building.m_SittingRoom << endl;
    cout << "好基友正在访问：" << building.m_BedRoom << endl;
}

void test01()
{
    Building b1;
    goodGay(b1);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
