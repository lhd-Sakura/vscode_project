/*
    多态案例    计算器实现

    如果想扩展新的功能，需求修改原码
    在真实开发中 提倡开闭原则：对扩展进行开放，对修改进行关闭

    组织结构清晰
    可读性强
    对于前期和后期的扩展以及维护性高

*/
#include <iostream>

using namespace std;

//计算器的抽象类
class AbstraceCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

class AddCalculator : public AbstraceCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

class SubCalculator : public AbstraceCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

class MulCalculator : public AbstraceCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
    AbstraceCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->getResult() << endl;
    delete abc;
}

int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
