#define MAXDIM 5

typedef struct{
	int dim;//����ά��
	int *lower;//��ά�±��ָ��
	int *upper;//��ά�Ͻ���ָ��
	int *constants;//ӳ�����������ָ��
} NArray,*NArrayPtr;
typedef struct{
	int *elem;//����Ԫ�ػ�ַ
	int num;//����Ԫ�ظ���
} NArrayType;