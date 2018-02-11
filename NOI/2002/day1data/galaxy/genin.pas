{ NOI 2002 Galaxy Data Generator by Rujia Liu }
const
  n:array[1..10] of integer=
  (5,20,100,1000,10000,30000,30000,30000,30000,30000);
  l:array[1..10] of longint=
  (10,100,1000,10000,50000,100000,200000,200000,500000,500000);
  freq:array[1..10] of integer=
  (1,2,1,3,2,1,5,3,2,5);
var
  gen:integer;
  datafile:string;
  father:array[1..30000] of integer;

function find_father(x:integer):integer;
var i,j,f,next:integer;
begin
  {find father}
  i:=x;
  while father[i]<>i do i:=father[i];
  f:=i;
  i:=x;
  while i<>f do
  begin
    next:=father[i];
    father[i]:=f;
    i:=next;
  end;
  find_father:=f;
end;

function moveship(x,y:integer):boolean;
var fx,fy:integer;
begin
  moveship:=false;
  fx:=find_father(x);
  fy:=find_father(y);
  if fx=fy then exit;
  father[father[fx]]:=fy;
  writeln('M ',x,' ',y);
  moveship:=true;
end;

var i,x,y:longint;
    result:boolean;
    c:longint;
begin
  for gen:=1 to 10 do
  begin
    str(gen,datafile);
    datafile:='galaxy'+datafile+'.in';
    assign(output,'');
    rewrite(output);
    writeln('Generating ',datafile,' ...');

    assign(output,datafile);
    rewrite(output);
    writeln(l[gen]);
    randomize;
    for i:=1 to n[gen] do father[i]:=i;
    c:=1;
    for i:=1 to l[gen] do
    begin
      if (c<n[gen])and(random(freq[gen])=0) then
      begin
        inc(c);
        repeat
          x:=random(n[gen])+1;
          y:=random(n[gen])+1;
          result:=moveship(x,y);
        until result;
      end
      else begin
        repeat
          x:=random(n[gen])+1;
          y:=random(n[gen])+1;
        until x<>y;
        writeln('C ',x,' ',y);
      end;
    end;
    close(output);
  end;
end.
