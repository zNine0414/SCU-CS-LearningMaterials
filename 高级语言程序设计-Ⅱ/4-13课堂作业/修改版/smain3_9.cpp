//主文件：smain3_9.cpp

#include"sclass3_9_companyStaff.h"   // 包含类声明文件

//测试程序
int main()
{
	char flag ='Y';            // 设置判断是否继续录入的标志并初始化为'Y'

	while ( toupper( flag ) == 'Y')
	{
		cout <<"请选择录入类别（1.经理2.销售员3.销售经理4.行政人员）";
		int n;
		cin >> n;
        CCompanyStaff* pA = new CManager();
        CCompanyStaff* pB = new CSaleman();
        CCompanyStaff* pC = new CSaleManager();
        CCompanyStaff* pD = new CAdminStaff();
        Context* pContext = new Context(pA);//随便指一个
        if (n==1){ pContext->ChangeCCompanyStaff(pA);pContext->RequestCManager();}
        else if(n==2){ pContext->ChangeCCompanyStaff(pB);pContext->RequestCSaleman();}
        else if(n==3){ pContext->ChangeCCompanyStaff(pC);pContext->RequestCSaleManager();}
        else if(n==4){ pContext->ChangeCCompanyStaff(pD);pContext->RequestCAdminStaff();}
        else cout << "选择有误!"<< endl;
		delete pContext;
		delete pA;
        delete pB;
        delete pC;
        delete pD;
		cout << endl <<"是否继续录入信息？（Y/N）";
		cin >> flag;		
	}
    
    system("pause");
    return 0;
}

