(*
第二题：
数论题，分解质因数。通过a0,a1,b0,b1确定X中每项质因子的最大幂数和最小幂数。然后再
把每个质因子的幂数范围乘起来。
PS:参考程序过10个点的总耗时为0.23秒,评测环境为2.10GHz 2.00GB
*)
const
     maxn=100;
     maxm=46341;
type
    data = record
        n,c : longint;
    end;
    ans = record
        n,min,max : longint;
    end;
    arr = array[0..maxn]of data;
var
    a0,a1,b0,b1     : longint;
    fa0,fa1,fb0,fb1 : arr;
    xmin,xmax,xn    : array[0..maxn]of longint;
    bool            : array[1..maxm]of boolean;
    next            : array[1..maxm]of longint;

procedure change(    n : longint;var a:arr);
var
    i,k,t : longint;
begin
    fillchar(a,sizeof(a),0);
    t:=0;
    i:=2;
    while n>1 do
    begin
if (i>trunc(sqrt(n)))and(t=0) then break;
        if i=-1 then break;
if n mod i=0 then
begin
     inc(t);
     n:=n div i;
end
else
begin
     if t>0 then
     begin
       inc(a[0].n);
             with a[a[0].n] do
             begin
                  n:=i;
                  c:=t;
             end;
             t:=0;
     end;
     i:=next[i];
end;
    end;
    if t>0 then
    begin
      inc(a[0].n);
      a[a[0].n].n:=i;
      a[a[0].n].c:=t;
    end;
    if n>1 then
    begin
      inc(a[0].n);
      a[a[0].n].n:=n;
      a[a[0].n].c:=1;
    end;
end; { change }
function get(var a : arr;n:longint):longint;
var
    i : longint;
begin
    for i:=1 to a[0].n do
if a[i].n=n then exit(a[i].c);
    exit(0);
end; { get }
function min_(a,b : longint):longint;
begin
    if a<b then exit(a) else exit(b);
end; { min }
function max_(a,b : longint):longint;
begin
    if a>b then exit(a) else exit(b);
end;

procedure cmin(n   ,c : longint);
var
    i : longint;
begin
    for i:=1 to xn[0] do
if xn[i]=n then
begin
        xmin[i]:=max_(xmin[i],c);
     exit;
end;
    inc(xn[0]);
    xn[xn[0]]:=n;
    xmin[xn[0]]:=c;
    xmax[xn[0]]:=maxlongint;
end; { cmin }
procedure cmax(n   ,c : longint);
var
    i : longint;
begin
    for i:=1 to xn[0] do
if xn[i]=n then
begin
        xmax[i]:=min_(xmax[i],c);
     exit;
end;
    inc(xn[0]);
    xn[xn[0]]:=n;
    xmax[xn[0]]:=c;
    xmin[xn[0]]:=0;
end; { cmin }
procedure init;
var
   i,j:longint;
begin
     fillchar(bool,sizeof(bool),true);
     for i:=2 to trunc(sqrt(maxm)) do
       if bool[i] then
       for j:=2 to maxm div i do
          bool[i*j]:=false;
     j:=-1;
     fillchar(next,sizeof(next),255);
     for i:=maxm downto 1 do
     begin
          next[i]:=j;
          if bool[i] then j:=i;
     end;

end;
procedure main;
var
    i,j,k,t: longint;
begin
    readln(a0,a1,b0,b1);
    change(a0,fa0);
    change(a1,fa1);
    change(b0,fb0);
    change(b1,fb1);
    fillchar(xn,sizeof(xn),0);
    fillchar(xmax,sizeof(xmax),0);
    fillchar(xmin,sizeof(xmin),0);
    for i:=1 to fa1[0].n do
cmin(fa1[i].n,fa1[i].c);
    for i:=1 to fb1[0].n do
cmax(fb1[i].n,fb1[i].c);
    for i:=1 to fb1[0].n do
    begin
         k:=get(fb0,fb1[i].n);
         if k<fb1[i].c then
         cmin(fb1[i].n,fb1[i].c);
    end;
    for i:=1 to fa0[0].n do
    begin
         k:=get(fa1,fa0[i].n);
         if k<fa0[i].c then
      cmax(fa0[i].n,k);
    end;
    for i:=1 to xn[0] do
    begin
if xmin[i]>xmax[i] then begin writeln(0);exit;end;
if xmax[i]=maxlongint then begin writeln(0);exit;end;
    end;
    t:=1
    ;
    for i:=1 to xn[0] do
t:=t*(xmax[i]-xmin[i]+1);
    writeln(t);
end; { main }
var
   tt:longint;
begin
    assign(input,'son.in');
    reset(input);
    assign(output,'son.out');
    rewrite(output);
    readln(tt);
    init;
    for tt:=tt downto 1 do
    begin
    main
    end;
    close(input);
    close(output);
end.
