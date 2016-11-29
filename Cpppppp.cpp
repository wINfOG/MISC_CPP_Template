#include <iostream>
constexpr char FLAG[] = "Please_Input_The_Flag";  //input the flag !!!


template <int Num1, int Num2> struct __CMP_INT { enum { ret = (Num1 == Num2) }; };
template <int Num1, int Num2> struct __X0R_INT { enum { ret = (Num1 ^ Num2) }; };
template <int n> struct Input_N{enum { ret = FLAG[n] };};
template <int num,int Mod_num> struct _Mod{enum{ret = num % Mod_num}; };
template<int n, int num> struct _Roll_Left { const static int ret = num << n; };
template<int n, int num> struct _Roll_Right { const static int ret = num >> n; };
template<int x, int y> struct _And_OP { const static int ret = x & y; };
template<int x, int y> struct _Or_OP { const static int ret = x | y; };

template <int n> struct __Add { enum { ret = n+__Add<n - 1>::ret }; };
template <> struct __Add<0> { enum { ret = 0 }; };
template <int len> struct __CMP_Flag_len { enum { ret = __CMP_INT<(sizeof(FLAG) - 1), len>::ret }; };


template <int n, int r> struct Case_1_2{enum {ret = __CMP_INT<__X0R_INT<Input_N<n>::ret,0x20>::ret,93>::ret};};
template <int n> struct Case_1_2<n, 0> {enum { ret = 0 };};

constexpr int CMPN[] = { 88,83,68,86,75 };
template <int n> struct CMPN_N { enum { ret = CMPN[n] }; };
template<int n, int cmp> struct Case1_Loop{ enum { next = Case1_Loop<n-1,__CMP_INT<CMPN_N<n>::ret, __X0R_INT<Input_N<n>::ret, 0x30>::ret>::ret>::next};};
template<int n> struct Case1_Loop<n, 1>{enum { next = Case1_Loop<n - 1, __CMP_INT<CMPN_N<n>::ret, __X0R_INT<Input_N<n>::ret, 0x30>::ret>::ret>::next}; };
template<> struct Case1_Loop<-1,1>{	enum { next = 1 };};
template<int n> struct Case1_Loop<n, 0> {enum { next = 0 }; };


template<int n, int cmp> struct _Add0rDec { enum { ret = 0 }; };

template<int n> struct _Add0rDec<n, 0> { enum { ret = (Input_N<n + 5* __CMP_Flag_len<26>::ret>::ret + n) }; };
template<int n> struct _Add0rDec<n, 1> { enum { ret = (Input_N<n + 5* __CMP_Flag_len<26>::ret>::ret - n) }; };
template<int n> struct _cAse2_X0r {enum {ret = __X0R_INT<__Add<n>::ret, 106>::ret}; };
template<int n> struct Case2_Encode{enum{ret = __X0R_INT<_Add0rDec<n, _Mod<n,2>::ret>::ret, _cAse2_X0r<n>::ret>::ret};};

template<int n> struct _SwapLeftRight { const static int ret = _Or_OP<_Roll_Right<4, n>::ret, _Roll_Left<4, _And_OP<n, 0xF>::ret>::ret>::ret; };
template<int n> struct Case2_Check { const static int ret = __X0R_INT<_SwapLeftRight<Case2_Encode<n>::ret>::ret, Case2_Check<n - 1>::ret>::ret; };
template <> struct Case2_Check<0> { const static int ret = _SwapLeftRight<Case2_Encode<0>::ret>::ret; };

constexpr int Check_The_Flag[] = { 0x93,0xd7, 0x57, 0xb5, 0xe5, 0xb0, 0xb0, 0x52, 0x2, 0x0, 0x72, 0xb5, 0xf1, 0x80, 0x7, 0x30, 0xa, 0x30, 0x44, 0xb };
template <int n> struct _Flag_Check { enum { ret = Check_The_Flag[n] }; };
template <int n, int cmp> struct Check_Flag { enum {ret = Check_Flag<n+1, __CMP_INT< _Flag_Check<n>::ret, Case2_Check<n>::ret>::ret>::ret}; };
template <> struct Check_Flag<20,1> {enum {ret  = 1}; };
template <int n> struct Check_Flag<n, 0> { enum { ret = 0 }; };//error


template <int ret__CMP_Flag_len> struct __Case1
{
	enum { ret = Case_1_2<26- ret__CMP_Flag_len,Case1_Loop<4, 1>::next>::ret };
};
template <> struct __Case1 <0> { enum { ret = 0 }; };



struct __Start
{
	enum
	{
		ret = Check_Flag<0, __Case1<__CMP_Flag_len<26>::ret>::ret>::ret
	};
};


int main()
{
	if (__Start::ret)
	{
		printf("You got it\n");
	}
	else
	{
		printf("Sorry\n");
	}
	return 0;
}
