#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <string.h>

////模拟实现strcpy
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(src);
//	char* ret = dest;
//	while (*dest++ = *src++);
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "hello bit";
//	char arr2[20] = "";
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a + 0));
//	printf("%d\n", sizeof(*a));
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", sizeof(a[1]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", sizeof(*&a));
//	printf("%d\n", sizeof(&a + 1));
//	printf("%d\n", sizeof(&a[0]));
//	printf("%d\n", sizeof(&a[0] + 1));
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));	//6
//	//arr单独放在sizeof内部，代表整个数组，大小为6个字节
//	printf("%d\n", sizeof(arr + 0));	//4/8
//	//arr代表首元素的地址，4/8个字节
//	printf("%d\n", sizeof(*arr));		//1
//	//arr代表首元素地址，对其解引用代表第一个元素，大小为1个字节
//	printf("%d\n", sizeof(arr[1]));    //1
//	//arr[1]代表数组第二个元素，1个字节
//	printf("%d\n", sizeof(&arr));	//4/8
//	//&arr取出整个数组地址，4/8个字节
//	printf("%d\n", sizeof(&arr + 1));	//4/8
//	//&arr取出整个数组的地址，&arr+1跳过一个数组，指向数组后面紧挨的空间，4/8个字节
//	printf("%d\n", sizeof(&arr[0] + 1));	///4/8
//	//&arr[0]代表首元素地址，+1代表第二个元素地址，4/8个字节
//	printf("%d\n", strlen(arr));	//随机值
//	//arr代表首元素地址，数组从第一个元素开始求字符串长度
//	//strlen求的是\0以前字符的个数，因为字符数组中并不包含\0，所以strlen会一直往后寻找，直到遇到\0，而我们不知道数组后面空间的内容，所以为随机值。
//	printf("%d\n", strlen(arr + 0));	//随机值
//	//arr+0代表首元素地址，数组从第一个元素开始求字符串长度
//	//随机值原因同上
//	printf("%d\n", strlen(*arr));	//error
//	//strlen函数的参数是一个地址，这里我们把第一个元素即'a'传给strlen函数，那么strlen就会把'a'的ASCII码值(97)当成地址来用，但是97处的地址并不属于我们，从而造成野指针问题，报错
//	printf("%d\n", strlen(arr[1]));	//error
//	//原因和上面类似
//	printf("%d\n", strlen(&arr));	//随机值
//	//&arr虽然取出整个数组的地址，但仍然是指向首元素，所以和上面的strlen(arr)一样
//	printf("%d\n", strlen(&arr + 1));	//随机值
//	//&arr取出整个数组的地址，+1跳过整个数组，指向数组后面紧挨的空间，但我们不知道后面空间何时遇到\0，所以仍然是随机值
//	printf("%d\n", strlen(&arr[0] + 1));	//随机值
//	//&arr[0]+1代表第二个元素地址，仍然是随机值
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));	//7
//	//arr代表整个数组，因为字符串末尾会自动补一个\0，所以arr数组有七个元素
//	printf("%d\n", sizeof(arr + 0));	//4/8
//	printf("%d\n", sizeof(*arr));	//1
//	printf("%d\n", sizeof(arr[1]));	//1
//	printf("%d\n", sizeof(&arr));	//4/8
//	printf("%d\n", sizeof(&arr + 1));	//4/8
//	printf("%d\n", sizeof(&arr[0] + 1));	//4/8
//
//	printf("%d\n", strlen(arr));	//6
//	//strlen遇到字符串末尾的\0停止，前面一共6个元素
//	printf("%d\n", strlen(arr + 0));	//6
//	printf("%d\n", strlen(*arr));	//error
//	printf("%d\n", strlen(arr[1]));    //error
//	printf("%d\n", strlen(&arr));	//6
//	printf("%d\n", strlen(&arr + 1));	//随机值
//	//&arr取出整个数组的地址，+1跳过整个数组，后面空间的内容未知，所以随机
//	printf("%d\n", strlen(&arr[0] + 1));	//5
//	//&arr[0]+1是第二个元素的地址，把它传给strlen，所以为5
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));	//4/8
//	//"abcdef"是常量字符串，char* p = "abcdef" 的作用是把字符串中'a'的地址赋给P，所以4/8
//	printf("%d\n", sizeof(p + 1));	//4/8
//	//p+1代表字符'b'的地址，4/8
//	printf("%d\n", sizeof(*p));    //1
//	printf("%d\n", sizeof(p[0]));	//1
//	printf("%d\n", sizeof(&p));    //4/8
//	//&p取出的是p的地址，是一个二级指针，但地址大小仍然是4/8
//	printf("%d\n", sizeof(&p + 1));    //4/8
//	//&p+1代表p所在空间后面紧挨的空间
//	printf("%d\n", sizeof(&p[0] + 1));    //4/8
//	//&p[0] <==> &(*(p+0)) <==> p，代表'a'的地址
//
//	printf("%d\n", strlen(p));    //6
//	printf("%d\n", strlen(p + 1));    //5
//	printf("%d\n", strlen(*p));    //error
//	printf("%d\n", strlen(p[0]));    //error
//	printf("%d\n", strlen(&p));    //随机值
//	//&p取出的是p的地址，这里有两个东西是不确定的：
//	//1、不知道p的地址中是否含有四个字节大小的数字0，p的地址可能0x14ffff44，也可能是0x1400ff00
//	//2、不知道p的后面空间的内容
//	//所以strlen求出来的值是随机的
//	printf("%d\n", strlen(&p + 1));    //随机值
//	//&p+1跳过了p的地址，直接来到了p其后的空间，消除了上面的第一点不确定，但第二段仍然存在
//	printf("%d\n", strlen(&p[0] + 1));    //5
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	//printf("%d\n", sizeof(p));
//	//printf("%d\n", sizeof(p + 1));
//	//printf("%d\n", sizeof(*p));
//	//printf("%d\n", sizeof(p[0]));
//	//printf("%d\n", sizeof(&p));
//	//printf("%d\n", sizeof(&p + 1));
//	//printf("%d\n", sizeof(&p[0] + 1));
//
//	//printf("%d\n", strlen(p));
//	//printf("%d\n", strlen(p + 1));
//	//printf("%d\n", strlen(*p));
//	//printf("%d\n", strlen(p[0]));
//	printf("%d\n", strlen(&p));
//	printf("%d\n", strlen(&p + 1));
//	printf("%d\n", strlen(&p[0] + 1));
//	return 0;
//}

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));	//48
	//a单独放在sizeof内部，表示整个二维数组的大小，3*4*4=48
	printf("%d\n", sizeof(a[0][0]));	//4
	//a[0][0]代表第一个元素，整形占4个字节
	printf("%d\n", sizeof(a[0]));	//16
	//二维数组的行名代表其对应一维数组的数组名
	//这里的a[0]代表二维数组第一行的数组名
	//一维数组的数组名单独放在sizeof内部，代表整个一维数组，4*4=16
	printf("%d\n", sizeof(a[0] + 1));	//4/8
	//a[0]代表第一行的数组名
	//a[0]不是单独放在sizeof内部，所以数组名代表首元素地址，即a[0][0]的地址
	//所以a[0]+1代表数组第二个元素a[0][1]的地址，4/8
	printf("%d\n", sizeof(*(a[0] + 1)));	//4
	//对数组第二个元素解的地址引用得到第二个元素，整形大小4个字节
	printf("%d\n", sizeof(a + 1));    //4/8
	//a代表首元素即第一行的地址，a+1跳过一行，指向第二行，第二行的地址4/8
	printf("%d\n", sizeof(*(a + 1)));	//16
	//第一行的地址+1指向第二行的地址，解引用得到第二行
	printf("%d\n", sizeof(&a[0] + 1));	//4/8
	//&a[0]取出第一行的地址，+1指向第二行的地址
	printf("%d\n", sizeof(*(&a[0] + 1)));	//16
	//对第二行的地址解引用得到整个第二行
	printf("%d\n", sizeof(*a));	//16
	//a代表首元素即第一行的地址，解引用得到第一行
	printf("%d\n", sizeof(a[3]));	//16
	//sizeof求数据大小时只关注数据的类型，不关注数据的内容
	//这里虽然这里a[3]越界了，但是根据a[3]的数据类型：int (*)[4] -- 数组指针，仍能求出a[3]的大小
	//a[3]代表一维数组的数组名单独放在sizeof内部代表整个数组的大小
	return 0;
}