const
  maxn=100;
var
  no:boolean;
  left,distance,nowp,cost,dp,d1,c,d2,p1:real;
  i,j,t,n:integer;
  place:array[0..maxn] of integer;
  p,d:Array[0..maxn] of real;
  gas:Array[0..maxn] of real;
begin
  write('D1=');  readln(d1);
  write('C=');   readln(c);
  write('D2=');  readln(d2);
  write('P=');   readln(p1);
  write('N=');   readln(n);
  dp:=d2;  p[0]:=p1;  d[0]:=0.0;  d[n+1]:=d1; no:=false;

  for i:=1 to n do
  begin
    write('D',i,':');  readln(d[i]);
    write('P',i,':');  readln(p[i]);
    if d[i]-d[i-1]>dp*c then no:=true;
  end;
  if d[n+1]-d[n]>dp*c then no:=true;
  if no then
  begin
    writeln('No solution');
    halt;
  end;

  {sort}
  for i:=0 to n do place[i]:=i;
  for i:=0 to n-1 do
    for j:=i+1 to n do
      if p[place[i]]<p[place[j]] then
      begin
        t:=place[i];
        place[i]:=place[j];
        place[j]:=t;
      end;

  fillchar(gas,sizeof(gas),0);
  cost:=0.0;  nowp:=0.0;
  {simulate}
  for i:=0 to n do
  begin
    {fill!}
    gas[i]:=c-nowp;

    {check if anything was bought at higher price! kick it out!}
    for j:=0 to n do
      if (place[j]<i) and (p[place[j]]>p[i]) then
      begin
        gas[i]:=gas[i]+gas[place[j]]; {replace}
        gas[place[j]]:=0.0; {throw away}
      end;

    {use petrol and move to next station}
    distance:=d[i+1]-d[i];
    nowp:=c-distance/dp;
    left:=distance/dp;
    for j:=n downto 0 do
      if gas[place[j]]>0 then
      begin
        if gas[place[j]]<left then
        begin
          left:=left-gas[place[j]];
          cost:=cost+gas[place[j]]*p[place[j]];
          gas[place[j]]:=0.0;
        end
        else begin
          gas[place[j]]:=gas[place[j]]-left;
          cost:=cost+left*p[place[j]];
          break;
        end;
      end;
  end;
  writeln(cost:0:2);
end.
