#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    block1=new QButtonGroup(this);            //分组
    block1->addButton(ui->radioButton,0);                   //一个值为0
    block1->addButton(ui->radioButton_2,1);                 //一个值为1
    block1->addButton(ui->radioButton_3,2);                 //一个值为2

    //this->setAcceptDrops(true);
    ifstream in("/home/ytlp/Desktop/SE5/equal.csv");
    string path="/home/ytlp/Desktop/SE5/";
    string line;
    getline(in, line);
    getline(in, line);
    stringstream st;
    st.clear();//清空流错误标志位，以便下一次使用，但是没用不会清空使用的内存空间
    st.str("");//清空string流对象，清空内存，占用大小置0
    st.str(line);//用s作为st流中的内容
    getline(st, left, ',');
    qDebug()<<left.c_str() ;
    getline(st, right, ',');
    qDebug()<<right.c_str() ;
    left=path+left;
    right=path+right;
    QFile *lfile=new QFile;   //申请一个文件指针
    lfile->setFileName(QString::fromStdString(left));
    bool okl=lfile->open(QIODevice::ReadOnly);
    if(okl)
    {
        qDebug()<<"isOK!";
         QTextStream inleft(lfile);
         ui->textBrowser->setText(inleft.readAll());    //在textBrowser中显示文件内容
         lfile->close();
    }
    QFile *rfile=new QFile;   //申请一个文件指针
    rfile->setFileName(QString::fromStdString(right));
    bool okr=rfile->open(QIODevice::ReadOnly);
    if(okr)
    {
        qDebug()<<"isOK!";
         QTextStream inleft(rfile);
         ui->textBrowser_2->setText(inleft.readAll());    //在textBrowser中显示文件内容
         rfile->close();
    }
    in.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//FILE* fp1 = fopen("/home/ytlp/Desktop/bidpf/f.txt", "w");
void MainWindow::pickPair()
{

    fstream out("/home/ytlp/Desktop/SE5/finalEqual.csv");
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
    }
}



void MainWindow::on_pushButton_clicked()
{
    if(block1->checkedId()==0)
    {
        ofstream out("/home/ytlp/Desktop/SE5/finalEqual.csv",ios::app);
        out<<left<<","<<right<<","<<"0"<<endl;
        out.close();
    }
    else if(block1->checkedId()==1)
    {
        ofstream out("/home/ytlp/Desktop/SE5/finalEqual.csv",ios::app);
        out<<left<<","<<right<<","<<"1"<<endl;
        out.close();
    }
//    else if(block1->checkedId()==2)
//    {
//        ofstream out("/home/ytlp/Desktop/SE5/finalEqual.csv");
//        out<<left<<","<<right<<","<<"2"<<endl;
//        out.close();
//    }
    else
        return;
    refineFile();
    Res();
    ifstream in("/home/ytlp/Desktop/SE5/equal.csv");
    string path="/home/ytlp/Desktop/SE5/";
    string line;
    for(int i=0;i<count;++i)
    {
        getline(in, line);
    }
    while(getline(in, line))
    {
        ++count;
        stringstream st;
        st.clear();//清空流错误标志位，以便下一次使用，但是没用不会清空使用的内存空间
        st.str("");//清空string流对象，清空内存，占用大小置0
        st.str(line);//用s作为st流中的内容
        getline(st, left, ',');
        qDebug()<<left.c_str() ;
        getline(st, right, ',');
        qDebug()<<right.c_str() ;
        left=path+left;
        right=path+right;
        if(judge(left,right)==0)
        {
            QFile *lfile=new QFile;   //申请一个文件指针
            lfile->setFileName(QString::fromStdString(left));
            bool okl=lfile->open(QIODevice::ReadOnly);
            if(okl)
            {
                qDebug()<<"isOK!";
                 QTextStream inleft(lfile);
                 ui->textBrowser->setText(inleft.readAll());    //在textBrowser中显示文件内容
                 lfile->close();
            }
            QFile *rfile=new QFile;   //申请一个文件指针
            rfile->setFileName(QString::fromStdString(right));
            bool okr=rfile->open(QIODevice::ReadOnly);
            if(okr)
            {
                qDebug()<<"isOK!";
                 QTextStream inleft(rfile);
                 ui->textBrowser_2->setText(inleft.readAll());    //在textBrowser中显示文件内容
                 rfile->close();
            }
            in.close();
            return;
        }
    }
    QMessageBox::information(this,"提示信息","ALL of the files have been confirmed");
    Res();
    this->close();
}

