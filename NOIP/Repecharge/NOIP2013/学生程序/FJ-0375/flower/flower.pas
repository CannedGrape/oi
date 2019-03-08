 var i,j,n,t,max,s:longint;
    h:array[1..100000] of longint;
    f:array[1..100000] of longint;
procedure search(x,y:longint);
var i,j:longint;
begin
   for i:=x to y-1 do
     begin
       if f[i]<>f[i+1] then  t:=t+1 ;
       if f[i]=f[i+1] then begin if (x<n) and (t>1) then search(x+t,y) else
        if (x=n) then exit; end;
       end;
    end;
begin
    assign(input,'flower.in'); reset(input);
    assign(output,'flower.out'); rewrite(output);
    readln(n);
    for i:=1 to n do
      read(h[i]);

    fillchar(f,sizeof(f),0);
    for i:=1 to n-1 do
       for j:=i+1 to n do
        begin
         if h[i]>h[j] then f[i]:=1 else f[i]:=0;
        end;
    if h[n]>h[n-1] then f[n]:=1 else f[n]:=0;
    max:=0;
    t:=1;
    search(1,n);
   if max<t then max:=(t+2) div 2;
    write(max);
    close(input); close(output);
    end.