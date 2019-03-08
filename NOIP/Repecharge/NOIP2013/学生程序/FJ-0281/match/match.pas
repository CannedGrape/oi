var
  i,j,k,m,n,t,cc:longint;
  a,b,aa,bb,c:array[0..100000] of longint;
procedure kp1(l,r:longint);
  var
    ll,rr,mm,mid:longint;
  begin
    ll:=l;  rr:=r;  mid:=a[(ll+rr) mod 2];
    while ll<=rr do
      begin
       while a[ll]<mid do  inc(ll);
       while a[rr]<mid do  dec(rr);
       if ll<=rr then
        begin
         mm:=a[ll];  a[ll]:=a[rr];  a[rr]:=mm;
         mm:=aa[ll];  aa[ll]:=aa[rr];  aa[rr]:=mm;
         inc(ll);  dec(rr);
        end;
      end;
      if ll<r then kp1(ll,r);
      if l<rr then kp1(l,rr);
  end;
procedure kp2(l,r:longint);
  var
   ll,rr,mm,mid:longint;
  begin
    ll:=l;  rr:=r;  mid:=a[(ll+rr) mod 2];
    while ll<=rr do
     begin
      while b[ll]<mid do  inc(ll);
      while b[rr]>mid do  dec(rr);
      if ll<=rr then
       begin
        mm:=b[ll];  b[ll]:=b[rr]; b[rr]:=mm;
        mm:=bb[ll];  bb[ll]:=bb[rr];  bb[rr]:=mm;
        inc(ll);  dec(rr);
       end;
     end;
     if ll<r then   kp2(ll,r);
     if rr>l then   kp2(l,rr);
  end;
begin
  assign(input,'match.in');  reset(input);
  assign(output,'match.out');  rewrite(output);
  readln(n);
  for i:=1 to n do
   begin read(a[i]);  aa[i]:=i;  end;
  readln;
  for i:=1 to n do
   begin read(b[i]);  bb[i]:=i;  end;
  kp1(1,n);   kp2(1,n);
  for i:=1 to n do
    for j:=1 to n do
      if a[i]=b[j] then
       begin
         c[j]:=i;  break;
       end;
  m:=0;
  while  m=0 do
   begin
     for i:=1 to n do
      if c[i]<>i then
        if c[c[i]]=i then begin cc:=(cc+1) mod 99999997;
        c[c[i]]:=c[i];  c[i]:=i;  end;
     for i:=1 to n do
      if c[i]<>i then
       begin
        cc:=(cc+1) mod 99999997;  c[i]:=c[c[i]];  c[c[i]]:=c[i];
       end;
     t:=1;
     for i:=1 to n do
       if c[i]<>i then t:=0;
     if t=1 then m:=1;
   end;
  write(cc);
  close(input);  close(output);
end.


