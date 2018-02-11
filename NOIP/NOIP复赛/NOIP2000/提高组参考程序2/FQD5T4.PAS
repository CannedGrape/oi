{$r-,q-,s-,n+,g+}
program FenQuPrepare_Day5_Task4_FQ2000P4;
const
  fn_in='input.txt';
  maxn=10;
var
  g:array[1..maxn,1..maxn] of integer;
  h:array[1..maxn,1..maxn,1..maxn,1..maxn] of integer;
  n,x,y:integer;

  procedure init;
  var x,y,w:integer;
  begin
    assign(input,fn_in);
    reset(input);
    fillchar(g,sizeof(g),0);
    readln(n);
    readln(x,y,w);
    while(x+y+w>0) do
    begin
      g[x,y]:=w;
      readln(x,y,w);
    end;
  end;

  function max(a,b:Integer):integer;
  begin
    if a>b then max:=a else max:=b;
  end;

  procedure Update(x1,y1,x2,y2,src:integer);
  var i:Integer;
  begin
    if (x1=x2) and (y1=y2) then
       h[x1,y1,x2,y2]:=max(h[x1,y1,x2,y2],src+g[x1,y1]) else
       h[x1,y1,x2,y2]:=max(h[x1,y1,x2,y2],src+g[x1,y1]+g[x2,y2]);
  end;

  procedure main;
  var x1,y1,x2,y2,sum:Integer;
  begin
    fillchar(h,sizeof(h),0);
    h[1,1,1,1]:=g[1,1];
    for sum:=2 to n+n-1 do
    begin
      for x1:=1 to sum-1 do
       for x2:=1 to sum-1 do
       begin
         y1:=sum-x1;
         y2:=sum-x2;
         Update(x1+1,y1,x2+1,y2,h[x1,y1,x2,y2]);
         Update(x1+1,y1,x2,y2+1,h[x1,y1,x2,y2]);
         Update(x1,y1+1,x2+1,y2,h[x1,y1,x2,y2]);
         Update(x1,y1+1,x2,y2+1,h[x1,y1,x2,y2]);
       end;
    end;
  end;

  procedure out;
  begin
    writeln(h[n,n,n,n]);
  end;

  begin
    init;
    main;
    out;
  end.