program puzzle;
var 
n,m,q,i,j,x,EX,EY,SX,SY,TX,TY:integer;
a:array [1..30,1..30] of integer;
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);
readln(n,m,q);
for i:=1 to n do
	begin
	 for j:=1 to m do
       read(a[i,j]);
	 readln;
	 end;
for i:=1 to q do
	begin
     x:=2;
	 readln(EX,EY,SX,SY,TX,TY);
     if (SX<>m) and (SY<>n) then 
		 begin
	       if (a[SX,SY-1]=0) and (a[SX-1,SY]=0) and (a[SX+1,SY]=0) then x:=-1;
           if (a[SX,SY-1]=0)  and (a[SX-1,SY]=0) and (a[SX,SY+1]=0) then x:=-1;
	       if (a[SX-1,SY]=0) and (a[SX+1,SY]=0) and (a[SX,SY+1]=0) then x:=-1;
	       if (a[SX,SY+1]=0) and (a[SX,SY-1]=0) and (a[SX+1,SY]=0) then x:=-1;
		 end;
	 if (SX=m) or (SY=n) or (SX=n) or (SY=m)then
		if  (a[SX,SY-1]=0)  or (a[SX-1,SY]=0) or (a[SX+1,SY]=0) or (a[SX,SY+1]=0) then x:=-1;
	 writeln(x);
	 end;
close(input);
close(output);
end.