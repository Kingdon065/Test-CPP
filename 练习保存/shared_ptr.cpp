#include "Test.h"



int main()
{
    unique_ptr<int[]> pU_ints(new int[5]);
    // ָ���Լ���deleter
    unique_ptr<int, void(*)(int*)> pU_ints2(new int[5], [](int* p) {delete [] p;});
    // shared_ptrָ���������ʱ�����ṩdeleter
    shared_ptr<int> pS_ints(new int[5], [](int* p) {delete[] p;});
    shared_ptr<int> pS_ints2(new int[5], default_delete<int>());

    for (int i = 0; i < 5; i++)
        pU_ints[i] = i;

    for (int i = 0; i < 5; i++)
        cout << pU_ints[i] << ' ';
    cout << endl;


    return 0;
}