#include <iostream>
#include <conio.h>
#include <thread>
#include <Windows.h>
using namespace std;
#define REPEAT_FFLUSH 5

long long sleep_time;
bool flag = true, next_step = false;

void Key(int k, bool mode)
{
	keybd_event(k, 0, (!mode ? KEYEVENTF_KEYUP : 0), 0);
}
void press(int k)
{
	Key(k, true);
	Key(k, false);
}
void Ctrl_(int k)
{
	Key(VK_CONTROL, true);
	press(k);
	Key(VK_CONTROL, false);
}

void go_Ent()
{
	while (flag)
	{
		Ctrl_(0x56);
		press(VK_RETURN);
		Sleep(sleep_time);
	}
	next_step = true;
}
void go_CtrlEnt()
{
	while (flag)
	{
		Ctrl_(0x56);
		Ctrl_(VK_RETURN);
		Sleep(sleep_time);
	}
	next_step = true;
}

int main()
{
	system("title ˢ������");
	system("mode con lines=10 cols=50");
	cout << "��ӭʹ��ˢ����\n";
	cout << "ˢ��ʱ��ʹ�ü������������\n\n";
	cout << "���η��͵ļ���Ƕ�ã�����λ������ms��\n> ";
	cin >> sleep_time;
	system("cls");
	int mode = 0;
	while (mode != 1 && mode != 2)
	{
		cout << "��ʲô�������ͣ�\n";
		cout << "1:Enter 2:Ctrl+Enter\n";
		cout << "> ";
		cin >> mode;
		system("cls");
	}
	cout << "�밴�������ʼ\n";
	_getch();
	system("cls");
	cout << "Ҫֹͣˢ�������лص���ҳ�沢���� [Esc] \n";
	thread t(mode - 1 ? go_CtrlEnt : go_Ent);
	t.detach();
	int c = 0;
	while (c != 27)
		c = _getch();
	flag = false;
	while (!next_step);
	for (int i = 1; i <= REPEAT_FFLUSH; i++)
		fflush(stdin);
	system("cls");
	cout << "��лʹ�ã��밴������˳�\n";
	_getch();
	return 0;
}

