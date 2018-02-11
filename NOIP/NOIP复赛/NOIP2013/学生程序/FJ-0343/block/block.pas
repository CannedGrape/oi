program bl;
uses math;
type
 tr=^tre;
 tre=record
   ln,rn,cn,zn,data:longint;
   lt,rt:tr;
 end;
var
t1:tr;
n,i,x,num:longint;
a,h,t:array[0..100001] of longint;

procedure build(ta:tr;l,r:longint);
var
tc1,tc2:tr; mid:longint;
begin
  ta^.ln:=l; ta^.rn:=r; ta^.cn:=r-l+1; ta^.zn:=0;
  if l=r then begin ta^.data:=a[l]; ta^.lt:=nil; ta^.rt:=nil; exit; end;
  mid:=(r+l) div 2;
  new(tc1); ta^.lt:=tc1; build(tc1,l,mid);
  new(tc2); ta^.rt:=tc2; build(tc2,mid+1,r);
  ta^.data:=(ta^.lt^.data)+(ta^.rt^.data);
end;

procedure update1(ta:tr);
begin
  if ta^.ln=ta^.rn then
  begin
    dec(ta^.data);
    if ta^.data=0 then ta^.zn:=1;
    exit;
  end;
  dec(ta^.data,ta^.cn);
  update1(ta^.lt);
  update1(ta^.rt);
  if ta^.lt^.zn=1 then inc(ta^.zn);
  if ta^.rt^.zn=1 then inc(ta^.zn);
end;

procedure done(ta:tr);
begin
  if (ta^.zn=0) and (ta^.ln=ta^.rn) then
  begin
    inc(num,ta^.data);
    inc(h[ta^.ln],ta^.data); inc(t[ta^.rn],ta^.data);
    ta^.data:=0; ta^.zn:=1;
    exit;
  end;
  while ta^.zn=0 do
  begin
  inc(num); inc(h[ta^.ln]); inc(t[ta^.rn]);dec(ta^.data,ta^.cn);
  update1(ta^.lt); update1(ta^.rt);
  if ta^.lt^.zn=1 then inc(ta^.zn);
  if ta^.rt^.zn=1 then inc(ta^.zn);
  end;
  if ta^.ln=ta^.rn then exit;
  done(ta^.lt);
  done(ta^.rt);
  ta^.data:=ta^.lt^.data+ta^.rt^.data;
end;

begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  new(t1);
  build(t1,1,n);
  done(t1);
  for i:=1 to n-1 do
  begin
    if (t[i]<>0) and (h[i+1]<>0) then
    begin
      x:=min(t[i],h[i+1]);
      dec(num,x);
    end;
  end;
  writeln(num);
close(input);
close(output);
end.
