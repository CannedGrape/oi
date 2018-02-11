var
  i,j,m,n,k,l,r,ro:longint;ans:int64;
  a,f:array [0..100000] of longint;
  lit:array [0..300100] of record l,r,ll,rr,b:longint;end;
  flag:array [0..300100] of boolean;
procedure heaps(k,e:longint);
var
  i,j:longint;
begin
  i:=k shl 1;if (i<e) and (a[f[i+1]]<a[f[i]]) then inc(i);
  while not (i>e) and (a[f[i]]<a[f[k]]) do
  begin
    f[0]:=f[i];f[i]:=f[k];f[k]:=f[0];
    k:=i;i:=k shl 1;if (i<e) and (a[f[i+1]]<a[f[i]]) then inc(i);
  end;
end;
procedure deep(ks:longint);
var
  i,j:longint;
begin
  i:=1;
  while not flag[i] do
  begin
    i:=i shl 1;
    if ks>lit[i].r then inc(i);
  end;
  while lit[i].l<lit[i].r do with lit[i] do
  begin
    k:=i;
    flag[i]:=false;i:=i shl 1;
    flag[i]:=true;flag[i+1]:=true;
    lit[i].l:=l;lit[i].r:=(l+r) div 2;
    lit[i+1].l:=(l+r) div 2+1;lit[i+1].r:=r;
    if ks>(l+r) div 2 then
    begin
      lit[i].b:=1;lit[i].ll:=1;lit[i].rr:=1;
      inc(i);
    end
    else
    begin
      lit[i+1].b:=1;lit[i+1].ll:=1;lit[i+1].rr:=1;
    end;
  end;
  lit[i].b:=0;flag[i]:=false;lit[i].ll:=0;lit[i].rr:=0;
  while i>1 do
  begin
    i:=i shr 1;
    lit[i].b:=lit[i shl 1].b+lit[i shl 1+1].b-lit[i shl 1].rr and lit[i shl 1+1].ll;
    lit[i].ll:=lit[i shl 1].ll;lit[i].rr:=lit[i shl 1+1].rr;
  end;
end;
begin
  assign(input,'block.in');reset(input);assign(output,'block.out');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do f[i]:=i;
  fillchar(flag,n shl 1+1,false);
  for i:=n div 2 downto 1 do heaps(i,n);
  with lit[1] do
  begin
    l:=1;r:=n;b:=1;flag[1]:=true;
  end;
  l:=0;m:=n;ans:=0;
  while m>0 do
  begin
    r:=a[f[1]];ro:=lit[1].b;
    inc(ans,ro*(r-l));
    while (m>0) and (a[f[1]]=r) do
    begin
      deep(f[1]);
      f[0]:=f[1];f[1]:=f[m];f[m]:=f[0];
      dec(m);heaps(1,m);
    end;
    l:=r;
  end;
  writeln(ans);
  close(input);close(output);
end.
