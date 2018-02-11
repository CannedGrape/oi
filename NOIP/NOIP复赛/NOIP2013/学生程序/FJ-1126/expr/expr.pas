var a,b,c,i,j,n,m,g,o,h,k:longint;
    x,y,z:ansistring;
    ab,ac,ad:array [0..200000] of longint;
begin
 assign(input,'expr.in');
 assign(output,'expr.out');
 reset(input);
 rewrite(output);
 readln(z);
 a:=pos('*',z);
 while a>0 do
  begin
   b:=a-1;
   while b>0 do
    begin
     if copy(z,b,1)='+' then break;
     dec(b);
    end;
   x:=copy(z,b+1,a-b-1);
   h:=b+1;
   b:=a+1;
   while b<=length(z) do
    begin
     if (copy(z,b,1)='+') or (copy(z,b,1)='*') then break;
     inc(b);
    end;
   k:=b;
   y:=copy(z,a+1,b-a-1);
   val(x,n,g);
   val(y,m,g);
   c:=(n mod 10000)*(m mod 10000) mod 10000;
   str(c,x);
   delete(z,h,k-h);
   insert(x,z,h);
   a:=pos('*',z);
  end;
 a:=pos('+',z);
 while a>0 do
  begin
   x:=copy(z,1,a-1);
   b:=a+1;
   while b<=length(z) do
    begin
     if copy(z,b,1)='+' then break;
     inc(b);
    end;
   y:=copy(z,a+1,b-a-1);
   val(x,n,g);
   val(y,m,g);
   c:=((n mod 10000)+(m mod 10000)) mod 10000;
   str(c,x);
   delete(z,1,b-1);
   insert(x,z,1);
   a:=pos('+',z);
  end;
 writeln(z);
 close(input);
 close(output);
end.


