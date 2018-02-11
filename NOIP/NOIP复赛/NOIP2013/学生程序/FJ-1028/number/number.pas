program number;
var a,s,m:array[1..1000000] of longint;
  s,m:array[1..1000000] of int64;
  n,p,maxl:longint;
procedure special(f:longint);
var k:longint;
  max,zc:int64;
begin
  if (a[f]<0) and (a[f]<s[f-1]) then s[f]:=s[f-1]
  else
  if (s[f-1]<0) and (a[f]>s[f-1]) then s[f]:=a[f]
  else begin
    zc:=0;
    max:=-100000000;
      for k:=f downto maxl+1 do
        begin
          zc:=zc+a[k];
          if zc>max then begin  max:=zc;
        end;
      if zc+s[f-1]>max then begin
        s[f]:=zc+s[f-1];
        maxl:=f;
      end
      else
      if max<s[f-1] then s[f]:=s[f-1]
      else begin
        s[f]:=max;
        maxl:=f;
      end;
    end;
  end;
end;
var i:longint;
  maxn,zh:int64;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  readln(n,p);
  for i:=1 to n do read(a[i]);
   s[1]:=a[1];
  maxl:=1;
  for i:=2 to n do special(i);
   m[1]:=a[1];
  maxm:=m[1];
  for i:=2 to n do
    begin
      zh:=m[i-1]+s[i-1];
      if zh>maxm then maxm:=zh;
      m[i]:=maxm
    end;
  rewrite(output);
  writeln(maxm mod p);
  close(input);
  close(output);
end.

