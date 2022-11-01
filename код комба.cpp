бин поиск
#include <iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>len(n);
	for (int i = 0; i < len.size(); i++) {
		cin >> len[i];
		int ans = len[0]+1,
			ans_l = 0,
			ans_r = 0,
			sum = 0,
			min_sum = 0,
			min_pos = -1;
		for (int j = 0; j < n; j++) {
			sum += len[j];

			int cur = sum - min_sum;
			if (cur > ans) {
				ans = cur;
				ans_l = min_pos + 1;
				ans_r = j;
			}

			if (sum < min_sum) {
				min_sum = sum;
				min_pos = j;
			}
			
		}
		cout << ans_l+1 << ' ' << ans_r+1 << ' ' << ans;
	}
}
--------------------------------------------------------------------
БИН ПОИСК 
ЗАДАЧА ОТ L ДО R
n = int(input())
n1 = list(map(int, input().split()))
n1.sort()
answer = []

def lbinsearch(l, r, num):
    if len(n1) == 1:
        return 0
    if n1[l] > num:
        return l
    if n1[r] < num:
        return r+l
    while l < r:
        m = (l + r) // 2
        if n1[m] >= num:
            r = m
        elif n1[m] < num:
            l = m + 1
    return l

def rbinsearch(l, r, num):
    if len(n1) == 1:
        if n1[0] == num:
            return 1
        else:
            return 0
    if n1[l] > num:
        return l
    if n1[r] < num:
        return r + l
    while l < r:
        m = (l + r + 1) // 2
        if n1[m] <= num:
            l = m
        elif n1[m] > num:
            r = m - 1
    return l + 1

k = int(input())
for k1 in range(k):
    l, r = list(map(int, input(). split()))
    answer.append(rbinsearch(0, len(n1)-1, r) - lbinsearch(0, len(n1) - 1, l))
print(*answer)
--------------------------------------------------------------------




задача различные числа

#include<iostream>
#include<vector>
#include<algorithm>
 
struct query {
    int id = 0, l = 0, r = 0, rez = 0;
};
 
bool cmp(const query &a, const  query &b){
    if (a.l / 500 == b.l / 500)
        return a.r < b.r;
    else
        return a.l < b.l;
}
 
bool cmp2(const query &a, const  query &b){
    return a.id < b.id;
}
 
int ans = 0;
 
std::vector<int> cnt(300001, 0);
 
int a = 0, b = -1;
void mo(std::vector<int>&v, query &q){
    int l = q.l, r = q.r;
    while(b < r){
        b++;
        if (cnt[v[b]] == 0) ans++;
        cnt[v[b]]++;
    }
    while(b > r){
        cnt[v[b]]--;
        if (cnt[v[b]] == 0) ans--;
        b--;
    }
    while(a < l){
        cnt[v[a]]--;
        if (cnt[v[a]] == 0) ans--;
        a++;
    }
    while(a > l){
        a--;
        if (cnt[v[a]] == 0) ans++;
        cnt[v[a]]++;
    }
    q.rez = ans;
}
 
 
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = 0, m = 0;
    std::cin >> n;
    std::vector<int> v(n), pos;
    for (size_t i = 0; i < v.size(); ++i) {
        std::cin >> v[i];
    }
    pos = v;
    std::sort(pos.begin(), pos.end());
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = int(lower_bound(pos.begin(), pos.end(), v[i]) - pos.begin());
    }
    std::cin >> m;
    std::vector<query> q(m);
    for (size_t i = 0; i < q.size(); ++i) {
        int l = 0, r = 0;
        std::cin >> l >> r;
        q[i].id = i;
        q[i].l = l - 1;
        q[i].r = r - 1;
    }
    std::sort(q.begin(), q.end(), cmp);
    for(size_t i = 0; i < q.size(); ++i){
        mo(v, q[i]);
    }
    std::sort(q.begin(), q.end(), cmp2);
    for(size_t i = 0; i < q.size(); ++i){
        std::cout << q[i].rez << '\n';
    }
    return 0;
}

ВЕРЕВОЧКИ

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	uint64_t n = 0, k = 0;
	cin >> n >> k;
	vector<int64_t> len(n);
	int64_t l = 0, r = 0;
	for (size_t i = 0; i < len.size(); i++) {
		cin >> len[i];
		r = max(r, len[i] + 1);
	}
	while (r - l > 1)
	{
		uint64_t m = (l + r) / 2;
		uint64_t cnt = 0;
		for (uint64_t i = 0; i < len.size(); i++) {
			cnt += (len[i] / m);
		}
		if (cnt < k)
		{
			r = m;
		}
		else {
			l = m;
		}
	}
	cout << l;
}
--------------------------------------------------------------------------------
s = input()
s = [int(i) for i in s.split()]#********
mn = 99999
mx = 0
for i in range(len(s)):
    if int(s[i]) > mx:
        mx = s[i]
    if int(s[i]) < mn:
        mn = s[i]
position = s.index(mx)
position1 = s.index(mn)
s.pop(position)
s.insert(position, mn)
s.pop(position1)
s.insert(position1, mx)
print(*s)#распакоука
