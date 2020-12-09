/*
    01鑳屽寘
    鍥炴函娉�

*/
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

#define N 101 //榛樿鏈夊崄涓囦釜鐗╁搧銆傜涓€涓笉浣跨敤
int weights[N];     //姣忎釜鐗╁搧鐨勯噸閲�
int values[N];     //姣忎釜鐗╁搧鐨勪环鍊�
int x[N];     //x[i]=1锛氱墿鍝乮鏀惧叆鑳屽寘锛�0浠ｈ〃涓嶆斁鍏�

int Items = 100;
int MaxWeight = 5000; //n锛氫竴鍏辨湁澶氬皯鐗╁搧锛宑锛氳儗鍖呯殑鏈€澶у閲�

string weight_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/weights100.txt";
string values_txt = "F:/A_Project/vscode_project/project_c++/arithmetic/text/values100.txt";

/*
*CurWeight 鍜� CurValue瀛樺偍褰撳墠鏀惧叆鑳屽寘鐨勬暟鎹紝闅忕潃瀵硅В绌洪棿鐨勪笉鏂繁鍏ヨ€屽彉鍖�
*/
int CurWeight = 0; //褰撳墠鏀惧叆鑳屽寘鐨勭墿鍝佹€婚噸閲�
int CurValue = 0;  //褰撳墠鏀惧叆鑳屽寘鐨勭墿鍝佹€讳环鍊�
/*
*BestValue 鍜� BestX鍦ㄦ壘鍒颁竴涓彾瀛愯妭鐐规椂杩涜 绾︽潫鍑芥暟 鍒ゆ柇锛屾弧瓒崇殑璇濆氨杩炲悓淇敼鍌ㄥ瓨鐨勬渶浼樿В
*/
int BestValue = 0; //鏈€浼樺€硷紱褰撳墠鐨勬渶澶т环鍊硷紝鍒濆鍖栦负0
int BestX[N];      //鏈€浼樿В锛汢estX[i]=1浠ｈ〃鐗╁搧i鏀惧叆鑳屽寘锛�0浠ｈ〃涓嶆斁鍏�

void read_text(int *nums, string location)
{

    ifstream ifs;
    ifs.open(location, ios::in);
    if (!ifs.is_open())
    {
        cout << "鏂囦欢鎵撳紑澶辫触锛�" << endl;
    }

    int num;
    int i = 0;
    
    //浠� x[1]寮€濮�
    while (ifs >> num)
    {
        i++;
        nums[i] = num;
    }

    ifs.close();
}

//鍥炴函杈撳嚭璺緞
void output()
{
    cout << "鏈€浼樺€兼槸:" << BestValue << endl;
    cout << "(";
    for (int i = 1; i <= Items; i++)
        cout << BestX[i] << " ";
    cout << ")";
}

/*
*鍥炴函鍑芥暟 鍙傛暟t琛ㄧず褰撳墠澶勫湪绗嚑灞傚仛鎶夋嫨锛宼=1鏃惰〃绀哄綋鍓嶅湪鍐冲畾鏄惁灏嗙涓€涓墿鍝佹斁鍏ヨ儗鍖�
*/
void backtrack(int t)
{
    //鍙跺瓙鑺傜偣锛岃緭鍑虹粨鏋�
    if (t > Items)
    {
        //濡傛灉鎵惧埌浜嗕竴涓洿浼樼殑瑙�
        if (CurValue > BestValue)
        {
            //淇濆瓨鏇翠紭鐨勫€煎拰瑙�
            BestValue = CurValue;
            for (int i = 1; i <= Items; ++i)
                BestX[i] = x[i];
        }
    }
    else
    {
        //閬嶅巻褰撳墠鑺傜偣鐨勫瓙鑺傜偣锛�0 涓嶆斁鍏ヨ儗鍖咃紝1鏀惧叆鑳屽寘
        for (int i = 0; i <= 1; ++i)
        {
            x[t] = i;

            if (i == 0) //涓嶆斁鍏ヨ儗鍖�
            {
                backtrack(t + 1);
            }
            else //鏀惧叆鑳屽寘
            {
                //绾︽潫鏉′欢锛氭斁鐨勪笅
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
    startTime = clock(); //璁℃椂缁撴潫
    backtrack(1);
    cout << BestValue << endl;
    endTime = clock(); //璁℃椂缁撴潫
    cout << "The run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    //output();

    return 0;
}