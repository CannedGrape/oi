program level;
  type station=array[1..1000]of integer;
       levepic=array[1..1000,1..1000]of 0..1;

  var n,m,i,j,k:integer;
      a:levepic;
      passed,unpass:station;
      unnum,turn:integer;
      s:integer;

procedure filled(var unpass:station;passed:station;var unnum:integer);
  var p,t1,t2:integer;
begin
  p:=passed[1];
  t1:=1;t2:=0;
  while p<=passed[s] do
    begin
      if p=passed[t1]
      then begin
             inc(p);inc(t1);
           end
      else begin
             inc(t2);
             unpass[t2]:=p;
             inc(p);
           end;
    end;
  unnum:=t2;
end;

procedure form(s,unnum:integer;var a:levepic);
  var p1,p2:integer;
begin
  for p1:=1 to s do
    for p2:=1 to unnum do
      a[unpass[p2],passed[p1]]:=1;
end;

function over:boolean;
  var f:boolean;
      p1,p2:integer;
begin
  f:=true;
  for p1:=1 to n do
    for p2:=1 to n do
      if a[p1,p2]=1 then f:=false;
  over:=f;
end;

function rudu(i:integer):integer;
  var count:integer;
      t:integer;
begin
  count:=0;
  for t:=1 to n do
    if a[t,i]=1 then count:=count+1;
  rudu:=count;
end;

procedure cutout(i:integer;var a:levepic);
  var t:integer;
begin
  for t:=1 to n do
    a[i,t]:=0;
end;

begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    begin
      fillchar(passed,sizeof(passed),0);
      fillchar(unpass,sizeof(unpass),0);
      read(s);
      for j:=1 to s do
        read(passed[j]);
      filled(unpass,passed,unnum);
      form(s,unnum,a);
    end;
  turn:=1;
  while not(over) do
    begin
      for i:=1 to n do
        if rudu(i)=0 then cutout(i,a);
      turn:=turn+1;
    end;
  writeln(turn);
  close(input);
  close(output);
end.