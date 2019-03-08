var
  i,j,k,m,n,x,y,z:longint;
  a,b,c:array[0..10000,0..10000] of longint;
  team:array[0..20030] of longint;
  pd:array[0..10000] of 0..1;
function min(aa,bb:longint):longint;
  begin
    if aa<bb then exit(aa);
    exit(bb);
  end;
procedure  spfa(x:longint);
  var
    hh,tt,now,ii,jj:longint;
  begin
    fillchar(team,sizeof(team),0);
    fillchar(pd,sizeof(pd),0);
    team[1]:=x;    now:=x;  hh:=0; tt:=1;
    pd[x]:=1;
    while hh<tt do
      begin
       inc(hh);
       now:=team[hh];
       for ii:=1 to a[now,0] do
        begin
         if pd[a[x,ii]]=0 then
          begin
            inc(tt);  team[tt]:=a[x,ii];     pd[team[tt]]:=1;
          end;
         jj:=min(c[x,now],b[now,team[tt]]);
         if ((c[x,team[tt]]<jj) or (c[x,team[tt]]>1000000)) and (jj>0) then
           c[x,team[tt]]:=jj;
        end;
       pd[now]:=0;
       if hh>3*n then break;
      end;
  end;
begin
  assign(input,'truck.in');  reset(input);
  assign(output,'truck.out');  rewrite(output);
  readln(n,m);
  fillchar(b,sizeof(b),0);
  for i:=1 to m do
   begin
     readln(x,y,z);
     inc(a[x,0]);  a[x,a[x,0]]:=y;  b[x,y]:=z+b[x,y];
     inc(a[y,0]);  a[y,a[y,0]]:=x;  b[y,x]:=z+b[y,x];
   end;

  fillchar(c,sizeof(c),$7f);
  for i:=1 to n do
   for j:=1 to n do
    if b[i,j]=0 then b[i,j]:=1000000000;
  for i:=1 to n do
    begin c[i,i]:=0;   b[i,i]:=0;    end;
  for i:=1 to n do
   spfa(i);
  {for i:=1 to n do
   begin
   for j:=1 to n do
    write(c[i,j],' ');
   writeln;
   end;                                      }
  readln(m);
  for i:=1 to m do
   begin
    readln(x,y);
    if c[x,y]>1000000 then write(-1)
     else write(c[x,y]);
   end;
  close(input);  close(output);
end.
