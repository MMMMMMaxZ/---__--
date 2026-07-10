#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 5000
struct Stick           //木棍结构体
{ int l;            //长度
    int w;            //重量
    bool flag;           //表示是否已处理过
    bool operator < (const Stick &o) const
    {
        return l<o.l || (l==o.l && w<o.w);
    }
};
Stick sticks[MAXN];
int main()
{
    ifstream inFile;
    inFile.open("in.txt", ios::in);
    if(!inFile){
        cout << "error open in.txt!" << endl;
        return 1;
    }

    if(!inFile.eof())
    {
        int n;
        inFile >> n;
        int l, w;
        for(int i=0; i<n;i++)
        {
            inFile >> l >> w;
            sticks[i].l = l;
            sticks[i].w = w;
            sticks[i].flag=false;
        }
        sort(sticks,sticks+n);
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (sticks[i].flag==false)    //若已经加工过，则继续循环
            {
                sticks[i].flag=true;
                int curw=sticks[i].w;     //当前木棍的重量
                for (int j=i+1;j<n;j++)
                {
                    if(!sticks[j].flag && sticks[j].w>=curw)
                    {
                        sticks[j].flag=true;  //直接加工该木棍
                        curw=sticks[j].w;
                    }
                }
                ans++;        //处理完所有不比curw小的木棍后，ans增1
            }
        }
        cout << ans << endl;
    }
    inFile.close();
    return 0;
}


