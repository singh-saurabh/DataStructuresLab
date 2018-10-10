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
    freopen("uncompressed_file.txt","w",stdout);
    int hashTableSize=275;
    set<int> valuesExisting;
    vector<string> hashTable(275);
    for(int i=0;i<256;++i)
    {
        string tem(1,char(i));
        valuesExisting.insert(i);
        hashTable[i]=tem;
    }
    int used=256;
    for(int i=256;i<275;++i)
    {
        hashTable[i]="NULL";
    }
    string pr = "" ;
    int pcode;
    int ccode;
    string decompressed;
    cin>>pcode;
    decompressed+=hashTable[pcode];
    while(cin>>ccode)
    {
        if(valuesExisting.find(ccode)==valuesExisting.end())
        {
            string tem(1,hashTable[pcode][0]);
            insertHash(hashTable,hashTable[pcode]+tem);
            valuesExisting.insert(getCode(hashTable,hashTable[pcode]+tem));
            decompressed+=hashTable[pcode]+tem;
        }
        else
        {
            string tem(1,hashTable[ccode][0]);
            insertHash(hashTable,hashTable[pcode]+tem);
            valuesExisting.insert(getCode(hashTable,hashTable[pcode]+tem));
            decompressed+=hashTable[ccode];
        }
        ++used;
        if(used>=hashTable.size()-hashTable.size()/10)
            hashTable.resize(2*hashTable.size(),"NULL");        
        pcode=ccode;
    }
    cout<<decompressed;
}