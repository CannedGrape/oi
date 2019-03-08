type v=int64;
var n,m,x,k,s,ans:v;
function ksm(a,b,c:v):v;
var r,ss,bb:v;
begin
	r:=1;
	ss:=a;
	bb:=b;
	while bb<>0 do
		begin
			if (bb and 1)=1 then r:=(r*ss)mod c;
			ss:=(ss*ss)mod c;
			bb:=bb shr 1;
		end;
	exit(r);
end;
begin
	assign(input,'circle.in');
	assign(output,'circle.out');
	reset(input);
	rewrite(output);
	read(n,m,k,x);
	s:=ksm(10,k,n);
	s:=(s*m)mod n;
	ans:=x;
	ans:=ans+s;
	//if ans>n-1 then ans:=ans-n;
	write(ans mod n);
	close(input);
	close(output);
end.