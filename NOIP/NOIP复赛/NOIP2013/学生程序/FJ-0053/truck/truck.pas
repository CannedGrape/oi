var f:array[0..5000,0..5000]of longint;
i,j,k,m,n,x,y,z:longint;
function max(a,b:longint):longint;
begin 
 if a>b then exit(a);
 exit(b);
end;
function min(a,b:longint):longint;
begin 
 if a>b then exit(b);
 exit(a);
end;
begin 
 assign(input,'truck.in');reset(input);
 assign(output,'truck.out');rewrite(output);
 readln(n,m);
 for i:=1 to n do 
	  for j:=1 to n do f[i,j]:=-1;
 for i:=1 to m do 
	begin 
	  readln(x,y,z);
	  f[x,y]:=z;
    end;
  for i:=1 to n do 
	   for j:=1 to n do 
		    for k:=1 to n do 
				 if (i<>j)and(j<>k)and(i<>k) then 
					  f[j,k]:=max(f[j,k],min(f[j,i],f[i,k]));
 readln(n);
 for i:=1 to n do
	begin 
      readln(x,y);
      writeln(f[x,y]);
    end;
 close(input);close(output);
end.