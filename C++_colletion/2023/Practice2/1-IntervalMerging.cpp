#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

//�ϲ�����

using namespace std;//���� n������ [li,ri]��Ҫ��ϲ������н��������䡣ע������ڶ˵㴦�ཻ��Ҳ���н���������ϲ���ɺ�����������     ���磺[1,3]�� [2,6]���Ժϲ�Ϊһ������ [1,6]


// �ϲ�����

const int N = 100010;
int n;

typedef pair<int, int> pii;
vector<pii> nums, res; // �洢�����vector��nums����������䣬res�Ǻϲ���Ľ��

int main()
{
    int st = -2e9, ed = -2e9; // ��ʼ����ǰ�ϲ��������ʼ�ͽ���λ��
    int n;
    scanf("%d", &n); // ������ϲ����������
    while (n--)
    {
        int l, r;
        scanf("%d%d", &l, &r); // ����ÿ���������ʼ�ͽ���λ��
        nums.push_back({l, r}); // ������洢��nums��
    }
    sort(nums.begin(), nums.end()); // ��nums�е����䰴����ʼλ�ý�������

    for(auto num:nums)                   
        {
            if(ed<num.first)                            //���1�����������޷��ϲ�
            {
                if(ed!=-2e9) res.push_back({st,ed}) ;   //����1�Ž�res����
                st=num.first,ed=num.second ;            //ά������2
            }
            //���2������������Ժϲ���������1����������2������2����������1
            else if(ed<num.second)  
                ed=num.second ;                         //����ϲ�
        }  
    //(ʵ����Ҳ�����3������1��������2����ʱ����Ҫ�κβ���������ʡ��)

    //ע���Ź���֮�󣬲�����������2��������1

    
    if(st != -2e9)
    res.push_back({st,ed});

    //����ѭ������ʱ��st,ed��������ʱ��st,ed��������Ҫ����ά����ֻ��Ҫ�Ž�res���鼴�ɡ�
    //��Ϊ��������һ�����У����Բ����ܼ������кϲ���



    printf("%d", res.size()); // ����ϲ�����������

    return 0;
}