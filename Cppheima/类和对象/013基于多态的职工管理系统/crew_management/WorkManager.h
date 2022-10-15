#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Worker.h"
#include "WorkManager.h"
#include "employee.h"
#include "Boss.h"
#include "Manager.h"

#define FILENAME "Member.txt"
#define MAXLIST 99
#define SUOJIN 10 //标准输出的缩进值

using namespace std;

class WorkManager
{
public:
	//构造函数调用
	WorkManager();


	//展示菜单的界面
	void ShowManue();

	//增加职工
	void Add_Emp();

	//增加职工
	void Add_Emp(int idx,int newid);

	//保存到文件
	void save();

	//读取文件内容
	int GetEmpNum();

	//列表初始化
	int _init_array();

	//显示列表信息函数
	void Show();

	//格式化输出列表
	void StdOut();

	//按ID排序冒泡
	void Order_ID();

	//按ID排序倒序冒泡
	void Order_ID_Reverse();

	//删除职工信息
	void Delete();

	//ID存在性检测，返回bool类型
	bool IsExist(int id, int* idx);

	//修改成员
	void Rectify();

	//查找职工
	void Find();

	//查找姓名
	int FindName(int *idx, string name);

	//查找职工类型
	int FindDept(int* idx, int deptid);

	//查找工作时长
	int FindTime(int* idx, int time);

	//排序
	void Order_all();

	//按职能部门
	void Order_Deptid();

	//按职能部门倒序
	void Order_Deptid_Reverse();

	//按工作时长排序
	void Order_Time();

	//按工作时长倒序
	void Order_Time_Reverse();

	//清除所有
	void Emptify();



	//退出程序
	void ExitSystem();

	//检测id是否与已有的重复了
	bool IsRepeat(int id);

	//清楚缓冲区
	static void Clearbuff();

	//析构函数调用
	~WorkManager();

	//判断文件读取是否出现数据异常，1正常，0,错误
	int TorF = 1;	

	//记录文件中的人数个数
	int m_EmpNum;

	//定义文件为空的标志量，0表示没有文件或数据为空
	int m_FileEmpty;

	//员工数组的指针
	Worker** m_EmpArray;//二级指针，存储产生多态的*worker，即指向Worker类型的指向Worker的指针的指针。
};