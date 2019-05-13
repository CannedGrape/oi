#ifndef __GEOMETRY
#define __GEOMETRY

#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

double _GEOMETRIC_ZERO=1e-8;

class tpoint {
	
	private:
		double x,y;
		
	public:
		
		void assign(double x, double y) {
			this->x=x;
			this->y=y;
			return;
		}
		
		tpoint() {
			assign(0,0);
		}
		
		tpoint(double x, double y) {
			assign(x,y);
		}
		
		double cor_x() const {
			return x;
		}
		
		double cor_y() const {
			return y;
		}
		
		
		double dotmetrix(const tpoint &p1, const tpoint &p2) const {
			return (p1.x-x)*(p2.x-x)+(p1.y-y)*(p2.y-y);
		}
		
		double crossmetrix(const tpoint &p1, const tpoint &p2) const {
			return (p1.x-x)*(p2.y-y)-(p2.x-x)*(p1.y-y);
		}
		
		double dis(const tpoint &a) const {
			return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
		}
		
		double abs() {
			return sqrt(x*x+y*y);
		}
		
		tpoint unitage() {
			double d=this->abs();
			tpoint ans(x/d,y/d);
			return ans;
		}
		
};

const tpoint _O(0,0);
 
inline tpoint operator + (const tpoint &p1, const tpoint &p2) {
	tpoint ans;
	ans.assign(p1.cor_x()+p2.cor_x(),p1.cor_y()+p2.cor_y());
	return ans;
}

inline tpoint operator - (const tpoint &p1, const tpoint &p2) {
	tpoint ans;
	ans.assign(p1.cor_x()-p2.cor_x(),p1.cor_y()-p2.cor_y());
	return ans;
}

inline double operator * (const tpoint &p1, const tpoint &p2) {
	return p1.cor_x()*p2.cor_x()+p1.cor_y()*p2.cor_y();
}

inline tpoint operator * (const tpoint &p1, double x) {
	tpoint ans;
	ans.assign(p1.cor_x()*x,p1.cor_y()*x);
	return ans;
}

inline tpoint operator * (double x, const tpoint &p1) {
  tpoint ans;
  ans.assign(p1.cor_x()*x,p1.cor_y()*x);
  return ans;
}

inline tpoint operator / (const tpoint &p1, double x) {
	tpoint ans;
	ans.assign(p1.cor_x()/x, p1.cor_y()/x);
	return ans;
}

class tline {
	
	private:
		tpoint ea, eb;
		inline void getabc(const tpoint &p1, const tpoint &p2, double &a, double &b, double &c) const {
			a=(p2.cor_y()-p1.cor_y());
			b=(p1.cor_x()-p2.cor_x());
			c=(p1.cor_x()*p2.cor_y()-p1.cor_y()*p2.cor_x());
			return;
		}
		
	public:	
		tline() {
			ea.assign(0,0);
			eb.assign(0,1);
		}
		
		void assign(const tpoint &p1, const tpoint &p2) {
			ea=p1;
			eb=p2;
			return;
		}
		
		tline(const tpoint &p1, const tpoint &p2) {
		  assign(p1,p2);
		}
		
		tpoint enda() const {
			return ea;
		}
		
		tpoint endb() const {
			return eb;
		}
		
		bool parallel(const tline &a, double zero=_GEOMETRIC_ZERO) const {
			tpoint p1=enda()-endb(), p2=a.enda()-a.endb();
			if (fabs(_O.crossmetrix(p1,p2))<zero) return true; else return false;
		}
		
		bool operator || (const tline &a) const {
			return parallel(a);
		}
		
		double length() const {
			return ea.dis(eb);
		}
		
		int intersectpoint(const tline &a, tpoint &x, double zero=_GEOMETRIC_ZERO) const {
			if (parallel(a,zero)) return -1;
			tpoint p1=ea, p2=eb, p3=a.enda(), p4=a.endb();
			double a1,b1,c1,a2,b2,c2;
			getabc(p1,p2,a1,b1,c1);
			getabc(p3,p4,a2,b2,c2);
			x.assign((c1*b2-c2*b1)/(a1*b2-a2*b1),(a1*c2-a2*c1)/(a1*b2-a2*b1));
			return 0;
		}
		
		bool inside(const tpoint &p, double zero1=_GEOMETRIC_ZERO, double zero2=_GEOMETRIC_ZERO) const {
			if ((fabs(p.crossmetrix(ea,eb))<zero1)&&(p.dotmetrix(ea,eb)<zero2)) return true; else return false;
		}
		
		double pointdis(const tpoint &p) const {
			return fabs(p.crossmetrix(ea,eb))/length();
		}
		
		tpoint mirror(const tpoint &p) const {
			tpoint temp=eb-ea;
			tpoint v(temp.cor_y(),-temp.cor_x());
		  if (p.crossmetrix(ea,eb)<0) v=_O-v;
			v=v.unitage();
			tpoint ans=p;
			double d=2*pointdis(p);
			ans=ans+d*v;
			return ans;
		}
	
};

#endif
