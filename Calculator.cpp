#include<iostream>
using namespace std;
int main()
{
    double a;//輸入的數字
    char b;//輸入的符號
    double sum;//輸出的總和
    double temp1;//暫存區1:被乘(除)數暨待加(減)數暫存區
    double temp2;//暫存區2:被次方數暨乘(除)數暫存區
    double num1;//處理次方時所用之數
    int num2;//處理數字翻轉時所用之數
    //輸入首數
    while(cin>>a)
    {
        //初始化階段
        sum=0;
        temp2=a;
        temp1=1;
        //以"符號(b)""數字(a)"為一組輸進迴圈
        while(cin>>b)
        {
            if(b=='+'||b=='-')
            {
                temp1*=temp2;//暫存區2乘進暫存區1裡
                sum+=temp1;//暫存區1加進總和裡
                temp1=1;//初始化暫存區1
                cin>>a;
                //判斷b的正負後將a丟進暫存區2
                if(b=='+')
                    temp2=a;
                else
                    temp2=(-a);
            }
            else if(b=='*'||b=='/')
            {
                temp1*=temp2;//暫存區2乘進暫存區1裡
                cin>>a;
                //判斷b的乘除後將a丟進暫存區2
                if(b=='*')
                    temp2=a;
                else
                    temp2=1/a;
            }
            else if(b=='^')
            {
                cin>>a;
                //確保正負號經次方後仍維持
                if(temp2<0)
                    num1=-temp2;
                else
                    num1=temp2;
                //處理次方
                for(int power_counter=(int)a-1;power_counter>0;power_counter--)
                    temp2*=num1;
            }
            else if(b=='$')
            {
                temp1*=temp2;//暫存區2乘進暫存區1裡
                sum+=temp1;//暫存區1加進總和裡
                temp1=1;//初始化暫存區1
                num2=(int)sum;//將總和的資料型態轉為整數以翻轉
                sum=0;//總和歸零
                //處理翻轉
                while(num2>=1)
                {
                    sum=sum*10+(num2%10);
                    num2/=10;
                }
                cin>>a;
                temp2=a;//將a丟進暫存區2
            }
            else
                break;
        }
        if(b=='=')
        {
            temp1*=temp2;//暫存區2乘進暫存區1裡
            sum+=temp1;//暫存區1加進總和裡
            cout<<"Sum= "<<sum<<endl<<endl;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
    return 0;
}
