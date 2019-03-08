program match;
const filename='match';
modp=99999997;
maxn=100000;
var n,m,i,j,k:longint;
temp:longint;
a,b,index1,index2:array[1..maxn]of longint;
unindex1,unindex2:array[1..maxn]of longint;

now,aim:array[1..maxn]of longint;
ans:int64;

procedure qsort1(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=index1[(l+r)shr 1];
  while i<=j do
    begin
      while a[index1[i]]<a[x] do inc(i);
      while a[x]<a[index1[j]] do dec(j);
      if i<=j then
        begin
          y:=index1[i];index1[i]:=index1[j];index1[j]:=y;
          unindex1[index1[i]]:=i;unindex1[index1[j]]:=j;
          inc(i);dec(j);
        end;
    end;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
end;

procedure qsort2(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=index2[(l+r)shr 1];
  while i<=j do
    begin
      while b[index2[i]]<b[x] do inc(i);
      while b[x]<b[index2[j]] do dec(j);
      if i<=j then
        begin
          y:=index2[i];index2[i]:=index2[j];index2[j]:=y;
          unindex2[index2[i]]:=i;unindex2[index2[j]]:=j;
          inc(i);dec(j);
        end;
    end;
  if l<j then qsort2(l,j);
  if i<r then qsort2(i,r);
end;

procedure megasort(l,r:longint);
var i,j,k,t,count1,count2:longint;
begin
  if l=r then exit;
  t:=(l+r)shr 1;
  megasort(l,t);
  megasort(t+1,r);
  i:=l;
  j:=t+1;

  count1:=t-i+1;
  count2:=r-j+1;
  for k:=1 to r-l+1 do begin
    if (i<=t)and(j<=r) then begin
      if now[i]<now[j] then begin
        aim[k]:=now[i];
        inc(i);
        dec(count1);
      end
      else begin
        aim[k]:=now[j];
        inc(j);
        dec(count2);
        inc(ans,count1);
      end;
    end
    else begin
      if i<=t then begin
        aim[k]:=now[i];
        inc(i);
        dec(count1);
      end;
      if j<=r then begin
        aim[k]:=now[j];
        inc(j);
        dec(count2);
      end;
    end;
  end;
  for k:=1 to r-l+1 do
    now[l+k-1]:=aim[k];
end;

begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);

  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do begin index1[i]:=i;index2[i]:=i;unindex1[i]:=i;unindex2[i]:=i; end;

  qsort1(1,n);
  qsort2(1,n);

  for i:=1 to n do
    begin
      temp:=index1[i];index1[i]:=unindex1[i];unindex1[i]:=temp;
      temp:=index2[i];index2[i]:=unindex2[i];unindex2[i]:=temp;
    end;
  {
  writeln;
  for i:=1 to n do write(index1[i],' ');writeln;
  for i:=1 to n do write(unindex1[i],' ');writeln;
  for i:=1 to n do write(index2[i],' ');writeln;
  for i:=1 to n do write(unindex2[i],' ');writeln;
  }
  for i:=1 to n do
    index2[i]:=unindex1[index2[i]];
  for i:=1 to n do begin
    index1[i]:=i;
    unindex1[index1[i]]:=i;
    unindex2[index2[i]]:=i;
  end;

  for i:=1 to n do
    now[i]:=index2[i];
  {
  writeln;
  for i:=1 to n do write(index1[i],' ');writeln;
  for i:=1 to n do write(unindex1[i],' ');writeln;
  for i:=1 to n do write(index2[i],' ');writeln;
  for i:=1 to n do write(unindex2[i],' ');writeln;
  }
  ans:=0;

  megasort(1,n);

  write(ans mod modp);

  close(input);close(output);
end.
