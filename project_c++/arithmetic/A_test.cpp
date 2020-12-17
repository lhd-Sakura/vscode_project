#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

const char* file_in="F:/A_Project/vscode_project/project_c++/arithmetic/text/10000.txt";
const int max_people=100000;
const int max_mine=100000;

int mine;
int peopleTotal;
int peopleNeed[max_mine];
int Gold[max_mine];
int sumGold[max_people][max_mine];

void init()
{
    cout << file_in << endl;
    ifstream inputFile(file_in);

    inputFile >> peopleTotal >> mine;

    for (int i=0;i<mine;++i)
      inputFile >> peopleNeed[i] >> Gold[i];

    for(int i=0;i<max_people;++i)
      for(int j=0;j<max_mine;++j)
        sumGold[i][j]=-1;

    inputFile.close();
}

int getMaxGold(int people, int mineNum)
{
    int totalGold;
    if(sumGold[people][mineNum]!=-1)
      //return sumGold[people][mineNum];
      totalGold=sumGold[people][mineNum];
    else if(mineNum==0)
    {
        if(people>=peopleNeed[mineNum])
          totalGold=Gold[mineNum];
        else
        {
            totalGold=0;
        }
    }
    else
    {
        if(people>=peopleNeed[mineNum])
          totalGold=std::max(getMaxGold(people, mineNum-1), getMaxGold(people-peopleNeed[mineNum],mineNum-1)+Gold[mineNum]);
        else
          totalGold=getMaxGold(people, mineNum-1);
    }
    sumGold[people][mineNum]=totalGold;
    return totalGold;
}

int main(int argc, char** argv)
{
    init();

    // cout << "peopleTotal" << "\t" << peopleTotal << endl;
    // cout << "mine" << "\t" << mine << endl;
    // cout << "peopleNeed\t" ;
    // for(int i=0;i<mine;++i)
    //   cout << peopleNeed[i] << "\t";
    // cout << endl;

    // cout << "Gold\t";
    // for(int i=0;i<mine;++i)
    //   cout << Gold[i] << "\t";
    // cout << endl;

    int result=getMaxGold(peopleTotal, mine);
    cout << "result\t" << result << endl;
}