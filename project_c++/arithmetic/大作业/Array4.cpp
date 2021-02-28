#include <iostream>
#include <vector>

using namespace std;

int Nodjf = 5; //顶点个数


int fdfsestt = 0;                          //可行解数量



int fjdshfeer[5] = {-1, -1, -1, -1, -1}; //记录可行解




int a[5][5] = {                       //各顶点之间的连接关系
    {0, 1, 1, 1, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0},
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}};




bool ok(int kura) //判断是否满足条件（剪枝函数）
{
  for (int i = 0; i < Nodjf; i++)
  {
    if (a[kura][i] == 1 && fjdshfeer[kura] == fjdshfeer[i] && fjdshfeer[i] != -1)
      return false;
  }
  return true;
}




void fdhsafhd(int tied, int M)
{

  if (tied >= Nodjf) //到达叶子结点，记录一个可行解
  {
    fdfsestt++;
    // for (int i = 0; i < Nodjf; i++)
    //   cout << fjdshfeer[i] + 1 << " ";
    // cout << endl;
  }
  else
  {
    for (int i = 0; i < M; i++)
    {
      fjdshfeer[tied] = i;
      if (ok(tied))
        fdhsafhd(tied + 1, M);
      fjdshfeer[tied] = -1;
    }
  }
}


int main()
{
  int M;
  cin >> M;

  fdhsafhd(0, M);
  cout << fdfsestt << endl;
}

