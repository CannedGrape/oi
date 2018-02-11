var
  a1,a2,a3,b1,b2,b3,a4,b4:array[0..100010]of int64;
  n,m,i,j,l,t,x,y:longint;
  s,ans:int64;

procedure q1(l,r:longint);
var i,j:longint; k,mid:int64;
begin
  i:=l; j:=r;
  mid:=a2[random(r-l)+l];
  repeat
    while a2[i]<mid do inc(i);
    while a2[j]>mid do dec(j);
    if j>=i then
      begin
        k:=a2[i];a2[i]:=a2[j];a2[j]:=k;
        k:=a3[i];a3[i]:=a3[j];a3[j]:=k;
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then q1(i,r);
  if l<j then q1(l,j);
end;

procedure q2(l,r:longint);
var i,j:longint; k,mid:int64;
begin
  i:=l; j:=r;
  mid:=b2[random(r-l)+l];
  repeat
    while b2[i]<mid do inc(i);
    while b2[j]>mid do dec(j);
    if j>=i then
      begin
        k:=b2[i];b2[i]:=b2[j];b2[j]:=k;
        k:=b3[i];b3[i]:=b3[j];b3[j]:=k;
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then q2(i,r);
  if l<j then q2(l,j);
end;

procedure q3(l,r:longint);
var i,j:longint; k,mid:int64;
begin
  i:=l; j:=r;
  mid:=a4[random(r-l)+l];
  repeat
    while a4[i]<mid do inc(i);
    while a4[j]>mid do dec(j);
    if j>=i then
      begin
        k:=a4[i];a4[i]:=a4[j];a4[j]:=k;
        k:=a1[i];a1[i]:=a1[j];a1[j]:=k;
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then q3(i,r);
  if l<j then q3(l,j);
end;

procedure q4(l,r:longint);
var i,j:longint; k,mid:int64;
begin
  i:=l; j:=r;
  mid:=b4[random(r-l)+l];
  repeat
    while b4[i]<mid do inc(i);
    while b4[j]>mid do dec(j);
    if j>=i then
      begin
        k:=b4[i];b4[i]:=b4[j];b4[j]:=k;
        k:=b1[i];b1[i]:=b1[j];b1[j]:=k;
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then q4(i,r);
  if l<j then q4(l,j);
end;


begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n); t:=99999997;
  for i:=1 to n do begin read(a1[i]); a3[i]:=i; end;
  for i:=1 to n do read(b1[i]); b3:=a3;
  a2:=a1; q1(1,n);
  b2:=b1; q2(1,n);
  for i:=1 to n do
    begin
      a1[i]:=i;b1[i]:=i;
    end;
  a4:=a3;b4:=b3;
  q3(1,n); q4(1,n);
  s:=0;
  for i:=1 to n do
    begin
      if a3[b1[i]]<>i then
        begin
          s:=(s+abs(i-a3[b1[i]])) mod t;
          for j:=1 to n do
            if a3[j]<a3[b1[i]] then inc(a3[j]);
          a3[b1[i]]:=i;
        end;
    end;
  writeln(s);
  readln;readln;
  close(input);close(output);
end.
