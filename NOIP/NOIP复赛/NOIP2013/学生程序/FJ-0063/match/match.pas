type
	v=longint;
var
	n,i,j:v;
	ans:int64;
	wza,wzb,a,b:array[0..100001]of v;
procedure qsa(l,r:v);
var ii,jj,mid,t:v;
begin
	ii:=l;
	jj:=r;
	mid:=a[(ii+jj)shr 1];
	repeat
		while a[ii]<mid do
			inc(ii);
		while a[jj]>mid do
			dec(jj);
		if ii<=jj then
			begin
				t:=a[ii];
				a[ii]:=a[jj];
				a[jj]:=t;
				t:=wza[ii];
				wza[ii]:=wza[jj];
				wza[jj]:=t;
				inc(ii);
				dec(jj);
			end;
	until ii>jj;
	if ii<r then qsa(ii,r);
	if l<jj then qsa(l,jj);
end;
procedure qsb(l,r:v);
var ii,jj,mid,t:v;
begin
	ii:=l;
	jj:=r;
	mid:=b[(ii+jj)shr 1];
	repeat
		while b[ii]<mid do
			inc(ii);
		while b[jj]>mid do
			dec(jj);
		if ii<=jj then
			begin
				t:=b[ii];
				b[ii]:=b[jj];
				b[jj]:=t;
				t:=wzb[ii];
				wzb[ii]:=wzb[jj];
				wzb[jj]:=t;
				inc(ii);
				dec(jj);
			end;
	until ii>jj;
	if ii<r then qsb(ii,r);
	if l<jj then qsb(l,jj);
end;
begin
	assign(input,'match.in');
	assign(output,'match.out');
	reset(input);
	rewrite(output);
	read(n);
	for i:=1 to n do
		begin
			read(a[i]);
			wza[i]:=i;
		end;
	for i:=1 to n do
		begin
			read(b[i]);
			wzb[i]:=i;
		end;
	qsa(1,n);
	//for i:=1 to n do
		//write(wza[i],' ');
	qsb(1,n);
	//writeln;
	//for i:=1 to n do
		//write(wzb[i],' ');
	//writeln;
	ans:=0;
	for i:=1 to n-1 do
		for j:=i+1 to n do
			if((wza[i]>wza[j])and(wzb[i]<wzb[j]))or((wza[i]<wza[j])and(wzb[i]>wzb[j]))then inc(ans);
	write(ans mod 99999997);
	close(input);
	close(output);
end.