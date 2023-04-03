//��������
#include<stdlib.h>
#include<stdio.h>
typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;
//����ã����Ƿ��ͣ�ʡȥһЩ������
typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;
typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//��ʼ��ջ
//��ʼ��1��s�ں����ڸ�һ���ռ䣬��ʱ����LinkStack** s��
//��ʼ��2��s���뺯����ǰ��ָ��һ���ռ䣬��ʱֻ��top=0��count=0���ɡ�
//��ͷ�ļ�Ӧ���ǵڶ�����˼��
Status initLStack(LinkStack* s) {
	//ջ����Ҫͷ�ڵ㣬���ʼ��ֻ��Ҫ��ջ��ָ��ָ��ա�
	//��ô���ܳ�ʼ��ʧ���أ�

	s->top = NULL;//NULL��stdlib.h�ж����ˣ���������
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s == NULL)exit(-1);//������ָ�������ֱ�Ӽ�
	else if (s->count != 0)return ERROR;
	return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s == NULL)return ERROR;
	if (s->count == 0)return ERROR;//�����з��֡�
	else 
	{
		*e = s->top->data;
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack* s) {
	//����
	if (s == NULL)return ERROR;
	StackNode* temp = s->top;
	for (int i = 0; i < s->count; i++)
	{
		s->top->data = 0;
		s->top = s->top->next;
	}
	s->top = temp;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	if (s == NULL)return ERROR;
	StackNode* temp = s->top;
	for (int i = 0; i < s->count; i++)
	{
		s->top = s->top->next;
		free(temp);
		temp = s->top;
	}
	s = NULL; //stack����malloc�õ��ģ�
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	if (s == NULL)return ERROR;
	*length = s->count;
	return SUCCESS;

}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	//˼·������һ����㣬�ӵ�ͷ��
	if (s == NULL)return ERROR;
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL)return ERROR;
	temp->data = data;
	temp->next = s->top;

	s->top = temp;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	//˼·���޸�top��free����һ���ڵ㼴��
	if (s == NULL)return ERROR;
	if (s->top == NULL)return ERROR;
	StackNode* temp = s->top;
	*data = s->top->data;//ջΪ��ʱ���ܳ�ջ�������з���bug��
	s->top = s->top->next;
	s->count--;//������ˣ������з���bug��
	free(temp);
	return SUCCESS;
}

//��һ����������
void LStackPrint(int q) 
{
	printf("%d\n", q);
	return;
}

Status TraverseLinkStack(LinkStack*e, void(*f)(int q))
{
	//˼·������
	StackNode* temp = e->top;
	for (int i = 0; i < e->count; i++)
	{
		if (e->top == NULL)return ERROR;
		f(e->top->data);
		e->top = e->top->next;
	}
	//��Ҫ�Ļ�ȥ��
	e->top = temp;
	return SUCCESS;
}

