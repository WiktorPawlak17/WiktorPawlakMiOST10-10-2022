#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int M = 0;
	int V = 0;
	vector<double> a;
	vector<double> t;
	vector<double> x;
	vector<double> p;
	vector<double> b;
	x.push_back(1);
	//gdy¿ x0 jest zawsze 1;
	
	cout << "Podaj pojemnosc systemu" << endl;
	cin >> V;
	
	cout << "Podaj liczbe klas zgloszen oferowanych systemowi" << endl;
	cin >> M;
	
	for(int i = 1; i <= M; i++) {
		cout << "Podaj wartosc a"<<i<<endl;
		double tmp = 0;
		cin >> tmp;
		a.push_back(tmp);
	}
	
	for(int i = 1; i <= M; i++) {
		cout << "Podaj wartosc t"<<i<<endl;
		double tmp = 0;
		cin >> tmp;
		t.push_back(tmp);
	}
	//wyzerowanie ca³ego wektora p
	for(int i = 0; i <= V; i++){
		p.push_back(0);
	}
	double temp = 0;
	
	//x1
	x.push_back(a[0]*t[0]);
	//x2
	temp = (t[1]*a[1] + a[0]*a[0]*t[0])/2;
	x.push_back(temp);
	//x3
	temp = a[0]*a[1]*t[0]+(a[0]*a[0]*a[0]*t[1])/12;
	x.push_back(temp);
	//xn
	
	for(int i = 4; i <=V;i++) {
		temp = 2*a[1]*x[i-2]*t[i-2]+a[0]*x[i-1]*t[i-1];
		temp/=i; 
		x.push_back(temp);
	}
	temp = 0;
	for(int i = 0; i <= V;i++) {
	temp+=x[i];	
	}
	p[0] = 1/temp;
	int channel = 0;
	cout << "Zajetosc ilu kanalow chcesz sprawdzic ? "<<endl;
	cin >> channel;
	temp = 0;
	for(int i = V - t[channel-1] + 1; i <=V;i++) {
		temp+=x[i] * p[0];
	}
	for(int i = 1; i < p.size();i++) {
		p[i] = p[0] * x[i];
	}
	cout << "Zajetosc " << channel << " kanalow to "<<temp<<endl;
	cout << "-------------------------"<<endl;
	for(int i = 0; i <= V; i++) {
		if(i < a.size()) {
		cout << "a"<<i<<" = "<<a[i] << endl;	
		}
		if(i<t.size()) {
		cout << "t"<<i<<" = "<<t[i] << endl;	
		}
		if(i<x.size()) {
		cout << "x"<<i<<" = "<<x[i] << endl;	
		}
		if(i<p.size()) {
		cout << "p"<<i<<" = "<<p[i] << endl;	
		}
		
		
		
		
	}
	
	return 0;
}
