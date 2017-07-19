#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Box {
	int l, w, h;
};
int box[21];

queue<Box> qu;
int main()
{
	int l, w, h,n;
	int ans = 0;
	cin >> l >> w >> h>>n;
	qu.push({ l,w,h });
	for (int i = 0; i < n; i++) {
		int k,num;
		cin >> k>>num;
		box[k] += num;
	}
	while (!qu.empty()) {
		Box now = qu.front();
		int min_ = min(now.l, min(now.w, now.h));
		int idx = 0;
		while (min_ != 1) {
			min_ = min_ >> 1;
			idx++;
		}
		while (box[idx] == 0) {
			idx--;
			if (idx < 0) {
				cout << -1 << endl;
				return 0;
			}
		}
		int box_size = pow(2, idx);
		int t_l, t_w, t_h;
		int t_l_size, t_w_size, t_h_size;
		if (now.l / box_size <= box[idx]) {
			t_l = now.l - (now.l / box_size)*box_size;
			t_l_size = now.l / box_size;
		}
		else {
			t_l = now.l - box_size*box[idx];
			t_l_size = box[idx];
		}
		if (now.w / box_size <= box[idx]) {
			t_w = now.w - (now.w / box_size)*box_size;
			t_w_size = now.w / box_size;
		}
		else {
			t_w = now.w - box_size*box[idx];
			t_w_size = box[idx];
		}
		if (now.h / box_size <= box[idx]) {
			t_h = now.h - (now.h / box_size)*box_size;
			t_h_size = now.h / box_size;
		}
		else {
			t_h = now.h - box_size*box[idx];
			t_h_size = box[idx];
		}
		ans += t_l_size * t_w_size*t_h_size;
		box[idx] -= max(t_l_size, max(t_h_size, t_w_size));
		qu.pop();
		if (t_l != 0 && now.w - t_w != 0 && now.h - t_h != 0) {
			qu.push({ t_l,now.w - t_w,now.h - t_h });
		}
		if (now.l - t_l != 0 && t_w != 0 && now.h - t_h != 0) {
			qu.push({ now.l - t_l,t_w,now.h - t_h });
		}
		if (t_l != 0 && t_w != 0 && now.h - t_h != 0) {
			qu.push({ t_l,t_w,now.h - t_h });
		}
		if (t_h != 0) {
			qu.push({ now.l,now.w,t_h });
		}
		
	}
	cout << ans << endl;
}