#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;
int ans[1024];
void conf();
void conf(){
	while(1){
        cout<<"请确认对此程序予以信任与认可。\n"
	          "如果不信任此程序，\n"
	          "可以选择停止使用并退出或卸载。\n"
	          "如果信任，请键入“confirm”后回车。\n";
    	cout<<"Please confirm that "
	          "you trust and approve of this program.\n"
	          " If you do not trust it,\n "
	          "you may choose to stop using it"
	          " and exit or uninstall it.\n"
	          " If you do trust it, "
	          "please type \"confirm\" "
	          "and press Enter.\n";
	    string confirm;
	    cin>>confirm;
	    if(confirm=="confirm")break;
	    
	    cout << "\033[2J\033[H" << flush;
	}
	cout << "\033[2J\033[H" << flush;
	return;
}
int main (){
	for(int k=0;k<1024;k++){
		ans[k]=0;
	}
	srand((int)time(0));
    conf();
    cout<<"输入题目数量（不超过1024）：";
    int num;
    cin>>num;
    cout<<"输入出题范围（建议10～500，但是可能更大）：";
    int sco;
    cin>>sco;
    cout<<"输入答案取值上限：";
    int ans_top;
    cin>>ans_top;
    cout<<"输入答案取值下限：";
    int ans_bott;
    cin>>ans_bott;
	int a,b;
	bool c;
	int i=0;
	int line=0;
	int sum=0;
	ofstream fout("/storage/emulated/0/Documents/math_homework.txt");
	while (i < num) {
	if (line == 4) {
		fout << endl;
		line = 0;
	}
	a = rand() % sco;
	b = rand() % sco;
	c = rand() % 2;

	// 1. 先按运算符算结果
	if (c == 1) {
		sum=a+b;
	} else {
		sum=a-b;
	}
	if (sum < ans_bott || sum > ans_top) continue;
	
	// 3. 顺手干掉 +0、-0
	if (a == 0 || b == 0) continue;

	// 4. 输出题目
	fout << a;
	if (c == 1) fout << "+";
	else        fout << "-";
	fout << b << "=" <<"     ";
	
	// 5. 存答案，推进循环
	ans[i] = sum;
	i++;
	line++;
}
	cout<<"题目输出完成，正在输出答案……\n";
	line=0;
	fout<<endl<<endl<<"以下为答案"<<endl<<endl;
	for(int op=0;op<num;op++){
		fout<<setw(4)<<ans[op]<<" ";
		line++;
		if(line==4){
			fout<<endl;
			line=0;
		}
	}
	cout<<"操作已成功完成。\n"
	      "提示：题目四个一行，答案与题目排版对应。\n"
	      "查看题目与答案，请转到：\n"
	      "/storage/emulated/0/Documents/math_homework.txt\n"
	      "（即在文件管理里面显示“文件”“文档”一类的文件夹）。";
	fout.close();
	return 0;
}
	