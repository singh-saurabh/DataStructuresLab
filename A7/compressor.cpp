#include<bits/stdc++.h>
#define int long long 
using namespace std;
int gethash(string s)
{
    int h=0;
    for(int i=0;i<s.length();++i)
    {
        h+=s[i];
    }
    return h;
}
void insertHash(vector<string> &hashTable,string s)
{
    int h=gethash(s);
    int k=1,size=hashTable.size();
    h%=size;
    while(hashTable[h] != "NULL" )
    {
        h+=k*k;
        ++k;
        h%=size;
    }
    hashTable[h]=s;
}
int getCode(vector<string> &hashTable,string s)
{
    int h=gethash(s);
    int k=1,size=hashTable.size();
    h%=size;
    while(hashTable[h] != s )
    {
        h+=k*k;
        ++k;
        h%=size;
    }
    return h;   
}
signed main(signed num,char* inputf[])
{
    freopen(inputf[1],"r",stdin);
    freopen("compressed_file.txt","w",stdout);
    string s;
    getline(cin,s);
    int n=s.length();
    string compressedString;
    int hashTableSize=275;
    set<string> valuesExisting;
    vector<string> hashTable(275);
    for(int i=0;i<256;++i)
    {
        string tem(1,char(i));
        valuesExisting.insert(tem);
        hashTable[i]=tem;
    }
    int used=256;
    for(int i=256;i<275;++i)
    {
        hashTable[i]="NULL";
    }
    string pr = "" ;
    for(int i=0;i<n;++i)
    {
        string tem(1,s[i]);
        pr += "" + tem ;
        if(valuesExisting.find(pr)==valuesExisting.end())
        {
            insertHash(hashTable,pr);
            valuesExisting.insert(pr);
            ++used;
            if(used>=hashTable.size()-hashTable.size()/10)
                hashTable.resize(2*hashTable.size(),"NULL");
            cout<<getCode(hashTable,pr.substr(0,pr.size()-1))<<" ";
            pr= "" + tem ;
        }
    }
    cout<<getCode(hashTable,pr)<<" "; 
}