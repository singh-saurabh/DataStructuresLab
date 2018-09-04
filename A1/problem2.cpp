#include <iostream>
#include <string>
#include <vector>
using namespace std ;

const int SIZE = 110 ;
unsigned long long f[SIZE] ;


vector <string> generate(string p) {
	vector <string> p_in_previous_F ;
	unsigned long long l = p.length() ;
	string str = "" ;
	char c1 , c2 , c3 ;
	unsigned long long i ;
	if(p == "01") {
		p_in_previous_F.push_back("10") ;
		p_in_previous_F.push_back("11") ;
		return p_in_previous_F ;
	}
	if(p == "11") {
		p_in_previous_F.push_back("01") ;
		return p_in_previous_F ;
	}
	for(i = 0 ; i <= l - 2 ;) {
		c1 = p[i] ;
		c2 = p[i + 1] ;
		if(c1 == '0' && c2 == '0') {
			return p_in_previous_F ;
			break ;
		}
		else if(c1 == '1' && c2 == '0') {
			str = str + "1" ;
			i = i + 2 ;
		}
		else if(c1 == '1' && c2 == '1') {
			c3 = p[i + 2] ;
			if(c3 == '1') {
				return p_in_previous_F ;
				break ;
			}
			else {
				str = str + "0" ;
				i = i + 1 ;
			}
		}
		else if(c1 == '0' && c2 == '1') {
			if(i == 0) {
				str = "1" ;
				i = i + 1 ;
			}
			else {
				return p_in_previous_F ;
				break ;
			}
		}
	}

	if(i == l - 1 && p[l - 1] == '0') {
		return p_in_previous_F ;
	}
	if(i == l - 1 && p[l - 1] == '1') {
		p_in_previous_F.push_back(str + "1") ;
		p_in_previous_F.push_back(str + "0") ;
		return p_in_previous_F ;
	}
	p_in_previous_F.push_back(str) ;
	return p_in_previous_F ;
}

unsigned long long occurances(string p , int n) {
	unsigned long long count = 0 ;
	vector <string> p_in_previous_F ;
	if(p.length() > 1) {
		p_in_previous_F = generate(p) ;
	}
	else {
		p_in_previous_F.push_back(p) ;
	}
	for(int i = 0 ; i < p_in_previous_F.size() ; i++) {
		if(p_in_previous_F[i] == "1")
			count = count + f[n - 1] ;
		else if(p_in_previous_F[i] == "0")
			count = count + f[n - 2] ;
		else if(p_in_previous_F[i].length() > f[n])
			count = count + 0 ;
		else
			count = count + occurances(p_in_previous_F[i] , n - 1) ;
	}
	return count ;
}

int main () {
	int n ;
	string p ;

	f[0] = f[1] = 1 ;
	for(int i = 2 ; i < SIZE ; i++) {
		f[i] = f[i - 1] + f[i - 2] ;
	}
	while(cin >> n && cin >> p) {
		if(p == "0" && n == 0) {
			cout << "1" << endl ;
			continue ;
		}
		if(p == "1")
			cout << f[n - 1] << endl ;
		else if(p == "0")
			cout << f[n - 2] << endl ;
		else {
			cout << occurances(p , n - 1) << endl ;
		}
	}
}
