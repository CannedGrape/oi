var n,i,j,t:longint;
    a:array[1..100000,1..2]of longint;
    b:array[1..100000,1..2]of longint;
    ak,s:array[1..100000]of longint;
    ans:int64;
procedure qsorta(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2,1];
         repeat
           while a[i,1]<x do
            inc(i);
           while x<a[j,1] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i,1]; a[i,1]:=a[j,1]; a[j,1]:=y;
                y:=a[i,2]; a[i,2]:=a[j,2]; a[j,2]:=y;
                inc(i); dec(j);
             end;
         until i>j;
         if l<j then
           qsorta(l,j);
         if i<r then
           qsorta(i,r);
      end;


procedure qsortb(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2,1];
         repeat
           while b[i,1]<x do
            inc(i);
           while x<b[j,1] do
            dec(j);
           if not(i>j) then
             begin
                y:=b[i,1]; b[i,1]:=b[j,1]; b[j,1]:=y;
                y:=b[i,2]; b[i,2]:=b[j,2]; b[j,2]:=y;
                inc(i); dec(j);
             end;
         until i>j;
         if l<j then
           qsortb(l,j);
         if i<r then
           qsortb(i,r);
      end;


begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      read(a[i,1]);
      a[i,2]:=i;
      ak[i]:=a[i,1];
    end;
  readln;
  for i:=1 to n do
    begin
      read(b[i,1]);
      b[i,2]:=i;
    end;
   qsorta(1,n);
   qsortb(1,n);
  for i:=1 to n do s[i]:=ak[b[i,2]];
  for i:=1 to n do
     if ak[i]<>s[i] then
      begin
       for j:=i+1 to n do
        if ak[j]=s[i] then
         begin
           t:=ak[i]; ak[i]:=ak[j]; ak[j]:=t;
           inc(ans);
           break;
         end;
     end;
   writeln(ans mod 99999997);
   close(input); close(output);
end.
