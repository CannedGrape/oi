program fbi(input,output);
const maxn=1024;
var t,n,i:integer;
    a:array[1..maxn]of '0'..'1';

function getfbi(h,t:integer):char;
var i:integer;
    flag:boolean;
begin
    flag:=true;
    i:=h+1;
    while flag and (i<=t) do begin
       if a[i]<>a[i-1] then flag:=false;
       i:=i+1;
    end;
    if flag then
        if a[h]='1' then getfbi:='I'
            else getfbi:='B'
    else getfbi:='F';
end;

procedure try(h,t:integer);
var mid:integer;
begin
    if h=t then
       if a[h]='1' then write('I')
          else write('B')
    else
       if h<t then begin
          mid:=(h+t) div 2;
          try(h,mid);
          try(mid+1,t);
          write(getfbi(h,t));
       end;
end;

begin
    assign(input,'fbi.in');
    reset(input);
    readln(n);
    t:=1;
    for i:=1 to n do t:=t*2;
    for i:=1 to t do read(a[i]);
    close(input);
    assign(output,'fbi.out');
    rewrite(output);
    try(1,t);
    writeln;
    close(output);
end.
