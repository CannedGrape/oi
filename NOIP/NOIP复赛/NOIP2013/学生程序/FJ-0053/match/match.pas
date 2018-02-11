type arr=array[0..100000]of longint;
var a,b,c:array[0..100000]of longint;
f:array[0..100000]of boolean;
i,j,k,m,n,tot,l:longint;
p:int64;
procedure kp(var b:arr;l,r:longint);
var i,j,m,t:longint;
begin 
 i:=l;j:=r; 
 m:=b[(l+r)div 2];
 repeat 
	while b[i]<m do inc(i);
	while b[j]>m do dec(j);
		if i<=j then begin  
			 t:=b[i];b[i]:=b[j];b[j]:=t;
		    inc(i);dec(j);
	    end;
 until i>j;
 if i<r then kp(b,i,r);
 if l<j then kp(b,l,j);
end;procedure kp1(var b:arr;l,r:longint);
var i,j,m,t:longint;
begin 
 i:=l;j:=r; 
 m:=b[(l+r)div 2];
 repeat 
	while b[i]<m do inc(i);
	while b[j]>m do dec(j);
		if i<=j then begin  
			 t:=b[i];b[i]:=b[j];b[j]:=t;
			 t:=c[i];c[i]:=c[j];c[j]:=t;		    
		    inc(i);dec(j);
	    end;
 until i>j;
 if i<r then kp1(b,i,r);
 if l<j then kp1(b,l,j);
end;
begin 
 assign(input,'match.in');reset(input);
 assign(output,'match.out');rewrite(output);
 readln(n);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do read(b[i]);
 c:=b;
 kp1(a,1,n);
 kp(b,1,n);
 for i:=1 to n do
	 if b[i]<>c[i] then inc(p);
 writeln(round((p+0.0000001)/2)mod 99999997);
 close(input);close(output);
end. 	