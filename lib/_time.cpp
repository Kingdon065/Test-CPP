#include <ctime>
#include <cmath>
#include <sstream>
#include <sys/time.h>   // for timeval
#include <iostream>
#include "_time.h"

// 定时睡眠
void  _sleep(int second)
{
    clock_t st = clock();
    while (clock()-st < second * CLOCKS_PER_SEC)
        ;
}

// 获得毫秒级系统时间
long get_current_time_msec()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

// 获得当前时间
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

// 重载运算符 Overload
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

// 友元重载运算符
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

// 格式化Time，保存为一个string
string Time::format()
{
    string format;
    std::ostringstream outstr;
    outstr << *this;
    format = outstr.str();

    return format;
}

// 友元函数
/* flag = 0 从小到大进行排序；flag = 1 从大到小进行排序 */
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

// 显示Time数组
void show_all(const Time t[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << t[i] << std::endl;
    }
}

// 只比较时间，返回时间s
int difference(const Time &lt1, const Time &lt2)
{
    int seconds1 = lt1.hour * 3600 + lt1.minute * 60 + lt1.second;
    int seconds2 = lt2.hour * 3600 + lt2.minute * 60 + lt2.second;

    return std::abs(seconds2 - seconds1);    // 返回绝对值
}

void ParamError::what()
{
    std::cout << "Error: 参数" << param << "不合法.\n";
}
