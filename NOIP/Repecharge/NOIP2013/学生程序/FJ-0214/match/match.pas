type
  arr=array[1..100000,1..2]of longint;
var
  a,b,c,d:array[1..100000,1..2]of longint;
  n,i,ans,j,p,lastj:longint;

procedure qsort(var f:arr; l,r:longint);
var
  i,j,p,mid:longint;
begin
  i:=l; j:=r;
  mid:=f[(l+r) div 2,1];
  repeat
    while f[i,1]<mid do inc(i);
    while f[j,1]>mid do dec(j);
    if i<=j then
     begin
       p:=f[i,1]; f[i,1]:=f[j,1]; f[j,1]:=p;
       p:=f[i,2]; f[i,2]:=f[j,2]; f[j,2]:=p;
       inc(i); dec(j);
     end;
  until i>j;
  if l<j then qsort(f,l,j);
  if i<r then qsort(f,i,r);
end;
begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do begin read(a[i,1]); a[i,2]:=i; end;
  for i:=1 to n do begin read(b[i,1]); b[i,2]:=i; end;
  c:=a; d:=b;
  qsort(c,1,n);
  qsort(d,1,n);

  for i:=1 to n do begin a[c[i,2],2]:=d[i,1]; b[d[i,2],2]:=c[i,1]; end;
  for i:=1 to n do
   begin
     if a[i,1]<>b[i,2] then
      begin
        inc(ans); ans:=ans mod 99999997;
        for j:=1 to n do if a[i,2]=b[j,1] then
         begin
           lastj:=j;
            if a[i,2]=b[j,1] then break;
         end;
        p:=a[i,1]; a[i,1]:=a[lastj,1]; a[lastj,1]:=p;
        p:=a[i,2]; a[i,2]:=a[lastj,2]; a[lastj,2]:=p;
      end;
   end;
   writeln(ans);
   close(input); close(output);
end.
