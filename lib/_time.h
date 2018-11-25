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

    /* flag = 0 从小到大进行排序；flag = 1 从大到小进行排序 */
    friend void sorted(Time t[], int len, int flag);
    friend void show_all(const Time t[], int len);
    friend int difference(const Time &t1, const Time &t2); // 只比较时间，返回时间s
    friend std::ostream & operator<<(std::ostream &os, const Time & t);


    void show() const;
    string format();
};

void _sleep(int second);     // 延时函数，单位为(s)
long get_current_time_msec();      // 获得毫秒级系统时间
Time get_localtime();   // 获得当前日期和时间(精确到单位s)


class ParamError
{
    int param;
public:
    ParamError(int p) : param(p) { }
    void what();
};


#endif // _TIME_H_INCLUDED
