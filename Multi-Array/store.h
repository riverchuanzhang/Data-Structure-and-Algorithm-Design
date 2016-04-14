#define MAXDIM 5

typedef struct{
	int dim;//数组维数
	int *lower;//各维下表的指针
	int *upper;//各维上界表的指针
	int *constants;//映像函数常量表的指针
} NArray,*NArrayPtr;
typedef struct{
	int *elem;//数组元素基址
	int num;//数组元素个数
} NArrayType;