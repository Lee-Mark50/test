#define MAX 100
/*检测是否为回文序列*/
int Check(char *str,LinkStack LS, LinkQueue* LQ)
{
	DataType data;
	DataType elem;
	int i = 0;
	/*从键盘依次输入字符以‘\’作为结束标志，将其依次压栈，入队，*/
	for(int i=0;i<=MAX;i++){
		cin>>str[i];
		if(str[i]!=' \ ')
		{
		PushStack(LS, str[i]);    /*将字符序列中的字符依次入栈*/
		EnterQueue(LQ, str[i]);   /*将字符序列中的字符依次入队*/
		}
		else break;
	}
	/*当栈不为空时循环弹栈和出队，如果遇到出栈的元素data与出队的元素不同
	则不是回文序列,如果栈为空，依然没遇到出队与出栈元素不同,则为回文序列*/
	while (!IsEmpty(LS))
	{
		PopStack(LS, &data);     /*将字符序列中的字符依次出栈*/
		DeleteQueue(LQ, &elem);  /*将字符序列中的字符依次出队*/
		if (data != elem)
		{
			cout<<"不是回文字符序列!\n";
			return 0;
		}
	}
	cout<<"是回文字符序列！\n";
}
