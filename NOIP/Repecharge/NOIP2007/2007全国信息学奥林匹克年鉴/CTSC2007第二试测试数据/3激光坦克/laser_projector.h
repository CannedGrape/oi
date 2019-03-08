#ifndef __LASER_PROJECTOR
#define __LASER_PROJECTOR

#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include "geometry.h"

using namespace std;

class tlaser_projector {
	private:
		const double zero;
		const double check_zero;
		const double maxnum;
		int k,limitk;
		tpoint posi,dire;
		vector<tline> list,history;
		
	public:
		void clear() {
			list.clear();
			history.clear();
			k=0;
			return;
		}
		
		tlaser_projector(double c1=1e-8, double c2=1e-3, double c3=1e100): zero(c1), check_zero(c2), maxnum(c3) {
			posi.assign(0,0);
			dire.assign(0,1);
			clear();
			k=0;
			limitk=0;
		}
		
		vector<tline> extracthistory() const {
			return history;
		}
		
		void reput(const tpoint &p) {
			posi=p;
			return;
		}
		
		void redirect(const tpoint &p) {
			dire=p;
			return;
		}
		
		void resetk() {
			k=0;
			return;
		}
		
		void resetlimit(const int lk) {
			limitk=lk;
			return;
		}
		
		void insertline(const tline &l) {
			list.push_back(l);
			return;
		}
		
		void clearhistory() {
			history.clear();
			return;
		}
		
		int currentk() const {
			return k;
		}
		
		void initialize(const tpoint &p1, const tpoint &p2) {
			reput(p1);
			redirect(p2);
			resetk();
			clearhistory();
			return;
		}
		
		void goforward(const double d);
		
		bool check(const tpoint &p) const {
			for (int i=0; i<history.size(); i++) {
				double d=history[i].length();
				if (history[i].inside(p,check_zero*d,check_zero*d)) return true;
			}
			return false;
		}
				
		tpoint position() const {
			return posi;
		}

		tpoint direction() const {
			return dire;
		}
		
};

void tlaser_projector::goforward(double b) {
	while ((fabs(b)>zero)&&(k<=limitk)) {
		int c=-1;
		double mindis=maxnum;
		tpoint x;
		tline temp(posi,dire);
		for (int i=0; i<list.size(); i++) {
			tpoint x1;
			if (temp.intersectpoint(list[i],x1)!=-1) 
				if ((x1.dotmetrix(list[i].enda(),list[i].endb())<-zero)&&(posi.dotmetrix(dire,x1)>zero))
					if (posi.dis(x1)<mindis) {
						c=i;
						mindis=posi.dis(x1);
						x=x1;
					}
		}
		if ((mindis>b)||(c==-1)) {
			tpoint v=dire-posi;
			v=v.unitage();
			tpoint temp=posi+(v*b);
			history.push_back(tline(posi,temp));
			posi=temp;
			b=0;
		}
		else {
			history.push_back(tline(posi,x));
			b=b-mindis;
			tpoint temp=list[c].mirror(posi);
			temp=x-temp;
			dire=x+temp;
			posi=x;
			k++;
		}
	}
	return;
}

#endif
