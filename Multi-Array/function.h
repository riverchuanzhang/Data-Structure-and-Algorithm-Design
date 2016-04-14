

void open1(){//主菜单界面
	printf("\n\n");
	printf("               *********多维数组操作主菜单**********   \n\n");
	printf("                   *1  创建多维数组                      \n");
	printf("                   *2  初始化多维数组的值                \n");
	printf("                   *3  对多维数组进行多种赋值`````               \n");
	printf("                   *4  确定多维数组的大小                   \n");
	printf("                   *5  对多维数组指定元素输出(定位)               \n");
	printf("                   *6  帮助                             \n");
	printf("                   *7  清屏                             \n");
	printf("                   *8  退出                             \n\n");
	printf("                                10计科三班，张大川制作\n");
	printf("                                           3110005966\n");
	printf("***********注意：提示要输入的数据必须是数字\n");
	printf("               *************************************    \n");
	//printf("请输入你的选择： ");
}

void open2(){//对多维数组赋值的子菜单界面
	printf("\n\n");
	printf("               *********对数组赋值的操作菜单********  \n\n");
	printf("                   *1  对一个多维数组指定下标的元素赋值        \n");
	printf("                   *2  对一个多维数组指定子数组进行赋值            \n");
	printf("                   *3  对一个多维数组同类型的子数组进行赋值          \n");
	printf("                   *4  对两个多维数组间同类型的子数组进行赋值             \n");
	printf("                   *5  对两个多维数组间进行赋值                      \n");
	printf("                   *6  清屏                                  \n");
	printf("                   *7  返回 \n\n");
	printf("**************注意：提示要输入的数据必须是数字  \n");
	printf("               ************************************  \n");
	//printf("请输入你的选择： ");
}

void InitNArray(NArray &A,NArrayType &a){//定义一个多维数组，各维下标是任意整数开始的连续整数，手动输入
	printf("                 *********创建一个多维数组*********\n");
	printf("请按提示创建：\n");
	int i,u,l,n,w;
	int flag1 ,flag2,flag3;
	flag1 = 1;
	while(flag1){
		printf("输入你想要的不大于%d的多维数组的维数，输入维数： ",MAXDIM);
		scanf("%d", &w);
		if(w<1 || w>MAXDIM) { 
			printf("维数不在处理范围内，按任意键返回，重新输入: \n");
			getch();
		}else {
			A.dim = w;//确定多维数组的维数，手动输入确定
			flag1 = 0;
		}
	}
	A.lower = (int *)malloc(A.dim * sizeof(int));//为各维的下界数值开拓存储空间
	A.upper = (int *)malloc(A.dim * sizeof(int));//为各维上界数值开拓存储空间
	for(i = 0;i<A.dim;i++){
		A.lower[i] = 0;
		A.upper[i] = 0;//初始化各维上下界数值值为0
	}
	for(i = 0;i<A.dim; i++){
		flag1 = 1;
		while(flag1){			
			flag2 = 1;
			flag3 = 1;
			while(flag2){
				printf("输入第%d维的上界: ",i+1);
				scanf("%d",&u);
				if(u<0){
					printf("输入的数据不在处理范围内，按任意键返回，重新输入,：\n");//上界数值不能为0
					getch();
				}else{
					A.upper[i] = u;//用A.upper[]数组存储各维上界数值
					flag2 = 0;
				}
			}
			while(flag3){
				printf("输入第%d维的下界： ",i+1);
				scanf("%d",&l);
				if(l<0){
					printf("输入的数据不在处理范围内，按任意键返回，重新输入：\n");//下界数值不能为0
					getch();
				}else {
					A.lower[i] = l;//用A.lower[]数组存储各维下界数值
					flag3 = 0;
				}
			}
			if(A.lower[i]<=A.upper[i]){//判断下界数值是不是小于上界数值
				flag1 = 0;
			}else {
				printf("你输入的上界大于下界，按任意键返回，重新输入：\n");
				getch();
			}
		}
							
	}	
	A.constants = (int *)malloc(A.dim * sizeof(int));//为各维映像函数常量表开拓存储空间
	A.constants[A.dim-1] = 1;
	for(i = A.dim-2;i>=0;i--){
		A.constants[i] = A.constants[i+1] *(A.upper[i+1] - A.lower[i+1]+1);//按公式初始化各维映像函数常量表数值，		
	}
	n=1;
	for(i = 0;i<A.dim;i++){
		n = n*(A.upper[i] - A.lower[i] +1);//计算所输入的多维数组的大小
	}
	a.num = n;
	a.elem = (int *)malloc(a.num * sizeof(int));//根据确定的多维数组大小来动态开拓存储空间
	for(i = 0;i<a.num;i++)
		a.elem[i] = 0;//设初始化多维数组的值为0
	printf("你已经成功创建了一个%d维的，大小是%d，多维数组A",A.dim,a.num);
	for(i=0 ;i<A.dim; i++){
		printf("[%d```%d]",A.lower[i],A.upper[i]);
	}
	printf("\n按任意键继续：\n");
	getch();

}
void CreatNArray(NArrayType &a,int k){
	printf("                 *********初始化一个多维数组*********\n");
	printf("请按提示初始化：\n");
	int i;
	if(k){//k=1时，为数组A初始化；k=0,时，为数组B初始化。
		for(i=0; i<a.num; i++){
			a.elem[i] = i+1;
			//根据传入的参数k的值初始化多维数组的值，可以手动输入，为了便于操作流畅，就用了循环递增赋值，值为：1,2,3····
		}
	}else {
		for(i=0; i<a.num; i++){
			a.elem[i] = i+3;
			//根据传入的参数k的值初始化多维数组的值，可以手动输入，为了便于操作流畅，就用了循环递增赋值，值为：3,4,5····
		}
	}	
	printf("初始化成功，多维数组的值是：\n");
	for(i = 0;i<a.num;i++){
		printf("%d  ",a.elem[i]);//输出初始化的数组的元素的值
	}
	printf("按任意键继续：\n");
	getch();
	
}
void Assign1(NArray &A,NArrayType &a){
	printf("                 *********对多维数组指定下标的元素赋值*********\n");
	printf("请按提示进行赋值：\n");
	int i,m[MAXDIM],x,y;
	int flag1;
	int pos ;
	int k;
	for(i = 0;i<A.dim; i++){
		flag1 = 1;
		while(flag1){
			printf("对于%d维数组，输入第%d维起始元素下标值,范围是[%d```%d]： ",A.dim,i+1,A.lower[i],A.upper[i]);
			scanf("%d",&x);
			if(x>=A.lower[i] && x<=A.upper[i]){
				m[i] = x;//用m[]数组存储起始元素下标，存储单元依次存取按顺序各维的下标
				flag1 = 0;
			}else{
				printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
				//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				getch();
			}	
		}	
	}	
	pos = 0;
	for(i=0; i< A.dim; i++){
		pos = pos + A.constants[i] * (m[i] - A.lower[i]);//根据下标值用公式计算指定下标元素所对应一维数组的位置
	}
	printf("赋值前该元素的值是： %d\n",a.elem[pos]);
	printf("输入你想赋予该元素的数值:  ");
	scanf("%d",&k);
	a.elem[pos] = k;//给指定下标元素的赋值
	printf("赋值后该元素的值是: %d\n",a.elem[pos]);
	printf("赋值成功,按任意键继续：\n");
	getch();
}
void Assign2(NArray &A,NArrayType &a){//对多维数组指定子数组进行赋值
	printf("                 *********对多维数组指定子数组进行赋值*********\n");
	printf("请按提示进行赋值：\n");
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
				printf("对于%d维数组，输入第%d维起始元素下标值,范围是[%d```%d]： ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m1[i] = x;//用m1[]数组存储起始元素下标，存储单元依次存取按顺序各维的下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
					getch();
				}	
			}
		
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("对于%d维数组，输入第%d维结束元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(y<=A.upper[i] && y>=A.lower[i]){
					m2[i] = y;//用m21[]数组存储结束元素下标，存储单元依次存取按顺序各维下标
					flag1 =0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
					getch();
				}
			}
		}
		pos1 =0;
		pos2 =0;
		for(i=0;i<A.dim; i++){
			pos1 = pos1 + A.constants[i] * (m1[i] - A.lower[i]);//根据下标值用公式计算起始地址所对应一维数组的位置
			pos2 = pos2 + A.constants[i] * (m2[i]-A.lower[i]);//根据下标值用公式计算结束地址所对应一维数组的位置
		}
		if(pos1<pos2) 
			flag2 = 0;//出错处理，起始地址不能大于结束地址，不然重新输入
		else
			printf("输入不合理，按任意键返回，重新输入： \n");
			getch();
	}
	printf("赋值前，所选子数组的值是A");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m1[i]);//输出赋值前的所选子数组元素的值
	}
	printf("到~");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m2[i]);
	}
	printf("\n元素值为: ");
	for(i = pos1; i<= pos2; i++){
		printf("  %d",a.elem[i]);
	}
	for(i=pos1;i<=pos2; i++){
		printf("输入你想赋的数值  ");
		scanf("%d",&k);//手动的给多维数组赋值
		a.elem[i] = k;
	}
	printf("赋值后，多维数组的值是：\n");
	for(i = pos1;i<=pos2 ;i++){
		printf("%d  ",a.elem[i]);//输出赋值前的所选子数组元素的值
	}
	printf("\n赋值成功，按任意键继续：\n");
	getch();

}

void Assign3(NArray &A,NArrayType &a){//对多维数组同类型的子数组进行赋值
	printf("                 *********对多维数组同类型的子数组进行赋值*********\n");
	printf("请按提示进行赋值：\n");
	int i,j,m1[MAXDIM],m2[MAXDIM],n1[MAXDIM],n2[MAXDIM];
	int flag1,flag2;
	int x,y;
	int num1,num2;
	flag2 = 1;
	while(flag2){
		for(i=0; i<A.dim; i++){
			flag1 =1;
			while(flag1){
				printf("对于%d维数组，输入你想替换的子数组A，第%d维起始元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m1[i] = x;//用m1[]数组存储起始元素下标，存储单元依次存取按顺序各维的标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("对于%d维数组，输入你想替换的子数组A，第%d维结束元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m2[i] = y;//用m2[]数组存储结束元素下标，存储单元依次存取按顺序各维下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 =1;
			while(flag1){
				printf("对于%d维数组，输入你想替换的子数组B，第%d维起始元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					n1[i] = x;//用n1[]数组存储起始元素下标，存储单元依次存取按顺序各维的下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("对于%d维数组，输入你想替换的子数组B，第%d维结束元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=A.upper[i] && x>=A.lower[i]){
					n2[i] = y;//用n1[]数组存储起始元素下标，存储单元依次存取按顺序各维的下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		num1 = 1;
		num2 = 1;
		for(i=0; i<A.dim; i++){
			num1 = num1 * (abs(m2[i] - m1[i]) +1);//计算所选子数组A的大小
			num2 = num2 * (abs(n2[i] - n1[i]) +1);//计算所选子数组B的大小
		}
		if(num1 == num2) 
			flag2 = 0;
		else
			printf("两个子数组不是同种类型的，按任意键返回，重新输入： \n");
			getch();//出错处理，如果A数组大小与B数组大小不相等，则重新输入
	}
	printf("\n");
	printf("你选择的子数组A是从： A");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m1[i]);
	}
	printf("到~~A");
	for(i=0; i<A.dim;i++){
		printf("[%d]",m2[i]);
	}
	printf("你选择的子数组B是从： B");
	for(i=0; i<A.dim; i++){
		printf("[%d]",n1[i]);
	}
	printf("到~~B");
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
		posA1 = posA1 + A.constants[i] * (m1[i] - A.lower[i]);//根据下标值用公式计算A数组起始地址所对应一维数组的位置
		posA2 = posA2 + A.constants[i] * (m2[i] - A.lower[i]);//根据下标值用公式计算A数组结束地址所对应一维数组的位置
		posB1 = posB1 + A.constants[i] * (n1[i] - A.lower[i]);//根据下标值用公式计算B数组起始地址所对应一维数组的位置
		posB2 =posB2 + A.constants[i] * (n2[i] - A.lower[i]);//根据下标值用公式计算B数组结束地址所对应一维数组的位置
	}
	printf("你选的子数组的值是： ");
	for(i = posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);
	}
	for(i = posA1,j = posB1; i<=posA2 && j<=posB2; i++,j++){
		a.elem[i] = a.elem[j];//对应子数组之间赋值
	}
	printf("\n赋值后，多维数组的值是：\n");
	for(i=posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);//输出赋值后所选子数组元素的值
	}
	printf("\n赋值成功，按任意键继续：\n");
	getch();

}
void Assign5(NArray &A,NArrayType &a,NArray &B,NArrayType &b){
	printf("                 *********对两个多维数组间进行赋值*********\n");
	int i,j;
	if(a.num != b.num){
		printf("两个数组不是同类型的多维数组，请按任意键返回\n");//如果两个数组不同类型，则返回。
		return ;
	}else {
		printf("赋值前A数组的值是：\n");
		for(i=0; i<a.num; i++) {
			printf("%d  ",a.elem[i]);//赋值前输出A数组的数值
		}
		printf("\n赋值前B数组的值是：\n");
		for(i=0; i<b.num; i++){
			printf("%d  ",b.elem[i]);
		}
		for(i=0,j=0; i<a.num && j<b.num; i++,j++){
			a.elem[i] = b.elem[i];//将B数组的值赋给A数组
		}
		printf("\n赋值后A数组的值是：\n");
		for(i=0; i<a.num; i++) {
			printf("%d  ",a.elem[i]);//输出赋值后A数组的值
		}
		printf("\n赋值成功，按任意键继续：\n");
	    getch();
	}

	
}
void Assign4(NArray &A,NArrayType &a,NArray &B,NArrayType &b){	
	printf("                 *********对两个多维数组间同类型的子数组组间进行赋值*********\n");
	printf("请按提示进行赋值：\n");
	int i,j,m1[MAXDIM],m2[MAXDIM],n1[MAXDIM],n2[MAXDIM];
	int flag1,flag2;
	int x,y;
	int num1,num2;
	flag2 = 1;
	while(flag2){
		for(i=0; i<A.dim; i++){
			flag1 =1;
			while(flag1){
				printf("对于%d维数组A，输入你想替换的子数组A1，第%d维起始元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m1[i] = x;//用m1[]数组存储A数组的子数组起始元素下标，存储单元依次存取按顺序各维的下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		for(i=0; i<A.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("对于%d维数组A，输入你想替换的子数组A1，第%d维结束元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=A.upper[i] && x>=A.lower[i]){
					m2[i] = y;//用m2[]数组存储A数组的子数组结束元素下标，存储单元依次存取按顺序各维的下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		for(i=0; i<B.dim; i++){
			flag1 =1;
			while(flag1){
				printf("对于%d维数组B，输入你想替换的子数组B1，第%d维起始元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&x);
				if(x<=B.upper[i] && x>=B.lower[i]){
					n1[i] = x;//用n1[]数组存储A数组的子数组结束元素下标，存储单元依次存取按顺序各维的下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		for(i=0; i<B.dim; i++){
			flag1 = 1;
			while(flag1){
				printf("对于%d维数组B，输入你想替换的子数组B1，第%d维结束元素下标值，范围是[%d```%d]: ",A.dim,i+1,A.lower[i],A.upper[i]);
				scanf("%d",&y);
				if(x<=B.upper[i] && x>=B.lower[i]){
					n2[i] = y;//用n2[]数组存储A数组的子数组结束元素下标，存储单元依次存取按顺序各维的下标
					flag1 = 0;
				}else{
					printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
					getch();//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				}
			}
		}
		num1 = 1;
		num2 = 1;
		for(i=0; i<A.dim; i++){
			num1 = num1 * (abs(m2[i] - m1[i]) +1);//计算所选子A数组的子数组A1的大小
			num2 = num2 * (abs(n2[i] - n1[i]) +1);//计算所选子B数组的子数组B1的大小
		}
		if(num1 == num2) 
			flag2 = 0;
		else
			printf("两个子数组不是同种类型的，按任意键返回，重新输入： \n");
			getch();
	}
	printf("\n");
	printf("你选择多维数组A的子数组A是从： A1");
	for(i=0; i<A.dim; i++){
		printf("[%d]",m1[i]);
	}
	printf("到~~A1");
	for(i=0; i<A.dim;i++){
		printf("[%d]",m2[i]);
	}
	printf("你选择的子数组B是从： B1");
	for(i=0; i<B.dim; i++){
		printf("[%d]",n1[i]);
	}
	printf("到~~B1");
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
		posA1 = posA1 + A.constants[i] * (m1[i] - A.lower[i]);//根据下标值用公式计算A数组的子数组起始地址所对应一维数组的位置
		posA2 = posA2 + A.constants[i] * (m2[i] - A.lower[i]);//根据下标值用公式计算A数组的子数组起始地址所对应一维数组的位置
		posB1 = posB1 + A.constants[i] * (n1[i] - A.lower[i]);//根据下标值用公式计算A数组的子数组起始地址所对应一维数组的位置
		posB2 =posB2 + A.constants[i] * (n2[i] - A.lower[i]);//根据下标值用公式计算A数组的子数组起始地址所对应一维数组的位置
	}
	printf("你选的子数组的值是： ");
	for(i = posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);
	}
	for(i = posA1,j = posB1; i<=posA2 && j<=posB2; i++,j++){
		a.elem[i] = b.elem[j];//把B数组的子数组B1的值赋给A数组的子数组A1
	}
	printf("\n赋值后，多维数组的值是：\n");
	for(i=posA1; i<=posA2; i++){
		printf("%d  ",a.elem[i]);//输出赋值后的A数组的子数组A1的值
	}
	printf("\n赋值成功，按任意键继续：\n");
	getch();

}

void Assign(NArray &A,NArrayType &a,NArray &B,NArrayType &b){
	int i,k,j;
	j=0;
	k=1;
	while(k){
		open2();
		printf("请输入你的选择： ");
		scanf("%d",&i);
		switch(i){
			case 1:{
				   Assign1(A,a);  //对一个多维数组指定下标的元素赋值
				   break;
				   }
			case 2:{
				   Assign2(A,a);//对一个多维数组指定子数组进行赋值
				   break;
				   }
			case 3:{
				   Assign3(A,a);//对一个多维数组同类型的子数组进行赋值
				   break;
				   }
			case 4:{
					Assign4(A,a,B,b);//对两个多维数组间同类型的子数组进行赋值  
					break;
				   }
			case 5:{
					Assign5(A,a,B,b);//对两个多维数组间进行赋值  
					break;
				   }
			case 6:{
					system("cls");//清屏
					break;
				   }
			case 7:{//返回
				   k=0;
				   break;
				   }


		}
	}
	
}
void size(NArray A,NArrayType a){
	printf("                 *********确定多维数组的大小*********\n");
	printf("请按提示进行赋值：\n");
	printf("这是个%d维数组的大小是： %d\n ,请按任意键继续",A.dim,a.num);
	getch();
}

void help(){
	printf("                 *********帮助文档*********\n");
	printf("请按提示进行赋值：\n");
	printf("按照所提示的信息一步一步走~~");

}
void output(NArray &A,NArrayType &a){
	printf("                 *********对多维数组指定元素输出*********\n");
	printf("请按提示进行赋值：\n");
	int i,m[MAXDIM];
	int flag1;
	int x,y;
	int pos;
	printf("请输入你想输出元素的下标： \n");
	for(i=0; i<A.dim; i++){
		flag1 = 1;
		while(flag1){
			printf("对于%d维数组，输入第%d维元素下标值,范围是[%d```%d]： ",A.dim,i+1,A.lower[i],A.upper[i]);
			scanf("%d",&x);
			if(x<=A.upper[i] && x>=A.lower[i]){
				m[i] = x;//用m[]数组存储起始元素下标，存储单元依次存取按顺序各维的下标
				flag1 = 0;
			}else {
				printf("你输入的下标不在处理的范围内，按任意键返回，重新输入：\n");
				//出错处理，各维元素的下标值不能大于各维上界，不能小于各维下界，不然重新输入
				getch();	
			}
		}
	}
	pos = 0;
	for(i=0; i<A.dim; i++){
		pos = pos + A.constants[i]*(m[i] - A.lower[i]);//根据下标值用公式计算指定下标元素所对应一维数组的位置
	}
	printf("你所指定的多维数组元素为：A",A.dim);
	for(i=0; i<A.dim; i++){
		printf("[%d]",m[i]);
	}
	printf(": %d\n",a.elem[pos]);
	printf("输出成功，请按任意键继续：\n");//输出所要找的下标元素的值
	getch();
}

