/*
    01背包
    回溯

*/


#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stack>
using namespace std;


 
#define N 1000   //默认有99个物品。第一个不使用
int weights[N];    //每个物品的重量
int values[N];    //每个物品的价值
int x[N];     //x[i]=1：物品i放入背包，0代表不放入
int Items;
int MaxWeight;       //n：一共有多少物品，c：背包的最大容量

string location = "F:/A_Project/vscode_project/project_c++/arithmetic/text/100.txt";
/*
*CurWeight 和 CurValue存储当前放入背包的数据，随着对解空间的不断深入而变化
*/
int CurWeight = 0;  //当前放入背包的物品总重量
int CurValue = 0;   //当前放入背包的物品总价值
/*
*BestValue 和 BestX在找到一个叶子节点时进行 约束函数 判断，满足的话就连同修改储存的最优解
*/
int BestValue = 0;  //最优值；当前的最大价值，初始化为0
int BestX[N];       //最优解；BestX[i]=1代表物品i放入背包，0代表不放入
 
void input()
{
    cout<<"请输入物品的个数："<<endl;
    cin>>Items;
    cout<<"请输入每个物品的重量及价值(如12 22):"<<endl;
    for(int i = 1; i <= Items; i++)
    {
        cin>>weights[i]>>values[i];
    }
    cout<<"请输入背包的容量："<<endl;
    cin>>MaxWeight;
}
void output()
{
    cout<<"最优值是:"<<BestValue<<endl;
    // cout<<"(";
    // for(int i=1;i<=Items;i++)
    //     cout<<BestX[i]<<" ";
    // cout<<")";
 
}
/*
*回溯函数 参数t表示当前处在第几层做抉择，t=1时表示当前在决定是否将第一个物品放入背包
*/
void backtrack(int t)
{
    //叶子节点，输出结果
    if(t>Items)
    {
        //如果找到了一个更优的解
        if(CurValue>BestValue)
        {
            //保存更优的值和解
            BestValue = CurValue;
            for(int i=1; i<=Items; ++i)
                BestX[i] = x[i];
        }
    }
    else
    {
        //遍历当前节点的子节点：0 不放入背包，1放入背包
        for(int i=0; i<=1; ++i)
        {
            x[t]=i;
 
            if(i==0) //不放入背包
            {
                backtrack(t+1);
            }
            else //放入背包
            {
                //约束条件：放的下
                if((CurWeight+weights[t])<=MaxWeight)
                {
                    CurWeight += weights[t];
                    CurValue += values[t];
                    backtrack(t+1);
                    CurWeight -= weights[t];
                    CurValue -= values[t];
                }
            }
        }
    }
 
 
}


void read_text(string location)
{

    ifstream ifs;
    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败：" << endl;
    }

    ifs >> Items >> MaxWeight;

    for (int i = 1; i <= Items; i++)
    {
        //cout << "第" << i + 1 << "件物品的重量和价值：";
        ifs >> weights[i] >> values[i];
    }

    ifs.close();
}
 
int main(int argc, char* argv[])
{
 
    read_text(location);
    backtrack(1);
    output();
    return 0;
}
























