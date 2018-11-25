#include <ctime>
#include <cmath>
#include <sstream>
#include <sys/time.h>   // for timeval
#include <iostream>
#include "_time.h"

// ��ʱ˯��
void  _sleep(int second)
{
    clock_t st = clock();
    while (clock()-st < second * CLOCKS_PER_SEC)
        ;
}

// ��ú��뼶ϵͳʱ��
long get_current_time_msec()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

// ��õ�ǰʱ��
Time get_localtime()
{
    time_t timer;
    struct tm *tblock;
    std::string weekdays[7] =
    {
        "Sun", "Mon", "Tues",
        "Wed", "Thur", "Fri", "Sat"
    };

    /* gets time of day */
    timer = time(NULL);

    /* converts date/time to a struture */
    tblock = localtime(&timer);
     Time t = {
            1900+tblock->tm_year,
            1+tblock->tm_mon,
            tblock->tm_mday,
            tblock->tm_hour,
            tblock->tm_min,
            tblock->tm_sec,
            weekdays[tblock->tm_wday]
     };

    return t;
}

// class Time
Time::Time(int y, int m, int d, int h, int mi, int s, const string &wd) :
    year(y), month(m), day(d), hour(h), minute(mi), second(s), weekday(wd)
{
}

// ��������� Overload
bool Time::operator>(const Time & t)
{
    int seconds1, seconds2;
    seconds1 = hour * 3600 + minute * 60 + second;
    seconds2 = t.hour * 3600 + t.minute * 60 + t.second;

    if (year > t.year)
        return true;
    else if (year == t.year && month > t.month)
        return true;
    else if (year == t.year && month == t.month && day > t.day)
        return true;
    else if (seconds1 > seconds2)
        return true;
    else
        return false;
}

bool Time::operator<(const Time & t)
{
    if (!(*this > t) && !(*this == t))
        return true;
    else
        return false;
}

bool Time::operator==(const Time & t)
{
    int seconds1, seconds2;
    seconds1 = hour * 3600 + minute * 60 + second;
    seconds2 = t.hour * 3600 + t.minute * 60 + t.second;

    if (year == t.year && month == t.month
        && day == t.day && seconds1 == seconds2)
        return true;
    else
        return false;
}

// ��Ԫ���������
std::ostream & operator<<(std::ostream &os, const Time & t)
{
    os.fill('0');
    os << t.year << '/';
    os.width(2);
    os << t.month << '/';
    os.width(2);
    os << t.day << ' ';
    os.width(2);
    os << t.hour << ':';
    os.width(2);
    os << t.minute << ':';
    os.width(2);
    os << t.second;
    if (t.weekday != "null")
        os << ' ' << t.weekday;
    return os;
}

void Time::show() const
{
    std::cout << *this << std::endl;
}

// ��ʽ��Time������Ϊһ��string
string Time::format()
{
    string format;
    std::ostringstream outstr;
    outstr << *this;
    format = outstr.str();

    return format;
}

// ��Ԫ����
/* flag = 0 ��С�����������flag = 1 �Ӵ�С�������� */
void sorted(Time t[], int len, int flag)
{
    Time temp;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (flag == 0)
            {
                if (t[i] > t[j])
                {
                    temp = t[i];
                    t[i] = t[j];
                    t[j] = temp;
                }
            }
            else if (flag == 1)
            {
                if (t[i] < t[j])
                {
                    temp = t[i];
                    t[i] = t[j];
                    t[j] = temp;
                }
            }
        }
    }
    if (flag != 0 && flag != 1)
        throw ParamError(flag);
}

// ��ʾTime����
void show_all(const Time t[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << t[i] << std::endl;
    }
}

// ֻ�Ƚ�ʱ�䣬����ʱ��s
int difference(const Time &lt1, const Time &lt2)
{
    int seconds1 = lt1.hour * 3600 + lt1.minute * 60 + lt1.second;
    int seconds2 = lt2.hour * 3600 + lt2.minute * 60 + lt2.second;

    return std::abs(seconds2 - seconds1);    // ���ؾ���ֵ
}

void ParamError::what()
{
    std::cout << "Error: ����" << param << "���Ϸ�.\n";
}
