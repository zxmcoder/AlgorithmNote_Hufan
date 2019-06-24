/*
要记住，stack和queue没有clear操作
用struct来代替联合体，只需要一个bool变量！
stack操作符栈，queue后缀队列，先弹出第二个操作数，然后再第一个操作数
数字压栈，符号数弹出栈中的两个数字，运算完成后再入栈
 */

/*
另外，文件多点测试需要注意
还有，codeup平台有点辣鸡
 */
#include<bits/stdc++.h>
using namespace std;
struct node{
	char op;
	double num;
	bool flag;
};
string str;
stack<node> s;
queue<node> q;
map<char,int> op;
void change();
double cal();
int main(){
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	while(getline(cin,str)&&str!="0"){
		for(string::iterator it=str.begin();it!=str.end();++it)
			if(*it==' ')str.erase(it);
		while(s.size())s.pop();
		change();
		printf("%.2f\n",cal());
	}
	return 0;
}
void change(){
	double num;
	node temp;
	for(int i=0;i<str.size();){
		if(isdigit(str[i])){
			temp.flag=true;
			temp.num=str[i++]-'0';
			while(i<str.size()&&isdigit(str[i])){
				temp.num=temp.num*10+str[i]-'0';
				i++;
			}
			q.push(temp);
		}
		else{
			temp.flag=false;
			while(s.size()&&op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op=str[i];
			s.push(temp);
			i++;
		}
	}
	while(s.size()){
		q.push(s.top());
		s.pop();
	}
}
double cal(){
	double temp1,temp2;
	node cur,temp;
	while(q.size()){
		cur=q.front();
		q.pop();
		if(cur.flag==true)s.push(cur);
		else{
			temp2=s.top().num;
			s.pop();
			temp1=s.top().num;
			s.pop();
			temp.flag=true;
			if(cur.op=='+')temp.num=temp1+temp2;
			else if(cur.op=='-')temp.num=temp1-temp2;
			else if(cur.op=='*')temp.num=temp1*temp2;
			else temp.num=temp1/temp2;
			s.push(temp);
		}
	}
	return s.top().num;
}