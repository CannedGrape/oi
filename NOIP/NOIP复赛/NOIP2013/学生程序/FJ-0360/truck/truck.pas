program truck;
var n,m,q,b,c,d,x,y,temp,z:longint;
a,zuida:array[1..10000,1..10000] of longint;
a1:array[0..10000,0..10000] of boolean;
chengong:boolean;

procedure try(zhiqian,l,mudi,zai:longint);
var f,g:longint;
begin
if l=mudi then begin
                 zuida[x,y]:=zai;
                 writeln(zai);
                 chengong:=true;
                 exit;
                end;

a1[zhiqian,l]:=false;
a1[l,zhiqian]:=false;

for x:=1 to n do
  if (a[l,x]>0) and (a1[l,x]) then
    if temp>a[l,x] then try(l,x,mudi,a[l,x]) else try(l,x,mudi,temp);
a1[zhiqian,l]:=true;
a1[l,zhiqian]:=true;
end;

begin
assign(input,'truck.in');assign(output,'truck.out');
reset(input);rewrite(output);

fillchar(a,sizeof(a),0);fillchar(zuida,sizeof(zuida),0);
fillchar(a1,sizeof(a1),true);

readln(n,m);

for b:=1 to m do begin
  readln(x,y,z);if a[x,y]<z then begin a[x,y]:=z;a[y,x]:=z;end;
  end;

readln(q);

for b:=1 to q do begin
  readln(x,y);temp:=maxlongint;
  chengong:=false;
  if zuida[x,y]=0 then begin
                         try(0,x,y,temp);
                         if chengong=false then writeln(-1);
                       end
                  else writeln(zuida[x,y]);
  end;


close(input);close(output);
end.
