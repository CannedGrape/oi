program circle;
var
 n,m,k,x,g:longint;

procedure fin;
begin
 assign(input,'circle.in'); reset(input);
 assign(output,'circle.out'); rewrite(output);
end;

procedure fout;
begin
 close(input);
 close(output);
end;

function gcd(a,b:longint):longint;
var
 r:longint;
begin
 repeat
  r:=a mod b;
  a:=b;
  b:=r;
 until r=0;
 exit(a);
end;

function power(k:longint):longint;
var
 i:longint;
begin
 power:=1;
 for i:=1 to k mod g do power:=power*10 mod g;
 if power=1 then power:=0;
 exit(power);
end;

begin
 fin;
 readln(n,m,k,x);
 g:=n div gcd(n,m);
 k:=power(k);
 writeln((x+m*k) mod n);
 fout;
end.
