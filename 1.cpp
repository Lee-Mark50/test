#define MAX 100
/*����Ƿ�Ϊ��������*/
int Check(char *str,LinkStack LS, LinkQueue* LQ)
{
	DataType data;
	DataType elem;
	int i = 0;
	/*�Ӽ������������ַ��ԡ�\����Ϊ������־����������ѹջ����ӣ�*/
	for(int i=0;i<=MAX;i++){
		cin>>str[i];
		if(str[i]!=' \ ')
		{
		PushStack(LS, str[i]);    /*���ַ������е��ַ�������ջ*/
		EnterQueue(LQ, str[i]);   /*���ַ������е��ַ��������*/
		}
		else break;
	}
	/*��ջ��Ϊ��ʱѭ����ջ�ͳ��ӣ����������ջ��Ԫ��data����ӵ�Ԫ�ز�ͬ
	���ǻ�������,���ջΪ�գ���Ȼû�����������ջԪ�ز�ͬ,��Ϊ��������*/
	while (!IsEmpty(LS))
	{
		PopStack(LS, &data);     /*���ַ������е��ַ����γ�ջ*/
		DeleteQueue(LQ, &elem);  /*���ַ������е��ַ����γ���*/
		if (data != elem)
		{
			cout<<"���ǻ����ַ�����!\n";
			return 0;
		}
	}
	cout<<"�ǻ����ַ����У�\n";
}
