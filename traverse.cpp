#include "traverse.h"

Traverse::Traverse()
{

}

void refineFile()
{
    Traverse traverse[1024];
    ifstream out("/home/ytlp/Desktop/SE5/finalEqual.csv");
    string line;
    int num=0;
    while(getline(out,line))
    {
        stringstream st;
        st.clear();//清空流错误标志位，以便下一次使用，但是没用不会清空使用的内存空间
        st.str("");//清空string流对象，清空内存，占用大小置0
        st.str(line);//用s作为st流中的内容
        string l,r,res;
        getline(st, l, ',');
        getline(st, r, ',');
        getline(st, res, ',');
        traverse[num].setLeft(l);
        traverse[num].setRight(r);
        traverse[num].setRes(res);
        ++num;
        traverse->addCount();
    }
    qDebug()<<num<<endl;
    out.close();
    ofstream out1("/home/ytlp/Desktop/SE5/finalEqual.csv",ios::app);
    if(num>1)
    for(int i=0;i<num;++i)
    {
        for(int j=i+1;j<num;++j)
        {
            int flag=0;
            string res1;
            string res2;
            string f1;
            string f2;
            if(traverse[i].getLeft()==traverse[j].getLeft())
            {
                res1=traverse[i].getRes();
                res2=traverse[j].getRes();
                f1=traverse[i].getRight();
                f2=traverse[j].getRight();
            }
            else if(traverse[i].getLeft()==traverse[j].getRight())
            {
                res1=traverse[i].getRes();
                res2=traverse[j].getRes();
                f1=traverse[i].getRight();
                f2=traverse[j].getLeft();
            }
            else if(traverse[i].getRight()==traverse[j].getRight())
            {
                res1=traverse[i].getRes();
                res2=traverse[j].getRes();
                f1=traverse[i].getLeft();
                f2=traverse[j].getLeft();
            }
            else if(traverse[i].getRight()==traverse[j].getLeft())
            {
                res1=traverse[i].getRes();
                res2=traverse[j].getRes();
                f1=traverse[i].getLeft();
                f2=traverse[j].getRight();
            }
            for(int k=0;k<num;++k)
            {
                if((f1==traverse[k].getLeft()&&f2==traverse[k].getRight())||(f2==traverse[k].getLeft()&&f1==traverse[k].getRight()))
                {
                    flag=1;
                    if((res1=="1"||res2=="1")&&traverse[k].getRes()=="0")
                        traverse[k].setRes("1");
                    break;
                }
            }
            if(flag==0)
            {
                if(res1=="0"&&res2=="0")
                {
                    traverse[num].setLeft(f1);
                    traverse[num].setRight(f2);
                    traverse[num].setRes("0");
                    ++num;
                    traverse->addCount();
                    if(f1!=""&&f2!="")
                        out1<<f1<<","<<f2<<","<<"0"<<endl;
                }
                else
                {
                    traverse[num].setLeft(f1);
                    traverse[num].setRight(f2);
                    traverse[num].setRes("1");
                    ++num;
                    traverse->addCount();
                    if(f1!=""&&f2!="")
                        out1<<f1<<","<<f2<<","<<"1"<<endl;
                }
            }
        }
    }
    out1.close();
}
bool judge(string left,string right)
{
    ifstream out("/home/ytlp/Desktop/SE5/finalEqual.csv");
    string line;
    while(getline(out,line))
    {
        stringstream st;
        st.clear();//清空流错误标志位，以便下一次使用，但是没用不会清空使用的内存空间
        st.str("");//清空string流对象，清空内存，占用大小置0
        st.str(line);//用s作为st流中的内容
        string l,r,res;
        getline(st, l, ',');
        getline(st, r, ',');
        getline(st, res, ',');
        if(l==left&&r==right)
        {
            out.close();
            return 1;
        }
        if(l==right&&r==left)
        {
            out.close();
            return 1;
        }
    }
    out.close();
    return 0;
}

void Res()
{
    ifstream out("/home/ytlp/Desktop/SE5/finalEqual.csv");
    ofstream resFile("/home/ytlp/Desktop/SE5/res.csv");
    resFile<<"file1,file2"<<endl;
    string line;
    while(getline(out,line))
    {
        stringstream st;
        st.clear();//清空流错误标志位，以便下一次使用，但是没用不会清空使用的内存空间
        st.str("");//清空string流对象，清空内存，占用大小置0
        st.str(line);//用s作为st流中的内容
        string l,r,res;
        getline(st, l, ',');
        getline(st, r, ',');
        getline(st, res, ',');
        if(res=="0")
            resFile<<l<<","<<r<<endl;
    }
    out.close();
    return;
}
