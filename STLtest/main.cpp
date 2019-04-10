//STL(标准模板库):算法，容器，迭代器，函数对象

#include<vector>//向量(类似数组)
#include<deque>//双端队列(索引数组加分段数组)
#include<list>//列表(双向链表)
#include<map>//映射map和多重映射multimap
#include<set>//集合set和多重集合multiset

#include<stack>
#include<queue>

#include<string>

//#include<utility>//pair和make_pair等
//#include<cctype>//isalpha和tolower等函数
//#include<algorithm>//几乎包含全部算法
#include<numeric>//数值算法
#include<functional>

#include<iostream>
using namespace std;

template<class T>
void kk(T a)
{
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
template<class T>
void kkk(T a)
{
	copy(a.begin(), a.end(), ostream_iterator<string>(cout, " "));//注意第二个参数是双引号括起来
	cout << endl;
}
int cheng(int a,int b)
{
	a *= b;
	cout << a << endl;
	return a;
}
class lei
{
public:
	int operator()(int a,int b)
	{
		return a*b;
	}
};
class lei0
{
public:
	void display()
	{
		cout << k << " ";
	}
	int k;
	lei0(int kk) :k(kk){};
};
int main()
{
	//构造函数赋值
	vector<int>a(5,2);//5个2,也可以直接5，表示5个0(int所以是0，类型T要用T())
	vector<int>aa(a.begin(), a.end());//结果不包含a.end，先闭后开的区间
	
	kk(a);
	kk(aa);

	a.assign(4, 4);//赋值函数赋值，和构造时一样，但是会清除原有数据
	kk(a);

	a.insert(a.begin() +2 ,2, 5);// 不写个数插入一个，是插在迭代器前,插入多个无返回值插入一个返回插入的值
	kk(a);
	a.insert(a.end(), a.begin(),a.end());//begin和end是迭代器，front和back是具体值的引用
	kk(a);								 //也是先闭后开的区间
										 //back是最后一个，end是最后一个的下一个

	a.resize(4);//大于原来则T()填充，小于则删除多余的
	kk(a);
	a.resize(6);
	kk(a);

	cout<<*a.erase(a.begin() + 3)<<endl;//返回删除元素的下一个迭代器
	kk(a);
	a.erase(a.end() - 2, a.end());//也是先闭后开的区间
	kk(a);

	a.push_back(1); //deque和list还有pop_front()，push_front()，vector没有，list还有splice接合
	kk(a);
	a.pop_back();
	kk(a);


	
	//deque和list练习
	deque<int>b;
	for (int i = 0; i < 10; i++)
	{
		b.push_front(i);
	}
	kk(b);

	list<int>c(b.rbegin(), b.rend());
	kk(c);
	
	list<int>::iterator p = c.begin();//定义迭代器
	while (p!=c.end())//交换相邻两个数
	{
		int temp = *p;
		p=c.erase(p);
		p++;
		c.insert(p, temp);
	}
	kk(c);

	b.assign(c.begin(), c.end());
	kk(b);

	//deque练习,从大到小输出奇数再从小到大输出偶数
	//cout << "输入待排数字" << endl;
	//istream_iterator<int>i1(cin), i2;
	int ii[9] = { 32, 43, 23, 78, 43,43, 6, 323, 5};
	vector<int>qa(ii,ii+8);
	sort(qa.begin(), qa.end());
	deque<int>qb;
	for (vector<int>::iterator qp=qa.begin(); qp < qa.end(); qp++)
	{
		if (*qp % 2 == 0)
			qb.push_back(*qp);
		else
			qb.push_front(*qp);
	}
	kk(qb);

	//list练习
	string s1[] = { "aa", "bb", "cc", "dd" };
	string s2[] = { "ee", "ff", "gg", "hh" };

	list<string>list1(s1, s1 + 4);//加4，注意左闭右开
	list<string>list2(s2, s2 + 4);

	list<string>::iterator listp = list1.begin();
	listp++;//可以++但是不能listp = listp + 1;
	advance(listp, 1);
	list1.splice(listp, list2,list2.begin(), list2.end());//在哪接合谁的哪部分，缺省接合全部，结合后删除接合的部分
	kkk(list1);

	//插入迭代器是适配器，辅助函数front_inserter(s),back_inserter(s),inserter(s,p)
	//list2.assign(list1.begin(), listp);
	//kkk(list2);
	//cout << "输入字符串"<<endl;
	//copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(list2));
	//kkk(list2);

	//stack和queue是容器适配器，stack基础容器是顺序容器，queue基础容器是双端队列或者列表，默认双端队列
	//利用栈反向输出字符串
	char ss[] = { "abcdefg" },*ssp=ss;
	stack<char>stack1;
	for (int i = 0; i < sizeof(ss)-1;i++)
	{
		stack1.push(*ssp);
		ssp++;
	}
	while (!stack1.empty())
	{
		cout << stack1.top();
		stack1.pop();
	}
	cout << endl;

	//优先级队列priority_queue也是容器适配器，基础容器是向量或者双端队列，默认向量，弹出最大值，top是最大值
	priority_queue<int>pq;
	vector<int>vk(ii, ii + sizeof(ii)/sizeof(int)-1);
	for (vector<int>::iterator vp = vk.begin(); vp < vk.end(); vp++)
	{
		pq.push(*vp);
	}
	while (!pq.empty())
	{
		cout << pq.top()<<' ';
		pq.pop();
	}
	cout << endl;

	//简单关联容器set，multiset
	//二元关联容器map，multimap
	//单重关联容器set,map
	//多重关联容器multiset,multimap
	//都自动按键升序排列

	//构造函数
	set<int>set0(ii, ii + sizeof(ii) / sizeof(int)-1);//出现重复元素只插入第一个
	kk(set0);
	multiset<int>multiset0(ii, ii + sizeof(ii) / sizeof(int)-1);//全插入
	kk(multiset0);
	//插入函数
	pair<set<int>::iterator, bool>pair0;
	pair0=set0.insert(100);//成功返回插入元素的迭代器和true，已存在返回相同元素的迭代器和fasle
	kk(set0);
	multiset0.insert(100);//插入总会成功，返回一个迭代器
	kk(multiset0);

	set0.insert(pair0.first, 101);//第一个参数迭代器，用于提示插入位置，提高插入效率，返回一个迭代器
	kk(set0);
	//删除函数，参数可以是键，迭代器，迭代器范围
	set0.erase(78);
	kk(set0);
	set<int>::iterator kp;
	kp = set0.begin();
	advance(kp, 4);//advance没有返回值
	set0.erase(kp, set0.end());
	kk(set0);
	//advance(set0.begin(), 2);//advance不改变begin,begin始终指向第一个元素,但是begin++等可以用来表示第二个元素等
	//find(k)按k键查找，有返回该元素迭代器，无返回end()
	//count(k)计数
	//lower_bound(k)不小于键的第一个元素的迭代器q1
	//upper_bound(k)大于k键的第一个元素的迭代器q2
	//equal_range(k)返回pair类型[q1, q2)
	cout << multiset0.count(43) << endl;

	//set练习
	set<double>set1;
	double setm[10] = { 1, 2, 7, 3, 6, 4, 5, 6, 6, 7 };
	for (auto m : setm)
	{
		set1.insert(m);
	}
	double mm = (*set1.begin() + *(--set1.end()))/2;
	cout << "<="<<mm<<":" << endl;
	copy(set1.begin(), set1.upper_bound(mm), ostream_iterator<double>(cout,"\t"));
	cout << endl;
	cout << ">=" << mm << ":" << endl;
	copy(set1.lower_bound(mm), set1.end(), ostream_iterator<double>(cout, "\t"));
	cout << endl;

	//map练习
	//选三门课，输出总学分
	map<string, int>kc;
	kc.insert(make_pair("aa", 1));
	kc.insert(make_pair("bb", 2));
	kc.insert(make_pair("cc", 3));
	kc.insert(make_pair("dd", 4));
	kc.insert(make_pair("ee", 5));

	int num = 0,sum=0;
	int i = 0;
	while (num<3)
	{
		string kc0[4] = {"aa","bb","ff","cc"};
		map<string, int>::iterator kcp=kc.find(kc0[i]);
		if (kcp == kc.end())
			cout << "没有"<<kc0[i]<<"课程或该课程已选" << endl;
		else
		{
			sum += kcp->second;
			num++;
			kc.erase(kcp);
		}
		i++;
	}
	cout << "总学分为：" << sum << endl;

	//map支持[]通过键访问附加数据，没有则新建，附加数据初始值为T()(整型就是0)
	//统计一句话中各字母出现个数
	map<char, int>map0;
	string word = { "hello word!" };
	for (auto wp : word)
	{
		if (isalpha(wp))
			map0[wp]++;
	}
	for (map<char, int>::iterator mp = map0.begin(); mp != map0.end(); mp++)
	{
		cout << mp->first << ":" << mp->second << endl;
	}

	//multiset允许多个重复元素，multimap允许一个键对应多个附加数据
	//multimap练习，输出某课程的上课时间
	multimap<string, string>map1;
	map1.insert(make_pair("aa", "1-1"));
	map1.insert(make_pair("bb", "1-2"));
	map1.insert(make_pair("aa", "2-1"));
	map1.insert(make_pair("dd", "2-2"));
	map1.insert(make_pair("dd", "3-1"));
	map1.insert(make_pair("dd", "3-2"));

	pair<multimap<string, string>::iterator, multimap<string, string>::iterator>pair1;
	pair1 = map1.equal_range("dd");
	for (multimap<string, string>::iterator pp = pair1.first; pp != pair1.second;pp++)

	{
		cout << pp->second << " ";
	}
	cout << endl;

	//函数对象(产生器，一元函数，二元函数，一元谓词，二元谓词)//一元二元是指输入参数多少，无则是产生器
	int w[5] = { 1, 2, 3, 4, 5 };
	//普通函数
	cout << accumulate(w, w + 5, 1, cheng)<<endl;
	//重载了函数调用运算符()的类的实例
	cout << accumulate(w, w + 5, 1, lei()) << endl;
	//标准库
	//plus,minus,multiplies,divides,modulus,negate加减乘除取余相反数，比较特殊类型大小需要重载<
	//equal_to,not_equal_to,greater,less,greater_equal,less_equal,logical_and,logical_or,logical_not//大于小于等于与或非，谓词函数对象
	cout << accumulate(w, w + 5, 1, multiplies<int>()) << endl;
	sort(w, w + 5, greater<int>());
	copy(w, w + 5, ostream_iterator<int>(cout, " "));
	cout << endl;
	//unary_function,binary_function是函数对象基类，分别用于设计一元和二元函数对象

	//函数适配器
	vector<int>ww = { 1, 2, 3, 4, 5 };
	//绑定适配器binder1st,binder2nd（对应的适配器辅助函数bind1st,bind2nd)
	cout << *(find_if(ww.begin(), ww.end(), bind2nd(greater<int>(), 2)))<<endl;
	
	//组合适配器unary_negate,binary_negate(not1,not2)
	cout << *(find_if(ww.begin(), ww.end(), not1(bind1st(greater_equal<int>(), 2)))) << endl;
	cout << *(find_if(ww.begin(), ww.end(), bind1st(not2(greater_equal<int>()), 2))) << endl;


	//指针函数适配器pointer_to_unary_function,pointer_to_binary_function(ptr_fun)
	for_each(ww.begin(), ww.end(), bind1st(ptr_fun(cheng), 5));

	//成员函数适配器(men_fun,men_fun_ref)
	//mem_fun_t,mem_fun_ref_t,
	//mem_fun1_t,mem_fun1_ref_t,
	//const_mem_fun_t,const_mem_fun_ref_t,
	//const_mem_fun1_t,const_mem_fun1_ref_t
	vector<lei0>e;
	vector<lei0*>pe;
	for (int i = 0; i < 5; i++)
	{
		lei0 ae(i);
		e.push_back(ae);
		lei0 *pae = new lei0(i + 5);
		pe.push_back(pae);
	}
	for_each(e.begin(), e.end(), mem_fun_ref(&lei0::display));
	for_each(pe.begin(), pe.end(), mem_fun(&lei0::display));
	cout << endl;
	//算法
	//不可变序列算法，可变序列算法，排序和搜索算法，数值算法

	int aaaa[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>aaa(aaaa,aaaa+(sizeof(aaaa)/sizeof(int)));
	kk(aaa);
	cout<<*remove_if(aaa.begin(), aaa.end(), bind1st(greater<int>(),4))<<endl;//remove_if,remove,unique只是把不被删除的元素赋值到前面[begin,mid)，然后返回最后mid
	kk(aaa);
	rotate_copy(aaa.begin(), aaa.begin() + 3, aaa.end(), ostream_iterator<int>(cout," "));//rotate_copy不会改变原序列的值
	cout << endl;
	kk(aaa);
	//sort参数是随机迭代器，stable_sort容器是双向迭代器即可，且对于等值元素排列后相对位置不变
	vector<int>bb(5);
	partial_sort_copy(aaa.begin(), aaa.begin() + 5, bb.begin(), bb.end(),greater<int>());//partial_sort_copy不会改变原序列的值
	kk(aaa);
	kk(bb);
	partial_sort(aaa.begin(), aaa.begin() + 5,aaa.end());//partial_sort是在全部里面找前n个较小的放在前面，其它放后面且相对位置不变
	kk(aaa);

	//不可变序列算法
	//for_each,find,find_if(支持循环查找),adjacent_find,find_first_of,find_end
	//mismatch,equal,search,search_n,count,count_if
	
	int mmm[] = { 9, 8, 7, 6, 5, 4, 3, 5, 2, 1, 1, 0 ,4, 3, 5, 2 };
	vector<int>m(mmm, mmm + 16);
	kk(m);
	cout<<*adjacent_find(m.begin(), m.end(), less<int>())<<endl;//注意返回的是相邻两个数前面的数的迭代器

	cout<<count_if(m.begin(), m.end(), bind2nd(less<int>(), 7))<<endl;

	cout<<*find_if(m.begin(), m.end(), bind1st(greater<int>(), 7))<<endl;//返回第一个满足条件的迭代器

	int mmm1[] = {4, 3, 5, 2};
	vector<int>m1(mmm1, mmm1 + 3);

	vector<int>::iterator m2;
	m2 = search(m.begin(), m.end(), m1.begin(), m1.end());//在序列m中查找序列m1，返回m中头个相等序列的第一个元素的迭代器
	cout << *(m2 - 1) << endl;

	m2=search_n(m.begin(), m.end(), 2, 1,equal_to<int>());//后面的参数是2个1的意思
	cout << *(m2 - 1) << endl;

	cout << equal(m.begin(), m.end(), m1.begin()) << endl;

	pair<vector<int>::iterator, vector<int>::iterator>m3;
	m3 = mismatch(m.begin(), m.end(), m1.begin());//返回不匹配位置的迭代器
	cout << *m3.first << " " << *m3.second << endl;

	//可变序列算法
	//copy,copy_n,copy_backward(先复制后面的),fill(替换),fill_n,generate(计算并替换),generate_n,partition(分割),stable_partition
	//rotate,rotate_copy,unique(去重),unique_copy,remove,remove_if,remove_copy,remove_copy_if
	//replace,replace_copy_if,reverse(反转),reverse_copy,swap,iter_swap,swap_ranges
	//transform,random_shuffle(随机重排)



	//排序和搜索算法
	//sort,stable_sort,partial_sort,partial_sort_copy
	//nth_element,includes
	//upper_bound,lower_bound,equal_range,binary_search//四个都是二分搜索算法
	//merge,inplace_merge
	//min,max,min_element,max_element
	//lexicographical_compare(词典顺序比较两序列)
	//next_permutation,prev_permutation
	//set_difference, set_union, set_intersection, set_symmetric_difference(对称差集)
	//make_heap,pop_heap,push_heap,sort_heap



	//数值算法
	//accumulate, partial_sum(部分和), adjacent_difference(相邻差), inner_product(内积,两个序列对应元素相乘的累加，第四个参数为累加的初始值)
	
	


	system("pause");
}

//随机访问容器：vector,deque
//可逆容器：list,map,set,multimap,multiset

//顺序容器: vector,deque,list
//关联容器: map,set,multimap,multiset
