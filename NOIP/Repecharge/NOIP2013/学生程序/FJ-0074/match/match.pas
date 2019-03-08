var n,i,t,j,time,x,y:longint;
    a,b,d:array[1..100000] of longint;
    //c:array[1..100000] of boolean;
//_________________________________
procedure iin;
begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
end;
procedure oout;
begin
  close(input);
  close(output);
end;
//_________________________________
begin
  iin;
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
   begin
    read(b[i]);
    if a[i]>b[i] then d[i]:=a[i]-b[i]
    else d[i]:=b[i]-a[i];
   end;
  for i:=1 to n-1 do
    begin
     j:=i+1;
     if a[i]>b[j] then x:=a[i]-b[j]
     else x:=b[j]-a[i];
     if a[j]>b[i] then y:=a[j]-b[i]
     else y:=a[j]-b[i];
     if (x+y)<(d[i]+d[j]) then
      begin
       time:=(time+1)mod 99999997;
       t:=a[i];  a[i]:=a[j];  a[j]:=t;
       d[i]:=y;  d[j]:=x;
      end;
    end;
  write(time);
  oout;

end.





