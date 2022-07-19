#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct Books {
    int serial;//���
    string bookname;//����
    string author;//����
    string Press;//������
    string time;//����ʱ��
    int price;//�۸�
    string borrow;//�ж��Ƿ񱻽���
};
//ͼ����Ϣ
struct Library {
    Books book[50];
    int count;
};
//ͼ�����Ϣ
void Menu()
{
    cout << "-----------------------------" << endl;
    cout << "!  *���ϴ�ѧͼ��ݹ���ϵͳ*     !" << endl;
    cout << "!  1.��¼�鼮               !" << endl;
    cout << "!  2.����鼮               !" << endl;
    cout << "!  3.�����鼮               !" << endl;
    cout << "!  4.�黹�鼮               !" << endl;
    cout << "!  5.�鼮����               !" << endl;
    cout << "!  6.ɾ���鼮               !" << endl;
    cout << "!  0.�˳�ϵͳ               !" << endl;
    cout << "-----------------------------" << endl;
}
//�˵�
void Logbooks(Library* Management)
{
    int year, month, day;
    string time;
    cout << "������ͼ���ţ�";
    cin >> Management->book[Management->count].serial;
    cout << "������ͼ��������";
    cin >> Management->book[Management->count].bookname;
    cout << "������ͼ�����ߣ�";
    cin >> Management->book[Management->count].author;
    cout << "������ͼ������磺";
    cin >> Management->book[Management->count].Press;
    cout << "������ͼ�����ʱ��(��ʽ��aaaa--bb--cc)��";
    cin >> Management->book[Management->count].time;
    cout << "������ͼ��۸�(��λ/Ԫ)��";
    cin >> Management->book[Management->count].price;
    cout << "��ӳɹ�" << endl;
    system("pause");
    //ʹ���������� 
    system("cls");
    Management->count++;
}
//1.��¼�鼮
void Browsebooks(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "Ŀǰͼ����鼮Ϊ��" << endl;
        system("pause");
        //ʹ���������� 
        system("cls");
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            if (Management->book[i].borrow == "�����ѱ�����")
            {
                cout << "ͼ���ţ�" << Management->book[i].serial << "\t";//���
                cout << "ͼ��������" << Management->book[i].bookname << "\t";//����
                cout << "ͼ�����ߣ�" << Management->book[i].author << "\t";//����
                cout << "ͼ������磺" << Management->book[i].Press << "\t";//������
                cout << "ͼ�����ʱ�䣺" << Management->book[i].time << "\t";//ʱ��
                cout << "ͼ��۸�" << Management->book[i].price << "\t";//�۸�
                cout << "ע�������ѱ�����" << endl;
                if (i + 1 >= Management->count)break;
            }
            else
            {
                cout << "ͼ���ţ�" << Management->book[i].serial << "\t";//���
                cout << "ͼ��������" << Management->book[i].bookname << "\t";//����
                cout << "ͼ�����ߣ�" << Management->book[i].author << "\t";//����
                cout << "ͼ������磺" << Management->book[i].Press << "\t";//������
                cout << "ͼ�����ʱ�䣺" << Management->book[i].time << "\t";//ʱ��
                cout << "ͼ��۸�" << Management->book[i].price << endl;//�۸�
                if (i + 1 >= Management->count)break;
            }
        }
        system("pause");
        //ʹ���������� 
        system("cls");
    }
}
//2.����鼮
int Borrow(Library* Management, int t)
{
    if (Management->book[t].borrow == "�����ѱ�����")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//�жϸ����Ƿ񱻽���
int Locatebooks(Library* Management, string bookname)
{
    int flag = 0;
    for (int i = 0; i < Management->count; i++, flag++)
    {
        if (Management->book[i].bookname == bookname)//Ѱ����
        {
            if (Borrow(Management, i) == 0)
                break;//����δ�����ߵ������������������±�
            else
            {
                flag = -1;//���鱻���ߵ����
                break;
            }
        }
        else
            flag = -3;//ͼ�����δ���ִ���
    }
    return flag;
}
//�����鼮(��������)
void Borrowingbooks(Library* Management)
{
    void Filling(int, Library*);
    if (Management->count == 0)
    {
        cout << "ͼ����л�δ����鼮" << endl;
    }
    else
    {
        string bookname;
        int t;
        cout << "������������";
        cin >> bookname;
        t = Locatebooks(Management, bookname);
        if (t >= 0)
        {
            Management->book[t].borrow = "�����ѱ�����";
            cout << "ͼ���ţ�" << Management->book[t].serial << "\t";//���
            cout << "ͼ��������" << Management->book[t].bookname << "\t";//����
            cout << "ͼ�����ߣ�" << Management->book[t].author << "\t";//����
            cout << "ͼ������磺" << Management->book[t].Press << "\t";//������
            cout << "ͼ�����ʱ�䣺" << Management->book[t].time << "\t";//ʱ��
            cout << "ͼ��۸�" << Management->book[t].price << endl;//�۸�
            cout << "�鼮���ĳɹ���" << endl;
        }
        else if (t == -1)
        {
            cout << "�����ѱ�����" << endl;
        }
        else if (t == -3)
        {
            cout << "ͼ�����δ���ִ���" << endl;
        }
    }system("pause");
    //ʹ���������� 
    system("cls");
}
//3.�����鼮
int Whether(Library* Management)
{
    for (int i = 0; i < Management->count; i++)
    {
        if (Management->book[i].borrow == "�����ѱ�����")
            return 1;
        else
            return 0;
    }
}
//�ж�ͼ����Ƿ��б�����??
void Returningbooks(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "ͼ����л�δ����鼮" << endl;
        system("pause");
        //ʹ���������� 
        system("cls");
    }
    else
    {
        if (Whether(Management) == 0)
        {
            cout << "ͼ���δ������ͼ��" << endl;
            cout << "����Ǳ�ͼ�������" << endl;;
            int selete;
            cout << "�������Ƿ�Ը�⽫�����������ͼ��ݣ�" << endl;
            cout << "1--Ը��" << endl;
            cout << "2--��Ը��" << endl;
            cout << "����������ѡ��";
            cin >> selete;
            if (selete == 1)
            {
                cout << "��л���ľ���������" << endl;
                cout << "�鷳������һ�¸���������Ϣ��" << endl;
                cout << "������ͼ���ţ�";
                cin >> Management->book[Management->count].serial;
                cout << "������ͼ��������";
                cin >> Management->book[Management->count].bookname;
                cout << "������ͼ�����ߣ�";
                cin >> Management->book[Management->count].author;
                cout << "������ͼ������磺";
                cin >> Management->book[Management->count].Press;
                cout << "������ͼ�����ʱ��(��ʽ��aaaa--bb--cc)��";
                cin >> Management->book[Management->count].time;
                cout << "������ͼ��۸�(��λ/Ԫ)��";
                cin >> Management->book[Management->count].price;
                cout << "��ӳɹ�" << endl;
                Management->count++;
                system("pause");
                //ʹ���������� 
                system("cls");
            }
            else if (selete == 2)
            {
                cout << "���Ѿ�����ͼ������������" << endl;
                system("pause");
                //ʹ���������� 
                system("cls");
            }
            //���ع���
            system("pause");
            //ʹ���������� 
            system("cls");
        }
        else
        {
            string bookname;
            cout << "��������黹�����������";
            cin >> bookname;
            int t = Locatebooks(Management, bookname);
            if (t >= 0)
            {
                Management->book[t].borrow = "�����ѹ黹";
            }
            else if (t == -3)
            {
                cout << "ͼ�����δ���ִ���" << endl;
                cout << "����Ǳ�ͼ�������" << endl;;
                int selete;
                cout << "�������Ƿ�Ը�⽫����������ͼ��ݣ�" << endl;
                cout << "1--Ը��" << endl;
                cout << "2--��Ը��" << endl;
                cout << "����������ѡ��";
                cin >> selete;
                if (selete == 1)
                {
                    cout << "��л���ľ���������" << endl;
                    cout << "�鷳������һ�¸���������Ϣ��" << endl;
                    cout << "������ͼ���ţ�";
                    cin >> Management->book[Management->count].serial;
                    cout << "������ͼ��������";
                    cin >> Management->book[Management->count].bookname;
                    cout << "������ͼ�����ߣ�";
                    cin >> Management->book[Management->count].author;
                    cout << "������ͼ������磺";
                    cin >> Management->book[Management->count].Press;
                    cout << "������ͼ�����ʱ��(��ʽ��aaaa--bb--cc)��";
                    cin >> Management->book[Management->count].time;
                    cout << "������ͼ��۸�(��λ/Ԫ)��";
                    cin >> Management->book[Management->count].price;
                    cout << "��ӳɹ�" << endl;
                    Management->count++;
                    system("pause");
                    //ʹ���������� 
                    system("cls");
                }
                else if (selete == 2)
                {
                    cout << "���Ѿ�����ͼ������������" << endl;
                    system("pause"); system("cls");
                }
            }system("pause"); system("cls");
        }
    }
}
//4.�黹�鼮
void Positionswitch(Books& a, Books& b)
{
    Books temp;
    temp = a;
    a = b;
    b = temp;
}
//λ�û���
void BookSorting(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "ͼ��������鼮�ɹ�����" << endl;
    }
    else
    {
        for (int i = 0; i < Management->count; i++)//����
        {
            for (int k = 0; k < Management->count; k++)
            {
                if (Management->book[k].serial < Management->book[i].serial)
                    Positionswitch(Management->book[k], Management->book[i]);
            }
        }cout << "�鼮�Ѿ����ݱ����С��������ɹ�" << endl;
    }
    system("pause"); system("cls");
}
//5.�鼮����
void Filling(int t, Library* Management)
{
    for (t = t; t < Management->count; t++)
    {
        Management->book[t + 1] = Management->book[t];
    }
}
//���
void Deletebooks(Library* Management)
{
    if (Management->count == 0)
    {
        cout << "��ͼ���ɾ��" << endl;
        system("pause"); system("cls");
    }
    else
    {
        string bookname;
        cout << "�������ɾ���鼮������";
        cin >> bookname;
        int t = Locatebooks(Management, bookname);
        if (t >= 0)
        {
            Filling(t, Management);//��λ����ǰ��
            Management->count--;
            cout << "�鼮ɾ���ɹ�" << endl;
        }
        else if (t == -1)
        {
            cout << "�����ѱ�����" << endl;
        }
        else if (t == -3)
        {
            cout << "ͼ�����δ���ִ���" << endl;
        }
        system("pause"); system("cls");
    }
}

void inputFromFile(Library* Management)
{
    ifstream ifs;
    string filename;
    cout << "�������ļ�·����";
    cin >> filename;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        cout << "���ļ�ʧ�ܣ�";
        return;
    }
    while (true)
    {
        string temp;
        //cout << "������ͼ���ţ�";
        if (!(ifs >> temp))
        {
            break;
        }
        Management->book[Management->count].serial = stoi(temp);
        //cout << "������ͼ��������";
        ifs >> temp;
        Management->book[Management->count].bookname = temp;
        //cout << "������ͼ�����ߣ�";
        ifs >> temp;
        Management->book[Management->count].author = temp;
        //cout << "������ͼ������磺";
        ifs >> temp;
        Management->book[Management->count].Press = temp;
        //cout << "������ͼ�����ʱ��(��ʽ��aaaa--bb--cc)��";
        ifs >> temp;
        Management->book[Management->count].time = temp;
        //cout << "������ͼ��۸�(��λ/Ԫ)��";
        ifs >> temp;
        Management->book[Management->count].price = stoi(temp);

        Management->count++;
    }
}


//6.ɾ���鼮
int main()
{
    int selete;
    Library Management;
    Management.count = 0;
    do {
        Menu();
        cout << "����������ѡ��";
        cin >> selete;
        switch (selete)
        {
        case 1://��¼�鼮
            Logbooks(&Management);
            break;
        case 2://����鼮
            Browsebooks(&Management);
            break;
        case 3://�����鼮 
            Borrowingbooks(&Management);
            break;
        case 4://�黹�鼮
            Returningbooks(&Management);
            break;
        case 5://�鼮����
            BookSorting(&Management);
            break;
        case 6://ɾ���鼮
            Deletebooks(&Management);
            break;
        case 0://�˳�ϵͳ
        {cout << "��ӭ�ٴ�ʹ�ã�";
        return 0;
        break; }
        default:
        {cout << "�������,���������룡";
        system("pause"); system("cls");
        break; }
        }
    } while (1);
}
