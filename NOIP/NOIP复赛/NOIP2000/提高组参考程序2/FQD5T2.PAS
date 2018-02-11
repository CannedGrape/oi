{$r-,q-,s-,n+,g+}
program FenQuPrepare_Day5_Task2_FQ2000P2;
const
  fn_in='input.txt';
  maxn=40;
  maxk=6;
  maxhpsize=50;
type
  hp=record len:integer;s:array[1..maxhpsize] of integer;end;
var
  n,k:longint;
  h:array[0..maxn] of hp;
  st:string;

  procedure PrintHP(const x:hp);
  var i:Integer;
  begin
    for i:=x.len downto 1 do
      write(x.s[i]);
  end;

  function compare(const a,b:hp):integer;
  var l:integer;
  begin
    if a.len>b.len then compare:=1 else
    if a.len<b.len then compare:=-1 else
    begin
      l:=a.len;
      while(l>0) and (a.s[l]=b.s[l]) do dec(l);
      if l=0 then compare:=0 else
      if a.s[l]>b.s[l] then compare:=1 else compare:=-1;
    end;
  end;

  procedure Multi(const a,b:hp;var c:hp);
  var i,j,l:Integer;
  begin
    fillchar(c,sizeof(c),0);
    for i:=1 to a.len do
     for j:=1 to b.len do
     begin
       inc(c.s[i+j-1],a.s[i]*b.s[j]);
       inc(c.s[i+j],c.s[i+j-1] div 10);
       c.s[i+j-1]:=c.s[i+j-1] mod 10;
     end;
    l:=i+j;
    while(l>1) and (c.s[l]=0) do dec(l);
    c.len:=l;
  end;

  procedure GenHp(i,j:Integer;var ret:hp);
  var l,l1:integer;
  begin
    fillchar(ret,sizeof(ret),0);
    while(i<j) and (st[i]='0') do inc(i);
    l1:=0;
    for l:=j downto i do
    begin
      inc(l1);
      ret.s[l1]:=ord(st[l])-ord('0');
    end;
    ret.len:=l1;
  end;

  procedure init;
  begin
    assign(input,fn_in);
    reset(input);
    readln(n,k);
    readln(st);
  end;

  procedure main;
  var tmp,tmp1,tmp2:hp;
      i,j,l,kk:integer;
  begin
    fillchar(h,sizeof(h),0);
    for i:=1 to n do
      GenHP(1,i,h[i]);
    for kk:=1 to k do
    begin
      for i:=n downto 1 do
      begin
        fillchar(h[i].s,sizeof(h[i].s),0);
        h[i].len:=1;
        for j:=kk to i-1 do
        begin
          GenHp(j+1,i,tmp1);
          Multi(h[j],tmp1,tmp2);
          if compare(tmp2,h[i])>0 then h[i]:=tmp2;
        end;
      end;
    end;
  end;

  procedure out;
  var i:Integer;
  begin
    PrintHp(h[n]);
    writeln;
  end;

  var x,y,z:hp;
  begin
    init;
    main;
    out;
{    x.s[1]:=4;
    x.s[2]:=0;
    x.len:=1;
    y.s[1]:=1;
    y.s[2]:=5;
    y.len:=2;
    multi(x,y,z);
    PrintHp(z);
    writeln;}{debug}
  end.