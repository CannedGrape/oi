var a,b:array[1..50000] of integer;
    c:array[1..50000] of longint;
    d:array[1..50000] of boolean;
    n,x,y,t:integer;
    m,ans,answer,z,i,q:longint;

//___________________________________
procedure iin;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
end;
procedure oout;
begin
  close(input);
  close(output);
end;
//___________________________________
procedure sear(xx:integer);
var ii,jj:longint;
begin
  if (xx=y)and(ans>answer) then answer:=ans
  else
   begin
    for ii:=1 to m do
    begin
     if (a[ii]=xx)and(d[ii]) then
      begin
       jj:=ans;
       if c[ii]<ans then ans:=c[ii];
       d[ii]:=false;
       sear(b[ii]);
       d[ii]:=true;
       ans:=jj;
      end;
     if (b[ii]=xx)and(d[ii]) then
      begin
       jj:=ans;
       if c[ii]<ans then ans:=c[ii];
       d[ii]:=false;
       sear(a[ii]);
       d[ii]:=true;
       ans:=jj;
      end;
    end;
   end;
end;

//___________________________________
begin
  iin;
  readln(n,m);
  for i:=1 to m do
   begin
    readln(x,y,z);
    if x<y then
     begin
      a[i]:=x; b[i]:=y; c[i]:=z;
     end
    else
     begin
      a[i]:=y; b[i]:=x; c[i]:=z;
     end;
   end;
  readln(q);
  for i:=1 to q do
   begin
    readln(x,y);
    fillchar(d,sizeof(d),true);
    if x>y then
     begin
      t:=x; x:=y; y:=t;
     end;
    ans:=maxlongint;
    answer:=-1;
    sear(x);
    writeln(answer);
   end;
  oout;
end.
