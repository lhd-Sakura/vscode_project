/*
    ������
    1.
    ����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
    ���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
    ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����


*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void buystock(int len, int *stock)
{
    int ans = 0;
    for (int i = 0; (i+1) < len; i++)
    {
        if(stock[i]<stock[i+1])
            ans = ans + stock[i + 1] - stock[i];
    }
    cout << ans << endl;
    
}

int main(int argc, char const *argv[])
{
    //�������뼰����ת����int ����������
    string str;
    getline(cin, str);
    int len = (str.size() / 2) + 1;
    //cout << len << endl;

    int stock[len];
    int j = 0;
    for (int i = 0; i < len; i++)
    {

        stock[i] = str[j] - 48;
        //cout << str[j] << endl;
        j = j + 2;
    }

    buystock(len, stock);

    return 0;
}