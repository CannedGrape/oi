program match;
type sz=array[0.. 100001]of longint;
var a,b,aa,bb:sz;
    i,j,t,n,l,r:longint;
    m,z,y,x:int64;
    procedure qs(l,r:longint;var s:sz);
    var tl,tr,mid,tt:longint;
    begin
      tl:=l;tr:=r;mid:=s[(l+r)shr 1];
      repeat
        while s[tl]<mid do inc(tl);
        while s[tr]>mid do dec(tr);
        if tl<=tr then
        begin
          tt:=s[tl];s[tl]:=s[tr];s[tr]:=tt;
          inc(tl);
          dec(tr);
        end;
      until tl>tr;
      if tl<r then qs(tl,r,s);
      if tr>l then qs(l,tr,s);
    end;
begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    aa[i]:=a[i];
  end;
  for i:=1 to n do
  begin
    read(b[i]);
    bb[i]:=b[i];
  end;
  qs(1,n,aa);
  qs(1,n,bb);
  m:=0;
  for i:=1 to n do if aa[i]<>a[i] then inc(m);
  x:=0;
  for i:=1 to n do if bb[i]<>b[i] then inc(x);
  writeln(abs(m-x)mod 99999997);
  close(input);
  close(output);
end.
