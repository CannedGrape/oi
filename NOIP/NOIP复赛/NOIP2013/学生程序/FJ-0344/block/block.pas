program block;
var
n,i,j,t,k,ans,x,y:longint;
h:array [1..100000] of longint;
a:array [0..99999] of longint;

procedure solve(x,y:longint);
begin
 fillchar(a,sizeof(a),0);
 a[0]:=1;
 while (h[x]=0) and (x<y) do x:=x+1;
if (h[x]<>0) and (h[y]<>0) then
begin
 t:=h[x];
 ans:=ans+1;
 for i:=x to y do
	 if (t>h[i]) and (h[i]<>0) then t:=h[i];
 for i:=x to y do
	 if h[i]=t then
		begin
		   for j:=1 to y do
			   begin
			   if a[j]=0 then
				   begin
			         a[j]:=i;
					 break;
					end;
			   end;
		end;
  for i:=x to y do
	  h[i]:=h[i]-t;
  while a[k]<>0 do
	 begin
      x:=a[k-1]; y:=a[k]+1;
	  solve(x,y);
      k:=k+1;
      if (a[k+1]=0) and (a[k]<=n) then solve(a[k]+1,n);
     end;
end;
end;

begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
 readln(n);
 fillchar(a,sizeof(a),0);
 a[0]:=1;
 for i:=1 to n do
	 read(h[i]);
 k:=1;  ans:=0;
 t:=h[1];

 ans:=ans+1;
 for i:=2 to n do
	 if (t>h[i]) and (h[i]<>0) then t:=h[i];
 for i:=1 to n do
	 if h[i]=t then
		begin
		   for j:=1 to n do
			   if a[j]=0 then
				   begin
			         a[j]:=i;
					 break;
					end;
		end;
  for i:=1 to n do
	  h[i]:=h[i]-t;
	x:=a[k-1];y:=a[k]-1;
  while a[k]<>0 do
	 begin
	  solve(x,y);
      k:=k+1;
      if (a[k+1]=0) and (a[k]<=n) then solve(a[k]+1,n);
     end;
 writeln(ans);
close(input);
close(output);
end.
