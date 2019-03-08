program circle;

const
maxn=1000000;

var
  c,n,m,x,i,round,round1:longint;
  k,j:longint;

procedure getting;
begin
  assign(input,'circle.in');
  reset(input);
  readln(n,m,k,x);
end;

procedure zuidagongyueshu;
var
a,b:longint;
begin
a:=m;
b:=n;
  repeat
    if a>b then a:=a mod b else b:=b mod a;
  until (a=0) or (b=0);
  if a=0 then c:=b else c:=a;
  b:=n div c;
  round1:=b;
end;

procedure calround;
begin
    begin
      round:=1;
      if k>10000000 then
        k:=k mod round1;
      for j:=1 to k do
      begin
        round:=(round*10) mod round1;
      end;
    exit;
    end;
end;

procedure work;
begin
  for i:=1 to round do
  begin
    x:=x+m;
    if x>n then x:=x-n;
  end;
end;

procedure gotting;
begin
assign(output,'circle.out');
rewrite(output);
writeln(x);
end;

begin
getting;
zuidagongyueshu;
calround;
work;
gotting;

end.
