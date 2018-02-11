program expr;
var
  i,j,k,n,num,t:longint;
  s,s1,s2:ansistring;
  a:Array[1..100000] of ansistring;
function cl(x:ansistring):ansistring;
var
  i:longint;
begin
  if length(x)<=4 then exit(x)
  else if length(x)>4 then
    begin
      delete(x,1,length(x)-4);
      i:=1;
      while (x[i] = '0') and (i<4) do delete(x,1,1);
      exit(x);
    end;
end;
function cf(x,y:ansistring):ansistring;
var
  num,num1:longint;
begin
  val(x,num);val(y,num1);
  str(num*num1,x);
  exit(x);
end;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(s);

  j:=1;n:=1; s:=s+'+';i:=1;
  while i<=length(s) do
    begin
      if s[i] = '+' then
        begin
          a[n]:=cl(copy(s,j,i-j));
          inc(n);j:=i+1;i:=j;
          //writeln(a[n-1],'    sghgf  ',i,'   hgjfkf   ',j);
        end
      else if s[i] = '*' then
        begin
          s1:=copy(s,j,i-j);
          k:=i+1;
          while (k<=length(s)) and (s[k] in ['0'..'9']) do inc(k);
          s2:=copy(s,i+1,k-i-1);
          a[n]:=cl(cf(cl(s1),cl(s2)));
          inc(n);
          j:=k+1;i:=j;
          //writeln(a[n-1],'  cgh  ',i,'    dsgsdgfdgdfh  ',j,'    numverse   ',k);
        end
      else inc(i);
    end;
  dec(n);
  //for i:=1 to n do writeln(a[i],'a[i]');
  num:=0;
  for i:=1 to n do
    begin
      val(a[i],t);
      num:=num+t;
    end;

  str(num,s);
  writeln(cl(s));
  //writeln(cl('1234567890'));
  //writeln(cf('9999','9999'));
  //readln;
  close(input);close(output);
end.
