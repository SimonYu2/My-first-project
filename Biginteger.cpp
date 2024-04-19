#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
void fill_random_int(vector<int> & v, int cnt){
	v.clear();
	for(int i = 0; i <= cnt; i++) v.push_back(rand());
}
struct BigInteger{
	static const long long base = 100000000;
	static const int width = 8;
	vector<int> s;
	BigInteger(int sum = 0) {*this = sum;}
	BigInteger operator = (int b){
		s.clear();
		do{
			s.push_back(b % base);
			b /= base;
		}while(b);
		return *this;
	}
	BigInteger operator = (const string str){
		int x;
		int len = (str.length() - 1) / width + 1;
		for(int i = 0; i < len; i ++){
			int end = str.length() - i * width, start = max(0, end - width);
			sscanf(str.substr(start, end - start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return *this;
	}
	BigInteger operator + (const BigInteger& b){
		BigInteger c;
		c.s.clear();
		for(int i = 0, g = 0; ; i ++){
			if(g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = g;
			if(i < s.size()) x += s[i];
			if(i < b.s.size()) x += b.s[i];
			c.s.push_back(x % base);
			g = x / base;
 		}
 		return c;
	}
	BigInteger operator += (const BigInteger& b){
		*this = *this + b;
		return *this;
	}
	bool operator < (const BigInteger & b){
		if(s.size() != b.s.size()) return s.size() < b.s.size();
		for(int i = s.size() - 1; i >= 0; i --) if(s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}

};
int main(){
	BigInteger x, y;
	x = "12312351236134713713713472351583";
	y = "1234246134612346134719309478190347810934871093487019348701";
	cout << (x < y);
	return 0;
} 
