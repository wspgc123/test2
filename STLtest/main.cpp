//STL(��׼ģ���):�㷨������������������������

#include<vector>//����(��������)
#include<deque>//˫�˶���(��������ӷֶ�����)
#include<list>//�б�(˫������)
#include<map>//ӳ��map�Ͷ���ӳ��multimap
#include<set>//����set�Ͷ��ؼ���multiset

#include<stack>
#include<queue>

#include<string>

//#include<utility>//pair��make_pair��
//#include<cctype>//isalpha��tolower�Ⱥ���
//#include<algorithm>//��������ȫ���㷨
#include<numeric>//��ֵ�㷨
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
	copy(a.begin(), a.end(), ostream_iterator<string>(cout, " "));//ע��ڶ���������˫����������
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
	//���캯����ֵ
	vector<int>a(5,2);//5��2,Ҳ����ֱ��5����ʾ5��0(int������0������TҪ��T())
	vector<int>aa(a.begin(), a.end());//���������a.end���ȱպ󿪵�����
	
	kk(a);
	kk(aa);

	a.assign(4, 4);//��ֵ������ֵ���͹���ʱһ�������ǻ����ԭ������
	kk(a);

	a.insert(a.begin() +2 ,2, 5);// ��д��������һ�����ǲ��ڵ�����ǰ,�������޷���ֵ����һ�����ز����ֵ
	kk(a);
	a.insert(a.end(), a.begin(),a.end());//begin��end�ǵ�������front��back�Ǿ���ֵ������
	kk(a);								 //Ҳ���ȱպ󿪵�����
										 //back�����һ����end�����һ������һ��

	a.resize(4);//����ԭ����T()��䣬С����ɾ�������
	kk(a);
	a.resize(6);
	kk(a);

	cout<<*a.erase(a.begin() + 3)<<endl;//����ɾ��Ԫ�ص���һ��������
	kk(a);
	a.erase(a.end() - 2, a.end());//Ҳ���ȱպ󿪵�����
	kk(a);

	a.push_back(1); //deque��list����pop_front()��push_front()��vectorû�У�list����splice�Ӻ�
	kk(a);
	a.pop_back();
	kk(a);


	
	//deque��list��ϰ
	deque<int>b;
	for (int i = 0; i < 10; i++)
	{
		b.push_front(i);
	}
	kk(b);

	list<int>c(b.rbegin(), b.rend());
	kk(c);
	
	list<int>::iterator p = c.begin();//���������
	while (p!=c.end())//��������������
	{
		int temp = *p;
		p=c.erase(p);
		p++;
		c.insert(p, temp);
	}
	kk(c);

	b.assign(c.begin(), c.end());
	kk(b);

	//deque��ϰ,�Ӵ�С��������ٴ�С�������ż��
	//cout << "�����������" << endl;
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

	//list��ϰ
	string s1[] = { "aa", "bb", "cc", "dd" };
	string s2[] = { "ee", "ff", "gg", "hh" };

	list<string>list1(s1, s1 + 4);//��4��ע������ҿ�
	list<string>list2(s2, s2 + 4);

	list<string>::iterator listp = list1.begin();
	listp++;//����++���ǲ���listp = listp + 1;
	advance(listp, 1);
	list1.splice(listp, list2,list2.begin(), list2.end());//���ĽӺ�˭���Ĳ��֣�ȱʡ�Ӻ�ȫ������Ϻ�ɾ���ӺϵĲ���
	kkk(list1);

	//���������������������������front_inserter(s),back_inserter(s),inserter(s,p)
	//list2.assign(list1.begin(), listp);
	//kkk(list2);
	//cout << "�����ַ���"<<endl;
	//copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(list2));
	//kkk(list2);

	//stack��queue��������������stack����������˳��������queue����������˫�˶��л����б�Ĭ��˫�˶���
	//����ջ��������ַ���
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

	//���ȼ�����priority_queueҲ��������������������������������˫�˶��У�Ĭ���������������ֵ��top�����ֵ
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

	//�򵥹�������set��multiset
	//��Ԫ��������map��multimap
	//���ع�������set,map
	//���ع�������multiset,multimap
	//���Զ�������������

	//���캯��
	set<int>set0(ii, ii + sizeof(ii) / sizeof(int)-1);//�����ظ�Ԫ��ֻ�����һ��
	kk(set0);
	multiset<int>multiset0(ii, ii + sizeof(ii) / sizeof(int)-1);//ȫ����
	kk(multiset0);
	//���뺯��
	pair<set<int>::iterator, bool>pair0;
	pair0=set0.insert(100);//�ɹ����ز���Ԫ�صĵ�������true���Ѵ��ڷ�����ͬԪ�صĵ�������fasle
	kk(set0);
	multiset0.insert(100);//�����ܻ�ɹ�������һ��������
	kk(multiset0);

	set0.insert(pair0.first, 101);//��һ��������������������ʾ����λ�ã���߲���Ч�ʣ�����һ��������
	kk(set0);
	//ɾ�����������������Ǽ�������������������Χ
	set0.erase(78);
	kk(set0);
	set<int>::iterator kp;
	kp = set0.begin();
	advance(kp, 4);//advanceû�з���ֵ
	set0.erase(kp, set0.end());
	kk(set0);
	//advance(set0.begin(), 2);//advance���ı�begin,beginʼ��ָ���һ��Ԫ��,����begin++�ȿ���������ʾ�ڶ���Ԫ�ص�
	//find(k)��k�����ң��з��ظ�Ԫ�ص��������޷���end()
	//count(k)����
	//lower_bound(k)��С�ڼ��ĵ�һ��Ԫ�صĵ�����q1
	//upper_bound(k)����k���ĵ�һ��Ԫ�صĵ�����q2
	//equal_range(k)����pair����[q1, q2)
	cout << multiset0.count(43) << endl;

	//set��ϰ
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

	//map��ϰ
	//ѡ���ſΣ������ѧ��
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
			cout << "û��"<<kc0[i]<<"�γ̻�ÿγ���ѡ" << endl;
		else
		{
			sum += kcp->second;
			num++;
			kc.erase(kcp);
		}
		i++;
	}
	cout << "��ѧ��Ϊ��" << sum << endl;

	//map֧��[]ͨ�������ʸ������ݣ�û�����½����������ݳ�ʼֵΪT()(���;���0)
	//ͳ��һ�仰�и���ĸ���ָ���
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

	//multiset�������ظ�Ԫ�أ�multimap����һ������Ӧ�����������
	//multimap��ϰ�����ĳ�γ̵��Ͽ�ʱ��
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

	//��������(��������һԪ��������Ԫ������һԪν�ʣ���Ԫν��)//һԪ��Ԫ��ָ����������٣������ǲ�����
	int w[5] = { 1, 2, 3, 4, 5 };
	//��ͨ����
	cout << accumulate(w, w + 5, 1, cheng)<<endl;
	//�����˺������������()�����ʵ��
	cout << accumulate(w, w + 5, 1, lei()) << endl;
	//��׼��
	//plus,minus,multiplies,divides,modulus,negate�Ӽ��˳�ȡ���෴�����Ƚ��������ʹ�С��Ҫ����<
	//equal_to,not_equal_to,greater,less,greater_equal,less_equal,logical_and,logical_or,logical_not//����С�ڵ������ǣ�ν�ʺ�������
	cout << accumulate(w, w + 5, 1, multiplies<int>()) << endl;
	sort(w, w + 5, greater<int>());
	copy(w, w + 5, ostream_iterator<int>(cout, " "));
	cout << endl;
	//unary_function,binary_function�Ǻ���������࣬�ֱ��������һԪ�Ͷ�Ԫ��������

	//����������
	vector<int>ww = { 1, 2, 3, 4, 5 };
	//��������binder1st,binder2nd����Ӧ����������������bind1st,bind2nd)
	cout << *(find_if(ww.begin(), ww.end(), bind2nd(greater<int>(), 2)))<<endl;
	
	//���������unary_negate,binary_negate(not1,not2)
	cout << *(find_if(ww.begin(), ww.end(), not1(bind1st(greater_equal<int>(), 2)))) << endl;
	cout << *(find_if(ww.begin(), ww.end(), bind1st(not2(greater_equal<int>()), 2))) << endl;


	//ָ�뺯��������pointer_to_unary_function,pointer_to_binary_function(ptr_fun)
	for_each(ww.begin(), ww.end(), bind1st(ptr_fun(cheng), 5));

	//��Ա����������(men_fun,men_fun_ref)
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
	//�㷨
	//���ɱ������㷨���ɱ������㷨������������㷨����ֵ�㷨

	int aaaa[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>aaa(aaaa,aaaa+(sizeof(aaaa)/sizeof(int)));
	kk(aaa);
	cout<<*remove_if(aaa.begin(), aaa.end(), bind1st(greater<int>(),4))<<endl;//remove_if,remove,uniqueֻ�ǰѲ���ɾ����Ԫ�ظ�ֵ��ǰ��[begin,mid)��Ȼ�󷵻����mid
	kk(aaa);
	rotate_copy(aaa.begin(), aaa.begin() + 3, aaa.end(), ostream_iterator<int>(cout," "));//rotate_copy����ı�ԭ���е�ֵ
	cout << endl;
	kk(aaa);
	//sort�����������������stable_sort������˫����������ɣ��Ҷ��ڵ�ֵԪ�����к����λ�ò���
	vector<int>bb(5);
	partial_sort_copy(aaa.begin(), aaa.begin() + 5, bb.begin(), bb.end(),greater<int>());//partial_sort_copy����ı�ԭ���е�ֵ
	kk(aaa);
	kk(bb);
	partial_sort(aaa.begin(), aaa.begin() + 5,aaa.end());//partial_sort����ȫ��������ǰn����С�ķ���ǰ�棬�����ź��������λ�ò���
	kk(aaa);

	//���ɱ������㷨
	//for_each,find,find_if(֧��ѭ������),adjacent_find,find_first_of,find_end
	//mismatch,equal,search,search_n,count,count_if
	
	int mmm[] = { 9, 8, 7, 6, 5, 4, 3, 5, 2, 1, 1, 0 ,4, 3, 5, 2 };
	vector<int>m(mmm, mmm + 16);
	kk(m);
	cout<<*adjacent_find(m.begin(), m.end(), less<int>())<<endl;//ע�ⷵ�ص�������������ǰ������ĵ�����

	cout<<count_if(m.begin(), m.end(), bind2nd(less<int>(), 7))<<endl;

	cout<<*find_if(m.begin(), m.end(), bind1st(greater<int>(), 7))<<endl;//���ص�һ�����������ĵ�����

	int mmm1[] = {4, 3, 5, 2};
	vector<int>m1(mmm1, mmm1 + 3);

	vector<int>::iterator m2;
	m2 = search(m.begin(), m.end(), m1.begin(), m1.end());//������m�в�������m1������m��ͷ��������еĵ�һ��Ԫ�صĵ�����
	cout << *(m2 - 1) << endl;

	m2=search_n(m.begin(), m.end(), 2, 1,equal_to<int>());//����Ĳ�����2��1����˼
	cout << *(m2 - 1) << endl;

	cout << equal(m.begin(), m.end(), m1.begin()) << endl;

	pair<vector<int>::iterator, vector<int>::iterator>m3;
	m3 = mismatch(m.begin(), m.end(), m1.begin());//���ز�ƥ��λ�õĵ�����
	cout << *m3.first << " " << *m3.second << endl;

	//�ɱ������㷨
	//copy,copy_n,copy_backward(�ȸ��ƺ����),fill(�滻),fill_n,generate(���㲢�滻),generate_n,partition(�ָ�),stable_partition
	//rotate,rotate_copy,unique(ȥ��),unique_copy,remove,remove_if,remove_copy,remove_copy_if
	//replace,replace_copy_if,reverse(��ת),reverse_copy,swap,iter_swap,swap_ranges
	//transform,random_shuffle(�������)



	//����������㷨
	//sort,stable_sort,partial_sort,partial_sort_copy
	//nth_element,includes
	//upper_bound,lower_bound,equal_range,binary_search//�ĸ����Ƕ��������㷨
	//merge,inplace_merge
	//min,max,min_element,max_element
	//lexicographical_compare(�ʵ�˳��Ƚ�������)
	//next_permutation,prev_permutation
	//set_difference, set_union, set_intersection, set_symmetric_difference(�ԳƲ)
	//make_heap,pop_heap,push_heap,sort_heap



	//��ֵ�㷨
	//accumulate, partial_sum(���ֺ�), adjacent_difference(���ڲ�), inner_product(�ڻ�,�������ж�ӦԪ����˵��ۼӣ����ĸ�����Ϊ�ۼӵĳ�ʼֵ)
	
	


	system("pause");
}

//�������������vector,deque
//����������list,map,set,multimap,multiset

//˳������: vector,deque,list
//��������: map,set,multimap,multiset
