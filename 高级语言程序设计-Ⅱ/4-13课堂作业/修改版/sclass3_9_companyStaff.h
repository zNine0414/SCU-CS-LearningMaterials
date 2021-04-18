// 类声明文件名：sclass3_9_companyStaff.h

// 编译预处理语句：如果未定义__SCLASS3_9_COMPANYSTAFF_H__ 则定义它，
// 直到遇到#endif结束。
#ifndef __SCLASS3_9_COMPANYSTAFF_H__ 
#define __SCLASS3_9_COMPANYSTAFF_H__ 

#include<iostream>   //包含头文件，使用iostream库用于输入输出
#include<cstring>     //包含头文件，使用字符串处理函数
using namespace std; //使用std名字空间

const int LEN = 50;  //定义一个常量，表示字符数组长度

// CEducation（教育背景）类的声明
class CEducation 
{
public:
	CEducation(){}; // 构造函数

	CEducation( char cSchool[], char cDegree )// 重载构造函数，为数据成员赋初值
	{
		strcpy( m_cSchool, cSchool );
		m_cDegree = cDegree;
	}

	void GetEdu( void );      // 输入教育背景的有关数据
	
	void PutEdu( void );     // 输出教育背景的有关信息

private:
	char m_cSchool[LEN];     // 毕业学校
	char m_cDegree;          // 最高学历：专科H、本科B、硕研M、博研D
};

// 以下是基类、聚合类CCompanyStaff的声明

class CCompanyStaff                                  // 员工类（根基类）
{
public:
	CCompanyStaff( void ){};                          // 构造函数	
	~CCompanyStaff( void ){};                         // 空析构函数		
	void CalculateSal( void ){};                      // 计算实发工资
	void OutPut( void );                              // 输出员工基本信息
	void InPut( void );                               // 输如员工基本信息
	virtual void SetMData() {};
	virtual void SetSData() {};

protected:
	CEducation Edu;                                  // 内嵌对象（教育背景）
	int m_iStaffNum;                                 // 工作编号
	char m_cName[LEN];         	 		 			 // 姓名
	float m_fRateOfAttend;    		     			 // 出勤率
	float m_fBasicSal ;         		     		 // 基本工资
	float m_fPrize ;       		         			 // 奖金
	static int s_iCount;                  			 // 静态累加器
};

//定义派生类：CAdminStaff（行政人员）
class CAdminStaff : public CCompanyStaff             
{
public:	
	CAdminStaff (){};                                // 派生类构造函数

	~ CAdminStaff (){};                              // 派生类构造函数

	// 计算行政人员的实际发放工资：基本工资＋奖金×当月出勤率
	void CalculateSal( void )                        
	{
		cout << endl <<" 当月实发工资："
		<< m_fBasicSal + m_fPrize * m_fRateOfAttend <<"元"<< endl;
	}
};

//定义派生类：CManager（经理）
class CManager : virtual public CCompanyStaff // 将CCompanyStaff指定为虚基类         
{
public:
	CManager(){};                                     // 构造函数

	void SetMData( void )                             // 输入经理数据
	{
		cout << endl <<"  公司总销售额：";
		cin >> m_fTAmount;
		cout << endl <<"  提成比例：";
		cin >> m_fDeductTRate;
	}

	// 计算经理的实际发放工资：基本工资＋总销售额×提成比例
	void CalculateSal( void )                          
	{
		cout << endl <<"  当月实际发放工资：";
		cout << m_fBasicSal + m_fTAmount * m_fDeductTRate <<"元"<< endl;
	}
	
protected:
	float m_fDeductTRate;                                // 经理提成比例
	float m_fTAmount;                                    // 总销售额
};

//定义派生类：CSaleman（销售人员）
class CSaleman : virtual public CCompanyStaff // 将CCompanyStaff指定为虚基类
{
public:
	CSaleman (){};                                        // 构造函数

	void SetSData( void )                                // 设置销售员数据
	{
		cout << endl <<"  个人销售额：";
		cin >> m_fPersonAmount;
		cout << endl <<"  提成比例：";
		cin >> m_fDeductRate;
	}

	 //计算销售员的实际发放工资：基本工资＋个人销售额×提成比例
	void CalculateSal( void )             
	{
		cout << endl <<"  当月实际发放工资：";
		cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate <<"元"<< endl;
	}
	
protected:
	float m_fDeductRate;                                 // 销售员提成比例
	float m_fPersonAmount;                               // 个人销售额
};

//定义派生类：CSaleManager（销售经理）
class CSaleManager : public CSaleman, public CManager    // 派生销售经理类
{
public:
	CSaleManager(){};                                     // 构造函数

	/* 
	   计算销售经理实发工资: 
	   基本工资＋个人销售额×销售员提成比例＋总销售额×经理提成比例
	*/
	void CalculateSal( void )                      
	{
		cout << endl <<"  当月实际发放工资：";
		cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate 
			    + m_fTAmount * m_fDeductTRate; 
		cout <<"元"<< endl;
	}
};

//定义用于改变指针指向、输出的Context类
class Context
{
public:
    Context(CCompanyStaff* pCCompanyStaff) : m_pCCompanyStaff(pCCompanyStaff) {}

    void RequestCManager()
    {
        if (m_pCCompanyStaff)
        {

            //核心步骤,根据指针指向的类型进行选择调用子类的函数。
            //虚函数使得其可以实现基类指针调用基类指针所指向的子类象的函数。动态绑定。
            m_pCCompanyStaff->InPut();         // 调用基类的接口
		 	m_pCCompanyStaff->SetMData();	   // 调用经理类的接口
			m_pCCompanyStaff->OutPut();        // 调用基类的接口
			m_pCCompanyStaff->CalculateSal();  // 调用经理类的接口
        }
    }
    void RequestCSaleman()
    {
        if (m_pCCompanyStaff)
        {

            m_pCCompanyStaff->InPut();
		 	m_pCCompanyStaff->SetSData();
			m_pCCompanyStaff->OutPut();
			m_pCCompanyStaff->CalculateSal();  // 调用销售人员类的接口
        }
    }
    void RequestCSaleManager()
    {
        if (m_pCCompanyStaff)
        {

            m_pCCompanyStaff->InPut();
			m_pCCompanyStaff->SetMData();
		 	m_pCCompanyStaff->SetSData();	 				
			m_pCCompanyStaff->OutPut();
			m_pCCompanyStaff->CalculateSal();   // 调用销售经理类的接口

        }
    }    
    void RequestCAdminStaff()
    {
        if (m_pCCompanyStaff)
        {

            m_pCCompanyStaff->InPut(); 	 				
			m_pCCompanyStaff->OutPut();
			m_pCCompanyStaff->CalculateSal();   // 调用行政人员类的接口       

        }
    }

    void ChangeCCompanyStaff(CCompanyStaff* pCCompanyStaff)
    {
        m_pCCompanyStaff = pCCompanyStaff;//改变指针指向的类的类型
    }

private:
    CCompanyStaff* m_pCCompanyStaff;
};


#endif   //结束编译预处理




