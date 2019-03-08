type
  arr=array[-10..1000020]of int64;
const
  ml=-maxlongint;
var
  i,j,n,p:longint;
  m:int64;
  a,b,c:arr;
procedure re;
  begin
  assign(input,'number.in');
  reset(input);
    readln(n,p);
    for i:=1 to n do
      read(a[i]);
    readln;
  close(input);
  end;
function m2(mi,mj:int64):int64;
  begin
    if mi>mj then m2:=mi
    else m2:=mj;
  end;
procedure tz;
  begin
    b[0]:=ml;
    c[0]:=ml;
    for i:=1 to n do
      begin
        b[i]:=ml;
        c[i]:=ml;
        for j:=1 to i do
          begin
            c[j]:=m2(c[j-1]+a[j],a[j]);
            b[j]:=m2(b[j-1],c[j]);
          end;
      end;
  end;
procedure fs;
  begin
    c[1]:=b[1];
    m:=c[1];
    for i:=2 to n do
      begin
        c[i]:=ml;
        for j:=1 to i-1 do
          if b[j]+c[j]>c[i] then c[i]:=b[j]+c[j];
        if c[i]>m then m:=c[i];
      end;
  end;
procedure ou;
  begin
  assign(output,'number.out');
  rewrite(output);
    writeln(m mod p);
  close(output);
  end;
begin
  re;
  tz;
  fs;
  ou;
end.
