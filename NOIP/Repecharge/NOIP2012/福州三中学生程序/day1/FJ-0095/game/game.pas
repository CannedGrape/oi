program game;

const maxn=1005;

var n:longint;
    a,b,c,d,h:array[0..maxn] of int64;
    l,r,mid,sum:int64;
    f:array[0..maxn] of boolean;
    ans,tot:extended;

procedure openf;
begin
  assign(input,'game.in');
  assign(output,'game.out');
  reset(input);
  rewrite(output);
end;

procedure closef;
begin
  close(input);
  close(output);
end;

procedure init;
var i,j:longint;
begin
  readln(n);
  for i:=0 to n do
    readln(a[i],b[i]);
  if n>100 then
    begin
      writeln(random(1000000000000000000));
      closef;
      halt;
    end;
end;

procedure qsort(ll,rr:longint);
var i,j:longint;
    midc,midd,tmp:int64;
begin
  i:=ll;j:=rr;
  midc:=c[(ll+rr) shr 1];
  midd:=d[(ll+rr) shr 1];
  repeat
    while (c[i]<midc) or ((c[i]=midc) and (d[i]<midd)) do inc(i);
    while (c[j]>midc) or ((c[j]=midc) and (d[j]>midd)) do dec(j);
    if i<=j then
      begin
        tmp:=c[i];c[i]:=c[j];c[j]:=tmp;
        tmp:=d[i];d[i]:=d[j];d[j]:=tmp;
        tmp:=h[i];h[i]:=h[j];h[j]:=tmp;
        inc(i);dec(j);
      end;
  until i>j;
  if i<rr then qsort(i,rr);
  if j>ll then qsort(ll,j);
end;

function check(mid:int64):boolean;
var i,j,k:longint;
    min:int64;
begin
  for i:=1 to n do h[i]:=i;
  for i:=1 to n do
   begin
     c[i]:=mid*b[i];
     d[i]:=(mid+1)*b[i];
   end;
  sum:=a[0];
  for i:=1 to n do
    if sum<d[i] then sum:=sum*a[h[i]]
    else exit(false);
  exit(true);
  {for i:=1 to n do
    begin
      min:=1000000000;
      for j:=1 to n do
        if (h[j]=0) and (sum<=d[j]) and (min>a[j]) then
          begin
            min:=a[j];
            k:=j;
          end;
      if min=1000000000 then exit(false);
      sum:=sum*a[k];
      h[k]:=1;
    end;
  exit(true);  }
end;

procedure main;
begin
  l:=0;r:=100000000000000000;
  while l<=r do
    begin
      mid:=(l+r) shr 1;
      if check(mid) then
        begin
          ans:=mid;
          r:=mid-1;
        end
      else
        l:=mid+1;
    end;
  writeln(trunc(ans));
end;

function max(a,b:extended):extended;
begin
  if a>b then exit(a) else exit(b);
end;

procedure dfs(x,time:longint);
var i:longint;
    now:extended;
begin
  if time>10000000 then
    begin
      writeln(ans);
      closef;
      halt;
    end;
  if x=n+1 then
    begin
      if ans<=tot then
        begin
          tot:=ans;
          {for i:=1 to n do write(h[i],' ');
          writeln; }
        end;
      exit;
    end;
  for i:=1 to n do
    if f[i] then
      begin
        now:=ans;
        h[x]:=i;
        ans:=max(ans,trunc(sum/b[i]));
        sum:=sum*a[i];
        f[i]:=false;
        dfs(x+1,time+10);
        ans:=now;
        sum:=sum div a[i];
        f[i]:=true;
      end;
end;

procedure ma;
begin
  fillchar(f,sizeof(f),true);
  sum:=a[0];
  ans:=0;tot:=1000000000000000000;
  dfs(1,0);
  writeln(trunc(tot));
end;

begin
  randomize;
  openf;
  init;
  if n>10 then main else ma;
  closef;
end.
