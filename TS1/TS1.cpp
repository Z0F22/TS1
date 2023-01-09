#include<iostream>
#include<fstream>
#include<string >
#include<sstream>
using namespace std;
int data_transfer(int orig_0, int orig_1);

int data_transfer(int orig_0, int orig_1)
{
	int sign = orig_0 >> 7;
	int exp = (orig_0 & 0x78) >> 3; //指数
	int mantis = (orig_0 & 0x07) * 256 + orig_1; //尾数
	int data;
	if (sign == 0) //符号
		data = (mantis << exp);
	else
		data = -(mantis << exp);
	return data;
}

void main()
{
	//输出文件定名为out.txt,与test.txt同目录

	int n = 0;
	int max_n = 0;
	int length = 63;
	char line[252];//缓冲区
	float pos[63][4] = {0};//最多能存储150个十进制数

	ifstream ifile("test.txt");
	while (ifile.good())
	{
		//Code Add..
		stringstream ss;
		int num = 0;

		ifile.getline(line, 252);
		puts(line);//检验是否能正常输出
		istringstream iss(line);//char向float转换

		//Code Add...
		ss << hex << line;
		
		for (n = 0; n < length; n++)
		{
			for (int i = 0; i < 4; i++)
			{	
				ss >> num;
				pos[n][i] = num;
				//iss >> pos[n][0] >> pos[n][1];//读取数据
			}
		}
	}
	max_n = n;
	n = 0;
	//控制台输出
	cout << endl << "OutPut:" << endl;
	for (n = 0; n < length; n++)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << pos[n][i]<<" ";
		}
		cout << endl;
	}

	//输出到out.txt
	ofstream outfile("out.txt");
	for (n = 0; n < length; n++)
	{
		for (int i = 0; i < 4; i++)
		{
			outfile << pos[n][i] << " ";
		}
		outfile << endl;
		cout << endl;
	}
	cout << "\"Output To File\" Action Done!" << endl;

	return;
	//int n = 0;
	//char line[512];//缓冲区
	//float pos[150][2];//转换数组区，从左至右分别是序号，X轴，Y轴，Z轴
	//ifstream ifile("test.txt");
	//while (ifile.good())
	//{
	//	ifile.getline(line, 512);
	//	puts(line);//检验是否能正常输出
	//	istringstream iss(line);//char向float转换
	//	iss >> pos[n][0] >> pos[n][1];//读取数据
	//	n++;
	//}
	//n = 0;
	//while (pos[n]!=0)
	//{
	//	cout << pos[n][0] << pos[n][1];
	//	n++;
	//}
	/*string str = "i an a boy";
	istringstream is(str);
	string s;
	while (is >> s)
	{
		cout << s << endl;
	}*/
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
