#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct Books {
    int serial;//编号
    string bookname;//书名
    string author;//作者
    string Press;//出版社
    string time;//出版时间
    int price;//价格
    string borrow;//判断是否被借走
};
//图书信息
struct Library {
    Books book[50];
    int count;
};
//图书馆信息
void Menu()
{
    cout << "-----------------------------" << endl;
    cout << "!  *中南大学图书馆管理系统*     !" << endl;
    cout << "!  1.登录书籍               !" << endl;
    cout << "!  2.浏览书籍               !" << endl;
    cout << "!  3.借阅书籍               !" << endl;
    cout << "!  4.归还书籍               !" << endl;
    cout << "!  5.书籍排序               !" << endl;
    cout << "!  6.删除书籍               !" << endl;
    cout << "!  0.退出系统               !" << endl;
    cout << "-----------------------------" << endl;
}
//菜单
void Logbooks(Library* Management)
{
    int year, month, day;
    string time;
    cout << "请输入图书编号：";
    cin >> Management->book[Management->count].serial;
    cout << "请输入图书书名：";
    cin >> Management->book[Management->count].bookname;
    cout << "请输入图书作者：";
    cin >> Management->book[Management->count].author;
    cout << "请输入图书出版社：";
    cin >> Management->book[Management->count].Press;
    cout << "请输入图书出版时间(格式：aaaa--bb--cc)：";
    cin >> Management->book[Management->count].time;
    cout << "请输入图书价格(单位/元)：";
    cin >> Management->book[Management->count].price;
    cout << "添加成功" << endl;
    system("pause");
    //使用清屏操作 
    system("cls");
    Management->count++;
}
//1.登录书籍
void Browsebooks(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "目前图书馆书籍为空" << endl;
        system("pause");
        //使用清屏操作 
        system("cls");
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            if (Management->book[i].borrow == "该书已被借走")
            {
                cout << "图书编号：" << Management->book[i].serial << "\t";//编号
                cout << "图书书名：" << Management->book[i].bookname << "\t";//书名
                cout << "图书作者：" << Management->book[i].author << "\t";//作者
                cout << "图书出版社：" << Management->book[i].Press << "\t";//出版社
                cout << "图书出版时间：" << Management->book[i].time << "\t";//时间
                cout << "图书价格：" << Management->book[i].price << "\t";//价格
                cout << "注：该书已被借走" << endl;
                if (i + 1 >= Management->count)break;
            }
            else
            {
                cout << "图书编号：" << Management->book[i].serial << "\t";//编号
                cout << "图书书名：" << Management->book[i].bookname << "\t";//书名
                cout << "图书作者：" << Management->book[i].author << "\t";//作者
                cout << "图书出版社：" << Management->book[i].Press << "\t";//出版社
                cout << "图书出版时间：" << Management->book[i].time << "\t";//时间
                cout << "图书价格：" << Management->book[i].price << endl;//价格
                if (i + 1 >= Management->count)break;
            }
        }
        system("pause");
        //使用清屏操作 
        system("cls");
    }
}
//2.浏览书籍
int Borrow(Library* Management, int t)
{
    if (Management->book[t].borrow == "该书已被借走")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//判断该书是否被借走
int Locatebooks(Library* Management, string bookname)
{
    int flag = 0;
    for (int i = 0; i < Management->count; i++, flag++)
    {
        if (Management->book[i].bookname == bookname)//寻找书
        {
            if (Borrow(Management, i) == 0)
                break;//该书未被借走的情况，返回书的数组下标
            else
            {
                flag = -1;//该书被借走的情况
                break;
            }
        }
        else
            flag = -3;//图书馆中未发现此书
    }
    return flag;
}
//查找书籍(根据书名)
void Borrowingbooks(Library* Management)
{
    void Filling(int, Library*);
    if (Management->count == 0)
    {
        cout << "图书馆中还未存放书籍" << endl;
    }
    else
    {
        string bookname;
        int t;
        cout << "请输入书名：";
        cin >> bookname;
        t = Locatebooks(Management, bookname);
        if (t >= 0)
        {
            Management->book[t].borrow = "该书已被借走";
            cout << "图书编号：" << Management->book[t].serial << "\t";//编号
            cout << "图书书名：" << Management->book[t].bookname << "\t";//书名
            cout << "图书作者：" << Management->book[t].author << "\t";//作者
            cout << "图书出版社：" << Management->book[t].Press << "\t";//出版社
            cout << "图书出版时间：" << Management->book[t].time << "\t";//时间
            cout << "图书价格：" << Management->book[t].price << endl;//价格
            cout << "书籍借阅成功！" << endl;
        }
        else if (t == -1)
        {
            cout << "该书已被借走" << endl;
        }
        else if (t == -3)
        {
            cout << "图书馆中未发现此书" << endl;
        }
    }system("pause");
    //使用清屏操作 
    system("cls");
}
//3.借阅书籍
int Whether(Library* Management)
{
    for (int i = 0; i < Management->count; i++)
    {
        if (Management->book[i].borrow == "该书已被借走")
            return 1;
        else
            return 0;
    }
}
//判断图书馆是否有被借书??
void Returningbooks(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "图书馆中还未存放书籍" << endl;
        system("pause");
        //使用清屏操作 
        system("cls");
    }
    else
    {
        if (Whether(Management) == 0)
        {
            cout << "图书馆未向外借出图书" << endl;
            cout << "本书非本图书馆所有" << endl;;
            int selete;
            cout << "请问您是否愿意将该数捐给凯武图书馆？" << endl;
            cout << "1--愿意" << endl;
            cout << "2--不愿意" << endl;
            cout << "请输入您的选择：";
            cin >> selete;
            if (selete == 1)
            {
                cout << "感谢您的捐赠！！！" << endl;
                cout << "麻烦您输入一下该书的相关信息：" << endl;
                cout << "请输入图书编号：";
                cin >> Management->book[Management->count].serial;
                cout << "请输入图书书名：";
                cin >> Management->book[Management->count].bookname;
                cout << "请输入图书作者：";
                cin >> Management->book[Management->count].author;
                cout << "请输入图书出版社：";
                cin >> Management->book[Management->count].Press;
                cout << "请输入图书出版时间(格式：aaaa--bb--cc)：";
                cin >> Management->book[Management->count].time;
                cout << "请输入图书价格(单位/元)：";
                cin >> Management->book[Management->count].price;
                cout << "添加成功" << endl;
                Management->count++;
                system("pause");
                //使用清屏操作 
                system("cls");
            }
            else if (selete == 2)
            {
                cout << "你已经被本图书馆列入黑名单" << endl;
                system("pause");
                //使用清屏操作 
                system("cls");
            }
            //隐藏功能
            system("pause");
            //使用清屏操作 
            system("cls");
        }
        else
        {
            string bookname;
            cout << "请输入待归还的书的书名：";
            cin >> bookname;
            int t = Locatebooks(Management, bookname);
            if (t >= 0)
            {
                Management->book[t].borrow = "该书已归还";
            }
            else if (t == -3)
            {
                cout << "图书馆中未发现此书" << endl;
                cout << "本书非本图书馆所有" << endl;;
                int selete;
                cout << "请问您是否愿意将该书捐给凯武图书馆？" << endl;
                cout << "1--愿意" << endl;
                cout << "2--不愿意" << endl;
                cout << "请输入您的选择：";
                cin >> selete;
                if (selete == 1)
                {
                    cout << "感谢您的捐赠！！！" << endl;
                    cout << "麻烦您输入一下该书的相关信息：" << endl;
                    cout << "请输入图书编号：";
                    cin >> Management->book[Management->count].serial;
                    cout << "请输入图书书名：";
                    cin >> Management->book[Management->count].bookname;
                    cout << "请输入图书作者：";
                    cin >> Management->book[Management->count].author;
                    cout << "请输入图书出版社：";
                    cin >> Management->book[Management->count].Press;
                    cout << "请输入图书出版时间(格式：aaaa--bb--cc)：";
                    cin >> Management->book[Management->count].time;
                    cout << "请输入图书价格(单位/元)：";
                    cin >> Management->book[Management->count].price;
                    cout << "添加成功" << endl;
                    Management->count++;
                    system("pause");
                    //使用清屏操作 
                    system("cls");
                }
                else if (selete == 2)
                {
                    cout << "你已经被本图书馆列入黑名单" << endl;
                    system("pause"); system("cls");
                }
            }system("pause"); system("cls");
        }
    }
}
//4.归还书籍
void Positionswitch(Books& a, Books& b)
{
    Books temp;
    temp = a;
    a = b;
    b = temp;
}
//位置互换
void BookSorting(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "图书馆中无书籍可供排序" << endl;
    }
    else
    {
        for (int i = 0; i < Management->count; i++)//排序
        {
            for (int k = 0; k < Management->count; k++)
            {
                if (Management->book[k].serial < Management->book[i].serial)
                    Positionswitch(Management->book[k], Management->book[i]);
            }
        }cout << "书籍已经根据编号由小到大排序成功" << endl;
    }
    system("pause"); system("cls");
}
//5.书籍排序
void Filling(int t, Library* Management)
{
    for (t = t; t < Management->count; t++)
    {
        Management->book[t + 1] = Management->book[t];
    }
}
//填充
void Deletebooks(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "无图书可删除" << endl;
        system("pause"); system("cls");
    }
    else
    {
        string bookname;
        cout << "请输入待删除书籍书名：";
        cin >> bookname;
        int t = Locatebooks(Management, bookname);
        if (t >= 0)
        {
            Filling(t, Management);//将位置向前移
            Management->count--;
            cout << "书籍删除成功" << endl;
        }
        else if (t == -1)
        {
            cout << "该书已被借走" << endl;
        }
        else if (t == -3)
        {
            cout << "图书馆中未发现此书" << endl;
        }
        system("pause"); system("cls");
    }
}

void inputFromFile(Library* Management)
{
    ifstream ifs;
    string filename;
    cout << "请输入文件路径：";
    cin >> filename;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        cout << "打开文件失败！";
        return;
    }
    while (true)
    {
        string temp;
        //cout << "请输入图书编号：";
        if (!(ifs >> temp))
        {
            break;
        }
        Management->book[Management->count].serial = stoi(temp);
        //cout << "请输入图书书名：";
        ifs >> temp;
        Management->book[Management->count].bookname = temp;
        //cout << "请输入图书作者：";
        ifs >> temp;
        Management->book[Management->count].author = temp;
        //cout << "请输入图书出版社：";
        ifs >> temp;
        Management->book[Management->count].Press = temp;
        //cout << "请输入图书出版时间(格式：aaaa--bb--cc)：";
        ifs >> temp;
        Management->book[Management->count].time = temp;
        //cout << "请输入图书价格(单位/元)：";
        ifs >> temp;
        Management->book[Management->count].price = stoi(temp);

        Management->count++;
    }
}


//6.删除书籍
int main()
{
    int selete;
    Library Management;
    Management.count = 0;
    do {
        Menu();
        cout << "请输入您的选择：";
        cin >> selete;
        switch (selete)
        {
        case 1://登录书籍
            Logbooks(&Management);
            break;
        case 2://浏览书籍
            Browsebooks(&Management);
            break;
        case 3://借阅书籍 
            Borrowingbooks(&Management);
            break;
        case 4://归还书籍
            Returningbooks(&Management);
            break;
        case 5://书籍排序
            BookSorting(&Management);
            break;
        case 6://删除书籍
            Deletebooks(&Management);
            break;
        case 0://退出系统
        {cout << "欢迎再次使用！";
        return 0;
        break; }
        default:
        {cout << "输入错误,请重新输入！";
        system("pause"); system("cls");
        break; }
        }
    } while (1);
}
