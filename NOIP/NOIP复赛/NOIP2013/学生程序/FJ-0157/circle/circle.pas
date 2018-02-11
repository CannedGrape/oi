program circle;
 var n,m,x,k:integer;
     time,i,j:longint;
     a:array[0..1000000]of integer;


begin

 assign(input,'circle.in');
 assign(output,'circle.out');
 reset(input);
 reset(output);

 readln(n,m,k,x);
 for i:=0 to n-1 do
  begin
     a[i]:=i;

  end;

 time:=1;
 for i:=1 to k do
  time:=time *10;

 for i:=1 to time do
  begin
   for j:=0 to n-1 do
    begin
       a[i]:=a[i]+m;
       if a[i]>(n-1) then a[i]:=a[i]-n;
    end;
  end;

 for i:=0 to n-1 do
     if a[i]=x then write(i);

 readln;

 close(input);
 close(output);

end.
