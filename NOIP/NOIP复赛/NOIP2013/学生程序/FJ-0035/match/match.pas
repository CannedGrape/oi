const mo:int64=99999997;
var n,i,j:longint;
    ans,now:int64;
    x,y,num:array[0..210000]of longint;
    mark:array[0..210000]of boolean;
procedure qs(l,r:longint);
var tl,tr,mid,tmp:longint;
begin
  tl:=l;  tr:=r;  mid:=x[(l+r) shr 1];
  repeat
    while x[tl]<mid do inc(tl);
    while x[tr]>mid do dec(tr);
    if tl<=tr then
      begin
        tmp:=y[tl];  y[tl]:=y[tr];  y[tr]:=tmp;
        tmp:=x[tl];  x[tl]:=x[tr];  x[tr]:=tmp;
        inc(tl);  dec(tr);
      end;
  until tl>tr;
  if tl<r then qs(tl,r);
  if l<tr then qs(l,tr);
end;
procedure qsort(l,r:longint);
var tl,tr,mid,tmp:longint;
begin
  tl:=l;  tr:=r;  mid:=y[(l+r) shr 1];
  repeat
    while y[tl]<mid do inc(tl);
    while y[tr]>mid do dec(tr);
    if tl<=tr then
      begin
        tmp:=y[tl];  y[tl]:=y[tr];  y[tr]:=tmp;
        tmp:=num[tl];  num[tl]:=num[tr];  num[tr]:=tmp;
        inc(tl);  dec(tr);
      end;
  until tl>tr;
  if tl<r then qsort(tl,r);
  if l<tr then qsort(l,tr);
end;
begin
assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(x[i]);
  for i:=1 to n do read(y[i]);
  for i:=1 to n do num[i]:=i;
  qs(1,n);
  qsort(1,n);
  fillchar(mark,sizeof(mark),0);
  ans:=0;
  for i:=1 to n do
    if not mark[i] then
      begin
        j:=num[i];
        mark[i]:=true;
        now:=1;
        while (j<>0)and(mark[j]=false) do
          begin
            inc(now);
            mark[j]:=true;
            j:=num[j];
          end;
        ans:=(ans+now-1) mod mo;
      end;
  writeln(ans);
close(input);close(output);
end.
