#ifndef TRAVERSE_H
#define TRAVERSE_H

#include<iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<QDebug>
using namespace std;

class Traverse
{
public:
    Traverse();
    int getCount()
    {
        return count;
    }
    string getLeft()
    {
        return left;
    }
    string getRight()
    {
        return right;
    }
    string getRes()
    {
        return res;
    }
    void addCount()
    {
        count=count+1;
    }
    void setTraverse(string l,string r,string re)
    {
        left=l;
        right=r;
        res=r;
    }
    void setLeft(string l)
    {
        left=l;
    }
    void setRight(string r)
    {
        right=r;
    }
    void setRes(string re)
    {
        res=re;
    }
private:
    string left;
    string right;
    string res;
    int count=0;

};
void refineFile();
bool judge(string left,string right);
void Res();
#endif // TRAVERSE_H
