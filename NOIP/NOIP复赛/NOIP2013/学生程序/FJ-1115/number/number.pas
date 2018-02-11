program number;
var n,p,s:longint;
    a,tz,fs:array[1..1000000]of longint;
    i,j,k:longint;
begin
    assign(input,'number.in');
    reset(input);
    assign(output,'number.out');
    rewrite(output);
    n:=0;p:=0;
    readln(n,p);
    fillchar(a,sizeof(a),0);
    fillchar(tz,sizeof(tz),0);
    fillchar(fs,sizeof(fs),0);
    s:=0;i:=0;j:=0;k:=0;
    for i:=1 to n do read(a[i]);
    tz[1]:=a[1];
    fs[1]:=a[1];
    for i:=2 to n do
     for j:=1 to i do
      if(a[j]>=0) then tz[i]:=tz[i]+a[j];




    fs[2]:=tz[1]+fs[1];
    s:=tz[1]+fs[1];

    for i:=3 to n do
     for j:=1 to i-1 do

      if (tz[j]+fs[j]>s) then
      begin
        fs[i]:=tz[j]+fs[j];
        s:=tz[j]+fs[j];
      end;



    s:=fs[1];
    for i:=1 to n do
     if fs[i]>s then s:=fs[i];
    if s>0 then writeln(s mod p);
    if s=0 then writeln('0');
    if s<0 then writeln('-',abs(s) mod p);
    close(input);
    close(output);
end.

