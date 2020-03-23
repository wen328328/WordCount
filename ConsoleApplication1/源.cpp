#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    FILE* fin;
    errno_t err_src_name;

    char  src_name[128];

    cout << "输入文件名：" << endl;
    cin >> src_name;


    err_src_name = fopen_s(&fin, src_name, "r");

    if (err_src_name != 0)
    {
        cout << "打开文件失败" << endl;
        return 0;

    }
}