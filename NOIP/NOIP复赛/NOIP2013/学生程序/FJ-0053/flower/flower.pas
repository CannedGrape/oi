var h,a,b:array[0..100000]of longint;
f:array[0..100000]of boolean;
i,n,m:longint;
function max(a,b:longint):longint;
begin 
 if a>b then exit(a);
 exit(b);end;
procedure work(t:longint);
var i,j:longint;bo:boolean;
begin
 j:=0;bo:=true;
 for i:=1 to n do
  if f[i] then begin inc(j);a[j]:=h[i];end;
 for i:=1 to (j div 2) do
  begin
   if (a[2*i]>a[2*1-1])and(a[2*i]>a[2*i+1]) then continue
	else begin bo:=false;break;end;
  end;
 if (bo)and(j>0) then begin m:=max(m,j);exit;end;
 if not bo then for i:=1 to (j div 2) do
  begin
   if (a[2*i]<a[2*1-1])and(a[2*i]<a[2*i+1]) then continue
    else exit;
  end;
 if j>0 then begin m:=max(m,j);exit;end;
end;
procedure dfs(t,k:longint);
var i:longint;
begin
 work(t-1);
 for i:=k to n do
  if f[i] then
   begin
    f[i]:=false;
    b[t]:=i;
	dfs(t+1,i);
	f[i]:=true;
   end;
end;
begin
 assign(input,'flower.in');reset(input);
 assign(output,'flower.out');rewrite(output);
 readln(n);m:=1;
 fillchar(f,sizeof(f),true);
 for i:=1 to  n  do read(h[i]);
 dfs(1,1);
 writeln(m);close(input);close(output);
end.