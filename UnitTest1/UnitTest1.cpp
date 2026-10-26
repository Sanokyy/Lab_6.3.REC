
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63REK
{
    TEST_CLASS(UnitTest63REK)
    {
    public:

        int SumEven(int a[], int n, int i)
        {
            if (i == n)
                return 0;

            if (a[i] % 2 == 0)
                return a[i] + SumEven(a, n, i + 1);
            else
                return SumEven(a, n, i + 1);
        }

        template <typename T>
        T SumEven(T a[], int n, int i)
        {
            if (i == n)
                return T();

            if (a[i] % 2 == 0)
                return a[i] + SumEven<T>(a, n, i + 1);
            else
                return SumEven<T>(a, n, i + 1);
        }

        TEST_METHOD(Test1)
        {
            int a[6] = { 2, 7, 4, 9, -6, 8 };
            Assert::AreEqual(8, SumEven(a, 6, 0));
        }

        TEST_METHOD(Test2)
        {
            int a[5] = { 1, 3, 5, 7, 9 };
            Assert::AreEqual(0, SumEven(a, 5, 0));
        }

        TEST_METHOD(Test3)
        {
            int a[4] = { 2, 4, 6, 8 };
            Assert::AreEqual(20, SumEven<int>(a, 4, 0));
        }

        TEST_METHOD(Test4)
        {
            int a[5] = { -2, -4, 3, 5, 0 };
            Assert::AreEqual(-6, SumEven<int>(a, 5, 0));
        }
    };
}
