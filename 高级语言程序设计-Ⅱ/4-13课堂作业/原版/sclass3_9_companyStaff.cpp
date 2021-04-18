// 类实现文件：sclass3_9_companyStaff.cpp

#include"sclass3_9_companyStaff.h" // 包含类声明文件

int CCompanyStaff::s_iCount = 1000; // 初始化静态数据成员s_iCount

// 实现类CEducation的成员函数GetEdu，输入信息
void CEducation::GetEdu( void )
{
	cout << endl <<"  毕业学校：";
	cin >> m_cSchool;
	cout << endl <<"  最高学历：（专科H、本科B、硕研M、博研D）";
	cin >> m_cDegree;

	// 用toupper函数将用户输入的学历规范为大写字符
	m_cDegree = toupper( m_cDegree );
	
}

// 实现类CEducation的成员函数PutEdu，输出信息
void CEducation::PutEdu( void )
{
	cout << endl <<"  毕业学校："<< m_cSchool << endl;
	cout << endl <<"  最高学历：";
	switch ( m_cDegree )         
	{
		case 'H': cout <<"专科"<< endl;
				  break;
		case 'B': cout <<"本科"<< endl;
			      break;
		case 'M': cout <<"硕研"<< endl;
			      break;
		case 'D': cout <<"博研"<< endl;
			      break;
		default:  cout <<"空"<< endl;  // 输入的学历在选项之外则为"空"
			      break;
	}
}

// 实现类CCompanyStaff的成员函数InPut，输入员工各项数据
void CCompanyStaff:: InPut( void )
{
	m_iStaffNum = ++s_iCount;       // 静态累加器自加1后赋给工作编号

	cout << endl << "请输入编号为"<< m_iStaffNum <<"号员工的姓名：";
	cin >> m_cName;	// 输入员工姓名

	Edu.GetEdu(); // 通过内嵌对象调用类CEducation的接口GetEdu，输入教育背景相关数据
	
	cout << endl << "  基本工资：";
	cin >> m_fBasicSal;     // 输入基本工资

	cout << endl << "  奖金：";
	cin >> m_fPrize;     // 输入奖金

	cout << endl <<"  出勤率：";
	cin >> m_fRateOfAttend;  // 输入出勤率

	// 规范用户输入的出勤率的值
	if ( m_fRateOfAttend > 1.0 )
	{
		m_fRateOfAttend = 1.0;
	}
	else 
		if ( m_fRateOfAttend < 0 )
		{
			m_fRateOfAttend = 0;
		}
		
}

// 实现类CCompanyStaff的成员函数OutPut，输出员工信息
void CCompanyStaff:: OutPut( void )
{
	cout << endl << "显示员工" << m_cName <<"的基本数据：";

	cout << endl << "  工作编号：" << m_iStaffNum;

	Edu.PutEdu();      // 通过内嵌对象调用类CEducation的接口PutEdu

	cout << endl << "  基本工资：" << m_fBasicSal;

	cout << endl << "  奖金：" << m_fPrize;
	
	cout << endl << "  出勤率：" <<  m_fRateOfAttend * 100 << "%";
}





