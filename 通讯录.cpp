#include <iostream>
using namespace std;
#include<string>
#define MAX 1234

struct person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

struct phonebook
{
	person personArray[MAX];
	int m_size;
};

void showmenu(){
	cout<<"****************************"<<endl;
	cout<<"*****   1.添加联系人   *****"<<endl;
	cout<<"*****   2.显示联系人   *****"<<endl;
	cout<<"*****   3.删除联系人   *****"<<endl;
	cout<<"*****   4.查找联系人   *****"<<endl;
	cout<<"*****   5.修改联系人   *****"<<endl;
	cout<<"*****   6.清空联系人   *****"<<endl;
	cout<<"*****   0.退出通讯录   *****"<<endl;
	cout<<"****************************"<<endl;
}

void addperson(phonebook*pb){
	
	if(pb->m_size==MAX){
		cout<<"通讯录已满，无法添加";
		return; 
	}
	
	cout<<"请输入名字："<<endl;
	cin>>pb->personArray[pb->m_size].m_name;
	
	cout<<"请输入年龄："<<endl;
	cin>>pb->personArray[pb->m_size].m_age;
	
	cout<<"请输入性别："<<endl;
	cout<<"1---男"<<endl;
	cout<<"2---女"<<endl;
	while(true)
	{
		int sex;
		cin>>sex;
		if(sex==1||sex==2){
			pb->personArray[pb->m_size].m_sex=sex;
			break;
		}
		cout<<"输入有误，请重新输入"<<endl;
	}
	
	cout<<"请输入号码："<<endl;
	cin>>pb->personArray[pb->m_size].m_phone;
	
	cout<<"请输入地址："<<endl;
	cin>>pb->personArray[pb->m_size].m_addr;
	
	pb->m_size++;
	system("pause");
	system("cls");
}

void print (const phonebook*pb)
{
	if(pb->m_size==0){
		cout<<"通讯录为空"<<endl;
	}
	for(int i=0;i<pb->m_size;i++){
		string sex ;
		if(	pb->personArray[i].m_sex==1){
			sex="男";
		}
		else if(pb->personArray[i].m_sex==2)
		{
			sex="女";
		}
		cout<<"名字："<<pb->personArray[i].m_name<<"   年龄："<<pb->personArray[i].m_age<<
		"   性别："<< sex <<"   号码："<<pb->personArray[i].m_phone<<
		"   地址："<<pb->personArray[i].m_addr<<endl;
	}
	
	system("pause");
	system("cls");
}

int IsExist(const phonebook * abs,string name)
{
	for(int i=0;i<abs->m_size;i++){
		if(name==abs->personArray[i].m_name){
			return i;
		}
	}
	return -1;
}
void deleteperson(phonebook * pb)
{
	string name;
	cout<<"请输入名字"<<endl;
	cin>>name;
	int ret=IsExist(pb,name);
	if(ret!=-1){
		for(int i=ret;i<pb->m_size;i++){
			pb->personArray[i]=pb->personArray[i+1];
		}
		pb->m_size--;
		cout<<"删除成功"<<endl;
	}
	else
		cout<<"查无此人"<<endl;
	
	system("pause");
	system("cls");
}

void Findperson(phonebook *pb)
{
	string name;
	cout<<"请输入名字"<<endl;
	cin>>name;
	int ret=IsExist(pb,name);
	if(ret!=-1){
		string sex ;
		if(	pb->personArray[ret].m_sex==1){
			sex="男";
		}
		else if(pb->personArray[ret].m_sex==2)
		{
			sex="女";
		}
		cout<<"名字："<<pb->personArray[ret].m_name<<"\t"
		<<"   年龄："<<pb->personArray[ret].m_age<<"\t"
		<<"   性别："<<pb->personArray[ret].m_sex<<"\t"
		<<"   号码："<<pb->personArray[ret].m_phone<<"\t"
		<<"   地址："<<pb->personArray[ret].m_addr<<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	
	system("pause");
	system("cls");
}

void modifyperson(phonebook*pb)
{
	string name;
	cout<<"请输入修改人名字"<<endl;
	cin>>name;
	int ret=IsExist(pb,name);
	if(ret!=-1){
		string name;
		cout<<"请输入修改后名字"<<endl;
		cin>>name;
		pb->personArray[ret].m_name=name;
		
		cout<<"请输入修改后年龄"<<endl;
		cin>>pb->personArray[ret].m_age;
		
		cout<<"请输入修改后性别"<<endl;
		cout<<"1---男"<<endl;
		cout<<"2---女"<<endl;
		while(true)
		{
			int sex;
			cin>>sex;
			if(sex==1||sex==2){
				pb->personArray[pb->m_size].m_sex=sex;
				break;
			}
			cout<<"输入有误，请重新输入"<<endl;
		}
		
		
		cout<<"请输入修改后电话"<<endl;
		cin>>pb->personArray[ret].m_phone;
		
		cout<<"请输入修改后住址"<<endl;
		cin>>pb->personArray[ret].m_addr;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	
	system("pause");
	system("cls");
	
}

void loop(){
	phonebook pb;
	
	pb.m_size=0;
	
	while(true){
		
		showmenu();
		
		int select=0;
		cin>>select;
		
		switch (select) {
		case 1:
			addperson(&pb);
			break;
		case 2:
			print(&pb);
			break;
		case 3:
			{
				deleteperson(&pb);
				break;   
			}
		case 4:
			Findperson(&pb);
			break;
		case 5:
			modifyperson(&pb);
			break;
		case 6:
			cout<<"清空联系人"<<endl;
			break;
		case 0:
			cout<<"退出通讯录,欢迎下次使用"<<endl;
			system("pause");
			return;
		default:
			cout<<"请重新输入"<<endl;
			break;
		}
	}
}



int main(){
	
	loop();
	
	//system("pause");
	return 0;
}
