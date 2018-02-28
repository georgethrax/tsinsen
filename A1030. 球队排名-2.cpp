#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int max_N = 20;
const int max_Name = 30;



class Node{
	public:
	Node(string name="", int x=0, int y=0, int z=0)
	:name(name), x(x), y(y), z(z)
	{}

	string name;
	int x;
	int y;
	int z;

	bool operator > (const Node & m)const;
	bool operator < (const Node & m)const;
};
bool gr(Node g, Node l){
	bool c = true;
	if (g.x > l.x){
		return true;
	}
	if (g.x < l.x){
		return false;
	}
	if (g.y > l.y){
		return true;
	}
	if (g.y < l.y){
		return false;
	}
	if (g.z > l.z){
		return true;
	}
	if (g.z < l.z){
		return false;
	}
	if (g.name > l.name){
		return false;
	}
	if (g.name < l.name){
		return true;
	}
	return false;
}

bool Node::operator > (const Node &m)const{
		return gr(*this, m);
}
bool Node::operator < (const Node &m)const{
		return !gr(*this, m);
}

/*
void sort(Node a[], int N){
	for (int i=0; i<N;i++){
		for (int j=i; j<N; j++){
			if (!gr(a[i], a[j])){
				Node t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}

}
*/

int main(int argc, char*argv[]){
	int N;
	cin >> N;

	vector<Node> a;

	for (int i=0; i< N; i++){
		int x,y,z;
		a.push_back(Node());
		cin >>a[i].name >>a[i].x >>a[i].y >>a[i].z;
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	for (int i=0; i<N; i++){
		cout << a[i].name <<endl;
	}
	return 0;
}