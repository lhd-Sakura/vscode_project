/*
    01背包
    回溯法

*/
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

#define N 100000 //默认有十万个物品。第一个不使用
int weights[N];     //每个物品的重量
int values[N];     //每个物品的价值
int x[N];     //x[i]=1：物品i放入背包，0代表不放入

int Items = 6;
int MaxWeight = 15; //n：一共有多少物品，c：背包的最大容量

string weight_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/weights2.txt";
string values_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/values2.txt";

/*
*CurWeight 和 CurValue存储当前放入背包的数据，随着对解空间的不断深入而变化
*/
int CurWeight = 0; //当前放入背包的物品总重量
int CurValue = 0;  //当前放入背包的物品总价值
/*
*BestValue 和 BestX在找到一个叶子节点时进行 约束函数 判断，满足的话就连同修改储存的最优解
*/
int BestValue = 0; //最优值；当前的最大价值，初始化为0
int BestX[N];      //最优解；BestX[i]=1代表物品i放入背包，0代表不放入

void read_text(int *nums, string location)
{

    ifstream ifs;
    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败：" << endl;
    }

    int num;
    int i = 0;
    while (ifs >> num)
    {
        i++;
        nums[i] = num;
    }

    ifs.close();
}

//回溯输出路径
// void output()
// {
//     cout << "最优值是:" << BestValue << endl;
//     cout << "(";
//     for (int i = 1; i <= n; i++)
//         cout << BestX[i] << " ";
//     cout << ")";
// }

/*
*回溯函数 参数t表示当前处在第几层做抉择，t=1时表示当前在决定是否将第一个物品放入背包
*/
void backtrack(int t)
{
    //叶子节点，输出结果
    if (t > Items)
    {
        //如果找到了一个更优的解
        if (CurValue > BestValue)
        {
            //保存更优的值和解
            BestValue = CurValue;
            for (int i = 1; i <= Items; ++i)
                BestX[i] = x[i];
        }
    }
    else
    {
        //遍历当前节点的子节点：0 不放入背包，1放入背包
        for (int i = 0; i <= 1; ++i)
        {
            x[t] = i;

            if (i == 0) //不放入背包
            {
                backtrack(t + 1);
            }
            else //放入背包
            {
                //约束条件：放的下
                if ((CurWeight + weights[t]) <= MaxWeight)
                {
                    CurWeight += weights[t];
                    CurValue += values[t];
                    backtrack(t + 1);
                    CurWeight -= weights[t];
                    CurValue -= values[t];
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{

    read_text(weights, weight_txt);
    read_text(values, values_txt);

    clock_t startTime, endTime;
    startTime = clock(); //计时结束
    backtrack(1);
    cout << BestValue << endl;
    endTime = clock(); //计时结束
    cout << "The run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;


    return 0;
}