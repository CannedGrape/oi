program match;
var n,i,step,min,j,k:longint;
    a,a1,b,b1,lq:array[-1..1000000] of longint;
    m,m1:array[-1..1000000] of boolean;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;

                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
procedure sort1(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a1[(l+r) div 2];
         repeat
           while a1[i]<x do
            inc(i);
           while x<a1[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a1[i];
                a1[i]:=a1[j];
                a1[j]:=y;

                y:=b1[i];
                b1[i]:=b1[j];
                b1[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort1(l,j);
         if i<r then
           sort1(i,r);
      end;
function pd:boolean;
var i:longint;
begin
    for i:=1 to n do
     if b[i]<>b1[i] then exit(false);
    exit(true);
end;
function x(l,n:longint):boolean;
var i,j:longint;
begin
     for i:=l to l+n do
     begin
      for j:=l to l+n do
       if b[i]=b1[j] then break;
      if b[i]<>b1[j] then exit(false);
     end;
     exit(true);
end;

begin
     assign(input,'match.in');reset(input);
     assign(output,'match.out');rewrite(output);
     fillchar(m,sizeof(m),false);
     min:=0;
     readln(n);
     for i:=1 to n do
      read(a[i]);
     for i:=1 to n do
      read(a1[i]);
     for i:=1 to n do
     begin
      b[i]:=i;b1[i]:=i;
     end;
     sort(1,n);
     sort1(1,n);
     step:=0;
     for j:=0 to n-1 do
      for i:=1 to n-j do
      begin
       for k:=i to i+k do
        if m1[k] then break;
       if not(m1[k]) then
        if x(i,j) then begin inc(lq[j]);
         for k:=i to i+j do
          m1[k]:=true;
        end;
      end;

     for i:=1 to n-1 do
     begin
      min:=(min+lq[i]*(i)) mod 99999997;end;
     writeln(min);
     close(input);close(output);
end.
