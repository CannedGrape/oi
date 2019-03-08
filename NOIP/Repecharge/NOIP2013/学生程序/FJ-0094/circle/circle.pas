program circle;
var
 a,m,n,x,i,p,k,s:longint;
 b:array[0..1000000]of integer;
begin
 assign(input,'circle.in');
 assign(output,'circle.out');
 reset(input);
 rewrite(output);
 readln(n,m,k,x);
 p:=x+m;
 for i:=1 to k do b[i+1]:=9;
 b[1]:=0;
 b[0]:=0;
 s:=2;
 while s<=k+1 do
  begin
   p:=p+m;
   p:=p mod n;
   b[k+1]:=b[k+1]-1;
   if b[k+1]=0 then
    begin
     b[k+1]:=b[k+1]+10;
     b[k]:=b[k]-1;
     for i:=k+1 downto s do
      if (b[i]=0) then
       begin
        b[i]:=b[i]+10;
        b[i-1]:=b[i-1]-1;
       end;
    end;
   if b[s-1]=0 then s:=s+1;
  end;
 writeln(p);
 close(input);
 close(output);
end.
