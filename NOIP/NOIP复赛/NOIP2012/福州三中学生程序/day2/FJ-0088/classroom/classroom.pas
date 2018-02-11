const filename='classroom';
maxn=1000000;maxt=2097152;
inf=maxlongint div 2;
var n,m,i,j,k,a,b,c:longint;

t,temp,s:longint;
tree:array[1..maxt]of longint;

function find(l,r:longint):longint;
var tl,tr,ansl,ansr,ans,p:longint;
begin
  ansl:=inf;ansr:=inf;
  tl:=t+l-1;
  tr:=t+r+1;
  while tl<tr do begin
    if (not(odd(tl)))and(tl+1<tr) then begin
      if tree[tl xor 1]<ansl then ansl:=tree[tl xor 1];
    end;
    if (   (odd(tr)))and(tl+1<tr) then begin
      if tree[tr xor 1]<ansr then ansr:=tree[tr xor 1];
    end;
    tl:=tl shr 1;
    tr:=tr shr 1;
    if ansl<inf then inc(ansl,tree[tl]);
    if ansr<inf then inc(ansr,tree[tr]);
  end;
  if ansl<ansr then ans:=ansl else ans:=ansr;
  p:=tl;
  while p>0 do begin
    p:=p shr 1;
    inc(ans,tree[p]);
  end;
  exit(ans);
end;

procedure change(l,r,x:longint);
var tl,tr,temp:longint;
begin
  tl:=t+l-1;
  tr:=t+r+1;
  while tl<tr do begin
    if (not(odd(tl)))and(tl+1<tr) then
      dec(tree[tl xor 1],x);
    if (   (odd(tr)))and(tl+1<tr) then
      dec(tree[tr xor 1],x);
    tl:=tl shr 1;
    tr:=tr shr 1;
    if tree[tl shl 1]<tree[tl shl 1+1] then
      temp:=tree[tl shl 1]
    else
      temp:=tree[tl shl 1+1];
    dec(tree[tl shl 1],temp);
    dec(tree[tl shl 1+1],temp);
    inc(tree[tl],temp);
    if tree[tr shl 1]<tree[tr shl 1+1] then
      temp:=tree[tr shl 1]
    else
      temp:=tree[tr shl 1+1];
    dec(tree[tr shl 1],temp);
    dec(tree[tr shl 1+1],temp);
    inc(tree[tr],temp);
  end;
end;
{
procedure print;
var i,j,temp:longint;
begin
  temp:=1;
  while 1 shl temp<>t do inc(temp);
  for i:=0 to temp do begin
    for j:=1 shl i to 1 shl (i+1)-1 do
      write(tree[j],' ');
    writeln;
  end;
  writeln;
end;
}
begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);

  read(n,m);
  t:=1;
  while 1 shl t<n+2 do inc(t);
  t:=1 shl t;
  for i:=1 to n do
    read(tree[t+i]);
  for i:=t-1 downto 1 do begin
    if tree[i shl 1]<tree[i shl 1+1] then
      temp:=tree[i shl 1]
    else
      temp:=tree[i shl 1+1];
    dec(tree[i shl 1],temp);
    dec(tree[i shl 1+1],temp);
    inc(tree[i],temp);
  end;

  for i:=1 to m do begin
    read(a,b,c);
    s:=find(b,c);
    if s>=a then change(b,c,a)
    else begin
      writeln(-1);
      writeln(i);
      close(input);close(output);
      halt;
    end;
  end;

  writeln(0);

  close(input);close(output);
end.
