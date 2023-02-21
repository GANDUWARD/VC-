#include<iostream>
#include<string>
#include<vector>
#include<iterator>
//int main()
//{
//	std::cout << "Enter two numbers:" << std::endl;
//	int v1 = 0, v2 = 0;
//	std::cin >> v1 >> v2;
//	std::cout << "The sum of " << v1 << " and " << v2
//		<< " is " << v1 + v2 << std::endl;
//	return 0;
//}
//int main()
//{
//	std::cout << "Hello,World" << std::endl;
//	return 0;
//}
//int main()
//{
//	std::cout << "Enter two numbers" << std::endl;
//	int v1 = 0, v2 = 0;
//	std::cin >> v1 >> v2;
//	std::cout << "The multiplication of ";
//	std::cout << v1 ;
//	std::cout << " and " ;
//	std::cout << v2 ;
//	std::cout << " is " ;
//	std::cout<<v1* v2 <<std::endl;
//	return 0;
//}
//int main()
//{
//	int sum = 0, val = 1;
//	while (val <= 10)
//	{
//		sum += val;
//		val++;
//	}
//	std::cout << "The sum of 1 to 10 inclusive is " << sum << std::endl;
//	return 0;
//}
//int main()
//{
//	int sum = 0, value = 0;
//	while (std::cin >> value)
//		sum += value;
//	std::cout << "The sum is " << sum << std::endl;
//	return 0;
//}
//int main()
//{
//    int cur; int val;
//    if (std::cin >> cur)
//    {    
//        int cnt = 1;
//        while (std::cin >> val)
//        {
//            if (val == cur)
//                cnt++;
//            else
//            {   
//                std::cout << cur << " occurs " << cnt << " times " << std::endl;
//                cur = val;
//                cnt = 1;
//            }
//        }
//        std::cout << cur << " occurs " << cnt << " times " << std::endl;
//    }
//    return 0;
//}
//int main()
//{
//	int sum = 0,val;
//	while (std::cin >> val)
//		sum += val;
//	std::cout << "The sum is " << sum << std::endl;
//	return 0;
//}
//int main()
//{
//	int i=1;
//	double t1, t2,a,s=0;
//	for (i = 1; i <= 4; i++)
//	{
//		std::cout << "请输入t" << i << "时刻与t" << i + 4 << "时刻:" << std::endl;
//		std::cin >> t1 >> t2;
//		a = 2 * 3.14 * ((i + 4) * t1 - i * t2) / (t2 * t2 * t1 - t1 * t1 * t2);
//		/*std::cout << "角速度" << i << "是" << a << std::endl;*/
//		printf("角加速度%d是%.4f\n",i, a);
//		s += a;
//	}
//	s = s / 4;
//	//std::cout << "角平均速度为" << s << std::endl;
//	printf("角平均加速度是%.4f\n",s);
//	return 0;
//}
//int main()
//{   
//	int i = 0;
//	int& refVal = i;     //&+变量名表示引用
//	std::cout << refVal << std::endl;
//	return 0;
//}
//int main()
//{
//	using std::string;
//	const string hexdigits = "0123456789ABCEF";//可能的十六进制数字
//	std::cout << "Enter a series of numbers between 0 and 15"
//		<< "separated by spaces.Hit ENTER when finished:"
//		<< std::endl;
//	string result;//用于保存十六进制的字符串
//	string::size_type n; //用于保存从输入流读取的数
//	while (std::cin >> n)
//		if (n < hexdigits.size())//忽略无效输入
//			result += hexdigits[n]; 
//	std::cout << "Your hex number is:" << result << std::endl;
//	return 1;
//}
//int main()
//{
//	using std::string;
//	string dusha;
//	string::size_type n;
//	std::cout << "Please enter a string:";
//	std::cin >> dusha;
//	for (n=0;n<dusha.size();n++)
//	{      
//			dusha[n] = 'X';
//	}
//	std::cout << "Your private string is:" << dusha << std::endl;
//}
//int main()
//{
//    using std::vector;
//    using std::string;
//    vector<string> svec;
//    vector<string> v1{ "a" ,"b" };
//    vector<string> v2(10);
//    vector<string> v3;
//    string x;
//    while (std::cin >> x)
//    {
//        v3.push_back(x);
//    }
//    return 1;
//}
//int main()
//{  
//	using std::vector;
//	vector<int> v1= {1, 2, 3, 4, 5, 6, 7, 8, 9};
//	for (auto &i : v1)
//		i *= i;
//	for (auto i : v1)
//		std::cout << i<<"  ";
//	std::cout << std::endl;
//	return 1;
//}
//int main()
//{
//	using std::vector;
//	vector<int> v1(11);
//	std::cout << "请输入学生成绩:";
//	unsigned score;
//	while (std::cin >> score)
//	{
//		if (score <= 100)
//			v1[score / 10]++;
//	}
//	std::cout << "各分数段统计个数:";
//	for (int i = 0; i < v1.size(); i++)
//		std::cout << v1[i] << "   ";
//	return 1;
//}
//int main()
//{
//	using std::string;
//	using std::vector;
//	vector<string> v1;
//	string x;
//	std::cout << "Please enter some words " << "seperated by space:";
//	while (std::cin >> x)
//	{
//		for (int i = 0; i < x.size(); i++)
//		{
//			if (x[i] >= 'a' && x[i] <= 'z')
//				x[i] += 'A' - 'a';
//		}
//		v1.push_back(x);
//	}
//	std::cout << "The consequence of the toupper words are ";
//	for (int i = 0; i < v1.size(); i++)
//			std::cout << v1[i] << "   ";
//	return 1;
//}
//int main()
//{
//    using std::string;
//    string s{ "dusha" };
//    if (s.begin() != s.end())
//    {
//        auto it = s.begin();
//        *it = toupper(*it);
//    }
//    std::cout << s << std::endl;
//    return 1;
//}
//int main()
//{
//    using std::string;
//    string s{ "dusha" };
//    for (auto it = s.begin(); it != s.end() && !isspace(*it); it++)
//        *it = toupper(*it);
//    std::cout << s << std::endl;
//	return 1;
//}
//int main()
//{
//	using std::vector;
//	vector<int> v1;
//	int x;
//	for (int i = 0; i < 10; i++)
//	{   
//		std::cin >> x;
//		v1.push_back(x);
//	}
//	for (auto k = v1.begin(); k != v1.end(); k++)
//	{
//		(*k) *= 2;
//		std::cout << *k << "  ";
//	}
//	return 1;
//}
//int main()
//{
//	using std::vector;
//	vector<int> v1(11);
//	std::cout << "请输入学生成绩:";
//	unsigned score;
//	while (std::cin >> score)
//	{
//		if (score <= 100)
//			*(v1.begin() + score / 10) += 1;
//	}
//	std::cout << "各分数段统计个数:";
//	for (auto i=v1.cbegin(); i<v1.cend(); i++)
//		std::cout <<*i << "   ";
//	return 1;
//}
//int main()
//{
//	constexpr size_t size = 10;
//	int a[size];
//	for (size_t i = 0; i < size; i++)
//		a[i] = i;
//	for (size_t i = 0; i < size; i++)
//		std::cout << a[i] << std::endl;
//	return 0;
//}
int main()
{
	return 0;
}
