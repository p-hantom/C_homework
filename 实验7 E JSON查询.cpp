#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
typedef long long ll;
int mo[4][2]= {0,1,1,0,0,-1,-1,0};
const int MAXN=0x3f3f3f3f;
const int sz=10005;
string s,str;
int pos,len,obcot,pacot;
int palen[sz],oblen[sz];
map<string,int> mp[sz];
map<int,string> ans[sz];
map<int,int> ob[sz];
void getparameter(int fa,int num)
{
    pos++;
    string tmp;
    for(int i=0; i<len&&pos<len; i++,pos++)
    {
        tmp+=str[pos];
        //cout<<tmp<<endl;
        if(str[pos+2]==','||str[pos+2]=='}')
        {

            pos+=2;
            ans[fa][num]="STRING "+tmp;
            break;
        }
    }

}

void getobject(int num)
{
    int son=1;
    for(; pos<len; pos++)
    {

        if(str[pos]=='\"')
        {
            pos++;
            string tmp;
            for(int i=0; i<len&&pos<len; i++,pos++)
            {
                tmp+=str[pos];
                //cout<<tmp<<endl;
                if(str[pos+2]==':')
                {
                    if(str[pos+3]=='\"')
                    {

                        pos+=3;
                        getparameter(num,son);
                        //cout<<str[pos]<<endl;
                        //cout<<num<<' '<<tmp<<' '<<son<<endl;
                        mp[num][tmp]=son++;
                        if(str[pos]=='}')
                        {
                            return ;
                        }
                        break;
                    }
                    else if(str[pos+3]=='{')
                    {

                        pos+=3;
                        ob[num][son]=++obcot;
                        getobject(obcot);
                        pos++;
                        ans[num][son]="OBJECT";
                        mp[num][tmp]=son++;
                        if(str[pos]=='}')
                        {
                            return ;
                        }
                        break;
                    }

                }
            }
        }
    }
}

void getans(int st,int num){
    int now;
    string tmp;
    for(int i=st;i<len;i++){
        tmp+=s[i];
        if(s[i+1]=='.'){
            //cout<<tmp<<endl;
            now=mp[num][tmp];

            if(now==0){
                cout<<"NOTEXIST"<<endl;
                return ;
            }
            now=ob[num][now];
            getans(i+2,now);
            return ;
        }else if(s[i+1]=='\0'){
            now=mp[num][tmp];

            if(now==0){
                cout<<"NOTEXIST"<<endl;
                return ;
            }
            //cout<<tmp<<endl;
            cout<<ans[num][now]<<endl;
            return ;
        }
    }
}

int main()
{
    freopen("r.txt","r",stdin);
    int n,m,cot;
    cin>>n>>m;
    getchar();
    string t;
    for(int i=1; i<=n; i++)
    {
        getline(cin,t);
        s.append(t);
    }
    //cout<<s<<endl;
    len=s.length();
    pos=0;
    cot=0;
    for(; pos<len; pos++)
    {
        if(s[pos]==' ')
        {
            continue;
        }
        if(s[pos]=='\\'){
            str+=s[++pos];
        }else{
            str+=s[pos];
        }
    }
cout<<str<<endl;
    len=str.length();pos=1;obcot=1;pacot=0;
    getobject(1);
    for(int i=1;i<=m;i++){
        getline(cin,s);
        //cout<<s<<endl;
        len=s.length();
        getans(0,1);
    }
    return 0;
}
