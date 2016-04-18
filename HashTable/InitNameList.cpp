#include"header_file.h"
                 

void InitNameList() //姓名初始化          

{

char *h;



NameList[0].spell="chenxiaopeng";NameList[0].student_number="3110005930";



NameList[1].spell="chenzhangjun";NameList[1].student_number="3110005931";



NameList[2].spell="chenzhenbang";NameList[2].student_number="3110005932";



NameList[3].spell="fanweiye";NameList[3].student_number="3110005933";



NameList[4].spell="fengyuming";NameList[4].student_number="3110005934";



NameList[5].spell="hejiner";NameList[5].student_number="3110005972";



NameList[6].spell="hongyongming";NameList[6].student_number="3110005936";



NameList[7].spell="huangzhao";NameList[7].student_number="3110005937";



NameList[8].spell="kongxiangzhu";NameList[8].student_number="3110005938";



NameList[9].spell="laizipeng";NameList[9].student_number="3110005939";



NameList[10].spell="lizuoquan";NameList[10].student_number="3110005940";



NameList[11].spell="liangweihe";NameList[11].student_number="3110005941";



NameList[12].spell="liangyingguo";NameList[12].student_number="3110005942";



NameList[13].spell="liuqihuan";NameList[13].student_number="3110005943";



NameList[14].spell="liuyuehui";NameList[14].student_number="3110005944";



NameList[15].spell="lizhipeng";NameList[15].student_number="3110005945";



NameList[16].spell="luwenfeng";NameList[16].student_number="3110005946";



NameList[17].spell="luchenglong";NameList[17].student_number="3110005947";



NameList[18].spell="lvxuan";NameList[18].student_number="3110005948";



NameList[19].spell="mayuejun";NameList[19].student_number="3110005949";



NameList[20].spell="panjiebin";NameList[20].student_number="3110005950";



NameList[21].spell="oujianling";NameList[21].student_number="3110005951";



NameList[22].spell="wangjianfeng";NameList[22].student_number="3110005952";



NameList[23].spell="wenxianjie";NameList[23].student_number="3110005953";



NameList[24].spell="wuzichao";NameList[24].student_number="3110005954";



NameList[25].spell="wujialiang";NameList[25].student_number="3110005955";



NameList[26].spell="xuboyan";NameList[26].student_number="3110005956";



NameList[27].spell="xuweilong";NameList[27].student_number="3110005957";



NameList[28].spell="yejia";NameList[28].student_number="3110005958";



NameList[29].spell="yeqiaofeng";NameList[29].student_number="3110005959";


int r,sum,i;

for (i=0;i<Name_Number;i++)

{

   sum=0;

   h=NameList[i].spell;
   
  for (r=0;*(h+r)!='\0';r++)//每个名字的字母相加的和作为关键值


   sum=*(h+r)+sum;
   
  

  NameList[i].key=sum;

}
 
}
