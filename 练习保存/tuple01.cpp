#include "Test.h"


int main()
{
    string s = "my tuple";
    auto x = make_tuple(s);
    get<0>(x) = "my value";
    cout << s << endl;
    cout << get<0>(x) << endl;

    auto y = make_tuple(ref(s));
    get<0>(y) = "my dream";
    cout << s << endl;
    cout << get<0>(y) << endl;

    typedef tuple<int, float , string> TupleType;
    cout << tuple_size<TupleType>::value << endl;
    tuple_element<1, TupleType>::type n = 10.567;
    cout << n << endl;

    auto tt = tuple_cat(make_tuple(42, 7.7, "tuple"), tie(n));
    cout << get<0>(tt) << endl;
    cout << get<1>(tt) << endl;
    cout << get<2>(tt) << endl;
    cout << get<3>(tt) << endl;

    return 0;
}