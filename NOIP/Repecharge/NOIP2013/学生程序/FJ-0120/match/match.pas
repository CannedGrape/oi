const p=99999997;
var
  i,j,k:longint;
  a,b,ta,tb,tta,ttb:array[0..100000] of int64;
  n,m,ans1,ans2,t,tot,tott:int64;




procedure kp1(l,r:longint);
var
  i,j:longint;
  t,mid:int64;
begin
  i:=l; j:=r;
  mid:=a[(l+r) div 2];
  repeat
    while (a[i]<mid) do inc(i);
    while (a[j]>mid) do dec(j);
    if i<=j then
     begin
       t:=a[i]; a[i]:=a[j]; a[j]:=t;
       t:=ta[i]; ta[i]:=ta[j]; ta[j]:=t;
       tta[i]:=ta[i]; tta[j]:=ta[j];
       inc(i); dec(j);
     end;

  until i>=j ;
  if i<r then kp1(i,r);
  if j>l then kp1(l,j);
end;

procedure kp2(l,r:longint);
var
  i,j:longint;
  t,mid:int64;
begin
  i:=l; j:=r;
  mid:=b[(l+r) div 2];
  repeat
    while (b[i]<mid) do inc(i);
    while (b[j]>mid) do dec(j);
    if i<=j then
     begin
       t:=b[i]; b[i]:=b[j]; b[j]:=t;
       t:=tb[i]; tb[i]:=tb[j]; tb[j]:=t;
       ttb[i]:=tb[i]; ttb[j]:=tb[j];
       inc(i); dec(j);
     end;

  until i>=j ;
  if i<r then kp2(i,r);
  if j>l then kp2(l,j);
end;


begin
assign(input,'match.in'); reset(input);
assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do begin read(a[i]); ta[i]:=i; tta[i]:=i;end;
  readln;
  for i:=1 to n do
    begin
      read(b[i]);
      tott:=(tott+(a[i]-b[i])*(a[i]-b[i])) mod p;
      tb[i]:=i;
      ttb[i]:=i;
    end;

  kp1(1,n);
  kp2(1,n);


  for i:=1 to n do tot:=(tot+(a[i]-b[i])*(a[i]-b[i])) mod p;

  if tot=tott then begin writeln(0); close(input); close(output); halt; end;



  for k:=1 to n do
   begin
     if ta[k]=tb[k] then continue;
     for i:=k+1 to n do
      begin
        if ta[i]=tb[k] then
         begin
           ans1:=(ans1+(i-k)) mod p;
           ans1:=(ans1+(i-1)-k) mod p;
           t:=ta[i]; ta[i]:=tb[k]; tb[k]:=t;
         end;
      end;
   end;

  if ans1=0 then begin writeln(ans1); close(input); close(output); halt; end;
  ta:=tta; tb:=ttb;


  for k:=1 to n do
   begin
     if ta[k]=tb[k] then continue;
     for i:=k+1 to n do
      begin
        if tb[i]=ta[k] then
         begin
           ans2:=(ans2+(i-k)) mod p;
           ans2:=(ans2+(i-1)-k) mod p;
           t:=tb[i]; tb[i]:=ta[k]; ta[k]:=t;
         end;
      end;
   end;


  if ans1<ans2 then writeln(ans1) else writeln(ans2);





close(input); close(output);
end.
