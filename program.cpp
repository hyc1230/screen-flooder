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
	system("title 刷屏神器");
	system("mode con lines=10 cols=50");
	cout << "欢迎使用刷屏器\n";
	cout << "刷屏时将使用剪贴板里的内容\n\n";
	cout << "两次发送的间隔是多久？（单位：毫秒ms）\n> ";
	cin >> sleep_time;
	system("cls");
	int mode = 0;
	while (mode != 1 && mode != 2)
	{
		cout << "按什么按键发送？\n";
		cout << "1:Enter 2:Ctrl+Enter\n";
		cout << "> ";
		cin >> mode;
		system("cls");
	}
	cout << "请按任意键开始\n";
	_getch();
	system("cls");
	cout << "要停止刷屏，请切回到本页面并按下 [Esc] \n";
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
	cout << "感谢使用！请按任意键退出\n";
	_getch();
	return 0;
}

