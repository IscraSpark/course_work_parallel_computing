#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <direct.h>
#include <io.h>
#include <string>
#include <fstream>
#include <map>
#include <vector>
//#include <regex>

using namespace std;

class A
{
	
private:
	vector<int> x;
public:
	A(int y)
	{
		x.push_back(y);
	}
	void add(int el){
		x.push_back(el);
	}
	void show()
	{
		for (int i = 0; i < x.size(); i++)
			cout << x[i] <<" ";
	}
	int sizeon()
	{
		return x.size();
	}

};
int main(){
	
	setlocale(LC_ALL, "rus");
	map <string, A> lol;
	
	if(lol["first"].sizeon()) cout<< "lol";
	auto it = lol.find("first");
	it->second.add(1);
	it->second.add(2);
	cout << it->first;
	it->second.show();
	/*_finddata_t data;
	string buff;
	buff = to_string(150);
	buff = buff + "\*";
	//cout << buff<<endl;
	char a[10];
	strcpy(a, buff.c_str());
	//cout << a;
	intptr_t handle = _findfirst(a,&data);
	//cout << data.name<<endl;
	ifstream fin(data.name);
	
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		fin >> buff; // считали первое слово из файла
		cout << buff << endl; // напечатали это слово
		fin.close(); // закрываем файл
	}*/
		system("pause");
		return 0;
}