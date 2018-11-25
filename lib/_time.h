#ifndef _TIME_H_INCLUDED
#define _TIME_H_INCLUDED
#include <string>
using std::string;

class Time
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    string weekday;
public:
    Time(int y=1970, int m=1, int d=1, int h=0,
         int mi=0, int s=0, const string & wd = "null");

    bool operator>(const Time & ct);
    bool operator<(const Time & ct);
    bool operator==(const Time & ct);

    /* flag = 0 ��С�����������flag = 1 �Ӵ�С�������� */
    friend void sorted(Time t[], int len, int flag);
    friend void show_all(const Time t[], int len);
    friend int difference(const Time &t1, const Time &t2); // ֻ�Ƚ�ʱ�䣬����ʱ��s
    friend std::ostream & operator<<(std::ostream &os, const Time & t);


    void show() const;
    string format();
};

void _sleep(int second);     // ��ʱ��������λΪ(s)
long get_current_time_msec();      // ��ú��뼶ϵͳʱ��
Time get_localtime();   // ��õ�ǰ���ں�ʱ��(��ȷ����λs)


class ParamError
{
    int param;
public:
    ParamError(int p) : param(p) { }
    void what();
};


#endif // _TIME_H_INCLUDED
