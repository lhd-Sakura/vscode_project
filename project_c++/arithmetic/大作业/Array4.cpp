#include <iostream>
#include <vector>

using namespace std;

int Nodjf = 5; //�������


int fdfsestt = 0;                          //���н�����



int fjdshfeer[5] = {-1, -1, -1, -1, -1}; //��¼���н�




int a[5][5] = {                       //������֮������ӹ�ϵ
    {0, 1, 1, 1, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0},
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}};




bool ok(int kura) //�ж��Ƿ�������������֦������
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

  if (tied >= Nodjf) //����Ҷ�ӽ�㣬��¼һ�����н�
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

