#pragma once

//C++ 随机数生成的简单适配
#include <random>

std::default_random_engine& global_urng()
{
    static std::default_random_engine u{};
    return u;
}

//通过重设发生器的种子使得接下来的数字真正的随机化
void randomize()
{
    static std::random_device rd{};
    global_urng().seed(rd());
}

//返回一个区间[a,b]之内的int数值
int pick(int from,int thro)
{
    static std::uniform_real_distribution<> d{};
    using parm_t = decltype(d)::param_type;
    return d(global_urng(),parm_t{from,thru});
}

//返回一个区间[a,b)之内的double值
double pick(double from,double thro)
{
     static std::uniform_real_distribution<> d{};
     using parm_t = decltype(d)::param_type;
     return d(global_urng(),parm_t{from,thru});
}

//投骰子例子
/*
 randomize();
 cout << "Now,we roll dice:\n";
 for(int i= 0; i < 15; ++i)
    cout << pick(1,6) << endl;
 */
