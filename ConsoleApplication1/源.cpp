#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    FILE* fin;
    errno_t err_src_name;

    char  src_name[128];

    cout << "�����ļ�����" << endl;
    cin >> src_name;


    err_src_name = fopen_s(&fin, src_name, "r");

    if (err_src_name != 0)
    {
        cout << "���ļ�ʧ��" << endl;
        return 0;

    }
}