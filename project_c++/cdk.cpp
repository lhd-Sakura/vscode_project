/*
    cdk兑换
    玄晶         GYD WL AAA ALBaPJhU
    200群侠      GYD TH AAA FhGauZHX
                 GYD TH AAA BhMURyZx
    玄碎         GYD RK AAA PLbpMSjM
    门派         GYD PG AAA KSLKjWZV

*/

#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0;
    ofstream ofs;
    ofs.open("cdk.txt", ios::out);
    while (i < 1)
    {
        char num[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
        srand((unsigned)time(0));

        char k1, k2, k3, k4, k5, k6, k7, k8;
        k1 = num[rand() % 52];
        k2 = num[rand() % 52];
        k3 = num[rand() % 52];
        k4 = num[rand() % 52];
        k5 = num[rand() % 52];
        k6 = num[rand() % 52];
        k7 = num[rand() % 52];
        k8 = num[rand() % 52];

        cout << "GYDWLAAA" << k1 << k2 << k3 << k4 << k5 << k6 << k7 << k8 << endl;

        ofs << "GYDWLAAA" << k1 << k2 << k3 << k4 << k5 << k6 << k7 << k8 << endl;

        i++;
    }

    ofs.close();
    return 0;
}

/*
//检查CDK长度
			option.sCdKey = option.sCdKey.replace(/^\s+|\s+$/g,'');
			if (option.sCdKey.length <= 0){
				alert('cdk不能为空！');
				return;
			}
			
			if (option.sCdKey.length != 16){
				alert('cdk格式不正确！');
				return;
			}
			
			//校验验证码
			option.sVerifyCode = option.sVerifyCode.replace(/^\s+|\s+$/g,'');
			if(!option.sVerifyCode){
				alert('您的验证码信息未输入。');
				return;
			}
			if(option.sVerifyCode.length != 4){
				alert('您的验证码信息填写出错。');
				return false;
			}
			var submitOption = {
				'sCdKey' : option.sCdKey,
				'iUin' : LoginManager.getUserUin(),
				'sVerifyCode' : option.sVerifyCode,
				'isVerifyCode' : true,
				'verifysession' : option.verifysession,
				'iVerifyId' : '21000104'
			};
			extend(submitOption, _submitOption);
			
			if (typeof(_submitOption) == 'undefined'){
				submitOption.sArea = "";
			}else{
				submitOption.sArea = _submitOption.sArea;
			}
			


*/
