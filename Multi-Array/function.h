

void open1(){//���˵�����
	printf("\n\n");
	printf("               *********��ά����������˵�**********   \n\n");
	printf("                   *1  ������ά����                      \n");
	printf("                   *2  ��ʼ����ά�����ֵ                \n");
	printf("                   *3  �Զ�ά������ж��ָ�ֵ`````               \n");
	printf("                   *4  ȷ����ά����Ĵ�С                   \n");
	printf("                   *5  �Զ�ά����ָ��Ԫ�����(��λ)               \n");
	printf("                   *6  ����                             \n");
	printf("                   *7  ����                             \n");
	printf("                   *8  �˳�                             \n\n");
	printf("                                10�ƿ����࣬�Ŵ�����\n");
	printf("                                           3110005966\n");
	printf("***********ע�⣺��ʾҪ��������ݱ���������\n");
	printf("               *************************************    \n");
	//printf("���������ѡ�� ");
}

void open2(){//�Զ�ά���鸳ֵ���Ӳ˵�����
	printf("\n\n");
	printf("               *********�����鸳ֵ�Ĳ����˵�********  \n\n");
	printf("                   *1  ��һ����ά����ָ���±��Ԫ�ظ�ֵ        \n");
	printf("                   *2  ��һ����ά����ָ����������и�ֵ            \n");
	printf("                   *3  ��һ����ά����ͬ���͵���������и�ֵ          \n");
	printf("                   *4  ��������ά�����ͬ���͵���������и�ֵ             \n");
	printf("                   *5  ��������ά�������и�ֵ                      \n");
	printf("                   *6  ����                                  \n");
	printf("                   *7  ���� \n\n");
	printf("**************ע�⣺��ʾҪ��������ݱ���������  \n");
	printf("               ************************************  \n");
	//printf("���������ѡ�� ");
}

void InitNArray(NArray &A,NArrayType &a){//����һ����ά���飬��ά�±�������������ʼ�������������ֶ�����
	printf("                 *********����һ����ά����*********\n");
	printf("�밴��ʾ������\n");
	int i,u,l,n,w;
	int flag1 ,flag2,flag3;
	flag1 = 1;
	while(flag1){
		printf("��������Ҫ�Ĳ�����%d�Ķ�ά�����ά��������ά���� ",MAXDIM);
		scanf("%d", &w);
		if(w<1 || w>MAXDIM) { 
			printf("ά�����ڴ���Χ�ڣ�����������أ���������: \n");
			getch();
		}else {
			A.dim = w;//ȷ����ά�����ά�����ֶ�����ȷ��
			flag1 = 0;
		}
	}
	A.lower = (int *)malloc(A.dim * sizeof(int));//Ϊ��ά���½���ֵ���ش洢�ռ�
	A.upper = (int *)malloc(A.dim * sizeof(int));//Ϊ��ά�Ͻ���ֵ���ش洢�ռ�
	for(i = 0;i<A.dim;i++){
		A.lower[i] = 0;
		A.upper[i] = 0;//��ʼ����ά���½���ֵֵΪ0
	}
	for(i = 0;i<A.dim; i++){
		flag1 = 1;
		while(flag1){			
			flag2 = 1;
			flag3 = 1;
			while(flag2){
				printf("�����%dά���Ͻ�: ",i+1);
				scanf("%d",&u);
				if(u<0){
					printf("��������ݲ��ڴ���Χ�ڣ�����������أ���������,��\n");//�Ͻ���ֵ����Ϊ0
					getch();
				}else{
					A.upper[i] = u;//��A.upper[]����洢��ά�Ͻ���ֵ
					flag2 = 0;
				}
			}
			while(flag3){
				printf("�����%dά���½磺 ",i+1);
				scanf("%d",&l);
				if(l<0){
					printf("��������ݲ��ڴ���Χ�ڣ�����������أ��������룺\n");//�½���ֵ����Ϊ0
					getch();
				}else {
					A.lower[i] = l;//��A.lower[]����洢��ά�½���ֵ
					flag3 = 0;
				}
			}
			if(A.lower[i]<=A.upper[i]){//�ж��½���ֵ�ǲ���С���Ͻ���ֵ
				flag1 = 0;
			}else {
				printf("��������Ͻ�����½磬����������أ��������룺\n");
				getch();
			}
		}
							
	}	
	A.constants = (int *)malloc(A.dim * sizeof(int));//Ϊ��άӳ�����������ش洢�ռ�
	A.constants[A.dim-1] = 1;
	for(i = A.dim-2;i>=0;i--){
		A.constants[i] = A.constants[i+1] *(A.upper[i+1] - A.lower[i+1]+1);//����ʽ��ʼ����άӳ������������ֵ��		
	}
	n=1;
	for(i = 0;i<A.dim;i++){
		n = n*(A.upper[i] - A.lower[i] +1);//����������Ķ�ά����Ĵ�С
	}
	a.num = n;
	a.elem = (int *)malloc(a.num * sizeof(int));//����ȷ���Ķ�ά�����С����̬���ش洢�ռ�
	for(i = 0;i<a.num;i++)
		a.elem[i] = 0;//���ʼ����ά�����ֵΪ0
	printf("���Ѿ��ɹ�������һ��%dά�ģ���С��%d����ά����A",A.dim,a.num);
	for(i=0 ;i<A.dim; i++){
		printf("[%d```%d]",A.lower[i],A.upper[i]);
	}
	printf("\n�������������\n");
	getch();

}
void CreatNArray(NArrayType &a,int k){
	printf("                 *********��ʼ��һ����ά����*********\n");
	printf("�밴��ʾ��ʼ����\n");
	int i;
	if(k){//k=1ʱ��Ϊ����A��ʼ����k=0,ʱ��Ϊ����B��ʼ����
		for(i=0; i<a.num; i++){
			a.elem[i] = i+1;
			//���ݴ���Ĳ���k��ֵ��ʼ����ά�����ֵ�������ֶ����룬Ϊ�˱��ڲ���������������ѭ��������ֵ��ֵΪ��1,2,3��������
		}
	}else {
		for(i=0; i<a.num; i++){
			a.elem[i] = i+3;
			//���ݴ���Ĳ���k��ֵ��ʼ����ά�����ֵ�������ֶ����룬Ϊ�˱��ڲ���������������ѭ��������ֵ��ֵΪ��3,4,5��������
		}
	}	
	printf("��ʼ���ɹ�����ά�����ֵ�ǣ�\n");
	for(i = 0;i<a.num;i++){
		printf("%d  ",a.elem[i]);//�����ʼ���������Ԫ�ص�ֵ
	}
	printf("�������������\n");
	getch();
	
}
void Assign1(NArray &A,NArrayType &a){
	printf("                 *********�Զ�ά����ָ���±��Ԫ�ظ�ֵ*********\n");
	printf("�밴��ʾ���и�ֵ��\n");
	int i,m[MAXDIM],x,y;
	int flag1;
	int pos ;
	int k;
	for(i = 0;i<A.dim; i++){
		flag1 = 1;
		while(flag1){
			printf("����%dά���飬�����%dά��ʼԪ���±�ֵ,��Χ��[%d```%d]�� ",A.dim,i+1,A.lower[i],A.upper[i]);
			scanf("%d",&x);
			if(x>=A.lower[i] && x<=A.upper[i]){
				m[i] = x;//��m[]����洢��ʼԪ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
				flag1 = 0;
			}else{
				printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
				//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				getch();
			}	
		}	
	}	
	pos = 0;
	for(i=0; i< A.dim; i++){
		pos = pos + A.constants[i] * (m[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����ָ���±�Ԫ������Ӧһά�����λ��
	}
	printf("��ֵǰ��Ԫ�ص�ֵ�ǣ� %d\n",a.elem[pos]);
	printf("�������븳���Ԫ�ص���ֵ:  ");
	scanf("%d",&k);
	a.elem[pos] = k;//��ָ���±�Ԫ�صĸ�ֵ
	printf("��ֵ���Ԫ�ص�ֵ��: %d\n",a.elem[pos]);
	printf("��ֵ�ɹ�,�������������\n");
	getch();
}
void Assign2(NArray &A,NArrayType &a){//�Զ�ά����ָ����������и�ֵ
	printf("                 *********�Զ�ά����ָ����������и�ֵ*********\n");
	printf("�밴��ʾ���и�ֵ��\n");
	int i,m1[MAXDIM],m2[MAXDIM],x,y;
	int flag1,flag2;
	int pos1,pos2;
	int k;
	flag2 =1;
	x = 0;
	y = 0;
	while(flag2){
		for(i=0; i<A.dim; i++){
			flag1 =1;
			while(flag1){
				printf("����%dά���飬�����%dά��ʼԪ���±�ֵ,��Χ��[%d```%d]�� ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m1[i] = x;//��m1[]����洢��ʼԪ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
					getch();
				}	
			}
		
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("����%dά���飬�����%dά����Ԫ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(y<=A.upper[i] && y>=A.lower[i]){
					m2[i] = y;//��m21[]����洢����Ԫ���±꣬�洢��Ԫ���δ�ȡ��˳���ά�±�
					flag1 =0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
					getch();
				}
			}
		}
		pos1 =0;
		pos2 =0;
		for(i=0;i<A.dim; i++){
			pos1 = pos1 + A.constants[i] * (m1[i] - A.lower[i]);//�����±�ֵ�ù�ʽ������ʼ��ַ����Ӧһά�����λ��
			pos2 = pos2 + A.constants[i] * (m2[i]-A.lower[i]);//�����±�ֵ�ù�ʽ���������ַ����Ӧһά�����λ��
		}
		if(pos1<pos2) 
			flag2 = 0;//��������ʼ��ַ���ܴ��ڽ�����ַ����Ȼ��������
		else
			printf("���벻��������������أ��������룺 \n");
			getch();
	}
	printf("��ֵǰ����ѡ�������ֵ��A");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m1[i]);//�����ֵǰ����ѡ������Ԫ�ص�ֵ
	}
	printf("��~");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m2[i]);
	}
	printf("\nԪ��ֵΪ: ");
	for(i = pos1; i<= pos2; i++){
		printf("  %d",a.elem[i]);
	}
	for(i=pos1;i<=pos2; i++){
		printf("�������븳����ֵ  ");
		scanf("%d",&k);//�ֶ��ĸ���ά���鸳ֵ
		a.elem[i] = k;
	}
	printf("��ֵ�󣬶�ά�����ֵ�ǣ�\n");
	for(i = pos1;i<=pos2 ;i++){
		printf("%d  ",a.elem[i]);//�����ֵǰ����ѡ������Ԫ�ص�ֵ
	}
	printf("\n��ֵ�ɹ����������������\n");
	getch();

}

void Assign3(NArray &A,NArrayType &a){//�Զ�ά����ͬ���͵���������и�ֵ
	printf("                 *********�Զ�ά����ͬ���͵���������и�ֵ*********\n");
	printf("�밴��ʾ���и�ֵ��\n");
	int i,j,m1[MAXDIM],m2[MAXDIM],n1[MAXDIM],n2[MAXDIM];
	int flag1,flag2;
	int x,y;
	int num1,num2;
	flag2 = 1;
	while(flag2){
		for(i=0; i<A.dim; i++){
			flag1 =1;
			while(flag1){
				printf("����%dά���飬���������滻��������A����%dά��ʼԪ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m1[i] = x;//��m1[]����洢��ʼԪ���±꣬�洢��Ԫ���δ�ȡ��˳���ά�ı�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("����%dά���飬���������滻��������A����%dά����Ԫ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m2[i] = y;//��m2[]����洢����Ԫ���±꣬�洢��Ԫ���δ�ȡ��˳���ά�±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 =1;
			while(flag1){
				printf("����%dά���飬���������滻��������B����%dά��ʼԪ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					n1[i] = x;//��n1[]����洢��ʼԪ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("����%dά���飬���������滻��������B����%dά����Ԫ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=A.upper[i] && x>=A.lower[i]){
					n2[i] = y;//��n1[]����洢��ʼԪ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		num1 = 1;
		num2 = 1;
		for(i=0; i<A.dim; i++){
			num1 = num1 * (abs(m2[i] - m1[i]) +1);//������ѡ������A�Ĵ�С
			num2 = num2 * (abs(n2[i] - n1[i]) +1);//������ѡ������B�Ĵ�С
		}
		if(num1 == num2) 
			flag2 = 0;
		else
			printf("���������鲻��ͬ�����͵ģ�����������أ��������룺 \n");
			getch();//���������A�����С��B�����С����ȣ�����������
	}
	printf("\n");
	printf("��ѡ���������A�Ǵӣ� A");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m1[i]);
	}
	printf("��~~A");
	for(i=0; i<A.dim;i++){
		printf("[%d]",m2[i]);
	}
	printf("��ѡ���������B�Ǵӣ� B");
	for(i=0; i<A.dim; i++){
		printf("[%d]",n1[i]);
	}
	printf("��~~B");
	for(i=0; i<A.dim;i++){
		printf("[%d]",n2[i]);
	}
	printf("\n");
	int posA1,posA2,posB1,posB2;
	posA1 =0;
	posA2 = 0;
	posB1 =0;
	posB2 = 0;
	for(i=0 ;i<A.dim; i++){
		posA1 = posA1 + A.constants[i] * (m1[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����A������ʼ��ַ����Ӧһά�����λ��
		posA2 = posA2 + A.constants[i] * (m2[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����A���������ַ����Ӧһά�����λ��
		posB1 = posB1 + A.constants[i] * (n1[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����B������ʼ��ַ����Ӧһά�����λ��
		posB2 =posB2 + A.constants[i] * (n2[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����B���������ַ����Ӧһά�����λ��
	}
	printf("��ѡ���������ֵ�ǣ� ");
	for(i = posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);
	}
	for(i = posA1,j = posB1; i<=posA2 && j<=posB2; i++,j++){
		a.elem[i] = a.elem[j];//��Ӧ������֮�丳ֵ
	}
	printf("\n��ֵ�󣬶�ά�����ֵ�ǣ�\n");
	for(i=posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);//�����ֵ����ѡ������Ԫ�ص�ֵ
	}
	printf("\n��ֵ�ɹ����������������\n");
	getch();

}
void Assign5(NArray &A,NArrayType &a,NArray &B,NArrayType &b){
	printf("                 *********��������ά�������и�ֵ*********\n");
	int i,j;
	if(a.num != b.num){
		printf("�������鲻��ͬ���͵Ķ�ά���飬�밴���������\n");//����������鲻ͬ���ͣ��򷵻ء�
		return ;
	}else {
		printf("��ֵǰA�����ֵ�ǣ�\n");
		for(i=0; i<a.num; i++) {
			printf("%d  ",a.elem[i]);//��ֵǰ���A�������ֵ
		}
		printf("\n��ֵǰB�����ֵ�ǣ�\n");
		for(i=0; i<b.num; i++){
			printf("%d  ",b.elem[i]);
		}
		for(i=0,j=0; i<a.num && j<b.num; i++,j++){
			a.elem[i] = b.elem[i];//��B�����ֵ����A����
		}
		printf("\n��ֵ��A�����ֵ�ǣ�\n");
		for(i=0; i<a.num; i++) {
			printf("%d  ",a.elem[i]);//�����ֵ��A�����ֵ
		}
		printf("\n��ֵ�ɹ����������������\n");
	    getch();
	}

	
}
void Assign4(NArray &A,NArrayType &a,NArray &B,NArrayType &b){	
	printf("                 *********��������ά�����ͬ���͵������������и�ֵ*********\n");
	printf("�밴��ʾ���и�ֵ��\n");
	int i,j,m1[MAXDIM],m2[MAXDIM],n1[MAXDIM],n2[MAXDIM];
	int flag1,flag2;
	int x,y;
	int num1,num2;
	flag2 = 1;
	while(flag2){
		for(i=0; i<A.dim; i++){
			flag1 =1;
			while(flag1){
				printf("����%dά����A�����������滻��������A1����%dά��ʼԪ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m1[i] = x;//��m1[]����洢A�������������ʼԪ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("����%dά����A�����������滻��������A1����%dά����Ԫ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m2[i] = y;//��m2[]����洢A��������������Ԫ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		for(i=0; i<B.dim; i++){
			flag1 =1;
			while(flag1){
				printf("����%dά����B�����������滻��������B1����%dά��ʼԪ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=B.upper[i] && x>=B.lower[i]){
					n1[i] = x;//��n1[]����洢A��������������Ԫ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		for(i=0; i<B.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("����%dά����B�����������滻��������B1����%dά����Ԫ���±�ֵ����Χ��[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=B.upper[i] && x>=B.lower[i]){
					n2[i] = y;//��n2[]����洢A��������������Ԫ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
					flag1 = 0;
				}else{
					printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
					getch();//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				}
			}
		}
		num1 = 1;
		num2 = 1;
		for(i=0; i<A.dim; i++){
			num1 = num1 * (abs(m2[i] - m1[i]) +1);//������ѡ��A�����������A1�Ĵ�С
			num2 = num2 * (abs(n2[i] - n1[i]) +1);//������ѡ��B�����������B1�Ĵ�С
		}
		if(num1 == num2) 
			flag2 = 0;
		else
			printf("���������鲻��ͬ�����͵ģ�����������أ��������룺 \n");
			getch();
	}
	printf("\n");
	printf("��ѡ���ά����A��������A�Ǵӣ� A1");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m1[i]);
	}
	printf("��~~A1");
	for(i=0; i<A.dim;i++){
		printf("[%d]",m2[i]);
	}
	printf("��ѡ���������B�Ǵӣ� B1");
	for(i=0; i<B.dim; i++){
		printf("[%d]",n1[i]);
	}
	printf("��~~B1");
	for(i=0; i<B.dim;i++){
		printf("[%d]",n2[i]);
	}
	printf("\n");
	int posA1,posA2,posB1,posB2;
	posA1 =0;
	posA2 = 0;
	posB1 =0;
	posB2 = 0;
	for(i=0 ;i<A.dim; i++){
		posA1 = posA1 + A.constants[i] * (m1[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����A�������������ʼ��ַ����Ӧһά�����λ��
		posA2 = posA2 + A.constants[i] * (m2[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����A�������������ʼ��ַ����Ӧһά�����λ��
		posB1 = posB1 + A.constants[i] * (n1[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����A�������������ʼ��ַ����Ӧһά�����λ��
		posB2 =posB2 + A.constants[i] * (n2[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����A�������������ʼ��ַ����Ӧһά�����λ��
	}
	printf("��ѡ���������ֵ�ǣ� ");
	for(i = posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);
	}
	for(i = posA1,j = posB1; i<=posA2 && j<=posB2; i++,j++){
		a.elem[i] = b.elem[j];//��B�����������B1��ֵ����A�����������A1
	}
	printf("\n��ֵ�󣬶�ά�����ֵ�ǣ�\n");
	for(i=posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);//�����ֵ���A�����������A1��ֵ
	}
	printf("\n��ֵ�ɹ����������������\n");
	getch();

}

void Assign(NArray &A,NArrayType &a,NArray &B,NArrayType &b){
	int i,k,j;
	j=0;
	k=1;
	while(k){
		open2();
		printf("���������ѡ�� ");
		scanf("%d",&i);
		switch(i){
			case 1:{
				   Assign1(A,a);  //��һ����ά����ָ���±��Ԫ�ظ�ֵ
				   break;
				   }
			case 2:{
				   Assign2(A,a);//��һ����ά����ָ����������и�ֵ
				   break;
				   }
			case 3:{
				   Assign3(A,a);//��һ����ά����ͬ���͵���������и�ֵ
				   break;
				   }
			case 4:{
					Assign4(A,a,B,b);//��������ά�����ͬ���͵���������и�ֵ  
					break;
				   }
			case 5:{
					Assign5(A,a,B,b);//��������ά�������и�ֵ  
					break;
				   }
			case 6:{
					system("cls");//����
					break;
				   }
			case 7:{//����
				   k=0;
				   break;
				   }


		}
	}
	
}
void size(NArray A,NArrayType a){
	printf("                 *********ȷ����ά����Ĵ�С*********\n");
	printf("�밴��ʾ���и�ֵ��\n");
	printf("���Ǹ�%dά����Ĵ�С�ǣ� %d\n ,�밴���������",A.dim,a.num);
	getch();
}

void help(){
	printf("                 *********�����ĵ�*********\n");
	printf("�밴��ʾ���и�ֵ��\n");
	printf("��������ʾ����Ϣһ��һ����~~");

}
void output(NArray &A,NArrayType &a){
	printf("                 *********�Զ�ά����ָ��Ԫ�����*********\n");
	printf("�밴��ʾ���и�ֵ��\n");
	int i,m[MAXDIM];
	int flag1;
	int x,y;
	int pos;
	printf("�������������Ԫ�ص��±꣺ \n");
	for(i=0; i<A.dim; i++){
		flag1 = 1;
		while(flag1){
			printf("����%dά���飬�����%dάԪ���±�ֵ,��Χ��[%d```%d]�� ",A.dim,i+1,A.lower[i],A.upper[i]);
			scanf("%d",&x);
			if(x<=A.upper[i] && x>=A.lower[i]){
				m[i] = x;//��m[]����洢��ʼԪ���±꣬�洢��Ԫ���δ�ȡ��˳���ά���±�
				flag1 = 0;
			}else {
				printf("��������±겻�ڴ���ķ�Χ�ڣ�����������أ��������룺\n");
				//��������άԪ�ص��±�ֵ���ܴ��ڸ�ά�Ͻ磬����С�ڸ�ά�½磬��Ȼ��������
				getch();	
			}
		}
	}
	pos = 0;
	for(i=0; i<A.dim; i++){
		pos = pos + A.constants[i]*(m[i] - A.lower[i]);//�����±�ֵ�ù�ʽ����ָ���±�Ԫ������Ӧһά�����λ��
	}
	printf("����ָ���Ķ�ά����Ԫ��Ϊ��A",A.dim);
	for(i=0; i<A.dim; i++){
		printf("[%d]",m[i]);
	}
	printf(": %d\n",a.elem[pos]);
	printf("����ɹ����밴�����������\n");//�����Ҫ�ҵ��±�Ԫ�ص�ֵ
	getch();
}

