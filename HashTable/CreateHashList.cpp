#include"header_file.h"
void CreateHashList_2() //������ϣ��   

{
	int i;

    for (i=0; i<HASH_LENGTH;i++) //�Թ�ϣ����г�ʼ��

       {
     HashList[i].spell="";   HashList[i].key=0; HashList[i].Search_Length=0;HashList[i].student_number=0;
       }

  for (i=0;i<HASH_LENGTH;i++)

       {

     int sum=0;int adress; int d; 

     adress=(NameList[i].key)%Random_Number;  //��ϣ����

      d=adress;

       if(HashList[adress].Search_Length==0)     //�����ǰ��λ��δ��

          {

       HashList[adress].key=NameList[i].key;

       HashList[adress].spell=NameList[i].spell;

       HashList[adress].Search_Length=1;
HashList[adress].student_number=NameList[i].student_number;

          }

        else   

          {
			int j=1;

        while (HashList[d].key!=0)
    

                {

            d=(d+NameList[i].key%10+1)%Random_Number;   //α���̽����ɢ�з������ͻ    

           sum=sum+1;   //���Ҵ�����1  

                }

   

         HashList[d].key=NameList[i].key;

         HashList[d].spell=NameList[i].spell;

         HashList[d].Search_Length=sum+1;
        HashList[d].student_number=NameList[i].student_number;

          }
}
}
 
