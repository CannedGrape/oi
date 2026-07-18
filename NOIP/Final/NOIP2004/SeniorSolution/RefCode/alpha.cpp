#include <fstream>
#include <string>
using namespace std;

ifstream fin("alpha.in");
ofstream fout("alpha.out");

bool finish, hash[256], used[27];
int n, stk[27];
string a, b, c;
string word;

void init() {
	fin >> n >> a >> b >> c;
	finish = false;
}

void outsol() {
	int i, ans[27];

	for (i = 0; i < n; i ++)
		ans[word[i] - 65] = stk[i];

	fout << ans[0];
	for (i = 1; i < n; i ++)
		fout << " " << ans[i];
	fout << endl;
	finish = true;
}

void addup(char ch) {
	if (!hash[ch]) {
		hash[ch] = true;
		word = word + ch;
	}
}

string change(string str, char x, char y) {
	for (int i = 0; i < n; i ++)
		if (str[i] == x)
			str[i] = y;
	return str;
}

void pre_doing() {
	word = "";
	memset(hash, 0, sizeof(hash));

	for (int i = n - 1; i >= 0; i --) {
		addup(a[i]); addup(b[i]); addup(c[i]);
	}

	memset(used, 0, sizeof(used));
}

bool bad() {
	int p, g = 0;
	for (int i = n - 1; i >= 0; i --) {
		if (a[i] >= n || b[i] >= n || c[i] >= n) return false;
		p = a[i] + b[i] + g;
		if (p % n != c[i]) return true;
		g = p / n;
		p %= n;
	}
	return false;
}

bool modcheck() {
	int i, p, p1, p2, g = 0;
	//a + b = c, all know
	for (i = n - 1; i >= 0; i --) {
		if (a[i] >= n || b[i] >= n || c[i] >= n) continue;
		p = (a[i] + b[i]) % n;
		if (!(p == c[i] || (p + 1) % n == c[i])) return true;
	}

	//a + ? = c
	for (i = n - 1; i >= 0; i --) {
		if (!(a[i] < n && c[i] < n && b[i] >= n)) continue;
		p1 = (c[i] - a[i] + n) % n;
		p2 = (p1 - 1) % n;
		if (used[p1] && used[p2]) return true;
	}
	
	//? + b = c
	for (i = n - 1; i >= 0; i --) {
		if (!(a[i] >= n && c[i] < n && b[i] < n)) continue;
		p1 = (c[i] - b[i] + n) % n;
		p2 = (p1 - 1) % n;
		if (used[p1] && used[p2]) return true;
	}

	//a + b = ?
	for (i = n - 1; i >= 0; i --) {
		if (!(a[i] < n && b[i] < n && c[i] >= n)) continue;
		p1 = (a[i] + b[i]) % n;
		p2 = (p1 + 1) % n;
		if (used[p1] && used[p2]) return true;
	}

	return false;
}

void dfs(int l) {
	int i;
	string A, B, C;

	if (finish) return;
	if (bad()) return;
	if (modcheck()) return;

	if (l == n) {
		outsol();
		return;
	}
	
	for (i = n - 1; i >= 0; i --)
		if (!used[i]) {
			used[i] = true;  A = a; B = b; C = c;
			a = change(A, word[l], i);
			b = change(B, word[l], i);
			c = change(C, word[l], i);
			stk[l] = i;
			dfs(l + 1);
			used[i] = false; a = A; b = B; c = C;
		}
}
	
int main() {
	init();
	pre_doing();
	dfs(0);
	return 0;
}
