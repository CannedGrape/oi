//flower
var a,s,e,f,vs,vb:array[0..100000] of longint;
  i,j,n,he,fl,mi,ma,t,ans:longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);he:=0;fl:=0;ans:=0;
  fillchar(s,sizeof(s),0);
  fillchar(e,sizeof(e),0);
  fillchar(f,sizeof(f),0);
  fillchar(vs,sizeof(vs),0);
  fillchar(vb,sizeof(vb),0);
  read(a[1]);fl:=0;
  for i:=2 to n do
  begin
    read(a[i]);
    if fl=0 then
    begin
      if a[i]>a[i-1] then
      begin
        fl:=1;
        inc(he);
        s[he]:=a[i-1];e[he]:=a[i];f[he]:=1;
      end;
      if a[i]<a[i-1] then
      begin
        fl:=2;
        inc(he);
        s[he]:=a[i];e[he]:=a[i-1];f[he]:=2;
      end;
      if a[i]=a[i-1] then
      begin
        fl:=3;
        inc(he);
        s[he]:=a[i];e[he]:=a[i];f[he]:=3;
      end;
    end;
    if fl=1 then
    begin
      if a[i]>a[i-1] then e[he]:=a[i] else fl:=0;
    end;
    if fl=2 then
    begin
      if a[i]<a[i-1] then s[he]:=a[i] else fl:=0;
    end;
    if fl=3 then
    begin
      if a[i]<>a[i-1] then fl:=0;
    end;
  end;
  if fl=0 then
  begin
    inc(he);s[he]:=a[n];e[he]:=a[n];f[he]:=3;
  end;
  vs[1]:=1;vb[1]:=1;
  if f[1]=1 then vs[1]:=2 else vb[1]:=2;
  if f[1]=3 then begin vs[1]:=1; vb[1]:=1; end;
  for i:=1 to he do
  begin
    if vs[i]>ans then ans:=vs[i];
    if vb[i]>ans then ans:=vb[i];
    for j:=i+1 to he do
    begin
      if f[i]=1 then
      begin
        if (f[j]=2) and (s[j]<e[i]) and (vb[j]<=vs[i]) then
            vb[j]:=vs[i]+1;
        if (f[j]=1) and (s[j]<e[i]) and (vs[j]<vs[i]+2) then
            vs[j]:=vs[i]+2;
        if (f[j]=2) and (e[j]>s[i]) and (vb[j]<vb[i]+2) then
            vb[j]:=vb[i]+2;
        if (f[j]=1) and (e[j]>s[i]) and (vs[j]<=vb[i]) then
            vs[j]:=vb[i]+1;
        if (f[j]=3) and (s[j]<e[i]) and (vb[j]<=vs[i]) then
            vb[j]:=vs[i]+1;
        if (f[j]=3) and (s[j]>s[i]) and (vs[j]<=vb[i]) then
            vs[j]:=vb[i]+1;
      end;
      if f[i]=2 then
      begin
        if (f[j]=1) and (e[j]>s[i]) and (vs[j]<=vb[i]) then
            vs[j]:=vb[i]+1;
        if (f[j]=2) and (e[j]>s[i]) and (vb[j]<vb[i]+2) then
            vb[j]:=vb[i]+2;
        if (f[j]=1) and (s[j]<e[i]) and (vs[j]<vs[i]+2) then
            vs[j]:=vs[i]+2;
        if (f[j]=2) and (s[j]<e[i]) and (vb[j]<=vs[i]) then
            vb[j]:=vs[i]+1;
        if (f[j]=3) and (s[j]>s[i]) and (vs[j]<=vb[i]) then
            vs[j]:=vb[i]+1;
        if (f[j]=3) and (s[j]<e[i]) and (vb[j]<=vs[i]) then
            vb[j]:=vs[i]+1;
      end;
      if f[i]=3 then
      begin
        if (f[j]=1) and (s[j]<s[i]) and (vs[j]<vs[i]+2) then
            vs[j]:=vs[i]+2;
        if (f[j]=1) and (e[j]>s[i]) and (vs[j]<=vb[i]) then
            vs[j]:=vb[i]+1;
        if (f[j]=2) and (e[j]>s[i]) and (vb[j]<vb[i]+2) then
            vb[j]:=vb[i]+2;
        if (f[j]=2) and (s[j]<s[i]) and (vb[j]<=vs[i]) then
            vb[j]:=vs[i]+1;
        if (f[j]=3) and (s[j]>s[i]) and (vs[j]<=vb[i]) then
            vs[j]:=vb[i]+1;
        if (f[j]=3) and (s[j]<s[i]) and (vb[j]<=vs[i]) then
            vb[j]:=vs[i]+1
      end;
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
