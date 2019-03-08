var
	n,max,tot,ans,num:int64;
	i,j:longint;
	flg:boolean;
	h,d,f,tm:array[0..100010] of int64;

procedure freopen;
begin
	assign(input,'block.in');reset(input);
	assign(output,'block.out');rewrite(output);
end;

procedure freclose;
begin
	close(input);close(output);
end;

procedure qsort(l,r: longint);
var
	i,j,x,y: longint;
begin
	i:=l;j:=r;x:=tm[(l+r) div 2];
	repeat
		while tm[i]<x do inc(i);
		while x<tm[j] do dec(j);
		if not(i>j) then
			begin
				y:=tm[i];tm[i]:=tm[j];tm[j]:=y;
                inc(i);dec(j);
			end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;              

begin
	freopen;
	readln(n);
	for i:=1 to n do
		read(h[i]);
	for i:= 2 to n do
		d[i]:=h[i]-h[i-1];
	max:=h[1];num:=0;tot:=1;f[tot]:=1;ans:=0;flg:=false;
	for i:=2 to n+1 do
		begin
			if d[i]>=0 then
				begin
					if h[i]>max then max:=h[i];
					flg:=true;
				end;
			if d[i]<0 then
				begin
					inc(num);
					flg:=false;
				end
			else
				if (flg) and (num>0) and (d[i]>0) then
					begin
						inc(ans,max);
						inc(tot);
						f[tot]:=i-1;
						num:=0;
						max:=h[i];
					end;
			if i=n+1 then inc(ans,max);
		end;
	for i:=2 to tot do tm[i]:=h[f[i]];
	qsort(2,tot);
	for i:=2 to tot do
		begin
			ans:=ans-tm[i];
			for j:=i+1 to tot do
				dec(tm[j],tm[i]);
		end;
	writeln(ans);
	freclose;
end.
